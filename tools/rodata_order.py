"""Reorder the rodata in a one-file EXE so jump tables can be matched in C.

Each EXE is one C file, so its .rodata comes out in file order: every
INCLUDE_RODATA line and every C data definition where it stands, plus the
unnamed rodata GCC writes next to a C function (`$LC` constants just before
it, jump tables just after it). For a function's own rodata to land at its
original address, every rodata item below that address has to come before
the function in the file, and every item above it after.

This script lays the file out that way (the DH1 layout, see "Jump tables and
rodata order" in docs/compiler-notes.md):

- Anchors are functions whose rodata is tied to their place in the file:
  C functions that emit unnamed rodata (found in GCC's output), and
  INCLUDE_ASM functions that use a jump table or carry rodata in their .s
  file. Each anchor has an address: its first table, or for a C function the
  first rodata item that follows it now.
- Anchors must rise with the file; an INCLUDE_ASM anchor that would break that
  is dropped and reported (it stays blocked).
- Every rodata item goes right after the last anchor whose address is at or
  below it, in address order.
- A C data definition that moves further down leaves an extern declaration in
  its old place, so the code above it still sees it.

usage: python -I tools/rodata_order.py <exe> <gcc-output.s> [--write]
  <gcc-output.s> is cc1's output for src/<exe>/<exe>.c (before maspsx).
"""
import re
import sys

exe, gcc_out = sys.argv[1], sys.argv[2]
write = "--write" in sys.argv
path = f"src/{exe}/{exe}.c"
asm_dir = f"asm/{exe}/nonmatchings/{exe}/"
text = open(path, newline="").read()
nl = "\r\n" if "\r\n" in text else "\n"
lines = text.split(nl)

ADDR = re.compile(r"(?:func|D|jtbl)_([0-9A-F]{8})$")


def addr_of(name):
    m = ADDR.search(name)
    return int(m.group(1), 16) if m else None


# ---- split the file into top-level statements --------------------------------
stmts = []  # dicts: kind, name, lines
i = 0
while i < len(lines):
    l = lines[i]
    m = re.match(r'INCLUDE_(ASM|RODATA)\("[^"]*", (\w+)\);', l)
    if m:
        kind = "asm" if m.group(1) == "ASM" else "rodata"
        stmts.append(dict(kind=kind, name=m.group(2), lines=[l]))
        i += 1
        continue
    if l.strip() == "" or l.startswith("#") or l.lstrip().startswith("//"):
        stmts.append(dict(kind="other", name=None, lines=[l]))
        i += 1
        continue
    if l.lstrip().startswith("/*"):
        j = i
        while "*/" not in lines[j]:
            j += 1
        stmts.append(dict(kind="other", name=None, lines=lines[i : j + 1]))
        i = j + 1
        continue
    # a C statement: read until braces balance and it ends in ';' or '}'
    j = i
    depth = 0
    seen_brace = False
    head = l
    while True:
        s = re.sub(r'"(\\.|[^"\\])*"', '""', lines[j])
        s = re.sub(r"'(\\.|[^'\\])*'", "''", s)
        s = re.sub(r"/\*.*?\*/|//.*", "", s)
        depth += s.count("{") - s.count("}")
        seen_brace |= "{" in s
        end = s.rstrip()
        if depth == 0 and (end.endswith(";") or (end.endswith("}") and seen_brace)):
            # a K&R header ("f(a)" then "int a;") is not the end yet
            is_knr = re.match(r"^[A-Za-z_].*\w\s*\([\w\s,]*\)\s*$", head) and not seen_brace
            if not is_knr:
                break
        j += 1
    block = lines[i : j + 1]
    flat = " ".join(block)
    kind, name = "other", None
    fm = re.match(r"^(?!extern\b|typedef\b)[^=;{]*?\b(\w+)\s*\([^;]*?\)[^;=]*\{", flat)
    dm = re.match(r"^(?!extern\b|typedef\b)[^(=]*?\b(D_[0-9A-F]{8})\b[^=]*=", flat)
    if dm:
        kind, name = "cdata", dm.group(1)
    elif fm and seen_brace:
        kind, name = "cfunc", fm.group(1)
    stmts.append(dict(kind=kind, name=name, lines=block))
    i = j + 1

# ---- anchors ------------------------------------------------------------------
# C functions with unnamed rodata, from GCC's output
gl = open(gcc_out).read().split("\n")
anon_c = set()
cur = None
for k, l in enumerate(gl):
    m = re.match(r"\s*\.ent\s+(\S+)", l)
    if m:
        cur = m.group(1)
        continue
    if re.match(r"^\s*(\.rdata|\.sdata)\s*$", l):
        lab = next((x.strip() for x in gl[k + 1 : k + 6] if x.strip().endswith(":")), "")
        if lab.startswith("$LC"):  # written before the function that uses it
            nxt = next(
                (re.match(r"\s*\.ent\s+(\S+)", x).group(1) for x in gl[k:] if re.match(r"\s*\.ent\s", x)),
                None,
            )
            if nxt and not nxt.startswith("__maspsx_include_asm_hack"):
                anon_c.add(nxt)
        elif lab.startswith("$L") and cur and not cur.startswith("__maspsx_include_asm_hack"):
            anon_c.add(cur)  # jump table, written after its function

rod_items = [s for s in stmts if s["kind"] in ("rodata", "cdata")]
for s in rod_items:
    s["addr"] = addr_of(s["name"])
    assert s["addr"] is not None, s["name"]

anchors = []  # (stmt index, addr, label, required)
for idx, s in enumerate(stmts):
    if s["kind"] == "cfunc" and s["name"] in anon_c:
        nxt = next((t for t in stmts[idx + 1 :] if t["kind"] in ("rodata", "cdata")), None)
        if nxt:
            anchors.append((idx, nxt["addr"], s["name"] + " (C)", True))
    elif s["kind"] == "asm":
        try:
            t = open(asm_dir + s["name"] + ".s").read()
        except FileNotFoundError:
            continue
        addrs = [addr_of(j) for j in re.findall(r"%hi\((jtbl_[0-9A-F]{8})\)", t)]
        if ".section .rodata" in t:
            addrs += [int(a, 16) for a in re.findall(r"/\* [0-9A-F]+ ([0-9A-F]{8}) ", t.split(".section .rodata", 1)[1])][:1]
        if addrs:
            anchors.append((idx, min(addrs), s["name"], False))

# keep anchors rising: required ones always, optional ones only if they fit
req = [a for a in anchors if a[3]]
for a, b in zip(req, req[1:]):
    assert b[1] > a[1], f"C anchors out of order: {a} {b}"
kept = list(req)
dropped = []
for a in sorted([a for a in anchors if not a[3]], key=lambda a: a[0]):
    trial = sorted(kept + [a], key=lambda a: a[0])
    if all(y[1] > x[1] for x, y in zip(trial, trial[1:])):
        kept = trial
    else:
        dropped.append(a)
kept.sort(key=lambda a: a[0])

# ---- place every rodata item after its anchor ---------------------------------
slot_of = {}
for s in rod_items:
    owner = None
    for a in kept:
        if a[1] <= s["addr"]:
            owner = a[0]
    slot_of[id(s)] = owner  # None: top of file, where the first item is now

first_rod = next(k for k, s in enumerate(stmts) if s["kind"] in ("rodata", "cdata"))
by_slot = {}
for s in sorted(rod_items, key=lambda s: s["addr"]):
    by_slot.setdefault(slot_of[id(s)], []).append(s)

old_pos = {id(s): k for k, s in enumerate(stmts)}
new_pos = {}
out = []
moved_down = []


def emit_slot(key, at):
    for s in by_slot.get(key, []):
        new_pos[id(s)] = at
        if out and out[-1]["lines"] != [""]:
            out.append(dict(kind="other", name=None, lines=[""]))
        out.append(s)


for k, s in enumerate(stmts):
    if k == first_rod:
        emit_slot(None, k)
    if s["kind"] in ("rodata", "cdata"):
        continue
    out.append(s)
    if k in by_slot:
        emit_slot(k, k)

# C definitions that move down leave an extern declaration behind
for s in rod_items:
    if s["kind"] == "cdata" and new_pos[id(s)] > old_pos[id(s)]:
        moved_down.append(s["name"])
        decl = " ".join(s["lines"]).split("=")[0].strip()
        decl = re.sub(r"\[[^\]]*\]", "[]", decl)
        ext = dict(kind="other", name=None, lines=["extern " + decl + ";"])
        k = next(i for i, t in enumerate(out) if t is s)
        # put it where the definition used to be: before the statement that followed it
        follow = next((t for t in stmts[old_pos[id(s)] + 1 :] if t["kind"] not in ("rodata", "cdata")), None)
        at = next(i for i, t in enumerate(out) if t is follow)
        out.insert(at, ext)

# collapse runs of blank lines
res = []
for s in out:
    for l in s["lines"]:
        if l == "" and res and res[-1] == "":
            continue
        res.append(l)

for a in kept: print("  kept", a[2], hex(a[1]), "stmt", a[0])
print(f"{exe}: {len(kept)} anchors kept ({len(req)} from C), {len(dropped)} dropped")
for a in dropped:
    print("  still blocked:", a[2], hex(a[1]))
if moved_down:
    print("  C data moved down (extern left in place):", ", ".join(moved_down))
if write:
    open(path, "w", newline="").write(nl.join(res))
    print("  written", path)

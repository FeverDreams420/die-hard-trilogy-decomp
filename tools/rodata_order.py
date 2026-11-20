"""Order the data includes in a one-file EXE so rodata lands at its address.

Each EXE is one C file, so each data section comes out in file order: every
INCLUDE_RODATA/INCLUDE_SDATA line and every C data definition where it
stands, plus the unnamed data GCC writes next to a C function (`$LC`
constants just before it, jump tables just after it). For a function's own
data to land at its original address, every item of that section below the
address has to come before the function in the file, and every item above it
after. Sections are independent: .rodata (jump tables, long strings) and
.sdata (short strings, small variables) each rise with the functions on
their own. An EXE without a .sdata subsegment has only the .rodata stream.

The layout (the DH1 layout, see "Jump tables and rodata order" in
docs/compiler-notes.md):

- Anchors are functions whose data is tied to their place in the file:
  C functions that write unnamed data (found in GCC's output; for .sdata the
  address comes from the "// in C, written by" tags in
  config/symbol_addrs.<exe>.txt), and INCLUDE_ASM functions that use a jump
  table, or reach a .sdata item with a lui pair (a short string).
- Anchors of one section must rise with the file; an INCLUDE_ASM anchor that
  would break that is dropped and reported (it stays blocked).
- Every item goes right after the last anchor of its section whose address
  is at or below it, in address order.
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


cfg = open(f"config/{exe}.yaml").read()
m = re.search(r"- \[(0x[0-9A-Fa-f]+), \.sdata, \w+\]", cfg)
if m:
    code = re.search(rf"name: {exe}\s*\n\s*type: code\s*\n\s*start: (0x[0-9A-Fa-f]+)\s*\n\s*vram: (0x[0-9A-Fa-f]+)", cfg)
    to_vram = lambda off: off - int(code.group(1), 16) + int(code.group(2), 16)
    SDATA = to_vram(int(m.group(1), 16))
    SDATA_END = to_vram(int(re.search(r"\.sdata, \w+\][^\n]*\n\s*- \[(0x[0-9A-Fa-f]+)", cfg).group(1), 16))
else:
    SDATA = 1 << 40  # no .sdata section: everything is one .rodata stream


def stream_of(addr):
    return "sdata" if addr >= SDATA else "rodata"


# ---- split the file into top-level statements --------------------------------
stmts = []  # dicts: kind, name, lines
i = 0
while i < len(lines):
    l = lines[i]
    m = re.match(r'INCLUDE_(ASM|RODATA|SDATA)\("[^"]*", (\w+)\);', l)
    if m:
        kind = "asm" if m.group(1) == "ASM" else "data"
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

DATA = ("data", "cdata")
items = [s for s in stmts if s["kind"] in DATA]
for s in items:
    s["addr"] = addr_of(s["name"])
    assert s["addr"] is not None, s["name"]
    s["stream"] = stream_of(s["addr"])

# ---- anchors ------------------------------------------------------------------
# C functions that write unnamed data, per section, from GCC's output
gl = open(gcc_out).read().split("\n")
anon_c = {}  # function -> set of streams
cur = None
HACK = "__maspsx_include_asm_hack"
for k, l in enumerate(gl):
    m = re.match(r"\s*\.ent\s+(\S+)", l)
    if m:
        cur = m.group(1)
        continue
    m = re.match(r"^\s*(\.rdata|\.sdata)\s*$", l)
    if not m:
        continue
    stream = "sdata" if m.group(1) == ".sdata" and SDATA < (1 << 40) else "rodata"
    lab = next((x.strip() for x in gl[k + 1 : k + 6] if x.strip().endswith(":")), "")
    if lab.startswith("$LC"):  # written before the function that uses it
        nxt = next((re.match(r"\s*\.ent\s+(\S+)", x).group(1) for x in gl[k:] if re.match(r"\s*\.ent\s", x)), None)
        if nxt and not nxt.startswith(HACK):
            anon_c.setdefault(nxt, set()).add(stream)
    elif lab.startswith("$L") and cur and not cur.startswith(HACK):
        anon_c.setdefault(cur, set()).add(stream)  # jump table, after its function

# .sdata data written by C functions, from the symbol file tags
c_sdata = {}
for name, fn in re.findall(r"^(D_[0-9A-F]{8}) = [^;]*; // in C, written by (\w+)", open(f"config/symbol_addrs.{exe}.txt").read(), re.M):
    c_sdata[fn] = min(c_sdata.get(fn, 1 << 40), addr_of(name))

# which INCLUDE_ASM functions reach each symbol with a lui pair, and which
# symbols the C code names (those are variables, not strings)
hi_users = {}
SYM = re.compile(r"\b(D_[0-9A-F]{8})\b")
c_names = set(SYM.findall(" ".join(l for s in stmts if s["kind"] not in DATA for l in s["lines"])))
for s in stmts:
    if s["kind"] == "asm":
        try:
            t = open(asm_dir + s["name"] + ".s").read()
        except FileNotFoundError:
            continue
        for d in set(SYM.findall(t)):
            hi_users.setdefault(d, set()).add(s["name"] if f"%hi({d})" in t else "")
for d in c_names:
    hi_users.setdefault(d, set()).add("")

anchors = []  # (stmt index, addr, label, required, stream)
for idx, s in enumerate(stmts):
    if s["kind"] == "cfunc" and s["name"] in anon_c:
        for stream in anon_c[s["name"]]:
            if stream == "sdata":
                assert s["name"] in c_sdata, f'{s["name"]} writes .sdata: tag it "// in C, written by" in symbol_addrs'
                anchors.append((idx, c_sdata[s["name"]], s["name"] + " (C)", True, stream))
            else:
                nxt = next((t for t in stmts[idx + 1 :] if t["kind"] in DATA and t["stream"] == stream), None)
                if nxt:
                    anchors.append((idx, nxt["addr"], s["name"] + " (C)", True, stream))
    elif s["kind"] == "asm":
        try:
            t = open(asm_dir + s["name"] + ".s").read()
        except FileNotFoundError:
            continue
        jt = [addr_of(j) for j in re.findall(r"%hi\((jtbl_[0-9A-F]{8})\)", t)]
        if ".section .rodata" in t:  # rodata kept in the function's file
            jt += [int(a, 16) for a in re.findall(r"/\* [0-9A-F]+ ([0-9A-F]{8}) ", t.split(".section .rodata", 1)[1])][:1]
        if jt:
            anchors.append((idx, min(jt), s["name"], False, "rodata"))
        # a short string: a .sdata item only this function reaches, with a lui pair
        lc = [a for d in re.findall(r"%hi\((D_[0-9A-F]{8})\)", t)
              if SDATA <= (a := addr_of(d)) < SDATA_END and hi_users.get(d) == {s["name"]}]
        if lc:
            anchors.append((idx, min(lc), s["name"], False, "sdata"))

kept, dropped = [], []
for stream in ("rodata", "sdata"):
    mine = [a for a in anchors if a[4] == stream]
    req = sorted([a for a in mine if a[3]], key=lambda a: a[0])
    for a, b in zip(req, req[1:]):
        assert b[1] > a[1], f"C anchors out of order: {a} {b}"
    keep = list(req)
    for a in sorted([a for a in mine if not a[3]], key=lambda a: a[0]):
        trial = sorted(keep + [a], key=lambda a: a[0])
        if all(y[1] > x[1] for x, y in zip(trial, trial[1:])):
            keep = trial
        else:
            dropped.append(a)
    kept += keep

# ---- place every item after its anchor ----------------------------------------
by_slot = {}
for s in sorted(items, key=lambda s: s["addr"]):
    owner = None
    for a in kept:
        if a[4] == s["stream"] and a[1] <= s["addr"] and (owner is None or a[0] > owner):
            owner = a[0]
    by_slot.setdefault(owner, []).append(s)

first_data = next(k for k, s in enumerate(stmts) if s["kind"] in DATA)
old_pos = {id(s): k for k, s in enumerate(stmts)}
new_pos = {}
out = []


def emit_slot(key, at):
    for s in by_slot.get(key, []):
        new_pos[id(s)] = at
        if out and out[-1]["lines"] != [""]:
            out.append(dict(kind="other", name=None, lines=[""]))
        out.append(s)


for k, s in enumerate(stmts):
    if k == first_data:
        emit_slot(None, k)
    if s["kind"] in DATA:
        continue
    out.append(s)
    if k in by_slot:
        emit_slot(k, k)

# C definitions that move down leave an extern declaration behind
moved_down = []
for s in items:
    if s["kind"] == "cdata" and new_pos[id(s)] > old_pos[id(s)]:
        moved_down.append(s["name"])
        decl = " ".join(s["lines"]).split("=")[0].strip()
        decl = re.sub(r"\[[^\]]*\]", "[]", decl)
        ext = dict(kind="other", name=None, lines=["extern " + decl + ";"])
        follow = next((t for t in stmts[old_pos[id(s)] + 1 :] if t["kind"] not in DATA), None)
        at = next(i for i, t in enumerate(out) if t is follow)
        out.insert(at, ext)

# collapse runs of blank lines
res = []
for s in out:
    for l in s["lines"]:
        if l == "" and res and res[-1] == "":
            continue
        res.append(l)

print(f"{exe}: {len(kept)} anchors kept, {len(dropped)} dropped")
for a in dropped:
    print(f"  still blocked ({a[4]}): {a[2]} {a[1]:08X}")
if moved_down:
    print("  C data moved down (extern left in place):", ", ".join(moved_down))
if write:
    open(path, "w", newline="").write(nl.join(res))
    print("  written", path)

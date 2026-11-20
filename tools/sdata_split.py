"""Write the per-item .s files for an EXE's .sdata and .data sections.

splat links a `.sdata` or `.data` subsegment from its C file and writes no
assembly for it, so the items the C files still pull in with INCLUDE_SDATA
or INCLUDE_DATA come from here, into asm/<exe>/nonmatchings/<file>/. Item
starts are those lines and the D_ variables defined in C; every other known
symbol inside an item gets its own label, as splat does for rodata. A word
that holds the address of a function or data item linked from elsewhere is
written as that symbol, so the tables keep pointing at the right place if
code moves. Run after splat (`make split` does).

usage: python tools/sdata_split.py <exe>
"""
import glob
import os
import re
import sys

exe = sys.argv[1]
cfg = open(f"config/{exe}.yaml").read()
code = re.search(rf"name: {exe}\s*\n\s*type: code\s*\n\s*start: (0x[0-9A-Fa-f]+)\s*\n\s*vram: (0x[0-9A-Fa-f]+)", cfg)
code_off, vram = int(code.group(1), 16), int(code.group(2), 16)
to_vram = lambda off: off - code_off + vram
# the code segment's subsegments, then the end marker
entries = re.findall(r"^\s*- \[(0x[0-9A-Fa-f]+)(?:, ([.\w]+), (\w+))?\]", cfg[code.end():], re.M)
sections = []  # (section, file, start, end)
for k, (off, typ, name) in enumerate(entries[:-1]):
    if typ in (".sdata", ".data"):
        sections.append((typ, name, to_vram(int(off, 16)), to_vram(int(entries[k + 1][0], 16))))
if not sections:
    sys.exit(0)  # no .sdata or .data subsegment for this EXE yet
target = re.search(r"target_path:\s*(\S+)", cfg).group(1)
data = open(target, "rb").read()

src = "".join(open(f).read() for f in glob.glob(f"src/{exe}/*.c"))
INCLUDE = {".sdata": "INCLUDE_SDATA", ".data": "INCLUDE_DATA"}
# top-level definitions only: a type at column 0, then the name, then "="
c_defs = set(re.findall(r"^(?!extern\b|return\b)[A-Za-z_][\w \t*]*?[\s*](D_[0-9A-F]{8})\b[^=\n;(]*=", src, re.M))
c_globals = {d for d in c_defs if not re.search(rf"^static\b[^=\n;(]*\b{d}\b", src, re.M)}

# Data that matched C functions write themselves (`$LC` strings): tagged
# "// in C" in config/symbol_addrs.<exe>.txt. An item stops where one starts.
symtext = open(f"config/symbol_addrs.{exe}.txt").read()
c_owned = set(re.findall(r"^(D_[0-9A-F]{8}) = [^;]*; //[^\n]*\bin C, written by\b", symtext, re.M))
c_defs |= c_owned

# symbols the remaining asm uses get their own label inside an item
known = set(re.findall(r"\b(D_[0-9A-F]{8})\b", src)) | c_defs
asm_funcs = set(re.findall(r'INCLUDE_ASM\("[^"]*", (\w+)\);', src))
rodata = set(re.findall(r'INCLUDE_RODATA\("[^"]*", (\w+)\);', src))
asm_labels = set()  # labels the linked asm defines
for f in glob.glob(f"asm/{exe}/nonmatchings/**/*.s", recursive=True):
    name = f.replace("\\", "/").rsplit("/", 1)[1][:-2]
    if name in asm_funcs or name in rodata:
        t = open(f).read()
        known |= set(re.findall(r"\b(D_[0-9A-F]{8})\b", t))
        asm_labels |= set(re.findall(r"^\s*[dg]label (\w+)\s*$", t, re.M))
try:
    for line in open(f"build/{exe}.undefined_syms_auto.txt"):
        known |= set(re.findall(r"^(D_[0-9A-F]{8})\b", line))
except FileNotFoundError:
    pass
addr = lambda s: int(s[2:], 16)

# addresses that a pointer word can name: functions and data defined somewhere in the link
named = {}
for n, a in re.findall(r"^(\w+) = (0x[0-9A-Fa-f]+);", symtext + "".join(open(f).read() for f in glob.glob("config/symbol_addrs.txt")), re.M):
    named[n] = int(a, 16)
c_funcs = set(re.findall(r"^[A-Za-z_][\w \t*]*?\b(\w+)\s*\([^;{]*\)\s*\{", src, re.M))
linked = asm_labels | asm_funcs | c_globals | (c_funcs - {f for f in c_funcs if f.startswith("__maspsx")})
sym_at = {}
# the labels this script writes are linked too
for sect, file, start, end in sections:
    includes = set(re.findall(rf'{INCLUDE[sect]}\("[^"]*", (D_[0-9A-F]{{8}})\);', src))
    starts = sorted((s for s in includes | c_defs if start <= addr(s) < end), key=addr)
    for k, s in enumerate(starts):
        b = addr(starts[k + 1]) if k + 1 < len(starts) else end
        if s in includes:
            linked |= {x for x in known | {s} if addr(s) <= addr(x) < b}
for n in linked:
    m = re.search(r"_([0-9A-F]{8})$", n)
    a = int(m.group(1), 16) if m else named.get(n)
    if a is not None:
        sym_at.setdefault(a, n)

written = {}


def body(a, b):
    out = []
    while a < b:
        off = a - vram + code_off
        if a % 4 == 0 and b - a >= 4:
            w = data[off : off + 4]
            v = int.from_bytes(w, "little")
            val = sym_at.get(v, f"0x{v:08X}")
            out.append(f"    /* {off:X} {a:08X} {w.hex().upper()} */ .word {val}")
            a += 4
        else:
            out.append(f"    /* {off:X} {a:08X} */ .byte 0x{data[off]:02X}")
            a += 1
    return out


for sect, file, start, end in sections:
    includes = set(re.findall(rf'{INCLUDE[sect]}\("[^"]*", (D_[0-9A-F]{{8}})\);', src))
    starts = sorted((s for s in includes | c_defs if start <= addr(s) < end), key=addr)
    assert starts and addr(starts[0]) == start, f"no item at the {sect} start {start:08X} ({file})"
    inner = sorted((s for s in known | includes if start <= addr(s) < end), key=addr)
    out_dir = f"asm/{exe}/nonmatchings/{file}/"
    os.makedirs(out_dir, exist_ok=True)
    n = 0
    for k, s in enumerate(starts):
        a = addr(s)
        b = addr(starts[k + 1]) if k + 1 < len(starts) else end
        if s not in includes:
            continue  # defined in C
        labels = [x for x in inner if a <= addr(x) < b] or [s]
        lines = [f".section {sect}", ""]
        for j, lab in enumerate(labels):
            la = addr(lab)
            lb = addr(labels[j + 1]) if j + 1 < len(labels) else b
            lines += [f"nonmatching {lab}", "", f"dlabel {lab}", *body(la, lb), f"enddlabel {lab}", ""]
        open(out_dir + s + ".s", "w", newline="\n").write("\n".join(lines))
        n += 1
    print(f"{exe}: wrote {n} {sect} items for {file} ({start:08X}-{end:08X})")

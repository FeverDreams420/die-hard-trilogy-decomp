"""Write the per-item .s files for an EXE's .sdata section.

splat links a `.sdata` subsegment from the C file and writes no assembly for
it, so the items the C file still pulls in with INCLUDE_SDATA come from here.
Item starts are the INCLUDE_SDATA lines and the D_ variables defined in C;
every other known symbol inside an item gets its own label, as splat does for
rodata. Run after splat (`make split` does).

usage: python tools/sdata_split.py <exe>
"""
import glob
import re
import sys

exe = sys.argv[1]
cfg = open(f"config/{exe}.yaml").read()
m = re.search(r"- \[(0x[0-9A-Fa-f]+), \.sdata, \w+\][^\n]*\n\s*- \[(0x[0-9A-Fa-f]+)", cfg)
if not m:
    sys.exit(0)  # no .sdata subsegment for this EXE yet
start_off, end_off = int(m.group(1), 16), int(m.group(2), 16)
target = re.search(r"target_path:\s*(\S+)", cfg).group(1)
vram = int(re.search(rf"name: {exe}\s*\n\s*type: code\s*\n\s*start: (0x[0-9A-Fa-f]+)\s*\n\s*vram: (0x[0-9A-Fa-f]+)", cfg).group(2), 16)
code_off = int(re.search(rf"name: {exe}\s*\n\s*type: code\s*\n\s*start: (0x[0-9A-Fa-f]+)", cfg).group(1), 16)
to_vram = lambda off: off - code_off + vram
start, end = to_vram(start_off), to_vram(end_off)
data = open(target, "rb").read()

src = "".join(open(f).read() for f in glob.glob(f"src/{exe}/*.c"))
includes = set(re.findall(r'INCLUDE_SDATA\("[^"]*", (D_[0-9A-F]{8})\);', src))
# top-level definitions only: a type at column 0, then the name, then "="
c_defs = set(re.findall(r"^(?!extern\b|return\b)[A-Za-z_][\w \t*]*?[\s*](D_[0-9A-F]{8})\b[^=\n;(]*=", src, re.M))

# Data that matched C functions write themselves (`$LC` strings): tagged
# "// in C" in config/symbol_addrs.<exe>.txt. An item stops where one starts.
c_owned = set(
    re.findall(r"^(D_[0-9A-F]{8}) = [^;]*; // in C\b", open(f"config/symbol_addrs.{exe}.txt").read(), re.M)
)
c_defs |= c_owned

# symbols the remaining asm uses get their own label inside an item
known = set(includes) | set(c_defs) | set(re.findall(r"\b(D_[0-9A-F]{8})\b", src))
asm_funcs = set(re.findall(r'INCLUDE_ASM\("[^"]*", (\w+)\);', src))
for f in glob.glob(f"asm/{exe}/nonmatchings/**/*.s", recursive=True):
    name = f.replace("\\", "/").rsplit("/", 1)[1][:-2]
    if name in asm_funcs:
        known |= set(re.findall(r"\b(D_[0-9A-F]{8})\b", open(f).read()))
try:
    for line in open(f"build/{exe}.undefined_syms_auto.txt"):
        known |= set(re.findall(r"^(D_[0-9A-F]{8})\b", line))
except FileNotFoundError:
    pass
addr = lambda s: int(s[2:], 16)
known = sorted((s for s in known if start <= addr(s) < end), key=addr)
starts = sorted((s for s in includes | c_defs if start <= addr(s) < end), key=addr)
assert starts and addr(starts[0]) == start, f"no item at the .sdata start {start:08X}"

out_dir = f"asm/{exe}/nonmatchings/{exe}/"


def body(a, b):
    out = []
    while a < b:
        off = a - vram + code_off
        if a % 4 == 0 and b - a >= 4:
            w = data[off : off + 4]
            out.append(f"    /* {off:X} {a:08X} {w.hex().upper()} */ .word 0x{int.from_bytes(w, 'little'):08X}")
            a += 4
        else:
            out.append(f"    /* {off:X} {a:08X} */ .byte 0x{data[off]:02X}")
            a += 1
    return out


for k, s in enumerate(starts):
    a = addr(s)
    b = addr(starts[k + 1]) if k + 1 < len(starts) else end
    if s not in includes:
        continue  # defined in C
    labels = [x for x in known if a <= addr(x) < b] or [s]
    lines = [".section .sdata", ""]
    for j, lab in enumerate(labels):
        la = addr(lab)
        lb = addr(labels[j + 1]) if j + 1 < len(labels) else b
        lines += [f"nonmatching {lab}", "", f"dlabel {lab}", *body(la, lb), f"enddlabel {lab}", ""]
    open(out_dir + s + ".s", "w", newline="\n").write("\n".join(lines))

print(f"{exe}: wrote {len(includes)} .sdata items ({start:08X}-{end:08X})")

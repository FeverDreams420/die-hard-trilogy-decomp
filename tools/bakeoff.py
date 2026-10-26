#!/usr/bin/env python3
"""Phase 4 compiler bake-off: compile each leaf in src/bakeoff/ under every
combination of settings and count exact matches against the original bytes.

Each src/bakeoff/<exe>_<ADDR>.c holds one function. Its original bytes are read
from disc/<EXE> at ADDR; the length is the instruction count in
build/ghidra/<EXE>.funcs.tsv. Words the linker would fill in (the relocations
GNU as leaves in the object) are blanked on both sides before comparing.

Prints the match table only; per-leaf results go to build/bakeoff.tsv.
Usage (WSL, repo root): .venv/bin/python tools/bakeoff.py [leaf ...]
       .venv/bin/python tools/bakeoff.py --show <leaf.c> <gcc> <opt> <G> <aspsx>
           (disassembles one compile next to the original, for example
            --show src/bakeoff/dh1_8004A7C4.c gcc-2.7.2-psx -O2 -G8 2.56)
"""
import csv
import glob
import itertools
import multiprocessing
import os
import re
import struct
import subprocess
import sys
import tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EXE_FILES = {"slus": "SLUS_001.19", "boot": "BOOT.EXE", "loader": "LOADER.EXE", "slide": "SLIDE.EXE",
             "dh1": "DH1.EXE", "dh2": "DH2.EXE", "dh3": "DH3.EXE"}
TSV = {"slus": "SLUS_001", "boot": "BOOT", "loader": "LOADER", "slide": "SLIDE",
       "dh1": "DH1", "dh2": "DH2", "dh3": "DH3"}

GCCS = sorted(os.path.basename(d) for d in glob.glob(os.path.join(ROOT, "tools", "gcc-*")))
OPTS = ["-O1", "-O2"]
GS = ["-G0", "-G4", "-G8"]
ASPSX = ["2.08", "2.21", "2.34", "2.56", "2.67", "2.79"]
CPPFLAGS = ["-nostdinc", "-Iinclude", "-undef", "-Dmips", "-D__mips__", "-D__OPTIMIZE__", "-D_MIPSEL",
            "-D_LANGUAGE_C", "-DLANGUAGE_C", "-DM2CTX"]
CFLAGS = ["-quiet", "-w", "-fno-builtin", "-fpeephole", "-ffunction-cse", "-fpcc-struct-return",
          "-fcommon", "-msoft-float"]
ASFLAGS = ["-EL", "-march=r3000", "-mtune=r3000", "-msoft-float", "-no-pad-sections", "-Iinclude",
           "-G0", "-O1"]
MASK = {"R_MIPS_HI16": 0xFFFF0000, "R_MIPS_LO16": 0xFFFF0000, "R_MIPS_GPREL16": 0xFFFF0000,
        "R_MIPS_26": 0xFC000000}


def original(exe, addr):
    data = open(os.path.join(ROOT, "disc", EXE_FILES[exe]), "rb").read()
    t_addr = struct.unpack_from("<I", data, 0x18)[0]
    with open(os.path.join(ROOT, "build", "ghidra", f"{TSV[exe]}.funcs.tsv"), newline="") as f:
        insns = next(int(r["insns"]) for r in csv.DictReader(f, delimiter="\t") if int(r["addr"], 16) == addr)
    off = addr - t_addr + 0x800
    return data[off:off + 4 * insns]


def compile_leaf(path, gcc, opt, g, aspsx, tmp):
    pre = subprocess.run(["cpp"] + CPPFLAGS + [path], capture_output=True, text=True, cwd=ROOT, check=True).stdout
    cc1 = os.path.join(ROOT, "tools", gcc, "cc1")
    asm = subprocess.run([cc1, opt, g] + CFLAGS, input=pre, capture_output=True, text=True)
    if asm.returncode:
        return None, None
    mas = subprocess.run([sys.executable, "tools/maspsx/maspsx.py", "--expand-div", f"--aspsx-version={aspsx}", g],
                         input=asm.stdout, capture_output=True, text=True, cwd=ROOT)
    obj = os.path.join(tmp, "t.o")
    if subprocess.run(["mipsel-linux-gnu-as"] + ASFLAGS + ["-o", obj], input=mas.stdout, text=True,
                      capture_output=True, cwd=ROOT).returncode:
        return None, None
    binf = os.path.join(tmp, "t.bin")
    subprocess.run(["mipsel-linux-gnu-objcopy", "-O", "binary", "-j", ".text", obj, binf], check=True)
    relocs = subprocess.run(["mipsel-linux-gnu-objdump", "-r", "-j", ".text", obj], capture_output=True,
                            text=True).stdout
    masks = {}
    for m in re.finditer(r"^([0-9a-f]{8}) (R_MIPS_\w+)", relocs, re.M):
        masks[int(m.group(1), 16)] = MASK.get(m.group(2), 0)
    return open(binf, "rb").read(), masks


def same(a, b, masks):
    if len(a) != len(b):
        return False
    for i in range(0, len(a), 4):
        m = masks.get(i, 0xFFFFFFFF)
        wa, wb = struct.unpack_from("<I", a, i)[0], struct.unpack_from("<I", b, i)[0]
        if wa & m != wb & m:
            return False
    return True


def show(leaf, *combo):
    exe, addr = os.path.basename(leaf)[:-2].split("_")
    want = original(exe, int(addr, 16))
    with tempfile.TemporaryDirectory(dir=os.path.join(ROOT, "build")) as tmp:
        got, masks = compile_leaf(leaf, *combo, tmp)
        if got is None:
            sys.exit("compile failed")
        for name, data in (("original", want), ("compiled", got)):
            path = os.path.join(tmp, name)
            open(path, "wb").write(data)
            out = subprocess.run(["mipsel-linux-gnu-objdump", "-D", "-b", "binary", "-m", "mips:3000", "-EL",
                                  path], capture_output=True, text=True).stdout
            print(f"-- {name} ({len(data) // 4} instructions)")
            for line in out.splitlines():
                m = re.match(r"\s+([0-9a-f]+):\s+[0-9a-f]{8}\s+(.*)", line)
                if m:
                    print(f"  {int(m.group(1), 16):3x}  {m.group(2)}")
        print("MATCH" if same(want, got, masks) else "DIFF")


def run_one(task):
    leaf, combo = task
    exe, addr = os.path.basename(leaf)[:-2].split("_")
    want = original(exe, int(addr, 16))
    with tempfile.TemporaryDirectory(dir=os.path.join(ROOT, "build")) as tmp:
        got, masks = compile_leaf(leaf, *combo, tmp)
    return os.path.basename(leaf)[:-2], combo, int(got is not None and same(want, got, masks))


def main():
    if sys.argv[1:2] == ["--show"]:
        return show(*sys.argv[2:7])
    leaves = sys.argv[1:] or sorted(glob.glob(os.path.join(ROOT, "src", "bakeoff", "*.c")))
    combos = list(itertools.product(GCCS, OPTS, GS, ASPSX))
    with multiprocessing.Pool() as pool:
        results = pool.map(run_one, [(leaf, c) for leaf in leaves for c in combos])
    wins = {c: 0 for c in combos}
    rows = []
    for name, c, ok in results:
        wins[c] += ok
        rows.append((name, *c, ok))
    with open(os.path.join(ROOT, "build", "bakeoff.tsv"), "w") as f:
        f.write("leaf\tgcc\topt\tG\taspsx\tmatch\n")
        for r in rows:
            f.write("\t".join(map(str, r)) + "\n")
    print(f"{len(leaves)} leaves x {len(combos)} settings; best first (matches / {len(leaves)}):")
    for c, n in sorted(wins.items(), key=lambda kv: -kv[1])[:12]:
        print(f"  {n:3}  {' '.join(c)}")
    per_leaf = {}
    for name, *_, ok in rows:
        per_leaf[name] = per_leaf.get(name, 0) + ok
    never = [n for n, k in per_leaf.items() if k == 0]
    print(f"leaves matching under no setting ({len(never)}): {' '.join(never)}")
    print("per-leaf results -> build/bakeoff.tsv")


if __name__ == "__main__":
    main()

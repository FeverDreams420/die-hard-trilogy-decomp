#!/usr/bin/env python3
"""Does one function in the rebuilt EXE match the original? Prints one line.

The function's original address and size come from its splat file,
asm/<exe>/nonmatchings/<seg>/<func>.s (it stays there after the function is in C).
Its address in the rebuilt EXE comes from build/<exe>.map, so a size change in
an earlier function doesn't hide a match.

Usage: python3 tools/funcdiff.py <exe> <func>      e.g. tools/funcdiff.py dh1 read_gun_v
"""
import glob
import os
import re
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
FILES = {"boot": "BOOT.EXE", "dh1": "DH1.EXE"}
LINE = re.compile(r"/\* ([0-9A-F]+) ([0-9A-F]{8}) ([0-9A-F]{8}) \*/")


def asm_file(exe, func):
    hits = glob.glob(os.path.join(ROOT, "asm", exe, "nonmatchings", "**", f"{func}.s"), recursive=True)
    if not hits:
        sys.exit(f"{func}: no asm/{exe}/nonmatchings/**/{func}.s")
    return hits[0]


def map_addr(exe, func):
    pat = re.compile(r"^\s+0x([0-9a-f]{8,16})\s+" + re.escape(func) + r"$")
    with open(os.path.join(ROOT, "build", f"{exe}.map")) as f:
        for line in f:
            m = pat.match(line)
            if m:
                return int(m.group(1), 16) & 0xFFFFFFFF
    return None


def main():
    exe, func = sys.argv[1], sys.argv[2]
    words = [LINE.search(l) for l in open(asm_file(exe, func))]
    words = [m for m in words if m]
    start, size = int(words[0].group(2), 16), 4 * len(words)
    disc = open(os.path.join(ROOT, "disc", FILES[exe]), "rb").read()
    built = open(os.path.join(ROOT, "build", FILES[exe]), "rb").read()
    t_addr = struct.unpack_from("<I", disc, 0x18)[0]
    new = map_addr(exe, func) or start
    a = disc[start - t_addr + 0x800:][:size]
    b = built[new - t_addr + 0x800:][:size]
    bad = [i for i in range(0, size, 4) if a[i:i + 4] != b[i:i + 4]]
    moved = "" if new == start else f" (now at 0x{new:08X})"
    if not bad:
        print(f"MATCH {func} 0x{start:08X} {len(words)} instructions{moved}")
    else:
        print(f"DIFF  {func} 0x{start:08X}: {len(bad)} of {len(words)} instructions differ,"
              f" first at +0x{bad[0]:X}{moved}")
        sys.exit(1)


if __name__ == "__main__":
    main()

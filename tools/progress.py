#!/usr/bin/env python3
"""Print how much of each EXE's code is matched C.

Reads the linker maps in build/ (run `make` first). A function still in
assembly has a `<name>.NON_MATCHING` alias next to it in the map; every other
function in .text is matched C. Function sizes run up to the next symbol.

    python3 tools/progress.py            # table
    python3 tools/progress.py --markdown # README table
"""
import re
import sys
from pathlib import Path

EXES = ["dh1", "dh2", "dh3"]
SYM = re.compile(r"^\s+0x([0-9a-f]{8})\s+(\S+)$")
TEXT = re.compile(r"^ \.text\s+0x([0-9a-f]{8})\s+0x([0-9a-f]+) build/src/")


def measure(exe):
    lines = Path(f"build/{exe}.map").read_text().splitlines()
    start = end = None
    syms, asm = {}, set()
    for line in lines:
        m = TEXT.match(line)
        if m:
            start = int(m.group(1), 16)
            end = start + int(m.group(2), 16)
            continue
        m = SYM.match(line)
        if m and start is not None:
            addr = int(m.group(1), 16)
            if start <= addr < end:
                name = m.group(2)
                if name.endswith(".NON_MATCHING"):
                    asm.add(name[: -len(".NON_MATCHING")])
                elif "=" not in name and not name.startswith("."):
                    syms.setdefault(addr, name)
    addrs = sorted(syms)
    funcs = done = size_done = 0
    for i, addr in enumerate(addrs):
        size = (addrs[i + 1] if i + 1 < len(addrs) else end) - addr
        funcs += 1
        if syms[addr] not in asm:
            done += 1
            size_done += size
    return funcs, done, end - start, size_done


def bar(frac, width=20):
    n = round(frac * width)
    return "█" * n + "░" * (width - n)


def main():
    rows = [(exe.upper(), *measure(exe)) for exe in EXES]
    if "--markdown" in sys.argv:
        print("| Game | Code matched | Functions |")
        print("| --- | --- | --- |")
        for name, funcs, done, size, size_done in rows:
            pct = 100 * size_done / size
            print(f"| **{name}** | `{bar(size_done / size)}` **{pct:.1f}%** "
                  f"| {done} / {funcs} |")
        return
    for name, funcs, done, size, size_done in rows:
        print(f"{name}  {100 * size_done / size:5.1f}% of code  "
              f"({size_done:#x} / {size:#x} bytes)  {done} / {funcs} functions")


if __name__ == "__main__":
    main()

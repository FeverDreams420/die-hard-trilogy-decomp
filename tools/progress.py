#!/usr/bin/env python3
"""Print how much of each EXE's code is matched C.

Reads the linker maps in build/ (run `make` first). A function still in
assembly has a `<name>.NON_MATCHING` alias next to it in the map; every other
function in .text is matched C. Function sizes run up to the next symbol.
The table also lists functions still in assembly that already have a C version
under `#ifndef NON_MATCHING` (docs/non-matching.md); they don't count as matched.

    python3 tools/progress.py                 # table
    python3 tools/progress.py --markdown      # README table
    python3 tools/progress.py --report FILE   # objdiff-format report.json

The report uses objdiff's report format (version 2), so progress trackers that
read objdiff reports can ingest it. Each C file is one unit and each EXE is a
progress category. Functions still in assembly count as 0% matched.

The PsyQ libraries (src/<exe>/psyq.c) are left out of every total, since the
PC port replaces them. Add --psyq to count them too.
"""
import json
import re
import sys
from pathlib import Path

EXES = ["dh1", "dh2", "dh3"]
WITH_PSYQ = "--psyq" in sys.argv
SYM = re.compile(r"^\s+0x([0-9a-f]{8})\s+(\S+)$")
TEXT = re.compile(r"^ \.text\s+0x([0-9a-f]{8})\s+0x([0-9a-f]+) build/(src/\S+)\.o$")


def units(exe):
    """Return [(source_path, start, end, [(name, addr, size, matched)])]."""
    found = []
    syms = asm = None
    for line in Path(f"build/{exe}.map").read_text().splitlines():
        m = TEXT.match(line)
        if m:
            start = int(m.group(1), 16)
            end = start + int(m.group(2), 16)
            syms, asm = {}, set()
            found.append((m.group(3), start, end, syms, asm))
            continue
        m = SYM.match(line)
        if m and syms is not None:
            addr = int(m.group(1), 16)
            if start <= addr < end:
                name = m.group(2)
                if name.endswith(".NON_MATCHING"):
                    asm.add(name[: -len(".NON_MATCHING")])
                elif "=" not in name and not name.startswith("."):
                    syms.setdefault(addr, name)
    out = []
    for path, start, end, syms, asm in found:
        if not WITH_PSYQ and Path(path).stem == "psyq":
            continue
        addrs = sorted(syms)
        funcs = []
        for i, addr in enumerate(addrs):
            size = (addrs[i + 1] if i + 1 < len(addrs) else end) - addr
            funcs.append((syms[addr], addr, size, syms[addr] not in asm))
        out.append((path, start, end, funcs))
    return out


def measure(exe):
    funcs = done = size = size_done = 0
    for _, start, end, fs in units(exe):
        size += end - start
        for _, _, fsize, matched in fs:
            funcs += 1
            if matched:
                done += 1
                size_done += fsize
    return funcs, done, size, size_done


NONMATCHING = re.compile(r'^#ifndef NON_MATCHING\nINCLUDE_ASM\("[^"]+", (\w+)\);$', re.M)


def nonmatching(exe):
    """Functions still in assembly that have a NON_MATCHING C version: (count, bytes)."""
    names = set()
    for path in Path(f"src/{exe}").glob("*.c"):
        names.update(NONMATCHING.findall(path.read_text()))
    sizes = [fsize for _, _, _, fs in units(exe)
             for name, _, fsize, matched in fs if name in names and not matched]
    return len(sizes), sum(sizes)


def bar(frac, width=20):
    n = round(frac * width)
    return "█" * n + "░" * (width - n)


def pct(part, whole):
    return round(100 * part / whole, 6) if whole else 100.0


def measures(funcs, done, size, size_done, nunits, ncomplete, complete_code):
    # 64-bit fields are strings, as objdiff writes them.
    return {
        "fuzzy_match_percent": pct(size_done, size),
        "total_code": str(size),
        "matched_code": str(size_done),
        "matched_code_percent": pct(size_done, size),
        "total_functions": funcs,
        "matched_functions": done,
        "matched_functions_percent": pct(done, funcs),
        "complete_code": str(complete_code),
        "complete_code_percent": pct(complete_code, size),
        "total_units": nunits,
        "complete_units": ncomplete,
    }


def report():
    totals = {}
    cats, out_units = [], []
    for exe in EXES:
        c = dict.fromkeys(("funcs", "done", "size", "size_done", "units",
                           "complete", "complete_code"), 0)
        for path, start, end, fs in units(exe):
            done = sum(1 for f in fs if f[3])
            size_done = sum(f[2] for f in fs if f[3])
            size = end - start
            complete = done == len(fs)
            out_units.append({
                "name": f"{exe}/{Path(path).stem}",
                "measures": measures(len(fs), done, size, size_done, 1,
                                     int(complete), size if complete else 0),
                "functions": [{
                    "name": name,
                    "size": str(fsize),
                    "fuzzy_match_percent": 100.0 if matched else 0.0,
                    "metadata": {"virtual_address": str(addr)},
                    "address": str(addr - start),
                } for name, addr, fsize, matched in fs],
                "metadata": {
                    "complete": complete,
                    "source_path": path,
                    "progress_categories": [exe],
                },
            })
            for key, val in (("funcs", len(fs)), ("done", done), ("size", size),
                             ("size_done", size_done), ("units", 1),
                             ("complete", int(complete)),
                             ("complete_code", size if complete else 0)):
                c[key] += val
        cats.append({"id": exe, "name": exe.upper(),
                     "measures": measures(*c.values())})
        for key, val in c.items():
            totals[key] = totals.get(key, 0) + val
    return {"measures": measures(*totals.values()), "categories": cats,
            "units": out_units, "version": 2}


def main():
    if "--report" in sys.argv:
        dest = Path(sys.argv[sys.argv.index("--report") + 1])
        dest.write_text(json.dumps(report(), indent=1) + "\n")
        return
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
        nm, nm_size = nonmatching(name.lower())
        if nm:
            print(f"      + {100 * nm_size / size:5.1f}% as NON_MATCHING C  "
                  f"({nm_size:#x} bytes)  {nm} functions")


if __name__ == "__main__":
    main()

#!/usr/bin/env python3
"""Turn an ExportFunctions.java TSV into splat symbol_addrs lines.

Keeps functions that Ghidra named (PsyQ signatures or the PSX loader) and drops
FUN_xxxxxxxx placeholders and the loader's GTE macro block at 0x20000000.

Usage: python tools/ghidra/tsv2symbols.py build/ghidra/BOOT.funcs.tsv BOOT.EXE > out.txt
"""
import collections
import csv
import sys


def main():
    tsv, exe = sys.argv[1], sys.argv[2]
    with open(tsv, newline="") as f:
        rows = [r for r in csv.DictReader(f, delimiter="\t")
                if r["source"] != "DEFAULT" and int(r["addr"], 16) >= 0x80000000]
    counts = collections.Counter(r["name"] for r in rows)
    print(f"// {exe}: library functions named by Ghidra's PsyQ signatures (tools/ghidra/tsv2symbols.py).")
    print("// Names that occur more than once get an _<addr> suffix so each stays unique.")
    for r in rows:
        name = r["name"]
        if counts[name] > 1:
            name = f"{name}_{r['addr'][2:].upper()}"
        print(f"{name} = 0x{r['addr'][2:].upper()}; // type:func size:{r['size']}")
    dupes = sum(1 for n, c in counts.items() if c > 1)
    print(f"{exe}: {len(rows)} symbols, {dupes} duplicated names", file=sys.stderr)


if __name__ == "__main__":
    main()

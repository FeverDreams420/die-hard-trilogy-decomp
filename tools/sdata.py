"""Route GCC's small data (.sdata) to the right section of the EXE.

Two kinds of .sdata need different handling:

- Compiler constants (`$LC` labels, initializers of 8 bytes or less): the
  original code reaches them with a `lui` pair, so maspsx must not see them
  as small data. `pre` hides their section from maspsx.
- Named small variables (`int D_800B679C = ...;` defined where its
  INCLUDE_SDATA/INCLUDE_RODATA line was): the original reaches them through
  `$gp`, so they stay in .sdata for maspsx, which writes `%gp_rel` accesses.

EXEs whose data is split (a `.sdata` subsegment in config/<exe>.yaml, mode
`split`) keep both in the real .sdata section. The others (mode `rodata`)
still have one .rodata segment for all data, so both go to .rodata: `$LC`
before maspsx, named variables after it.

Uninitialised variables past the end of the EXE (.sbss and .bss) are not in
the file, but a function may still reach one through `$gp`. Declare it in C
without a value (`static u8 D_800A2E7C[8];`), so GCC emits `.lcomm` (or
`.comm`) and maspsx writes `%gp_rel` for it under -G8. maspsx then defines it
at the end of the file as a label in .sbss or .bss; `post` removes those
labels for named addresses (`D_XXXXXXXX`), so each reference resolves to the
address in build/<exe>.undefined_syms_auto.txt instead.

DH1 (ASPSX 2.34) is the exception: its loads from compiler constants go
through `$gp` (DH1 0x80041AB4 copies two bytes of "\r\n" with `lb`/`sb`
from `%gp_rel`), so `pre ... lc-gp` leaves `$LC` visible to maspsx. Taking
the address of a constant (`la`) still gives a `lui` pair under 2.34.

usage: python sdata.py pre split|rodata [lc-gp]  (stdin to stdout)
       python sdata.py post split|rodata
"""
import re
import sys

NAMED_ADDRESS = re.compile(r"D_[0-9A-F]{8}$")


def pre(lines, mode, lc_gp=False):
    if lc_gp:
        return lines
    # `.section .sdata` is the same section to the assembler, but maspsx only
    # treats a bare `.sdata` as small data
    hidden = "\t.section\t.sdata\n" if mode == "split" else "\t.rdata\n"
    out = []
    for i, line in enumerate(lines):
        if line.rstrip("\n") == "\t.sdata":
            label = next(
                (l.strip() for l in lines[i + 1 :] if l.strip().endswith(":")), ""
            )
            if label.startswith("$LC"):
                line = hidden
        out.append(line)
    return out


def strip_bss(lines):
    # maspsx writes each bss entry as optional `.align`/`.globl` lines, the
    # label and `.space`, after a `.section .sbss` or `.section .bss` line
    out, entry, in_bss = [], [], False
    for line in lines:
        s = line.strip()
        if s in (".section .sbss", ".section .bss"):
            in_bss = True
            out.append(line)
            continue
        if not in_bss:
            out.append(line)
            continue
        if s.startswith(".section"):
            in_bss = False
            out += entry
            entry = []
            out.append(line)
            continue
        entry.append(line)
        if s.startswith(".space"):
            label = next((e.strip()[:-1] for e in entry if e.strip().endswith(":")), "")
            if not NAMED_ADDRESS.match(label):
                out += entry
            entry = []
    return out + entry


def post(lines, mode):
    lines = strip_bss(lines)
    if mode == "split":
        return lines
    # the MIPS .rdata directive means .rodata; ".section .rdata" would not
    return ["\t.rdata\n" if l.rstrip("\n") == ".section .sdata" else l for l in lines]


if __name__ == "__main__":
    sys.stdin.reconfigure(newline="\n")
    sys.stdout.reconfigure(newline="\n")
    step, mode = sys.argv[1], sys.argv[2]
    lines = sys.stdin.readlines()
    if step == "pre":
        lines = pre(lines, mode, lc_gp="lc-gp" in sys.argv[3:])
    else:
        lines = post(lines, mode)
    sys.stdout.writelines(lines)

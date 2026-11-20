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

usage: python sdata.py pre|post split|rodata  (stdin to stdout)
"""
import sys


def pre(lines, mode):
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


def post(lines, mode):
    if mode == "split":
        return lines
    # the MIPS .rdata directive means .rodata; ".section .rdata" would not
    return ["\t.rdata\n" if l.rstrip("\n") == ".section .sdata" else l for l in lines]


if __name__ == "__main__":
    sys.stdin.reconfigure(newline="\n")
    sys.stdout.reconfigure(newline="\n")
    step, mode = sys.argv[1], sys.argv[2]
    lines = sys.stdin.readlines()
    sys.stdout.writelines({"pre": pre, "post": post}[step](lines, mode))

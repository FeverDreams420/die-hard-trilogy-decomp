"""Keep GCC's small data in the single .rodata segment of each EXE.

Each EXE has one .rodata segment that also holds its .data and .sdata, so
everything GCC puts in .sdata has to end up in .rodata at its place in the
file. Two kinds of .sdata need different handling:

- Compiler constants (`$LC` labels, initializers of 8 bytes or less): the
  original code reaches them with a `lui` pair, so `pre` renames their .sdata
  to .rdata before maspsx sees them.
- Named small variables (`int D_800B679C = ...;` defined where its
  INCLUDE_RODATA line was): the original reaches them through `$gp`, so they
  stay in .sdata for maspsx, which then writes `%gp_rel` accesses, and `post`
  renames the section to .rdata afterwards.

usage: python sdata.py pre|post  (stdin to stdout)
"""
import sys


def pre(lines):
    out = []
    for i, line in enumerate(lines):
        if line.rstrip("\n") == "\t.sdata":
            label = next(
                (l.strip() for l in lines[i + 1 :] if l.strip().endswith(":")), ""
            )
            if label.startswith("$LC"):
                line = "\t.rdata\n"
        out.append(line)
    return out


def post(lines):
    return [
        # the MIPS .rdata directive means .rodata; ".section .rdata" would not
        "\t.rdata\n" if l.rstrip("\n") == ".section .sdata" else l
        for l in lines
    ]


if __name__ == "__main__":
    sys.stdin.reconfigure(newline="\n")
    sys.stdout.reconfigure(newline="\n")
    lines = sys.stdin.readlines()
    sys.stdout.writelines({"pre": pre, "post": post}[sys.argv[1]](lines))

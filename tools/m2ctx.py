#!/usr/bin/env python3
"""Write an m2c context file: preprocessed C without function bodies, plus prototypes.

    m2ctx.py <preprocessed.c | -> <aux-info.txt>  > build/ctx_<exe>.c

The input is an EXE's C file run through cpp with -DM2CTX (see the Makefile's
build/ctx_%.c rule), so it holds every typedef, struct and global the matched
code uses. m2c can't parse K&R function headers, so function definitions are
dropped and replaced by the ANSI prototypes cc1 writes with -aux-info.

Top-level text is cut into chunks at ';' and at the '}' closing a top-level
'{'. A chunk ending in a body whose head has '(' and no '=' (so not a struct,
union, enum or initializer) is a function definition. In a K&R header,
"T f(a, b) T a; T b; {", the ';'s after the ')' don't end the chunk.
"""
import re
import sys

KNR = re.compile(r"\w\s*\([\w\s,]*\)\s*[A-Za-z_]")
TAG = re.compile(r"\b(struct|union|enum)(\s+\w+)?\s*$")


def strip_bodies(src):
    out, start, depth, brace, i, n = [], 0, 0, 0, 0, len(src)
    while i < n:
        c = src[i]
        if c in "\"'":
            i += 1
            while i < n and src[i] != c:
                i += 2 if src[i] == "\\" else 1
        elif c == "{":
            if depth == 0:
                brace = i
            depth += 1
        elif c == "}":
            depth -= 1
            if depth == 0:
                head = src[start:brace]
                if "(" in head and "=" not in head and not TAG.search(head):
                    start = i + 1
        elif c == ";" and depth == 0:
            chunk = src[start:i + 1]
            if "=" in chunk or not KNR.search(chunk):
                out.append(chunk)
                start = i + 1
        i += 1
    return "".join(out)


C_WORDS = set("""extern static const volatile signed unsigned void char short int long
float double struct union enum""".split())


def prototypes(path, body):
    """Prototypes from the aux-info file, leaving out any whose types the body
    doesn't declare (a typedef local to another C file of the EXE)."""
    known = set(re.findall(r"\w+", body)) | C_WORDS
    seen, protos = set(), []
    for line in open(path):
        # "/* file:line:OF */ extern void f (int); /* (a) int a; */"
        m = re.match(r"/\* [^*]*\*/ ([^;]*;)", line)
        name = m and re.search(r"(\w+)\s*\(", m.group(1))
        if not name or name.group(1) in seen or name.group(1).startswith("__maspsx"):
            continue
        seen.add(name.group(1))
        words = set(re.findall(r"[A-Za-z_]\w*", m.group(1))) - {name.group(1)}
        if words <= known:
            protos.append(m.group(1))
    return protos


def main():
    src = sys.stdin.read() if sys.argv[1] == "-" else open(sys.argv[1]).read()
    body = strip_bodies(src)
    sys.stdout.write(body + "\n" + "\n".join(prototypes(sys.argv[2], body)) + "\n")


if __name__ == "__main__":
    main()

# Non-matching C

Matching a large function byte for byte is slow. The logic usually comes out quickly, but the last register-allocation and scheduling differences can take hours of permuter runs. The PC port only needs C that behaves like the original. So a function that doesn't match yet can carry a working C version next to its assembly:

```c
// NON_MATCHING: register allocation in the loop (12 lines)
#ifndef NON_MATCHING
INCLUDE_ASM("asm/dh1/nonmatchings/dh1", func_8004D650);
#else
void func_8004D650(void) {
    ...
}
#endif
```

The normal build (`make`, `make check`) still assembles the original instructions, so the EXEs keep matching. `make nonmatching` builds a second tree in `build/nm/` with `NON_MATCHING` defined, which compiles the C versions instead.

## Rules

- **Same standard of C as a match.** Use the original compiler's view of the world: the real types, no register pins, no asm, no `// FAKE`. The C should be something the original programmer could have written, so that the match can be finished from it later.
- **Behaviour must be the same.** Only add a version whose output, under `bash tools/match.sh nmdiff <exe> <func>`, differs from the original in ways that don't change behaviour: register numbers, instruction order, which of two equal branches comes first. If a difference might change behaviour (a missing store, a different constant, a signed/unsigned load), fix it first.
- **Say what is left.** The `// NON_MATCHING:` line above the block names what still differs and roughly how many diff lines. That's where to start when you come back to the function.
- **Leave the data alone.** The function's `INCLUDE_RODATA`, `INCLUDE_SDATA` and `INCLUDE_DATA` lines stay where they are, because the matching build needs them. The C version gets its own string literals and jump tables. Declare the globals it uses `extern`; don't define them in C, or the `build/nm` link has the symbol twice.
- **Keep it compiling.** Run `make nonmatching` before committing a `NON_MATCHING` block, next to `make check`.

## When it matches

Delete the `// NON_MATCHING:` line, the `#ifndef NON_MATCHING`, the `INCLUDE_ASM` line, the `#else` and the `#endif`, then handle the data as for any match (jump tables, `$gp` variables; see `docs/compiler-notes.md`).

## What the build/nm EXEs are for

They only check that the C versions compile and link, and they feed `match.sh nmdiff`. They don't run: code after a longer function moves to new addresses, but the EXE header and some data tables still hold the original ones.

`python3 tools/progress.py` lists the `NON_MATCHING` functions on a separate line. They don't count towards the matched percentage, or towards the progress report.

# Stuck functions

Functions that didn't match after a reasonable effort. Each stays `INCLUDE_ASM` until revisited.

| Function | Also in | Best result | What's left | Tried |
| --- | --- | --- | --- | --- |
| DH2 0x80077CE0 (sum of `size/4` words, last first) | DH3 0x80077128 | 15 instructions, loop shape wrong (GCC 2.5.7 `-O2 -G8`, ASPSX 2.34) | The original copies `n` and tests the old value (`move v0,a1` / `addiu a1,a1,-1` / `bnez v0`); ours compares the new value with -1 and sets `sum = 0` later. | `while (n--)`, `while (n-- != 0)`, `size >>= 2; while (size--)` with `size` signed and unsigned (`src/bakeoff/dh2_80077CE0.c`) |

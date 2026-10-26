# Stuck functions

Functions that didn't match after a reasonable effort. Each stays `INCLUDE_ASM` until revisited.

| Function | Also in | Best result | What's left | Tried |
| --- | --- | --- | --- | --- |
| DH2 0x80077CE0 (sum of `size/4` words, last first) | DH3 0x80077128 | 15 instructions, loop shape wrong (GCC 2.5.7 `-O2 -G8`, ASPSX 2.34) | The original copies `n` and tests the old value (`move v0,a1` / `addiu a1,a1,-1` / `bnez v0`); ours compares the new value with -1 and sets `sum = 0` later. | `while (n--)`, `while (n-- != 0)`, `size >>= 2; while (size--)` with `size` signed and unsigned (`src/bakeoff/dh2_80077CE0.c`) |
| DH1 0x800508F0 (angle difference wrapped to +-0x400) | | One instruction short (GCC 2.5.7 `-O2 -G8`, ASPSX 2.34) | The original shifts into `v0` and copies it twice (`move a0,v0` / `move v1,v0`); ours shifts straight into `v1` and copies once. Closest: `s32 x = (f(a, p->unk1C) - D_800A2FC6) << 20 >> 20; s16 r = x;` with `abs`, `over = ad - 0x400`, `r = 0x400 - over` / `r = ad - 0x800`. | one result variable (`0x400 - (ad - 0x400)` gets folded to `0x800 - ad`), parameter reused as the result, `s16` result, extra copy of the shifted value |

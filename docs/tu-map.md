# Source file map

Each game's code (from 0x8001E470 to the PsyQ `start`) is built from one C file today. The original was several files, and a few functions can't match until their file boundaries are back in place. This page lists the boundaries found so far, the evidence for each, and the split proposed for the build. Boundaries marked *provisional* are buildable anywhere inside their window. They can move later without affecting any match.

## How boundaries show in the binary

- **`$gp` means "defined in this file".** GCC writes a `$gp` access only for a small variable defined in the same file (or a `static` one). A `lui` pair is used for an `extern`. So all `$gp` users of one variable share a file, and a function that loads that variable with a `lui` pair is in a different file. This is the only hard evidence so far.
- **Small data follows file order.** Each file's `.sdata` is one block, and blocks come in link order. GCC 2.x writes a file's unused-until-the-end statics after its other data. So a variable used by an early function can sit above the data of later functions *in the same file*. DH2's `.sdata` shows this.
- **String and jump-table stream.** Strings and jump tables (the start of each EXE's `.rodata`) rise with the code across the whole EXE, so they agree with any split and don't place one.
- **Initialised tables** (the rest of `.rodata`, from DH1 0x8007C3BC, DH2 0x80089568, DH3 similar) are not in code order, so they can't place boundaries.
- **Call graph.** A helper called only by functions on one side of a window, or calling only into one side, was most likely written in that side's file. Used only inside windows already forced by `$gp`.
- **What gives nothing:** there is no padding between functions, no frame-pointer (`-O0`) code, and no source file names in the strings (the only `$Id:` strings are PsyQ's `bios.c`, `intr.c` and `sys.c`).

## DH2

| Boundary | Window | Evidence | Proposed cut |
| --- | --- | --- | --- |
| map / main game | after 0x80022CA8, at or before 0x8003DBC4 | `D_800B61FC` (path nodes) is reached through `$gp` by 0x80022528, 0x80022974, 0x80022A10 and 0x80022CA8, and through `lui` by 0x80046498, 0x8004C5C4, 0x8004D31C, 0x8005D82C, 0x800645F8, 0x80069518, 0x8006D640 and 0x800720E4. | 0x800234D8, *provisional*: 0x8002318C shares data with 0x80022CA8 (`D_800B6390`..`D_800B63A6`). The callers inside the window don't settle it. |
| main game / end module | after 0x80072B00, at or before 0x80078430 | `D_800B679C` is reached through `$gp` by 0x8007270C, 0x80072884 and 0x80072B00, and through `lui` by 0x80078430. Callers narrow it: up to 0x80077BB0 every function is called from, or calls, the main file (0x80077BB0 is called by 0x80075E28 and calls 0x80074950 and 0x800754C8). 0x80077D1C is called only by 0x80077E28 and calls only 0x8007870C and 0x800789FC. 0x80077CE0 is called from both sides. | 0x80077D1C |

The main file is probably one large file from at least 0x8003DBC4 to 0x80072B00. Its `.sdata` users run in code order from `D_800B6568` (0x80044844) to `D_800B679C` (0x8007270C). Then come `D_800B69E5`..`D_800B69F0`, used by 0x8003DBC4, 0x8003FC9C and 0x80042728, which looks like the end-of-file statics. Nothing yet says where its start lies between 0x800234D8 and 0x8003DBC4, or whether the code before 0x80022528 is one file or several.

## DH3

| Boundary | Window | Evidence | Proposed cut |
| --- | --- | --- | --- |
| main game / end module | after 0x80071F48, at or before 0x80077878 | `D_800B5A40` is reached through `$gp` by 0x80071B54, 0x80071CCC and 0x80071F48, and through `lui` by 0x80077878. The end module is the same code as DH2's. From 0x800767E0 to 0x80077270 the function sizes and call shapes match DH2's 0x80077398 to 0x80077E28 one for one. | 0x80077164 (DH2's 0x80077D1C) |

The `.sdata` users run in code order across the whole game (0x800B54FE at 0x800229C4 up to 0x800B5A40 at 0x80071B54), so no other boundary is visible.

## DH1

No forced boundaries: every `.sdata` and `.sbss` variable is reached either only through `$gp` or only through `lui`. Three stuck functions point at boundaries that the binary doesn't place yet (`docs/stuck.md`):

- 0x8002186C and 0x80020F08 need different declarations of the pool counts at 0x801F759C.
- 0x80044470, 0x80044B74 and 0x80044E9C read `D_801F7D50` without `volatile`, while nine render functions need it `volatile`.
- 0x80039858's jump table is 8-byte aligned within its own file.

## Splitting the build

Each split file gets its own `c` subsegment and its own `.rodata` and `.sdata` subsegments in `config/<exe>.yaml`:

- **Strings and jump tables** go to the file whose functions use them. The stream rises with the code, so each file's part is one address range.
- **Initialised tables** stay in one file, as a `.data` subsegment. The linker places all `.data` after every file's `.rodata`, which matches the EXE.
- **Small data:** each file's `.sdata` starts at its first variable. A `$gp` variable is defined in the file of its `$gp` users. Every other file keeps an `extern`.

`make check` runs after each cut.

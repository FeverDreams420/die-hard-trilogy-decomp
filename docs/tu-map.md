# Source file map

Each game's code (from 0x8001E470 to the PsyQ `start`) was several C files in the original, and a few functions can't match until their file boundaries are back in place. This page lists the boundaries found so far, the evidence for each, and how the build is split. Boundaries marked *provisional* are buildable anywhere inside their window. They can move later without affecting any match.

## How boundaries show in the binary

- **`$gp` means "defined in this file".** GCC writes a `$gp` access only for a small variable defined in the same file (or a `static` one). A `lui` pair is used for an `extern`. So all `$gp` users of one variable share a file, and a function that loads that variable with a `lui` pair is in a different file. This is the only hard evidence so far.
- **Small data follows file order.** Each file's `.sdata` is one block, and blocks come in link order. GCC 2.x writes a file's unused-until-the-end statics after its other data. So a variable used by an early function can sit above the data of later functions *in the same file*. DH2's `.sdata` shows this.
- **String and jump-table stream.** Strings and jump tables (the start of each EXE's `.rodata`) rise with the code across the whole EXE, so they agree with any split and don't place one.
- **Initialised tables** (DH1 from 0x8007C3BC, DH2 from 0x80089568, DH3 from 0x80087A40) are not in code order, so they can't place boundaries.
- **Call graph.** A helper called only by functions on one side of a window, or calling only into one side, was most likely written in that side's file. Used only inside windows already forced by `$gp`.
- **What gives nothing:** there is no padding between functions, no frame-pointer (`-O0`) code, and no source file names in the strings (the only `$Id:` strings are PsyQ's `bios.c`, `intr.c` and `sys.c`).

## DH2

| Boundary | Window | Evidence | Cut |
| --- | --- | --- | --- |
| map / main game | after 0x80022CA8, at or before 0x8003DBC4 | `D_800B61FC` (path nodes) is reached through `$gp` by 0x80022528, 0x80022974, 0x80022A10 and 0x80022CA8, and through `lui` by 0x80046498, 0x8004C5C4, 0x8004D31C, 0x8005D82C, 0x800645F8, 0x80069518, 0x8006D640 and 0x800720E4. | 0x800234D8 (`map.c`), *provisional*: 0x8002318C shares data with 0x80022CA8 (`D_800B6390`..`D_800B63A6`). The callers inside the window don't settle it. |
| main game / end module | after 0x80072B00, at or before 0x80078430 | `D_800B679C` is reached through `$gp` by 0x8007270C, 0x80072884 and 0x80072B00, and through `lui` by 0x80078430. Callers narrow it: up to 0x80077BB0 every function is called from, or calls, the main file (0x80077BB0 is called by 0x80075E28 and calls 0x80074950 and 0x800754C8). 0x80077D1C is called only by 0x80077E28 and calls only 0x8007870C and 0x800789FC. 0x80077CE0 is called from both sides. | 0x80077D1C (`movie.c`) |

The main file is probably one large file from at least 0x8003DBC4 to 0x80072B00. Its `.sdata` users run in code order from `D_800B6568` (0x80044844) to `D_800B679C` (0x8007270C). Then come `D_800B69E5`..`D_800B69F0`, used by 0x8003DBC4, 0x8003FC9C and 0x80042728, which looks like the end-of-file statics. Nothing yet says where its start lies between 0x800234D8 and 0x8003DBC4, or whether the code before 0x80022528 is one file or several.

## DH3

| Boundary | Window | Evidence | Cut |
| --- | --- | --- | --- |
| main game / end module | after 0x80071F48, at or before 0x80077878 | `D_800B5A40` is reached through `$gp` by 0x80071B54, 0x80071CCC and 0x80071F48, and through `lui` by 0x80077878. The end module is the same code as DH2's. From 0x800767E0 to 0x80077270 the function sizes and call shapes match DH2's 0x80077398 to 0x80077E28 one for one. | 0x80077164 (`movie.c`, DH2's 0x80077D1C) |

The `.sdata` users run in code order across the whole game (0x800B54FE at 0x800229C4 up to 0x800B5A40 at 0x80071B54), so no other boundary is visible.

## DH1

No forced boundaries: every `.sdata` and `.sbss` variable is reached either only through `$gp` or only through `lui`. Three stuck functions point at boundaries that the binary doesn't place yet (`docs/stuck.md`):

- 0x8002186C and 0x80020F08 need different declarations of the pool counts at 0x801F759C.
- 0x80044470, 0x80044B74 and 0x80044E9C read `D_801F7D50` without `volatile`, while nine render functions need it `volatile`.
- 0x80039858's jump table is 8-byte aligned within its own file.

## Data layout

In DH2 and DH3, the data between the code and `$gp` is two sections, in link order:

| Part | DH2 | DH3 | Section | File |
| --- | --- | --- | --- | --- |
| game strings and jump tables | 0x80087F7C | 0x80086BD4 | `.rodata` | each game file in turn |
| PsyQ library strings and jump tables | 0x80088B64 | 0x800870D8 | `.rodata` | `psyq.c` |
| pad library data (`InitPAD`, `GUN_OBJ_*`) | 0x80089508 | 0x800879E0 | `.data` | `gun.c` |
| game tables | 0x80089568 | 0x80087A40 | `.data` | each game file in turn |
| small data | 0x800B61E4 | 0x800B54E4 | `.sdata` | each game file in turn |

So the tables were writable data in the original (`.data`, not `const`): `gun.c` comes first in the link, and its data sits at the start of `.data`, after every file's `.rodata`. The tables are pulled in with `INCLUDE_DATA` (`tools/sdata_split.py` writes them, with pointers as symbols), and `tools/rodata_order.py` leaves them where they are.

## Current files

Each file has its own `c`, `.rodata`, `.data` and `.sdata` subsegments in `config/<exe>.yaml` where it owns any of that data:

| File | Code | Strings | Tables | Small data |
| --- | --- | --- | --- | --- |
| `src/dh2/map.c` (*provisional*) | 0x8001E470 | 0x80087F7C | 0x80089568 (the credits tables, and those only its code uses) | 0x800B61E4, with `D_800B61FC` |
| `src/dh2/dh2.c` | 0x800234D8 | 0x800880E0 | 0x80089804 | 0x800B621C |
| `src/dh2/movie.c` | 0x80077D1C | 0x80088AC8 | none | none |
| `src/dh3/dh3.c` | 0x8001E470 | 0x80086BD4 | 0x80087A40 | 0x800B54E4 |
| `src/dh3/movie.c` | 0x80077164 | 0x8008703C | none | none |

- **The movie file** (MDEC movie playback, then the loader for the next EXE) never uses `$gp`. The small items only it uses, `D_800B67E8` and the `"Loaded\n"` string `D_800B67F0` (DH3: `D_800B5A8C`, `D_800B5A94`), lie inside the main file's small data, so the main file defines them and the movie code names them through `extern`s.
- **The map file's small data** ends before `D_800B621C`, the first item whose users all lie after 0x8002318C. A short string written by 0x80023920 (`D_800B637C`) is in the main file's small data, which agrees.
- **Types** used by more than one file go in `include/` (`include/task.h` for `struct Task`, shared by DH2 and DH3). Declarations only one file needs stay in it.

`make check` runs after each cut.

# Compiler notes (Phase 2)

Status: **Phase 4 settled (Oct 25, 2026): GCC 2.5.7 (`gcc-2.5.7-psx`), `-O2 -G8`, ASPSX 2.34 for DH1 and 2.21 for LOADER; DH2 and DH3 turned out to use 2.21 as well (Phase 7).** Details under run 4.

## Step 1: PsyQ SDK version

Every one of the seven EXEs carries the same three `$Id` stamps from Sony's `libapi`/`libetc` sources:

| String | SLUS_001.19 | BOOT | DH1 |
| --- | --- | --- | --- |
| `$Id: bios.c,v 1.77 1996/05/13 06:58:16 suzu Exp $` | 0x8002B048 | 0x80013244 | 0x8007BD18 |
| `$Id: intr.c,v 1.73 1995/11/10 05:29:40 suzu Exp $` | 0x8002B2BC | 0x800132B4 | 0x8007B724 |
| `$Id: sys.c,v 1.120 1996/05/01 12:09:07 noda Exp $` | 0x8002B364 | 0x8001335C | 0x8007B88C |

(LOADER, SLIDE, DH2 and DH3 have the same three strings; `python -I` string scan, Oct 25, 2026.)

- **Finding:** all seven programs were linked against the same library build, with sources dated up to **May 13, 1996**.
- **Confirmed: PsyQ 3.5.0 in all seven EXEs.** The ghidra_psx_ldr extension (release 2026.10.03, Ghidra 12.1.4) detects the version from the binary and stores it as `Program Information.PsyQ Version = 3.5.0`. It then applied its 3.5.0 signatures. Read headless with `tools/ghidra/PrintOptions.java` (Oct 25, 2026).
- Signature-named functions per EXE, written to `config/symbol_addrs.<exe>.txt` by `tools/ghidra/tsv2symbols.py`:

  | EXE | Functions found | Named (library) | Unnamed |
  | --- | --- | --- | --- |
  | SLUS_001.19 | 465 | 426 | 39 |
  | BOOT | 230 | 222 | 8 |
  | LOADER | 700 | 522 | 178 |
  | SLIDE | 492 | 412 | 80 |
  | DH1 | 1032 | 655 | 377 |
  | DH2 | 1160 | 653 | 507 |
  | DH3 | 1125 | 638 | 487 |

  Function counts exclude the 153 GTE macro labels the loader adds at 0x20000000. **Guess:** the unnamed functions are mostly the game's own code, but some may be library functions the signatures missed.
- Ghidra's decompiler fails on SLUS_001.19 at 0x800215DC ("Unable to resolve constructor"), probably a GTE or coprocessor instruction it doesn't know. This only affects Ghidra's C view, not the function list.
- The other library strings (`ResetGraph:jtb=%08x,env=%08x`, `CD_newmedia: sarching dir..`, `GPU timeout:que=%d,...`) carry no version number.

## Step 2: `$gp` and `-G`

`gp0` is 0 in every EXE header, so each program's startup code sets `$gp` itself, with a `lui`/`addiu` pair about 0x70 bytes after the entry point:

| EXE | Instructions | `$gp` | File ends |
| --- | --- | --- | --- |
| SLUS_001.19 | 0x800215B0 `lui gp,0x800B` / 0x800215B4 `addiu gp,0xF95C` | 0x800AF95C | 0x800AFD00 |
| BOOT.EXE | 0x800139CC / 0x800139D0 | 0x8001B1C4 | 0x8001B800 |
| LOADER.EXE | 0x80036638 / 0x8003663C | 0x800514A4 | 0x80051D00 |
| SLIDE.EXE | 0x8002A288 / 0x8002A28C | 0x8004158C | 0x80041D00 |
| DH1.EXE | 0x8006B23C / 0x8006B240 | 0x800A29EC | 0x800A2D00 |
| DH2.EXE | 0x80078F4C / 0x80078F50 | 0x800B61E4 | 0x800B6D00 |
| DH3.EXE | 0x80078394 / 0x80078398 | 0x800B54E4 | 0x800B5D00 |

How the game code reads globals:

- **`$gp` is really used.** For example DH1 0x8001E9DC `lhu a1, 0x0(gp)` and 0x8001EA44 `sh a2, 0x2(gp)`; DH2 0x80022578 `lw v1, 0x18(gp)`. Every gp-relative access is at a small positive offset (DH1: 23 distinct addresses from 0x800A29EC to 0x800A2E82). So the game code was **not** built with `-G0`.
- **Only a few small variables go through `$gp`:** 4 (SLIDE) to 23 (DH1) distinct addresses per EXE. All accesses are 1, 2 or 4 bytes wide, none 8. Most globals (arrays, structs) are reached with `lui` pairs, as expected for anything larger than the `-G` limit.
- **Guess:** `-G8` (PsyQ's usual setting) or `-G4`. The Phase 4 bake-off decides between them. BOOT has no gp-relative accesses at all, so it may be built differently, or simply have no small globals.
- A handful of gp-area addresses are also reached through `lui` pairs (DH2 0x800B61FC via 0x800464C0; DH3 0x800B5788 via 0x8002B7E8). This may mean some files were built with a different `-G`, or it may be address-of (`&var`) code. Check these in Ghidra.

## Step 3: candidate compilers (first guess)

With a mid-1996 SDK:

| GCC | Released | On this machine | Verdict |
| --- | --- | --- | --- |
| 2.6.3 | Nov 1994 | no | candidate; shipped with earlier PsyQ releases |
| 2.7.2 | Nov 1995 | yes (`tools/gcc-2.7.2-psx`) | **main candidate** |
| 2.8.1 | 1998 | yes (`tools/gcc-2.8.1-psx`) | too new for a 1996 game; use only as a control |

Which GCC PsyQ 3.5 actually shipped is not yet confirmed. Supporting evidence: the psyz project (in the Parasite Eve port, `third_party/psyz/decomp`) rebuilds PsyQ 3.5.0 libraries with GCC 2.7.2 and maspsx `--aspsx-version=2.56`, so those are the starting settings in our `Makefile`. The prologue and epilogue shapes in Phase 4 will settle it.

## Steps 4–5: cross-references and leaf functions

Both come from `python -I tools/recon.py`, which reads the Ghidra tables in `build/ghidra/*.funcs.tsv` and the EXEs in `disc/` (Oct 25, 2026). Full lists are in `docs/phase2/`.

How it compares functions: the same C linked into two EXEs gives the same instructions except where the linker filled in an address. The script blanks those spots (`jal`/`j` targets, `lui` immediates, the low half of a `lui` address pair, `$gp` offsets) and hashes what is left. **Limitation:** two tiny functions with the same shape but different globals also hash equal. For example the 6-instruction `CdReadCallback` body matches several other library stubs in SLUS.

### Step 4: code shared between the games

There are no overlays, so the original question ("which main-EXE functions does each overlay call") doesn't apply. The useful version is: which of the game's own (unnamed) functions appear in more than one EXE.

- 1676 unnamed functions across the seven EXEs collapse to 1319 distinct bodies.
- **Very little game code is shared.** Leaving out bodies also found in SLUS or BOOT (probably library code), only **26 bodies (703 instructions)** are in all three games and **97 bodies (7320 instructions)** are in two of them. DH1, DH2 and DH3 each have 330–365 functions found in no other EXE.
- The biggest body in all three games is 163 instructions and makes 13 calls: LOADER 0x800361D0, SLIDE 0x80029E20, DH1 0x8006ADB0, DH2 0x80078AE4, DH3 0x80077F2C. It sits just before each EXE's startup code. **Guess:** a shared init or main-loop helper.
- LOADER and SLIDE share most of their unnamed code with the games (only 95 of LOADER's 178, and 14 of SLIDE's 80, are unique).
- Four unnamed bodies match a signature-named function in another EXE (`CdReadCallback`, `_check_gun_flag`, `COUNTER_OBJ_170`, `MEMMOVE_OBJ_64`). These are all 2–6 instruction stubs, so they are probably shape collisions, not missed library functions.
- Consequence for later phases: shared priority functions are few, so each game will be mostly its own matching job (Phase 7). The `shared-functions.tsv` list says which matches carry over to other EXEs.

### Step 5: leaf functions

- **121 distinct unnamed leaf bodies** (2–20 instructions, no calls). 13 are in all three games, 57 read globals through `lui` pairs, 4 use `$gp`, and 5 set up a stack frame. 8 also appear in SLUS or BOOT and are flagged as probable library code.
- `docs/phase2/bakeoff-leaves.tsv` picks 25 for the Phase 4 bake-off: every `$gp` and stack-frame leaf, then the most widely shared. The `$gp` ones (LOADER 0x800307EC, DH2 0x8007270C, DH1 0x80067E20, DH1 0x80067E60) are the ones that will decide `-G8` versus `-G4`.
- **Compiler clue:** some leaves allocate a stack frame they never use. DH2 0x80031F90 is just `addiu sp,sp,-16` / `jr ra` / `addiu sp,sp,16`, and LOADER 0x8001E984 adds one `sh zero,88(a0)`. An optimizing GCC normally drops an unused frame, so this is a fingerprint for the bake-off: the right compiler and flags must reproduce it. **Guess:** these functions had a local variable that was optimized away after its stack slot was assigned.

## Phase 4: bake-off (in progress)

Harness: `.venv/bin/python tools/bakeoff.py` compiles every `src/bakeoff/<exe>_<ADDR>.c` under each GCC in `tools/gcc-*` × `-O1`/`-O2` × `-G0`/`-G4`/`-G8` × maspsx `--aspsx-version` 2.08/2.21/2.34/2.56/2.67/2.79 (72 settings with two compilers, about 3 minutes). It compares each result with the original bytes, ignoring words the linker fills in. `--show <leaf> <gcc> <opt> <G> <aspsx>` disassembles one compile next to the original.

### Run 1 (Oct 25, 2026): 23 leaves, GCC 2.7.2 and 2.8.1

The 25 picked leaves minus two that can't be C: DH1 0x8006B3E0 writes `$sp` directly, and LOADER 0x8003ACF8 is GTE code (`mtc2`).

- **Only 3 of 23 match under any setting:** DH2 0x8003456C and LOADER 0x80026268 under all 72 settings, LOADER 0x80026278 only with GCC 2.7.2 (any `-O`, `-G` and ASPSX). Best setting: 3/23.
- **The 20 failures have the right shape and length but differ in register choice and operand order, consistently.** Examples:
  - LOADER 0x80030AA8 has `addu a0,a0,a1` / `lw v0,8(a0)`; ours has `addu a1,a1,a0` / `lw v0,8(a1)`.
  - LOADER 0x80026254 has `addu v0,a0,a1` … `li v1,-4`; ours computes in `a0` and uses `v0` for the constant.
  - The original keeps the first operand as the destination and uses `v0`/`v1` for temporaries, where GCC 2.7.2 and 2.8.1 reuse the argument registers. That pattern is too regular to come from how the C is worded, which points at the compiler.
- Five more leaves allocate a stack frame they never use (DH1 0x80023400 and 0x80042538, DH2 0x80031F90, DH3 0x80055648, LOADER 0x8001E984). Neither compiler does that for this C.
- **ASPSX hint:** LOADER 0x800307EC and DH1 0x80067E60 are the same function, but the indexed byte store is expanded differently:
  - LOADER: `lui at` / `addiu at,at,lo` / `addu at,at,v0` / `sb a0,0(at)`;
  - DH1: `lui at` / `addu at,at,v0` / `sb a0,lo(at)`.
  
  maspsx's version table gives the `addiu` form to ASPSX 2.21 and earlier. **Guess:** LOADER was assembled with an older ASPSX than DH1.

### Run 2 (Oct 25, 2026): GCC 2.6.3 added (108 settings)

- **GCC 2.6.3 matches the same 3 leaves and fails the same 20.** For these leaves 2.6.3, 2.7.2 and 2.8.1 produce identical code, and so does every flag tried on four representative leaves. The flags were `-O0`, `-O3`, `-fno-schedule-insns(2)`, `-fno-expensive-optimizations`, `-fno-strength-reduce`, `-fno-omit-frame-pointer`, `-fno-defer-pop`, `-fforce-mem`, `-fno-peephole`, `-fno-function-cse`, `-fcaller-saves`, `-g`, `-fno-cse-follow-jumps`, and `-mno-gas`/`-mmips-as`/`-mno-abicalls`.
- **The unused stack frames are explained:** a call that the compiler later throws away still reserves the 16-byte argument area. `void f(void) { if (0) printf(...); }` gives exactly DH2 0x80031F90's 16-byte frame, and adding an unused `int x[2]` gives DH3 0x80055648's 24-byte frame. **Guess:** debug prints compiled out with a macro. To check: the dead string (`"debug
"` in our test) stays in `.rdata`, so the original data should contain unused debug strings near these functions.
- **What remains is three patterns none of our compiler builds reproduces:**
  1. the result is computed in `v0`/`v1`, not in a dead argument register;
  2. the first operand stays the destination (`addu a0,a0,a1` where ours has `addu a1,a1,a0`);
  3. a frame with no saved registers is restored in the `jr ra` delay slot. GCC prints that epilogue as text after its delay-slot pass, so it can't fill the slot, and maspsx (like ASPSX) never fills slots.
- **Conclusion so far:** the game was probably not built with these decompals/old-gcc rebuilds (GNU GCC plus PSX patches). **Guess:** Sony's own `cc1psx` from the PsyQ SDK differs in register allocation and in its epilogue. Next ways to find out:
  1. decomp.me, whose PS1 presets run Sony's PsyQ compilers. This means uploading a few leaves' asm to a public site.
  2. A local copy of the PsyQ SDK, if one is available: `cc1psx.exe` run through Wine/DOSBox in place of `cc1`.

### Run 3 (Oct 25, 2026): decomp.me, every PS1 compiler

Three leaves uploaded to decomp.me and compiled under all 24 PS1 compilers there with `-O2 -G0`. Score 0 means an exact match; scratches `UmS5u`, `8uRbX` and `MNFBs` on decomp.me.

| Compiler | LOADER 0x80026254 | LOADER 0x80030AA8 | DH1 0x8004A7C4 |
| --- | --- | --- | --- |
| **gcc2.5.7-psx** | **0** | 20 (**0** with `Entry16 *e = &base[i]; return e->c;`) | **0** |
| gcc2.6.0-psx, gcc2.6.3-psx | 30 | 20 | 100 |
| gcc2.7.x (psx, cdk, mipsel), gcc2.8.x | 30 | 20 | 125 |
| gcc2.91.66-psx, gcc2.95.2-psx | 30 | 20 | 100 |
| psyq3.3, psyq3.5, psyq4.5, psyq4.6, psyq_263_221 | 30 | 20 | 100 |
| psyq3.6, psyq4.0–4.4 | 30 | 20 | 125 |

- **Finding: GCC 2.5.7 (PSX patches) reproduces all three, including the `v0` register choice and DH1 0x8004A7C4's `mflo v0` / `nop` / jump-over shape. No other compiler matches any of the three, Sony's PsyQ presets included.**
- So the game's own code was compiled with a GCC older than the PsyQ 3.5 libraries it links against. **Guess:** the developers kept an older compiler while updating the libraries.
- `0x80030AA8` shows that wording still matters: `return base[i].c;` scores 20 even under 2.5.7, while taking `&base[i]` first matches.

### Run 4 (Oct 25, 2026): GCC 2.5.7 locally, 144 settings

`gcc-2.5.7-psx` from decompals/old-gcc 0.17 is in `tools/gcc-2.5.7-psx/`. Changes to the leaf set since run 1:
- LOADER 0x8003A818 dropped: it writes three words through `t0`–`t2` to offset 20, the `t[3]` field of a PsyQ `MATRIX`. **Guess:** it's libgte's `TransMatrix`, hand-written asm the signatures missed.
- C reworded where needed:
  - table getters take `&base[i]` first;
  - small globals are *defined* in the file, so GCC knows their size and uses `$gp`;
  - LOADER 0x80036008's loop is written as `while (1) { if (digit) return s; s++; }`;
  - DH1 0x80023400 walks with pointers;
  - frame leaves contain `if (0) printf(...)` (see run 2).

**Winner: GCC 2.5.7, `-O2 -G8`, ASPSX 2.34 matches 20 of 22 leaves.** The next best settings reach 18, and the old-gcc 2.6.3/2.7.2/2.8.1 builds stay at 3 or fewer.

| GCC 2.5.7 `-O2 -G8`, matches per EXE | 2.08 | 2.21 | 2.34 | 2.56 | 2.67 | 2.79 |
| --- | --- | --- | --- | --- | --- | --- |
| LOADER (10 leaves) | 9 | **10** | 9 | 8 | 8 | 8 |
| DH1 (6) | 3 | 3 | **6** | **6** | **6** | **6** |
| DH2 (5) | 3 | **4** | **4** | 3 | 3 | 3 |
| DH3 (1) | 1 | 1 | 1 | 1 | 1 | 1 |

- **`-O2`** beats `-O1` (108 against 96 leaf matches summed over ASPSX versions).
- **`-G8`:** under `-G0` and `-G4` the `$gp` leaves fail (DH1 0x80067E20 and 0x80067E60, DH2 0x8007270C, LOADER 0x800307EC).
- **ASPSX differs between EXEs.** LOADER 0x800307EC matches only with 2.21: its indexed store is `lui at` / `addiu at` / `addu at` / `sb a0,0(at)`, the expansion of ASPSX 2.21 and earlier. DH1 0x80067E60, the same function, matches only with 2.34 or later. DH2 rules out 2.56 and later, so the games use **2.34**.
- **Still failing:** DH2 0x80077CE0 (`while (n--)` sum, also in DH3). The original tests the old value of `n`; ours compares with -1. Three wordings tried; it goes to Phase 5.
- **In the real build:** DH1 0x80023400, 0x80042538, 0x8004A7C4 and 0x80061A30 are now C in `src/dh1/dh1.c`, and `make check` matches.
- **`$gp` globals (solved Nov 20, 2026):** under `-G8`, a plain `extern` comes out as a `lui` pair; maspsx writes `%gp_rel` only for variables defined in the file. Define the variable in place of its `INCLUDE_RODATA` line, with its value from the `.s` file (`Entry18 *D_800B679C = (Entry18 *)0x80010000;`), and keep an `extern` above the users. It stays at its address, and `tools/sdata.py` keeps it in `.sdata` until after maspsx. First match: DH2 0x8007270C. Not yet covered: gp variables past the end of the file (`.sbss`), and offsets into a symbol (`D_800A29F0+2` named `D_800A29F2`).
- **Data layout (Nov 20, 2026):** each game's data is two sections, `.rodata` (constants and `.data`, from the end of the code) and `.sdata` (from `$gp` to the end of the file), and each rises with function order on its own. Before the split, short strings of early functions (`"LOADING"`, DH2 0x800B6384) were written before the jump tables of later ones (0x80088154), which blocked 13 DH2 and 7 DH3 table functions. How it fits together:
  - `config/<exe>.yaml` has a `.sdata` subsegment at `$gp`. splat writes no files for it; `tools/sdata_split.py` (run by `make split`) writes one per `INCLUDE_SDATA` line from the EXE.
  - Data that matched C writes itself (`$LC` strings of 8 bytes or less) is tagged `// in C, written by <func>` in `config/symbol_addrs.<exe>.txt`, so the item before it stops there.
  - Every `INCLUDE_RODATA` item is `force_not_migration`, so splat never moves one into a function file (pinning only the ones that moved was a cascade). A clean `make split` rebuilds all four EXEs matching.
  - `tools/sdata.py` hides `$LC` small constants from maspsx (the original reaches them with `lui` pairs) and keeps named small variables visible (`$gp`).
  - `tools/rodata_order.py <exe> <cc1 output>` puts every data line right after the function that owns its address range; `--write` applies it. Run it after adding data lines. It lists anchors it had to drop; the remaining ones are guessed `.sdata` strings, not tables.
  - First table match after the split: DH2 0x8003CF4C, unchanged from its parked draft.
- **To confirm later:** the frame leaves suggest debug prints compiled out with `if (0)`, which would leave their format strings in `.rodata`. Look for unused debug strings near those functions.

## Jump tables and rodata order

A `switch` compiled to a jump table puts the table in `.rodata` right after the function in the compiler's output. `dh1.c` is one translation unit, so its `.rodata` comes out in file order: every `INCLUDE_RODATA` line, plus anything the C functions emit, in the order they appear. For a C function's table to land at its original address, every rodata item below that address has to come before the function in `dh1.c`, and every item above it after.

- **No rodata in function `.s` files.** splat's `migrate_rodata_to_functions` had moved rodata into nine functions' `.s` files (InitPAD's strings at 0x8007C254, small `.sdata` items at 0x800A29FC, 0x800A2B3C and others). Those can't be moved apart from their function, so they blocked every table before them. They are marked `force_not_migration:True` in `config/symbol_addrs.dh1.txt`, together with 14 jump tables that would migrate once those were out of the way. Every rodata item is now its own `INCLUDE_RODATA` line.
- **Each game jump table sits right after its function** in `dh1.c`, followed by the rodata up to the next table. Table addresses rise with function addresses (all 47 game tables, `main` to 0x800685F0), so this order holds. Matching a jump-table function is then a plain swap: replace the `INCLUDE_ASM` line and delete the table's `INCLUDE_RODATA` line below it.
- **No `.align 3`.** GCC 2.5.7 writes `.align 3` then `.align 2` before each table. The original tables are only word aligned in absolute terms: `jtbl_8007ACA0` (0 mod 8) is followed directly by `jtbl_8007ACB4` (4 mod 8), and the rodata itself starts at 0x8007A6E4. One C file also can't reproduce the section start of each original source file. The Makefile (`JTBL_ALIGN`) drops the `.align 3`; any padding in the original belongs to the symbol before the table. Look at this again when `dh1.c` is split into files (Phase 8).
- First table match: 0x8005D610 (`jtbl_8007B348`).

## DH2 and DH3 settings check (Phase 7)

DH2 and DH3 use the same compiler settings as DH1: GCC 2.5.7 `-O2 -G8`. The check is the
111 functions (53 DH2, 58 DH3) whose DH1 twin's C rebuilds them to the original bytes with
only symbol names changed, or with a constant, field offset or type changed where the games
differ. None needed a different compiler or flag.

The assembler is older, though: **ASPSX 2.21 for DH2 and DH3.** Every symbol+register load or
store in their game code is the 2.21 expansion `lui at` / `addiu at,at,%lo(sym)` / `addu at,at,reg`
/ `op rd,0(at)` (155 functions in DH2, 179 in DH3), and none uses the 2.34 form `lui at` /
`addu at,at,reg` / `op rd,%lo(sym)(at)`; DH1 is the reverse (DH2 0x80065328 reads two volume
tables this way). In maspsx 2.21 and 2.34 differ only in this expansion, so the twins that
matched with 2.34 still match. The Makefile sets `ASPSX_VER := 2.21` for `build/src/dh2/` and
`build/src/dh3/`.

## Phase 5: matching idioms for GCC 2.5.7

Patterns that turned a near-miss into a match. Each names the DH1 function where it was found.

| What the original shows | C that produces it |
| --- | --- |
| A count-down loop that copies `n` and tests the old value (`move v0,a1` / `addiu a1,a1,-1` / `bnez v0`) | `n = i--; if (n == 0) break;` (plain `while (i--)` compares the new value with -1) |
| A field load kept after a store to a scalar global | Read the field through a raw cast, `*(T **)((u8 *)task + 0x1C)` (0x8004BDD0). The scheduler assumes struct fields and scalar globals never alias and hoists the load otherwise; array indexing doesn't help. |
| A bare `break 7` (`0x0007000D`) with no `div` before it, in DH2 task functions | `TRAP()` from `include/common.h` (inline asm; see `docs/port-todo.md`). maspsx splits a single `break` operand into two 10-bit fields, so the macro writes `break 0x1C00` (7 << 10) to get the ASPSX word. |
| Loads of the task check (`t->func`, `D_800B7350`) stay below a run of global pointer stores instead of being hoisted above them | Make the stored-to globals an array (`u8 *D_800BDA74[7]`, DH2 0x8006E740). Array and struct-field stores count as possibly aliasing the field load; separate scalar globals don't, and the scheduler moves the loads up. The same goes for a store through `p` that must stay after argument loads: write it as a struct field (`p->unk0 = 0`), not `*(s16 *)p = 0` (0x80034BA0). |
| A pointer argument kept in `a0` across a call | The callee takes it: `func_8003EB60(p)` (DH2 0x8005A9B0). |
| Two values swap registers around an `a || b` test that assigns the same thing | Write it as `if (a) x = y; else if (b) x = y;` (0x8005C6F0). Each branch then has its own copy, which changes how GCC allocates the registers for the compared values. |
| A pointer global loaded again after a store through it (`sw zero,0(v0)`, then `lw v1,%lo(D_800A317C)`) | Store through a plain pointer, `*(s32 *)D_800A317C->vals = 0;` (0x8001ECC8). A store to a struct field (`->vals->f = 0`) is assumed not to touch a scalar global, so GCC reuses the first load. |
| Two neighbouring globals re-read on every loop pass through one base register (`addiu t0,%lo(D_800A79F2)`, then `lhu 0(t0)` / `lhu 2(t0)`) | Declare them as one array, `extern u16 D_800A79F2[2];` (0x8003EEA8). As separate scalars GCC hoists both loads out of the loop. |
| A frame 8 bytes larger than the saved registers need | An unused 8-byte local, for example `SVECTOR unused;` (0x800433F4) |
| A global's address kept in an `$s` register across a call | Read it through a local pointer, `s16 *count = &D_801D209C;` (0x8003BA6C) |
| A constant reloaded on every pass (`li v0,-1`) instead of kept in an `$s` register | Write the loop with a label and `if (++i < n) goto top;` (0x8006AD2C). Loop-invariant motion only runs on `for`/`while`/`do` loops. |
| A global loaded as `lui` + `addiu`, then `lhu 0(reg)` (the low half not folded into the load) | Declare it `volatile` (0x8005C244, `D_800A32AC`, probably pad input). Volatile shared arrays also stop delay slots from being filled (0x8002076C). |
| `if (g == NULL) ... else g->f` reloads `g` in the `else` branch instead of reusing the tested value | Declare `g` `volatile` (0x80030090, `D_801F7D50`). |
| `$a1`-`$a3` look like call arguments but the callee never reads them | They may be leftovers from earlier code; try the call with fewer arguments (0x80030090). |
| A local filled from an 8-byte constant with `lwl`/`lwr` pairs (`la` of a constant, then four unaligned loads and stores) | A struct of `char` initialized from a string, `struct { char str[8]; } name = { "d" };`. A plain `char buf[8] = "d"` copies two bytes and calls `memset` instead. The constant goes to `.sdata`, which the Makefile renames to `.rdata` (0x80069728). |
| A pointer increment sits in the delay slot of the `jal` that receives it | Increment in the argument: `AddPrim(ot, prim++)` (0x800691F0). |
| An array walked with two `$s` pointers a field apart (base and base+6), both stepped by the element size | Step a pointer with `p++` (0x80050844). A `short` index needs a sign extension every pass, which blocks strength reduction. |
| A byte load (`lbu`) from a field that other code reads as 16 bits | `u16` field read as `field & 0xFF`; combine narrows the load (0x80050358, `VoiceState.id`) |
| Several fields set to one value, stored in reverse field order | A chained assignment `a = b = c = 0;`: GCC stores the rightmost name first (0x8002A194, 0x800523AC) |
| A global read hoisted to the top in our build, but read late (after stores to a struct) in the original | Declare the global as a one-field struct (`extern struct { s32 unk0; } D_...;`). GCC 2.5.7 assumes a plain scalar can't overlap a struct field, so it moves the read early; a struct read has to wait behind the stores (0x800360C8, 0x800584A4). Neighbouring globals read together can instead be one array (`D_800A305C[3]`, 0x80021264) |
| A load through one pointer scheduled above stores through another | The read comes first in the source; the scheduler then sinks the store (`movie->unk40 = info->mode;` first, 0x800523AC) |
| A struct copy comes out as `lwl`/`lwr` pairs, but the original uses `lhu`/`sh` per field | Copy field by field (`RECT`, 0x800523AC) |
| A value just stored is loaded again (`lhu`) instead of reused | Another store through the same `s16 *` between the write and the read; CSE drops the remembered value (`speed[9] = 0;` between, 0x800665E8) |
| `lhu` where you expect `lh` (or `sltu`), and nothing extends the value | The field is unsigned: `u16`/`u32`, or cast both sides of an `==` to `(u16)` (0x80049744, 0x80031264, 0x8005F880) |
| An unused stack frame | A call removed as dead code, probably `if (0) printf(...)` |
| A value stored to two globals straight from its register, with no extra `move`, then sign-extended for an index | Store it once and read the global back: `D_800A3234 = n + 2; D_800A3024 = D_800A3234;`, then index with `D_800A3024`. An `s16` local holding `n + 2` adds a copy (0x80020380) |
| A frame larger than the saved registers need, but no unused local fits | Try no local at all first: 0x8002FEC0 has a 0x38 frame and matches without one. Otherwise size the local to the gap (`u8 unused[56]`, 0x80020380) |
| An `int` argument passed without the `sll`/`sra` that a `short` parameter would add | The callee's prototype takes `int` (`func_800296F8(s32, s32, s32)`, 0x800473CC) |
| `abs` done in place (`bgez v0` / `nop` / `negu v0,v0`) after the element address is already computed | `a[i] = ABS(i + -6);` with `ABS` from `common.h`. `ABS(i - 6)` doesn't work: GCC folds `-(i - 6)` into `6 - i` before it can see the abs. A separate `d = i - 6;` statement computes the value before the address (0x8005E478) |
| One error path reached by `beqz` over a `j`, shared by two checks | Write the error block out twice (`if (fail) { cleanup(); return 0; }` after each loop); GCC merges the copies (0x80052234) |
| A loop whose exit test sits at the bottom with a `move` in the delay slot, where `do`/`while` or `for` comes out rotated | `while (1) { ...; if (++i >= n) return ...; }` (0x800439A4) |
| `lhu` of a stack argument and `sll`/`sra` of register arguments, while callers pass plain `int` | An old-style definition with `s16` parameters (`void f(a, b) Anim *a; s16 b; {`); drop any later `int` prototype (0x80024DA8) |
| Two `mult`s issued back to back before either result is used | Compute both products into `s32` temporaries first, then use them; put the shifted product first in the sum (`(dx >> 12) + p->pos.x`, 0x80057918) |
| Argument copies to saved registers placed after the first global loads, not at the top | Declare a parameter that only ever goes into byte stores as `u8` instead of `s32` (0x80040D98) |
| A global reloaded on every pass of a loop, where ours hoists it out | Read the loop bound straight from its global in the `for` test (`i < D_800A3074`) instead of a local copy; GCC 2.5.7 hoists only one load per loop (0x80058788) |
| Stores through pointers don't force a reload of a scalar global (struct field stores are assumed not to alias plain scalars) | Make the global a struct (`History D_801D2078` with `idx`, `log[5][2]`); struct-to-struct accesses can alias, so the field gets reloaded (0x8003A790) |
| Field accesses off one base register at the wrong offsets (`-2`, `0x18`) | GCC uses the address of the first field named in the source as the base; reorder statements so the original base field comes first (0x80058788) |
| The compared bound loaded before the negate of an absolute value | `if (ABS(x) < p->limit)` instead of `if (x < 0) x = -x;` then compare (0x800493D0) |
| An early `return 0` adding a `j` the original lacks | One exit: `if (ok) { ... } else { r = 0; } return r;` (0x80045EF4) |
| A lerp result used without `sll`/`sra` sign extension | `func_800296F8` returns `int`, not `s16` (0x80050158) |
| A store scheduled after a global load the original has before it (or the reverse) | Store through a struct field (`data->unk0 = 0`) instead of `*(s16 *)p`; struct fields are assumed not to alias plain scalars, so loads can move past them (0x8003E85C) |
| An early `addiu sN, s0, off` kept for one late field store | Take the field's address in a local at the top (`s16 *state = &obj->unk2C;`) (0x80033820) |
| A `u8` argument copied with `move` (no `andi`) before `~x` | Widen it through an `s16` local: `s16 c = shade; g0 = ~c;` (0x80040FF4) |
| A struct copied to the stack and never used (`lwl`/`lwr` into `0x10(sp)`) | An unused local `Struct v = global;`; its declaration order against other locals sets which load comes first (0x80031070) |
| Caller sign-extends a `u16` argument the callee declares `u16` | The original caller saw another prototype; use a K&R definition plus `extern T f();` and cast at the call (`(s16)x`) (0x80031070, 0x8005AB1C) |
| Per-field stores in the wrong order around a global `++` | Reorder the source statements; GCC 2.5.7 keeps scalar-global order but moves struct-field stores freely (0x80036DE8) |
| `setcode`, then `lbu`/`ori 2` reload of the code byte | `setcode(p, c); setlen(p, n); setSemiTrans(p, 1);` in that order: the `setlen` store between them stops the fold (0x80040E94) |
| Constant stores to a struct hoisted above table loads | Declare the table without `const`; GCC 2.5.7 then keeps stores after loads that might alias (0x80033490) |
| Chained `a = b = x` stores in the wrong order | The rightmost target is stored first; swap the chain (0x80033490) |
| `x >> 1` as `srl` instead of `sll`/`sra 17` | Use `(shade >> 1)` in each expression, not `shade >>= 1` (0x80040E94) |
| Three identical tails, one using a saved pointer | Write the tail out in each branch; GCC cross-jumps them (0x800495F8) |
| `lhu` from a signed field, then `sll`/`sra` at each use | Copy the field into an `s16` local; using the field directly gives `lh` (0x80055298, 0x800585D4) |
| `sra v1,v0,17` into a new register, not `v0` | `c >>= 1` on the `s16` variable, not a new `half` local (0x800550D8) |
| Parameter used before a late `move` to a saved register | The early uses read the parameter and the later ones a copy: `s32 y2 = y;` after the other initializers (0x800550D8) |
| Value kept out of `a0` before a call | Keep the stores in source order so the argument setup overlaps it: `tpage`, colours, then the call (0x8002F6C0) |
| `* 2` of an `s16` call result comes out as `sll 16`/`sra 15` | Use `<< 1` (0x8005B1CC) |
| A quotient lands in its own register and is then copied with `move` | Declare the quotient variable `s16` (`s16 frame = t / step;`) (0x80031C58) |
| `-(x - K)` comes out as `li`/`subu` where the original has `addiu -K`/`negu` | Two statements: `x -= K; x = -x;` (0x80031ED0) |
| `p + i + 1` adds the base first, then 8 | Write `p + (i + 1)` (0x80031ED0) |
| Two pointers stepped together in a loop, one of them only for colours and `AddPrim` | Post-increment in the argument: `AddPrim(ot, line++);` (0x80031ED0) |
| A global store stays above the `D_800B7350` load of a trap check, while other stores sink below it | Both globals are `volatile`; GCC 2.5.7's scheduler keeps two volatile accesses in order. `D_800B7350` is `volatile` in `dh2.c` (DH2 0x80046498 with `D_801F7548` and `D_801F9A56`) |
| A global store stays above a later load through a struct pointer | Write the global as an array element (`D_801F7540[4]`, not `D_801F7550`). A store to a plain fixed scalar may be reordered past a varying struct access; a store to an array element may not (DH2 0x80046498) |
| `li v1,0xffff` where the C gives `li v1,-1` | The global is `u16`, not `s16` (DH2 0x8003D8D4, `D_800B6C30`) |
| A global's address loaded once (`addiu v1`) and used for both `lbu 0(v1)` and `sb zero,0(v1)` | A local pointer: `flag = &G; if (*flag) { *flag = 0; ... }` (DH2 0x8002318C) |
| Rodata (strings, tables) inside a function's `.s` file | Write it as `const` data right above the function, in address order; write a backslash as `\\`, since `"\ "` silently drops the backslash (DH2 0x8001E6EC, credit tables at 0x80089568) |
| Short strings (8 bytes or less) inside a function's `.s` file | Plain string literals in the call land at the right address (DH2 0x80041168 `"FREE
"`, 0x8004F8B8, 0x80023920) |
| Two separate tests `slti x,2` / `bltz x` where ours has one `sltiu` | GCC folds `n < 2 && n >= 0` into an unsigned compare; nest them as `if (n < 2) { if (n >= 0) ...` (DH2 0x8005F4E4) |
| `addu v0,v0,a0` (field first) where ours has `addu v0,a0,v0` | For `+` GCC puts a register before a memory operand; load the field into a local first, `base = d->base; d->base = base + delta;` (DH3 0x8002BFF4) |
| Leaf function with a stack frame (`addiu sp,-0x18`) and no stores | The frame is unused spill slots, so its size tracks how many temporaries the C creates; try shapes until it matches, e.g. `if (m < h3) return h3; return m;` instead of a ternary (DH3 0x80028D04) |
| Inline block-move loop with an `or`/`andi 3` alignment test | The copied type has no 4-byte fields; copy through a `u8 data[N]` struct (DH3 0x8002BFF4) |
| A call result promoted with `andi 0xFF` and kept in one register | Callee returns `u8` and the local is `s32` (DH3 0x8002DA20) |
| Two loads of the same global pointer around a NULL test | Declare it `struct Task *volatile` (DH2 0x80061F6C `D_801F7548`, 0x80067298 `D_801F758C`) |
| A short-lived value lands in `a0` where ours uses `v1` | It shares a variable with a later value that ends up in `a0` (the colour and the depth `z`, DH2 0x80033F74) |
| `move a3,v1` of a constant address before a loop's entry test, where ours puts it after | Assign the base to a named local after the code that also uses the address (DH2 0x80034A18) |
| Pool slot found, then `ptr` loaded before the two byte stores | Assign `t->vals = ptr[i]` before `t->unk2E`/`t->unk2F`; the scheduler can't hoist the load above possibly aliasing stores (DH2 0x80074304) |
| Two addresses CSE'd from one base (`addiu a3,a1,0x386`) though splat names them separately | They are fields of one object: the pool free counts, used flags and pointer tables at 0x801F6DB8 are one struct (DH2 0x80074304, DH3 0x8007374C) |
| Running sum comes out as `addu v0,v1,v0` then `addiu v1,v0,1` | One expression, `sum = sum + *p++ + 1;`, not `+=` or a separate `sum++` (0x8006994C) |
| `addu a0,a0,s0` (integer first) where pointer arithmetic gives `addu a0,s0,a0` | Hold the old pointer as an integer: `s32 old = (s32)G; f((void *)(size + old));` (0x8001FE84) |
| Looked-up index should stay in `v0` as the return value | `if (match) return voice; return -1;` rather than assigning `-1` to the variable (0x800504B8) |
| `sll 16`/`sra 16` at a call that passes a parameter straight on | The parameter is `s16`; an `s32` parameter passed to an `s16` callee gets no extension (0x8006B188) |
| Global loaded again right after `G++` | Plain `G++; return G;` with a `u16` global already reloads; no `volatile` needed (0x8004FB10) |
| Empty function that still makes a stack frame | An unused local array sized to the frame: `u8 unused[24];` (0x80055EE0) |
| Load of the spawned task's data hoisted above the store of the task pointer | Read the data pointer through a cast, `*(T **)((u8 *)task + 0x1C)`, so it isn't a struct-field load (0x800411E4, as 0x80051960) |
| Stack slot stored, reloaded and decremented (`sh`/`lhu`/`addiu`/`sh`) | A `volatile s16` local counter (0x800391E0) |
| Global pointer copied into a `t` register before a loop | Use the global directly in the loop; GCC hoists the load itself. A local copy changes the registers (0x800391E0) |
| Saved registers numbered in the wrong order for parameters and locals | Assign locals with statements after the parameter-using call instead of initialisers, e.g. `i = 0; flag = 0;` before the loop (0x80023270) |
| Index-to-pointer fixups all load into one register | One reused `idx` temporary: `idx = (s32)f->v[0]; f->v[0] = &verts[idx];` (0x8003219C/0x80054C70 pattern) |
| `bne a1,v0` instead of `bne v0,a1` | Swap the comparison operands (`dec->w != sector->width`, 0x800525F8) |
| `li v0,0` / `li v0,-1` pair in delay slots at the end | `if (a != 'M' \|\| b != 'C') return 0; return -1;` (0x8006A920) |
| Pointer increment scheduled before the counter increment | `for (...; v++, i++)` rather than `i++, v++` (0x8004FB38) |
| `j join` with the value set in the delay slot, store at the join | Identical stores in both branches (`if (c) p->f = 2; else p->f = -2;`); GCC cross-jumps the tails. A preset variable gives `li` before the branch instead (0x8003516C, 0x800403C8) |
| A field compared and then used is reloaded (`lh` twice) | Put a store to the same struct between them in the source (`obj->a = 1; n = obj->b * 18;`); the scheduler moves the store down (0x8005F1F0) |
| `lhu` + `sll 16`/`sra 16` on a global, or two reloads after `x--` | The global is `volatile`; `x--;` as a statement then `if (x == 0)` gives the double reload (0x8003E4E8) |
| `lwl`/`lwr` copy of 8 bytes into a local | `RECT r = D_800A2B14;` / `SVECTOR v = D_800A2B50;` from a `.data` global (2-byte alignment); from rodata (0x8007..., 0x8008...) it is an initializer and needs the rodata split (0x80052E88, 0x8005A42C) |
| Parameter copied to its saved register late, after other stores | Copy it into a local just before first use (`file = arg1;`) (0x8003E77C, 0x8005A42C) |
| `(u16)v >> 8` as `sll 16`/`srl 24` from the sign-extended value | `s16 v = p->f; hi = (v >> 8) & 0xFF;` (0x800689BC) |
| Store order wrong in a block of independent stores | Try every order of the few statements involved; a small script finds it in minutes (0x8006937C, 0x80052E88) |
| Loop over a global pointer's elements with the pointer and other globals loaded once before the loop, no extra address register | Index the global directly, `for (i = 0; i < n; i++) G[i].x += dx;` with `u32 i`. An indexed reference counts as a structure access, so GCC hoists the scalar globals out of the loop; a local pointer copy changes the loop (0x800418DC) |
| Global's full address kept in a saved register (`lui`/`addiu` then `lh 0(s0)`) for a later load and store | Declare it as an array and use `G[0]` (0x8001F0F8, `D_801C1F04`) |
| `lui`/`addiu` then `lhu 0(v0)` for a pad word | `volatile u16` array element, `D_800A32AC[1]`; a `volatile u16` scalar loads `lhu %lo(sym)` directly (0x8001F0F8) |
| Jump table entry for a case below the lowest real value (`addiu +1` before the range check) | An explicit empty `case -1: break;` (0x80021554) |
| Both tests' values computed before the first branch (second subtraction in a delay slot) | Compute both locals first, then one `if (a > N \|\| b > N) return;` (0x8004161C) |
| Unused 8 bytes below the locals in the frame | An unused local `SVECTOR unused;` declared first (0x800290D4) |
| Local array copied from rodata with `lwl`/`lwr` | Works now: write the initializer and delete the rodata symbol's `INCLUDE_RODATA` line, as long as it sits right before the function with nothing emitting rodata in between (0x800418DC, 0x800290D4) |
| Count-down loop `addiu a0,s3,-1` / `beq a0,-1` with the `-1` shared with an earlier `== -1` test, `count` kept intact | `for (i = count - 1; i != -1; i--)` (DH3 0x800697A8, 0x800781F8); `while (count--)` decrements `count` itself and `for (i = 0; i < n; i++)` counts up |
| Error path returns the saved value (`move v0,s2`) instead of `li v0,-1` | Put the success path in an `else` and keep one `return addr;` at the end (DH3 0x800697A8) |
| `sw $ra` to a global (caller tracking, DH3 0x80072A40, 0x800724C4, DH2 0x800735F8, 0x8007307C) | Not C: `__builtin_return_address(0)` under GCC 2.5.7 loads from the stack frame instead. `GET_RA(global);` in `include/common.h` (a marked fake, one `sw $31` through an `"=m"` operand) at the point of the store; ASPSX expands it to `lui $at` / `sw $ra` |
| Globals next to each other stay below struct stores (not hoisted above them) | Declare them as one array (`D_800B5EFC[3]`, `D_801DA432[3]` in DH3), like DH1 `D_800A305C` (DH3 0x80072374) |
| Caller passes an `s16` argument computed in a wider type | GCC 2.5.7 does not truncate to the prototype's `s16`; the original writes `(s16)` casts at the call (DH2 0x80062B38, DH3 0x80064308) |
| `u16` field set with `ori 0xFFFF` | Write `0xFFFF` into a `u16` field; `-1` gives `addiu` (DH2 0x80035384, DH3 0x80048B74) |
| Unused 8 bytes in the frame | `s32 unused[2];` (DH2 0x80065430, DH3 0x80028648) |
| Two task pointers 0xC apart, second one reloaded after a store | One array `struct Task *D_801F80B0[]`, elements `[0]` and `[3]` (DH3 0x80024088) |
| `lhu` of the low half of an `s32` global | GCC narrows the load when the result is truncated to `s16`: declare the global `VECTOR` (DH3 `D_801FAE04`, 0x80060A20) |
| Array element loaded once through `$at` (`lui at`/`addiu at`/`addu at,at,reg`/`lw`) and both stored and compared | Read it into a local first: `p = table[i]; obj->f = p; if (p == X)`. Reading `table[i]` twice gives two loads (DH3 0x80051864) |
| Call result compared with a field loaded after the call | Put the call on the left: `if (f(...) > d->unkC)`; `d->unkC < f(...)` loads the field first (DH3 0x80044DE8) |
| `addiu 0x40` on the depth before `sra 3` for the OT index | `ot + ((otz + 64) >> 3)`, not `ot + 16 + (otz >> 3)` (DH2 0x8002B61C, DH3 0x80030B00) |
| Task pointer reloaded after its own `NULL` test | Declare it `volatile` (DH2 `D_801F7548`, 0x800532A4) |
| A global (`otz`, the prim pointer, the `ReadSZfifo` results) is loaded only after a store to a prim field, not hoisted above it | GCC 2.5.7 assumes a struct field store through a pointer cannot alias a plain global, so it hoists the load. Make that store a cast store of a different type, which is not a struct reference: `*(s16 *)&prim->uv2 = tex[4];`. Same for loads (`*(u32 *)&prim->xy0`). A cast to the field's own type is folded back to the field and does not help (DH3 0x8002D5DC, 0x800382A8, 0x8002DFB4; DH2 0x8002CF34). This fits the original using PsyQ `POLY_FT4` (`u8 u0, v0`) and `*(u16 *)&p->u0` stores |
| A copy of the prim pointer is kept in `s2` (set in the delay slot of the buffer-full check) and passed to `AddPrim` | `prim *start = prim;` then `prim++; AddPrim(ot, start); D_800B63AC = prim;` (DH3 0x8002E864, DH2 0x8006C9F4) |
| `prim++` lands in the delay slot of the `otz > 0` test | Put `prim++` inside the `if`, before `AddPrim(ot, start)` (DH2 0x80028408) |
| `tex = base + f->tex + offset` with the offset term added last | Write it in that order; `base + offset + f->tex` reassociates differently (DH3 0x80031548, 0x80031674) |
| A scalar global read as `lui`/`addiu`/`lw 0(v0)` instead of `lui`/`lw %lo` | Declare it as an array and read `*(volatile s32 *)D_X` (DH3 0x80024428, DH2 0x80046658) |
| An 8-byte `lwl`/`lwr` copy from a rodata label that disassembles as the string `"d"` | A local `SVECTOR pos = {100, 0, 0};` (0x64 is `'d'`; DH2 0x80075E28, DH3 0x80075270). A `char` array initializer emits `memset` instead |
| A countdown loop the compiler turns into a pointer compare (`bne a3,t0` against the end address) | `for (i = N; i != -1; i--)`; `i >= 0` keeps the counter and branches with `bgez` (DH2 0x800462F0, DH3 0x80027744) |
| `p->x = p->x + dx` comes out as `addu v0,v0,t2` but the original has `addu v0,t2,v0` | Write `dx + p->x` (DH2 0x800462F0) |
| A 16-bit copy loaded with `lh` and stored with `sh` from an address 2 past an `s32` global | Read the upper half: `D_80169FE4 = D_800B6A6C >> 16;` (DH2 0x80070CFC). A plain `s16` copy always loads with `lhu` |
| `lhu` + `sll`/`sra` for an index read once, and stores after a call kept in source order | `volatile u16` index, `volatile` destinations (DH2 0x80024274). `(s16)` of a plain `u16` folds into `lh` |
| The next pointer stored back after `AddPrim` is computed before the `jal` | `AddPrim(ot, p++); G = p;` (DH2 0x80075900, 0x80041064) |
| A field read once through `arr[i].f` and again through a pointer to the same element | Keep both forms: first test `D_801D9DAC[v].state`, later `p->state` with `p = &D_801D9DAC[v]`; CSE doesn't merge them (DH2 0x80065CB0) |
| An `s32` global returned as `s16` with `lw` + `sll`/`sra` instead of `lh` | Declare it `volatile` (DH2 `D_800B725C`, 0x80046658) |
| A leaf with an 8-byte frame and no call | An unused `u8 unused[8];`, parameter `s32` when it isn't sign-extended (DH3 0x8006899C) |
| `move v0,a0` / `slt` / `bnez` / `move v0,a1` (min or max) | `if (a < b) return a; return b;`, not a ternary or a result variable (DH3 0x80026748, 0x80026764) |
| `abs(v)` copied into `v0` before the `negu` | `s32 m = ABS(v);` then `lim = ABS(lim);` (DH2 0x80024790) |
| A count-down loop over an `s16` that tests `n` first and then the old value | `while (n--)` with `s16 n` (DH2 0x80032D24) |
| A field read again (`lw s1`) after the stores that follow the `+=` | Read it after the first of those stores, not right after the `+=` (DH2 0x800219EC) |
| `xor` into a new register then `move` back | Declare the accumulator `u8` (DH2 0x8005F40C) |
| A range check `addiu +1` / `andi 0xFFFF` / `sltiu` on an `s16` | `i >= -1 && i <= 0x1000` (GCC folds it) (DH3 0x8004DC84); `(u16)i < 24` comes from `i < 0 \|\| i >= 0x18` (DH3 0x80054CE4) |
| A volatile global read without the volatile `lhu`/`sll`/`sra` form | Read it through `*(s16 *)&D_X` (DH3 0x80066B1C) |
| `sll`/`sra` on a call result before it is added or stored to a 32-bit field | The callee returns `s32`; cast at the call, `(s16)f(p)`. A callee declared `s16` is trusted to be extended already (DH3 `func_80028BF0`, 0x8004C828, 0x80059744) |
| A frame larger than the saved registers, nothing stored in it | Unused `VECTOR`/`SVECTOR` locals of the right total size (DH3 0x80022604, 0x8004C828). A leaf with a bare 16-byte frame matched with no local at all (0x80054A04); `if (0) call()` and `u8 unused[16]` gave 32 |
| A global pointer reloaded on every loop pass from an address hoisted into a register | Wrap it in a struct (`D_800B853C.ent[...]`); struct-to-struct accesses can alias the loop's field stores (DH3 0x8002CED0) |
| A frame 8 bytes larger than the original | `(SVECTOR *)&scalar` makes the scalar addressable; some nested `if`s also cost 8. Use real locals and early returns (DH3 0x8003E25C) |
| An `s16` argument passed on without `sll`/`sra` where the original extends it | Cast at the call, `f((s16)(k * 85))` (DH2 0x8004FC84) |
| `lhu` of a constant table scheduled after unrelated struct stores | A plain (non-`const`) `u16` array, read as `[2]` and `[0]`; `const` scalars are hoisted above the stores (DH3 0x8002C58C) |
| `bnez` to the body, fall-through `j` to the epilogue with `v0 = 0` in the delay slot | `if (t != NULL) { ...; return -1; } return 0;` rather than an early `return 0` (DH3 0x80059744, DH2 0x800256A4) |
| A sum kept in `v0` instead of overwriting the argument's saved register | Split it: `k = f(n); k += n;` (DH2 0x80057734) |
| `lh` of the upper half of an `s32` global | `x >> 16` (DH3 0x8006FC14) |
| A struct global's address CSE'd (`la s1, sym+off`) and used at other offsets for neighbouring "globals" | They are elements of one struct array (`Unk8005A018 D_801F77E8[2]`, DH2 0x8004D264, 0x8003D1F8) |
| Two equality tests (`x == 12`, `x == 13`) instead of one unsigned range check | Two separate `else if` statements; an `\|\|` chain or a `switch` both give `x - 12 < 2` (DH3 0x8002AF48) |
| `addu` operand order and registers differ in a loop over a struct array | Index directly, `f[i].field`, rather than `e = &f[i]; e->field` (DH2 0x800348D4, DH3 0x80048360) |
| A pointer copied to a saved register and incremented before a call that takes the old value | A second pointer, `prim = p; p++; AddPrim(ot, prim);` (`AddPrim(ot, p++)` increments after the call) (DH2 0x800493CC) |
| Store order of `a = b = v` | The inner target `b` is stored first; write the chain in the order the stores appear (DH3 0x80046084) |
| A store to a struct field moved below a following load of a plain global (and taken into a branch delay slot) | GCC 2.5.7 assumes an in-struct store can't alias a scalar global; the original wrote it through a cast, `*(u32 *)&t->xy2 = ...` or `*(s16 *)&prim->uv2 = tex[4]`, so the load stays after it (DH2 0x8002D5AC, 0x8002E75C, DH3 0x80034AC8) |
| A load from one pointer scheduled before a store through another (`lw v0,28(s0)` before `sw s0,44(a2)`) | Load into a temporary first: `void *v = owner->vals; d->unk2C = owner; d->unk28 = v;` (DH2 0x80060AEC) |
| A local held in `a0` at a call that seems to take no arguments | The callee takes it: check its first instructions for `a0` (`func_8003BE74`, `func_8004ED7C` take the prim; DH2 0x8002D5AC, DH3 0x80034E24) |
| A timeout counter tested before the decrement (`move v0,s1` / test / `addiu s1,s1,-1` in the delay slot) | `if (n-- == 0)` (DH2 0x80074138) |
| An `s16` copy kept sign-extended in a saved register across a call | The destination is `s32`: `s32 idx = j;` (DH2 0x8003FA60) |
| `lhu` where an `s16` field is subtracted | `(u16)p->unk22` (DH3 0x8003FA90) |
| One shared load hoisted above a sign test that picks a call argument | Two calls, one per sign, instead of `d < 0 ? -k : k` (DH3 0x8003FA90) |
| A branch delay slot left empty although the target's first instruction writes `v0` | The function returns a value (old-style implicit `int`) and falls off the end, so `v0` is live at exit (DH3 0x80026A74 family) |
| Frame 8 or 16 bytes larger than the original with nothing stored there | An unused local of that size, declared where its slot falls (`SVECTOR unused;`, `VECTOR unused;`; DH3 0x8006D988, 0x800224B4) |
| Each field of a global table read through its own `lui`/`addiu sym+off` plus the index | The table is a global array of structs (`extern VECTOR D_801984F0[]`, `D_801984F0[n - 1].vx`); a pointer cast or `&scalar` indexing shares one base register (DH3 0x800504A4) |
| An error path placed after the success path's `return 0` | `goto error;` with the error code at the end; GCC 2.5.7 keeps source order and threads each failing branch to the right block (DH2 0x80071A08) |
| `move s1,v0` after a computed value that is compared right away | The variable is `s16` (DH2 0x8006684C, DH3 0x80045B60) |
| A store placed between a call and the read-modify-write that uses its result | Keep the result in an `s32` temporary: `d = f() - 0x40; x.a = r; x.b += d;` (DH3 0x800669C0) |

## PsyQ library settings

The library code linked into DH1, DH2 and DH3 was built with a different compiler from the game code. A bake-off on 14 DH2 library leaves (`src/bakeoff/dh2_8007D0EC.c` to `dh2_80087F04.c`: the primitive helpers, `GetClut`, `SetPriority`, `SetDefDispEnv`, `DumpClut`, `CdPosToInt`, `CdIntToPos`, `memmove`) gives:

| Leaf | 2.5.7 | 2.6.3 | 2.7.2 | 2.8.1 |
| --- | --- | --- | --- | --- |
| `AddPrim`, `AddPrims`, `CatPrim`, `TermPrim`, `NextPrim`, `IsEndPrim` (P_TAG bitfields) | no | yes | yes | yes |
| `CdPosToInt` | no | yes | yes | yes |
| `DumpClut` | no | yes | yes | no |
| `SetPriority` | yes | yes | no | yes |
| `GetClut`, `SetPolyF3`, `SetDefDispEnv` | yes | yes | yes | yes |
| `CdIntToPos`, `memmove` | yes under 2.6.3 after rewriting (below) | | | |

- **Confirmed: GCC 2.6.3 at `-O2`**, the only version that matches every leaf. The game's GCC 2.5.7 misses all the `P_TAG` bitfield helpers, so library files need their own compiler setting.
- `-G` and ASPSX 2.08 to 2.34 make no difference on these leaves (2.56 and later do). **Guess:** `-G0`, since only one DH2 library function touches `$gp`.
- **Confirmed: ASPSX 2.34 for the library code in all three EXEs.** Symbol loads use the 2.34 form (`lui`/`lbu %lo`, for example `CdStatus`, DH2 0x8007CAFC), even in DH2 and DH3, whose game code uses 2.21. The bake-off can't see this because it masks relocations.
- Hardware register pointers are `volatile` (`StartRCnt`, DH2 0x8007FE74, keeps `sw; jr ra; nop`). Without it GCC moves the store into the delay slot.
- The library files are `src/<exe>/gun.c` and `src/<exe>/psyq.c`; the Makefile sets their compiler, `-G0` and ASPSX 2.34.
- `CdIntToPos` keeps `i / 75` in its own variable and does `sec %= 60` after taking the minutes; with `i / 75 / 60` GCC folds the divisions into one by 4500. `memmove` copies backwards with `dst[n] = src[n]`, so the end pointers come from strength reduction after `n--`. Ghidra's length for `memmove` stops before its shared `jr ra` tail, so the bake-off script reports it as a miss.
- Splat had split many library functions at the signature labels named `*_OBJ_*`. Those reached only by `j`, fall-through or jump tables are labels inside the previous function and have been removed from the symbol files; the remaining `*_OBJ_*` names are real static functions (`jal` targets).
- GCC 2.6.3 moves an `if` whose body is only `return <constant or load>` to the end of the function, so the code after the `if` falls through. To get the return as the fall-through, write the other branch as the `if` body (`if (num > 0) { ...; return num; } return 0;`, `SpuInitMalloc`), or test the opposite condition (`if (i >= 3) return 0; return count;`, `GetRCnt`).
- A function that returns `int` keeps `$v0` live at its exit even without a `return` value, so reorg won't copy a loop's first `$v0` instruction into the loop branch's delay slot. The original's `nop` there (`init_ring_status`, DH2 0x8007F95C) means the function was declared `int`.
- Old GCC alias rule: a load from a plain global can move above a store through a pointer only if the store is to a struct field. `SpuInitMalloc` needs `top->addr` (a struct) for `D_800A21BC` to load before it.
- `x++` on a `volatile` global as a statement loads, adds, stores, then loads again (`trapIntrVSync`, `_spu_reset` loop counter).
- Repeated use of one struct field's address (`sym+offset`) is CSE'd into a register (`la` then `0(reg)`); a plain global or a field at offset 0 is not. So `SetGraphDebug`'s `la` form means the libgpu globals are one struct.
- A retry written with `goto` keeps its constants inside the loop (no `loop.c` hoisting into saved registers); a `for`/`do` loop hoists them (`CdInit`, DH2 0x8007E970).
- A value masked in place (`c &= 0xFFCF;`) keeps its register, so reorg can't use the masked copy to fill a delay slot (`_spu_reset`).
- About 45 library functions per EXE are BIOS call stubs (`li $t2, 0xA0/0xB0/0xC0; jr $t2`) and about 60 are libgte routines built on GTE instructions. Both were written in assembly and stay as assembly. That leaves about 290 library functions per EXE (about 14,500 instructions) to write in C.
- A field of a global struct that is read and written several times gets its address in a saved register (`la s1, D_800A3F40+5`, then `lbu`/`sb 0(s1)`); separate `extern u8` variables never do. The libgpu state at 0x800A3F40 (`printf` pointer, `type`, `queue`, `debug`, `reverse`, `DISPENV` at +0x70) is declared as one struct in DH2 `psyq.c` for this (`SetGraphDebug`, `SetGraphQueue`, `SetDispMask`).
- A `u16` status read through a `volatile` pointer keeps a redundant `andi 0xFFFF` after the `lhu` (`StGetNext`).
- `while (i--)` with `i = 16` gives the `li 15 ... addiu -1; bne -1` count-down loop; `for (i = 0; i < 16; i++)` stays a count-up `slt` loop (`DecDCTPutEnv`).
- `i == 0 || i == 1` folds to an unsigned `sltiu 2` (`SetRCnt`).
- A function pointer as a struct's first member makes GCC keep the struct's address in a saved register across several calls. The libgpu print function at 0x800A3F40 (DH2) is therefore its own global, and the libgpu state struct starts at 0x800A3F44 (`DumpDispEnv`, DH2 0x8008437C). DH1 and DH3 are laid out the same way.
- `(~st >> 31) & 1` gives `nor`/`srl 31`; `!(st & 0x80000000)` gives `srl 31`/`xori 1` (MDEC `timeout`, DH2 0x80087150).
- A command packet filled field by field and then passed by address: write the fields in packet order, so GCC keeps `&packet[2]` in a register and passes it minus 8 (`MoveImage`, DH2 0x800815AC).
- Unresolved: in `CdRead` (DH2 0x8007C910) and the SPU quit routine (0x8007BC3C) the next call's argument is set before the previous result is stored, with the `jal` delay slot left empty. GCC 2.5.7 to 2.8.1, ASPSX 2.08 to 2.79, `-O3` and `-fschedule-insns(2)` all fill the slot instead, so these objects may have been built with other settings.
- Unresolved: `get_cs`/`get_ce`/`get_dx`/`get_mode`/`get_ofs` load libgpu fields through an unfolded `lui`/`addiu` address, then `lhu` plus `sll`/`sra`. Only a `volatile` struct reproduces that, and it breaks `GetGraphType`.
- A do/while loop over an `s16 i` whose index the original keeps sign-extended in a saved register (and reuses for `i << 8`): copy it into an `s32 j = i` after the first call in the body and index with `j` (DH3 0x8006B170, DH2 0x8006F110).
- Two plain loads of the same global in one block mean it was declared `volatile` (DH2 `D_801F7544`, 0x8006F110); a `*(T volatile *)&x` cast gives an `addiu`/`lw 0` pair instead.

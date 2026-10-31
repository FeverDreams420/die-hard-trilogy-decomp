# Compiler notes (Phase 2)

Status: **Phase 4 settled (Oct 25, 2026): GCC 2.5.7 (`gcc-2.5.7-psx`), `-O2 -G8`, ASPSX 2.34 for the games and 2.21 for LOADER.** Details under run 4.

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
- **Open for Phase 5/6:** under `-G8`, GCC 2.5.7 uses `$gp` only for variables it knows are small. A plain `extern` comes out as a `lui` pair, so `$gp` globals have to be defined in (or moved into) the C file that uses them. Those definitions change `.sbss`/`.sdata` layout, so they wait until data is split per file.
- **To confirm later:** the frame leaves suggest debug prints compiled out with `if (0)`, which would leave their format strings in `.rodata`. Look for unused debug strings near those functions.

## Phase 5: matching idioms for GCC 2.5.7

Patterns that turned a near-miss into a match. Each names the DH1 function where it was found.

| What the original shows | C that produces it |
| --- | --- |
| A count-down loop that copies `n` and tests the old value (`move v0,a1` / `addiu a1,a1,-1` / `bnez v0`) | `n = i--; if (n == 0) break;` (plain `while (i--)` compares the new value with -1) |
| A field load kept after a store to a scalar global | Read the field through a raw cast, `*(T **)((u8 *)task + 0x1C)` (0x8004BDD0). The scheduler assumes struct fields and scalar globals never alias and hoists the load otherwise; array indexing doesn't help. |
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

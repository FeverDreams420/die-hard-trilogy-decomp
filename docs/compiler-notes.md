# Compiler notes (Phase 2)

Status: **in progress.** Steps 1–2 have first results from scanning the raw EXEs. Signature matching in Ghidra, and steps 3–5 with function boundaries, still need Ghidra.

## Step 1: PsyQ SDK version

Every one of the seven EXEs carries the same three `$Id` stamps from Sony's `libapi`/`libetc` sources:

| String | SLUS_001.19 | BOOT | DH1 |
| --- | --- | --- | --- |
| `$Id: bios.c,v 1.77 1996/05/13 06:58:16 suzu Exp $` | 0x8002B048 | 0x80013244 | 0x8007BD18 |
| `$Id: intr.c,v 1.73 1995/11/10 05:29:40 suzu Exp $` | 0x8002B2BC | 0x800132B4 | 0x8007B724 |
| `$Id: sys.c,v 1.120 1996/05/01 12:09:07 noda Exp $` | 0x8002B364 | 0x8001335C | 0x8007B88C |

(LOADER, SLIDE, DH2 and DH3 have the same three strings; `python -I` string scan, Oct 25, 2026.)

- **Finding:** all seven programs were linked against the same library build, with sources dated up to **May 13, 1996**.
- **Guess:** that date points to **PsyQ 3.5** (mid-1996). It needs confirming with PsyQ signature matching in Ghidra, which also names the library functions for `symbol_addrs`.
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

Which GCC PsyQ 3.5 actually shipped is not yet confirmed. The prologue and epilogue shapes in Phase 4 will settle it.

## Steps 4–5: cross-references and leaf functions

Not started. Both need function boundaries and call graphs, which is Ghidra work (headless scripts).

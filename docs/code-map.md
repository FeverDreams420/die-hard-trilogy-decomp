# Code map (Phase 1)

Status: **done (Phase 1 checkpoint).** Steps 1–5 came from static data and the disassembly. Step 6 confirmed the boot chain in DuckStation on Oct 25, 2026: boot → LOADER, and all three games, load exactly as traced.

## Disc

| | |
| --- | --- |
| Release | Die Hard Trilogy (USA) (Rev 1), serial SLUS-00119 |
| Volume ID | `DHT` |
| Track 01 (MODE2/2352, data) | 48,864 sectors, SHA-1 `2d24572e92415e09c37b68c83ba8b8947aee1ce4` |
| Tracks 02–21 | CD audio |
| Extracted with | `tools/extract_disc.py` (layout in `disc/_layout.csv`) |

`SYSTEM.CNF`: `BOOT = cdrom:\SLUS_001.19;1`, `TCB = 4`, `EVENT = 10`, `STACK = 801fff00`.

## Code regions

Every code file is a complete PS-X EXE, not a headerless overlay. The load address and size come from each file's 0x800-byte header (`t_addr` at 0x18, `t_size` at 0x1C, entry `pc0` at 0x10). `gp0` is 0 in every header, so `$gp` is set by startup code instead (Phase 2).

| File | LBA | Load address | End | Text size | Entry | `jr $ra` count | SHA-1 | Role |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| `SLUS_001.19` | 47735 | 0x8001D500 | 0x800AFD00 | 0x92800 | 0x80021530 | 321 | `5839ac38072317a52118d0d322318dc14d3ea146` | First boot: finds all EXEs on disc, starts BOOT.EXE |
| `BOOT.EXE` | 48696 | **0x80013000** | 0x8001B800 | 0x8800 | 0x80013960 | 139 | `e96cf5a9aa3c83c36b584f736dc44919eaba0305` | EXE launcher: loads EXE number N and runs it |
| `LOADER.EXE` | 637 | 0x8001D500 | 0x80051D00 | 0x34800 | 0x800365CC | 563 | `c3caa8cbec3ea01e6bd5c6ae2ad9ea0dec1e8d96` | Game-select menu |
| `SLIDE.EXE` | 48622 | 0x8001D500 | 0x80041D00 | 0x24800 | 0x8002A21C | 394 | `671b4845998f92d046d3da07828a8c26e37697a2` | Slideshow (guess: uses `SEL/LOADSLID.BIN`) |
| `DH1.EXE` | 48030 | 0x8001D500 | 0x800A2D00 | 0x85800 | 0x8006B1C0 | 1014 | `a66e6a75356c296fe81165b137c04277236b62c4` | Die Hard (third-person) |
| `DH2.EXE` | 23 | 0x8001D500 | 0x800B6D00 | 0x99800 | 0x80078EE0 | 1181 | `b403d7ed6d529c32cebd24a9faed4874aec74715` | Die Harder (first-person) |
| `DH3.EXE` | 331 | 0x8001D500 | 0x800B5D00 | 0x98800 | 0x80078328 | 1246 | `2b7b3485205f30ae64702713b726d68d4c6369ea` | Die Hard with a Vengeance (driving) |

`jr $ra` count is the number of `0x03E00008` words, a rough count of functions. No other file on the disc has a meaningful count (two near-identical D3 map files have 4 each, almost certainly data).

## Boot chain (static trace, confirmed at runtime)

Six executables load at 0x8001D500, so only one is in memory at a time. They pass control through **`BOOT.EXE`** (0x80013000–0x8001B800, below everything else) and a small shared block of low RAM that survives every swap. No program uses BIOS `LoadExec`. Each reads EXEs itself with libcd (`CdControl(CdlSetloc)` + `CdRead`: header sector first, then the body) and starts them with BIOS `Exec` (A0 function 0x43).

### The shared block at 0x80012800

| Address | Contents | Written by | Read by |
| --- | --- | --- | --- |
| 0x80012800 | `int` index of the EXE BOOT should run next | SLUS (0x80021468), every program's exit routine | BOOT (0x80013650) |
| 0x80012804 | `CdlFILE[6]` (24 bytes each): disc position and size of each EXE | SLUS only, via `CdSearchFile` (loop at 0x800214B4) | BOOT (indexed); every program (entry 0, to reload BOOT) |

EXE index = order of the name table in SLUS (0x8009C344, 40-byte records): **0 BOOT, 1 LOADER, 2 DH1, 3 DH2, 4 DH3, 5 SLIDE**.

### Flow

1. **`SLUS_001.19`** (started by `SYSTEM.CNF`): calls `CdSearchFile` for all six EXEs and fills 0x80012804 ("Finding position of %s"). It loads entry 0 (**BOOT.EXE**) with `0x800210F4`, gives it stack 0x8001D4F0, writes **1** to 0x80012800 and calls `Exec` (0x80021478).
2. **`BOOT.EXE`** main loop (0x800138A4): reads the index (0x80013640), loads `0x80012804 + index × 24`, **requires `t_addr == 0x8001D500`** (0x800137D4), clears 0x8001E500–0x801FFFFB, gives the program stack 0x801FFFF0 and calls `Exec` (0x80013938). So the first program it runs is **LOADER.EXE**.
3. **Every other program** (LOADER, SLIDE, DH1–3) ends through the same exit routine, linked separately into each one. The routine reloads BOOT.EXE from entry 0, writes the next index to 0x80012800 and calls `Exec` on BOOT, which starts the next program.

| Program | Exit routine (wrapper → body) | Next-EXE indices passed |
| --- | --- | --- |
| LOADER | 0x800365A8 → 0x8003649C | variable at 0x80051D50 (0x80032000), plus 1 (0x80030B94) |
| DH1 | 0x8006B188 → 0x8006B07C | 1 (0x8003E4D0, 0x800689A4, 0x80068C68), 5 (0x80068D70) |
| DH2 | 0x80078EBC → 0x80078DB0 | 5 (0x800239F4), 1 (0x80023A04, 0x8007286C), variable (0x80073CD8) |
| DH3 | 0x80078304 → 0x800781F8 | 5 (0x80025A24), 1 (0x80025A34, 0x80071CB4), variable (0x80073120) |
| SLIDE | 0x8002A1F8 → 0x8002A0EC | 1 (0x8001E748, 0x80024604), variable (0x80025A70) |

LOADER's menu (switch at 0x8001E604) maps choice **0 → 2 (DH1), 1 → 3 (DH2), 2 → 4 (DH3)** into 0x80051D50. Choice 3 stores a value from `s1` (not yet traced).

```
SLUS_001.19 ──(index 1)──> BOOT ──> LOADER ──(2/3/4)──> BOOT ──> DH1 / DH2 / DH3
                            ^                                       │
                            └──── exit routine: 1 → LOADER, 5 → SLIDE (guess: end of game)
```

Not yet explained: the variable indices in DH2, DH3 and SLIDE, and LOADER's choice 3.

### Step 6: emulator check

In the DuckStation CPU debugger, add an **Execute** breakpoint (not Read/Write) at **0x80013660** in BOOT. By then `lw a1, 0x2800(a1)` at 0x80013650 has loaded the next-EXE index, so register **a1** shows it directly. Reset the system so BOOT runs from the start.

Expected `a1`: 1 on boot (LOADER), then 2 / 3 / 4 after choosing Die Hard / Die Harder / Die Hard with a Vengeance in the menu.

For more detail, BOOT's copy of the EXEC header is at 0x8001B34C: `t_addr` at 0x8001B354 should be 0x8001D500, and `t_size` at 0x8001B358 should match the table above.

| Date | Action | Result | Matches? |
| --- | --- | --- | --- |
| 2026-10-25 | Chose Die Hard in the menu | `a1` = 2 at 0x80013660, then DH1 loaded | yes |
| 2026-10-25 | System → Reset | `a1` = 1 at 0x80013660 (BOOT loading LOADER) | yes |
| 2026-10-25 | Chose Die Harder in the menu | `a1` = 3 (0x00000003) at 0x80013660 | yes |
| 2026-10-25 | Chose Die Hard with a Vengeance in the menu | `a1` = 4 at 0x80013660 | yes |

All four values match the static trace, so the boot chain is confirmed at runtime.

**Side observation (guess, needs follow-up):** an earlier *Read* breakpoint on 0x80013938, which is inside BOOT's code, was hit by an ordinary data load at PC 0x8003225C (`lw a0, -0x6(a2)` with a2 = 0x8001393E). At that moment s3 = 2 and s4 = 0x80012800, the same values the exit routine keeps in those registers, but which EXE was running wasn't recorded. A program treating BOOT's memory as data would explain why every program reloads BOOT.EXE from disc before handing back, instead of jumping back into it.

## Data (no code)

| Files | Contents (from names; guess) |
| --- | --- |
| `D1/LOADONCE.BIN`, `D1/CON1/CONCAT1.*`, `D1/CON2/CONCAT2.*` | Die Hard level archives. They start with a count and an offset table (`LOADONCE.BIN`: 4 entries, first at 0x44). |
| `D2/DATA/*`, `D2/MAPS/*WRLD.BIN` | Die Harder level data, maps, motion, sound |
| `D3/DATA/*`, `D3/MAPS/*WRLD.BIN` | Die Hard with a Vengeance level data, maps, sound |
| `SEL/LOADGRAF.BIN`, `SEL/LOADSFX.BIN`, `SEL/LOADSLID.BIN` | Menu/loader graphics, sound, slides (same count + offset table style) |
| `MOVIES/*.STR` | FMV (Mode 2 Form 2 sectors, extracted raw) |

### CD audio tracks named as files

The ISO volume claims 237,034 sectors, but the data track is only 48,864. The extra 20 directory entries point past the data track at the 20 audio tracks. The game probably uses `CdSearchFile` on these names to find where each music track starts, then plays it as CD audio.

`AIRPORT.BIN` (LBA 49014), `NEWWING.BIN`, `UNDERGRO.BIN`, `RUNWAY.BIN`, `PLANE.BIN`, `CHURCH.BIN`, `SNOWCHAS.BIN`, `INTER.BIN`, `HARLEMFI.BIN`, `CENTRALP.BIN`, `CHINATOW.BIN`, `WALLSTRE.BIN`, `QUAYSIDE.BIN`, `SUBWAYFI.BIN`, `AQUADUCT.BIN`, `DHR1.BIN`, `DH1CHINE.BIN`, `DH1MECHR.BIN`, `CNT.BIN`, `HELIDROP.BIN` (LBA 236408)

Sectors outside any file: LBA 18–21 (the ISO path tables, normal) and LBA 48714–48863 (all zero, end-of-track padding).

## Effect on the plan

The original plan assumed one shared main executable plus per-game overlays. The disc instead has seven standalone executables, so:

- Each game is its own splat target with its own header and SHA-1 (`DH1.EXE`, `DH2.EXE`, `DH3.EXE`), rather than an overlay segment.
- Engine code and PsyQ libraries are **linked into each EXE separately** (confirmed for libcd and the exit routine, which appear in every program at different addresses). The same function may exist up to seven times. Phase 2 cross-referencing should look for these duplicates, since a function matched once can be reused for its copies.
- Six EXEs share the address range from 0x8001D500, so one address means a different function in each EXE. A single `config/symbol_addrs.txt` can't hold their names. Each EXE needs its own symbol file, with only the shared low-RAM block (0x80012800) in a common file.
- Which file plays the role of "main" in Phase 3 is open. The smallest real target (`BOOT.EXE`, 36 KB) is a good first splat target for learning, before a full game.

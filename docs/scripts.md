# Scripts you can run yourself

Every analysis script in this repo prints a short answer and writes any long list to a file, so you can rerun it yourself. Run them from the repo root (`C:\src\die-hard-trilogy-decomp`). Paths in `disc/` and `build/` are on your machine only and never committed.

## From PowerShell (Windows)

| What | Command | Output |
| --- | --- | --- |
| Export Ghidra's function table for one EXE (slow, about 1–2 minutes) | `& 'C:\ghidra_12.1.4_PUBLIC\support\analyzeHeadless.bat' C:\src\die-hard-trilogy-decomp\build\ghidra headless -import C:\src\die-hard-trilogy-decomp\disc\DH1.EXE -overwrite -scriptPath C:\src\die-hard-trilogy-decomp\tools\ghidra -postScript ExportFunctions.java C:\src\die-hard-trilogy-decomp\build\ghidra\DH1.funcs.tsv` | `build/ghidra/DH1.funcs.tsv` (address, size, instructions, calls, name) |
| Turn that table into symbols | `python tools/ghidra/tsv2symbols.py build/ghidra/DH1.funcs.tsv DH1.EXE > config/symbol_addrs.dh1.txt` | one `name = addr; // type:func` line per library function |
| Phase 2 steps 4–5: shared code and leaf functions | `python -I tools/recon.py` (or add `shared` / `leaves`) | summary on screen; lists in `docs/phase2/` |
| BIOS calls, references to an address, callers of a function | `python -I tools/re/psxx.py disc/DH1.EXE callers 0x8001E9DC` | one line per hit |
| Check the disc files against the recorded hashes | `cd disc; sha1sum -c ../config/hashes.txt` (Git Bash or WSL) | `OK` per file |

The headless Ghidra project in `build/ghidra/` is separate from your GUI project, so you can run these while Ghidra is open. To rerun a script on an EXE that's already imported, replace `-import ...\DH1.EXE -overwrite` with `-process DH1.EXE -noanalysis`.

## From WSL (Ubuntu)

Open it with `wsl -d Ubuntu-24.04 --cd /mnt/c/src/die-hard-trilogy-decomp`, then:

| What | Command |
| --- | --- |
| Disassemble an address range | `bash tools/re/dis.sh DH1.EXE 0x8001E9DC 0x8001EA74` |
| Check that the toolchain is installed | `bash tools/check-env.sh` |
| Rerun splat for every EXE in the Makefile | `make split` |
| Rebuild and compare with the disc | `make check` (prints `OK` and the SHA-1, or the first differing byte) |
| Show a function's assembly | `bash tools/match.sh asm dh1 func_8004A7C4` |
| Draft C for it with m2c | `bash tools/match.sh m2c dh1 func_8004A7C4` |
| Does my C for it match? (one line) | `bash tools/match.sh score dh1 func_8004A7C4` |
| Side-by-side diff, once | `bash tools/match.sh diff dh1 func_8004A7C4` |
| Live diff that rebuilds when you save the C file (`q` quits) | `bash tools/match.sh watch dh1 func_8004A7C4` |

## Reading the `docs/phase2/` lists

They open in Excel or any spreadsheet as tab-separated files.

- `shared-functions.tsv`: one row per distinct unnamed function body. `games` = how many of DH1/DH2/DH3 contain it, `where` = every `EXE:address` it was found at.
- `leaf-functions.tsv`: unnamed functions of 2–20 instructions that call nothing. `lib` = 1 means it also appears in SLUS or BOOT, so it's probably a library function. `frame`, `gp`, `abs` = sets up a stack frame, reads a `$gp` global, reads a `lui` global.
- `bakeoff-leaves.tsv`: the 25 leaves picked for the Phase 4 compiler test.

In Ghidra, press **G** and type an address from these lists to jump to it.

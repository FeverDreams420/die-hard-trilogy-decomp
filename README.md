# Die Hard Trilogy decompilation *in progress*

A byte-matching decompilation of Die Hard Trilogy (PlayStation, 1996), with a native PC port to follow. See `docs/code-map.md` for where the code lives on the disc and `docs/compiler-notes.md` for the toolchain.

This repository contains no game data. You need your own copy of the game.

## Progress

<p align="center">
  <a href="https://bytematch.dev/FeverDreams420/die-hard-trilogy-decomp"><img alt="Code matched" src="https://bytematch.dev/FeverDreams420/die-hard-trilogy-decomp.svg?label=Code%20matched&measure=matched_code_percent&style=for-the-badge"></a>
  <a href="https://bytematch.dev/FeverDreams420/die-hard-trilogy-decomp"><img alt="Functions" src="https://bytematch.dev/FeverDreams420/die-hard-trilogy-decomp.svg?label=Functions&measure=matched_functions&style=for-the-badge"></a>
</p>
<p align="center">
  <a href="https://bytematch.dev/FeverDreams420/die-hard-trilogy-decomp"><img alt="Die Hard" src="https://bytematch.dev/FeverDreams420/die-hard-trilogy-decomp.svg?label=Die%20Hard&measure=matched_code_percent&category=dh1&style=for-the-badge"></a>
  <a href="https://bytematch.dev/FeverDreams420/die-hard-trilogy-decomp"><img alt="Die Harder" src="https://bytematch.dev/FeverDreams420/die-hard-trilogy-decomp.svg?label=Die%20Harder&measure=matched_code_percent&category=dh2&style=for-the-badge"></a>
  <a href="https://bytematch.dev/FeverDreams420/die-hard-trilogy-decomp"><img alt="With a Vengeance" src="https://bytematch.dev/FeverDreams420/die-hard-trilogy-decomp.svg?label=With%20a%20Vengeance&measure=matched_code_percent&category=dh3&style=for-the-badge"></a>
</p>

The badges count bytes of each game's code that build from matching C, and link to the full breakdown on [bytematch.dev](https://bytematch.dev/FeverDreams420/die-hard-trilogy-decomp). `python3 tools/progress.py` prints the same figures from a local build.

`make report` writes them to `build/report.json` in objdiff's report format, with one unit per C file and one category per game. `make upload-progress` checks the build, then sends that report for the current commit, which updates the badges. It needs the project's upload token, either in `BYTEMATCH_TOKEN` or in `~/.bytematch_token`, and no uncommitted changes. Keep the token out of the repo.

If you want to help, you can see the code map here: [View Code Map](docs/code-map.md)


## Build environment

The project builds under **WSL2 (Ubuntu 24.04)**. The repo lives on the Windows side at `C:\src\die-hard-trilogy-decomp`, which WSL sees as `/mnt/c/src/die-hard-trilogy-decomp`, so Windows tools (Ghidra, DuckStation) and the Linux build share one copy.

Ubuntu packages:

```
sudo apt install binutils-mips-linux-gnu make git python3 python3-venv
```

## Setup

1. Extract the disc's files into `disc/` (git-ignored), then check them against the known hashes:
   ```
   .venv/bin/python tools/extract_disc.py "/path/to/Die Hard Trilogy (USA) (Rev 1) (Track 01).bin" disc
   cd disc && sha1sum -c ../config/hashes.txt
   ```
2. Copy the Linux builds of the PS1 GCC compilers into `tools/gcc-<version>/` (git-ignored).
3. Install the Python tools into a virtual environment (see `tools/README.md` once it exists).

## Layout

| Folder | Contents |
| --- | --- |
| `config/` | splat configs, `symbol_addrs.txt`, `hashes.txt` |
| `asm/` | splat output (generated, git-ignored) |
| `src/` | C sources: `main/`, then one folder per game |
| `include/` | game headers; `include/psyq/` for Sony SDK headers |
| `tools/` | maspsx, compilers, scripts |
| `docs/` | code map, findings, compiler notes |
| `disc/` | your extracted game files (git-ignored) |
| `build/` | build outputs (git-ignored) |

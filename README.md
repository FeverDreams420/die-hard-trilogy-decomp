# Die Hard Trilogy decompilation *in progress*

A byte-matching decompilation of Die Hard Trilogy (PlayStation, 1996), with a native PC port to follow.

This repository contains no game data. You need your own copy of the game.

If you want to help, you can see the code map here: [Click Here](docs/phase2/code-map.md.md)

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

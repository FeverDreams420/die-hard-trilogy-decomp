# asm-differ settings (tools/asm-differ/diff.py reads this from the repo root).
# Which EXE to diff comes from the DIFF_EXE environment variable (boot, dh1, ...);
# tools/match.sh sets it. Compares disc/<EXE> with build/<EXE> using build/<exe>.map.
import os

FILES = {"boot": "BOOT.EXE", "dh1": "DH1.EXE"}


def apply(config, args):
    exe = os.environ.get("DIFF_EXE", "dh1")
    config["baseimg"] = f"disc/{FILES[exe]}"
    config["myimg"] = f"build/{FILES[exe]}"
    config["mapfile"] = f"build/{exe}.map"
    config["source_directories"] = ["src", "include"]
    config["arch"] = "mipsel"
    config["map_format"] = "gnu"
    config["objdump_executable"] = "mipsel-linux-gnu-objdump"
    config["make_command"] = ["make"]

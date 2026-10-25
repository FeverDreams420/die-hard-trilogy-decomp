#!/usr/bin/env python3
"""Phase 2 steps 4-5: shared functions across EXEs, and the leaf-function shortlist.

Reads the Ghidra tables (build/ghidra/<EXE>.funcs.tsv, from ExportFunctions.java)
and the EXEs in disc/. Writes the full lists to docs/phase2/ and prints only a
short summary.

How functions are compared: the same C compiled into two EXEs gives the same
instructions except where the linker filled in an address. So each word is
masked before hashing: jal/j targets, lui immediates, the low half of a
lui/addiu (or lui/lw) address pair, and $gp offsets. Functions with equal
masked bytes are treated as the same function. This is a heuristic: two tiny
functions with the same shape but different globals also compare equal.

Usage (from the repo root, Windows or WSL):
    python -I tools/recon.py            # both lists
    python -I tools/recon.py shared     # step 4 only
    python -I tools/recon.py leaves     # step 5 only
"""
import collections
import csv
import hashlib
import os
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EXES = [  # (short name, disc file, Ghidra table)
    ("SLUS", "SLUS_001.19", "SLUS_001"),
    ("BOOT", "BOOT.EXE", "BOOT"),
    ("LOADER", "LOADER.EXE", "LOADER"),
    ("SLIDE", "SLIDE.EXE", "SLIDE"),
    ("DH1", "DH1.EXE", "DH1"),
    ("DH2", "DH2.EXE", "DH2"),
    ("DH3", "DH3.EXE", "DH3"),
]
GAMES = ("DH1", "DH2", "DH3")
GP, SP = 28, 29
LEAF_MAX = 20  # instructions
BAKEOFF = 25  # leaves picked for the Phase 4 bake-off
OUT = os.path.join(ROOT, "docs", "phase2")


def load_exe(path):
    data = open(path, "rb").read()
    t_addr = struct.unpack_from("<I", data, 0x18)[0]
    return data, t_addr


def mask_words(words):
    """Return the words with link-time addresses zeroed, plus feature flags."""
    out, hi_regs = [], set()
    uses_gp = uses_abs = frame = False
    for w in words:
        op, rs, rt = w >> 26, (w >> 21) & 31, (w >> 16) & 31
        m = w
        if op in (2, 3):  # j, jal
            m = w & 0xFC000000
        elif op == 0x0F:  # lui
            m = w & 0xFFFF0000
            hi_regs.add(rt)
            uses_abs = True
        elif op >= 0x08:  # I-type: addiu, ori, loads, stores, ...
            if rs == GP and op not in (0x04, 0x05):
                m = w & 0xFFFF0000
                uses_gp = True
            elif rs in hi_regs and op not in (0x04, 0x05, 0x06, 0x07):
                m = w & 0xFFFF0000
            if op == 0x09 and rs == SP and rt == SP:
                frame = True
            # a load or ALU op overwrites rt; a store or branch does not
            if op < 0x28 and op not in (0x04, 0x05, 0x06, 0x07):
                hi_regs.discard(rt)
        else:  # R-type / special: rd is overwritten
            hi_regs.discard((w >> 11) & 31)
        out.append(m)
    return out, uses_gp, uses_abs, frame


def read_funcs():
    funcs = []  # dicts
    for short, disc, tsv in EXES:
        data, t_addr = load_exe(os.path.join(ROOT, "disc", disc))
        with open(os.path.join(ROOT, "build", "ghidra", f"{tsv}.funcs.tsv"), newline="") as f:
            for r in csv.DictReader(f, delimiter="\t"):
                addr = int(r["addr"], 16)
                if addr < 0x80000000:
                    continue  # the loader's GTE macro labels
                size = int(r["size"], 16)
                off = addr - t_addr + 0x800
                raw = data[off:off + size - size % 4]
                words = list(struct.unpack(f"<{len(raw) // 4}I", raw))
                masked, uses_gp, uses_abs, frame = mask_words(words)
                funcs.append({
                    "exe": short, "addr": addr, "size": size,
                    "insns": int(r["insns"]), "calls": int(r["calls"]),
                    "named": r["source"] != "DEFAULT", "name": r["name"],
                    "hash": hashlib.sha1(struct.pack(f"<{len(masked)}I", *masked)).hexdigest()[:12],
                    "gp": uses_gp, "abs": uses_abs, "frame": frame,
                })
    return funcs


def groups_of(funcs):
    g = collections.defaultdict(list)
    for f in funcs:
        g[f["hash"]].append(f)
    return g


def label(group):
    names = sorted({f["name"] for f in group if f["named"]})
    return names[0] if names else ""


def where(group):
    return " ".join(f"{f['exe']}:{f['addr']:08X}" for f in group)


def likely_lib(exes):
    # SLUS and BOOT are small loaders that are almost all PsyQ code, so a body
    # that also appears there is probably a library function the signatures missed
    return bool(exes & {"SLUS", "BOOT"})


def shared(funcs):
    groups = groups_of(funcs)
    rows = []
    for h, grp in groups.items():
        exes = {f["exe"] for f in grp}
        if not any(not f["named"] for f in grp):
            continue  # pure library, already named
        rows.append((h, grp, exes))
    rows.sort(key=lambda r: (-len(r[2] & set(GAMES)), -len(r[2]), -r[1][0]["insns"]))
    os.makedirs(OUT, exist_ok=True)
    path = os.path.join(OUT, "shared-functions.tsv")
    with open(path, "w", newline="") as f:
        f.write("hash\tgames\texes\tinsns\tcalls\tsuggested_name\twhere\n")
        for h, grp, exes in rows:
            f.write(f"{h}\t{len(exes & set(GAMES))}\t{len(exes)}\t{grp[0]['insns']}\t{grp[0]['calls']}"
                    f"\t{label(grp)}\t{where(sorted(grp, key=lambda x: [e[0] for e in EXES].index(x['exe'])))}\n")
    # summary
    unnamed = [f for f in funcs if not f["named"]]
    print(f"step 4: {len(unnamed)} unnamed functions in {len(EXES)} EXEs -> {len(rows)} distinct bodies")
    for n in (3, 2, 1, 0):
        sel = [r for r in rows if len(r[2] & set(GAMES)) == n]
        print(f"  in {n} of DH1/DH2/DH3: {len(sel)} bodies"
              + (f" ({sum(1 for r in sel if len(r[2]) > 3)} also in BOOT/LOADER/SLIDE/SLUS)" if n == 3 else ""))
    missed = [r for r in rows if label(r[1])]
    print(f"  unnamed bodies that match a signature-named function in another EXE: {len(missed)}")
    for exe in [e[0] for e in EXES]:
        mine = [f for f in unnamed if f["exe"] == exe]
        uniq = sum(1 for f in mine if {g["exe"] for g in groups[f["hash"]]} == {exe})
        print(f"  {exe:6} unnamed {len(mine):4}, only in this EXE {uniq:4}")
    print(f"  -> {os.path.relpath(path, ROOT)}")


def leaves(funcs):
    groups = groups_of(funcs)
    rows = []
    for h, grp in groups.items():
        f0 = grp[0]
        if any(f["named"] for f in grp) or f0["calls"] or f0["insns"] > LEAF_MAX or f0["insns"] < 2:
            continue
        exes = {f["exe"] for f in grp}
        rows.append((h, grp, exes))
    # functions in more games first (one match then covers several EXEs), then bigger
    rows.sort(key=lambda r: (-len(r[2] & set(GAMES)), -len(r[2]), -r[1][0]["insns"]))
    path = os.path.join(OUT, "leaf-functions.tsv")
    with open(path, "w", newline="") as f:
        f.write("hash\tgames\texes\tlib\tinsns\tframe\tgp\tabs\twhere\n")
        for h, grp, exes in rows:
            g = grp[0]
            f.write(f"{h}\t{len(exes & set(GAMES))}\t{len(exes)}\t{int(likely_lib(exes))}\t{g['insns']}"
                    f"\t{int(g['frame'])}\t{int(g['gp'])}\t{int(g['abs'])}\t{where(grp)}\n")
    # bake-off shortlist: game code only, every $gp and stack-frame leaf, then the rest
    game = [r for r in rows if not likely_lib(r[2]) and r[1][0]["insns"] >= 3]
    pick = [r for r in game if r[1][0]["gp"] or r[1][0]["frame"]]
    pick += [r for r in game if r not in pick][:BAKEOFF - len(pick)]
    path2 = os.path.join(OUT, "bakeoff-leaves.tsv")
    with open(path2, "w", newline="") as f:
        f.write("exe\taddr\tinsns\tframe\tgp\tabs\talso_in\n")
        for h, grp, exes in pick:
            g = grp[0]
            f.write(f"{g['exe']}\t0x{g['addr']:08X}\t{g['insns']}\t{int(g['frame'])}\t{int(g['gp'])}"
                    f"\t{int(g['abs'])}\t{where(grp[1:])}\n")
    print(f"step 5: {len(rows)} distinct unnamed leaf bodies (2-{LEAF_MAX} instructions, no calls)")
    print(f"  in all 3 games {sum(1 for r in rows if len(r[2] & set(GAMES)) == 3)},"
          f" use $gp {sum(1 for r in rows if r[1][0]['gp'])},"
          f" use lui globals {sum(1 for r in rows if r[1][0]['abs'])},"
          f" have a stack frame {sum(1 for r in rows if r[1][0]['frame'])}")
    print(f"  likely library (also in SLUS or BOOT) {sum(1 for r in rows if likely_lib(r[2]))}")
    print(f"  -> {os.path.relpath(path, ROOT)}, {len(pick)} picked -> {os.path.relpath(path2, ROOT)}")


def main():
    what = sys.argv[1:] or ["shared", "leaves"]
    funcs = read_funcs()
    if "shared" in what:
        shared(funcs)
    if "leaves" in what:
        leaves(funcs)


if __name__ == "__main__":
    main()

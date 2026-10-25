#!/usr/bin/env python3
"""Extract the ISO9660 filesystem from a PS1 data track (MODE2/2352 .bin).

Usage (from the repo root, inside WSL):
    .venv/bin/python tools/extract_disc.py "/mnt/c/dumps/<game> (Track 01).bin" disc

Writes every file into the output folder, plus `_layout.csv` (path, start LBA,
sector count, size, form) and a report of disc regions no file covers.

How a PS1 sector is laid out (2352 bytes raw):
    0x000  12 bytes  sync pattern
    0x00C   4 bytes  header (minute, second, frame, mode=2)
    0x010   8 bytes  subheader (file, channel, submode, coding; stored twice)
    0x018 2048 bytes user data      <- Mode 2 Form 1: normal files
          or 2324 bytes user data   <- Mode 2 Form 2: XA audio / STR video
Form 2 is flagged by bit 5 (0x20) of the submode byte at offset 0x12. Form 2
files are written raw, 2336 bytes per sector (subheader onward), which is
what dumpsxiso and emulators expect.
"""

import csv
import os
import struct
import sys

RAW = 2352
DATA = 2048
FORM2_RAW = 2336
SUBMODE_FORM2 = 0x20


class Disc:
    def __init__(self, path):
        self.f = open(path, "rb")
        self.sectors = os.path.getsize(path) // RAW

    def raw(self, lba):
        self.f.seek(lba * RAW)
        return self.f.read(RAW)

    def data(self, lba):
        return self.raw(lba)[24:24 + DATA]

    def is_form2(self, lba):
        return bool(self.raw(lba)[0x12] & SUBMODE_FORM2)


def parse_dir(disc, lba, size, prefix, out):
    """Walk one directory extent; append (path, lba, size, is_dir) to out."""
    for i in range((size + DATA - 1) // DATA):
        sector = disc.data(lba + i)
        pos = 0
        while pos < DATA:
            rec_len = sector[pos]
            if rec_len == 0:  # records never cross sectors; rest is padding
                break
            ext_lba = struct.unpack_from("<I", sector, pos + 2)[0]
            ext_size = struct.unpack_from("<I", sector, pos + 10)[0]
            flags = sector[pos + 25]
            name_len = sector[pos + 32]
            name = sector[pos + 33:pos + 33 + name_len]
            pos += rec_len
            if name in (b"\x00", b"\x01"):  # "." and ".."
                continue
            name = name.decode("ascii").split(";")[0]
            path = prefix + name
            if flags & 0x02:
                out.append((path + "/", ext_lba, ext_size, True))
                parse_dir(disc, ext_lba, ext_size, path + "/", out)
            else:
                out.append((path, ext_lba, ext_size, False))


def main():
    if len(sys.argv) != 3:
        sys.exit(__doc__)
    disc = Disc(sys.argv[1])
    out_dir = sys.argv[2]

    pvd = disc.data(16)
    if pvd[1:6] != b"CD001":
        sys.exit("No ISO9660 volume descriptor at sector 16; is this the data track?")
    print("Volume ID:", pvd[40:72].decode("ascii").strip())
    print("Volume size:", struct.unpack_from("<I", pvd, 80)[0], "sectors;",
          "track has", disc.sectors)

    root = pvd[156:156 + 34]
    root_lba = struct.unpack_from("<I", root, 2)[0]
    root_size = struct.unpack_from("<I", root, 10)[0]
    entries = [("/", root_lba, root_size, True)]
    parse_dir(disc, root_lba, root_size, "", entries)

    used = [False] * disc.sectors
    for lba in range(18):  # system area (0-15) and volume descriptors (16-17)
        used[lba] = True

    rows = []
    for path, lba, size, is_dir in entries:
        count = max(1, (size + DATA - 1) // DATA)
        for s in range(lba, min(lba + count, disc.sectors)):
            used[s] = True
        if is_dir:
            continue
        if lba + count > disc.sectors:
            # Points past the data track, e.g. at a CD audio track. Nothing to extract.
            rows.append((path, lba, count, size, "outside"))
            continue
        form2 = any(disc.is_form2(lba + s) for s in range(count))
        dest = os.path.join(out_dir, path)
        os.makedirs(os.path.dirname(dest) or out_dir, exist_ok=True)
        with open(dest, "wb") as f:
            if form2:
                for s in range(count):
                    f.write(disc.raw(lba + s)[16:16 + FORM2_RAW])
            else:
                buf = b"".join(disc.data(lba + s) for s in range(count))
                f.write(buf[:size])
        rows.append((path, lba, count, size, "form2" if form2 else "form1"))

    rows.sort(key=lambda r: r[1])
    with open(os.path.join(out_dir, "_layout.csv"), "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["path", "lba", "sectors", "size", "form"])
        w.writerows(rows)

    print(f"\n{'LBA':>7} {'sectors':>7} {'size':>10} form   path")
    for path, lba, count, size, form in rows:
        print(f"{lba:>7} {count:>7} {size:>10} {form}  {path}")

    # Regions no file or directory claims. Games sometimes read these by LBA.
    gaps, start = [], None
    for lba, u in enumerate(used + [True]):
        if not u and start is None:
            start = lba
        elif u and start is not None:
            gaps.append((start, lba - start))
            start = None
    print("\nSectors not covered by any file:")
    for start, count in gaps:
        nonzero = any(any(disc.data(start + s)) for s in range(count))
        print(f"  LBA {start}-{start + count - 1} ({count} sectors)"
              f"{'  <-- contains data' if nonzero else '  (all zero)'}")
    if not gaps:
        print("  none")


if __name__ == "__main__":
    main()

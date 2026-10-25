#!/usr/bin/env bash
# dis.sh EXE START STOP  -- disassemble a PS-X EXE address range (run from repo root in WSL: bash tools/re/dis.sh DH1.EXE 0x8001E9DC 0x8001EA74)
exe="$1"; start="$2"; stop="$3"
mkdir -p build/re
txt="build/re/$(basename "$exe").text"
[ -f "$txt" ] || tail -c +2049 "disc/$exe" > "$txt"
vma=$(python3 -c "import struct;print(hex(struct.unpack_from('<I',open('disc/$exe','rb').read(),0x18)[0]))")
mipsel-linux-gnu-objdump -D -b binary -m mips:3000 -EL --adjust-vma="$vma" \
    --start-address="$start" --stop-address="$stop" "$txt" \
    | grep -E '^ *8' | sed -E 's/^ *([0-9a-f]+):\s+[0-9a-f]+\s+/\1  /'

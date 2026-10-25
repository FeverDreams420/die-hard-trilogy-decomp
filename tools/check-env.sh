#!/usr/bin/env bash
# Checks that every tool the build needs is present. Run from the repo root inside WSL:
#   bash tools/check-env.sh
cd "$(dirname "$0")/.." || exit 1

PY=.venv/bin/python
status=0

check() {
    local name="$1"; shift
    if out=$("$@" 2>&1); then
        printf '  OK    %-18s %s\n' "$name" "$(echo "$out" | head -1)"
    else
        printf '  FAIL  %-18s %s\n' "$name" "$(echo "$out" | tail -1)"
        status=1
    fi
}

echo "Binutils"
check mipsel-as        mipsel-linux-gnu-as --version
check mipsel-ld        mipsel-linux-gnu-ld --version
check mipsel-objcopy   mipsel-linux-gnu-objcopy --version

echo "Python tools"
check splat            $PY -m splat --version
check maspsx           $PY tools/maspsx/maspsx.py --help
check m2c              $PY tools/m2c/m2c.py --help
check asm-differ       $PY tools/asm-differ/diff.py --help
check permuter         $PY tools/decomp-permuter/permuter.py --help

echo "Compilers"
found=0
for d in tools/gcc-*/; do
    [ -x "$d/cc1" ] || continue
    found=1
    check "$(basename "$d")" bash -c "echo 'int f(void){return 1;}' | $d/cc1 -quiet -O2 -o /dev/null && echo cc1 runs"
done
[ $found = 1 ] || { echo "  FAIL  no tools/gcc-*/cc1 found"; status=1; }

exit $status

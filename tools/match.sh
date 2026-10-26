#!/usr/bin/env bash
# Helpers for matching one function.
# Run in WSL from the repo root. <exe> is the Makefile name: boot, dh1, ...
#
#   bash tools/match.sh asm   <exe> <func>   print the function's splat asm file
#   bash tools/match.sh m2c   <exe> <func>   draft C from m2c into build/match/<func>.c, and print it
#   bash tools/match.sh build                rebuild (make), errors only
#   bash tools/match.sh score <exe> <func>   rebuild, then one line: MATCH, or how many instructions differ
#   bash tools/match.sh diff  <exe> <func>   rebuild, then a one-shot side-by-side diff (stops at the first jr ra)
#   bash tools/match.sh watch <exe> <func>   interactive diff.py that rebuilds when you save (q to quit)
#   bash tools/match.sh check                make check (every EXE must still match)
set -o pipefail
cd "$(dirname "$0")/.." || exit 1
PY=.venv/bin/python
cmd="$1" exe="$2" func="$3"

asm_path() {
    local f
    f=$(find "asm/$exe/nonmatchings" -name "$func.s" 2>/dev/null | head -1)
    [ -n "$f" ] || { echo "no asm/$exe/nonmatchings/**/$func.s" >&2; exit 1; }
    echo "$f"
}

build() { make -s 2>&1 | grep -vE '^(cpp|tools/gcc|mipsel|\.venv)' ; return "${PIPESTATUS[0]}"; }

case "$cmd" in
    asm)   cat "$(asm_path)" ;;
    m2c)   mkdir -p build/match
           $PY tools/m2c/m2c.py --target mipsel-gcc-c "$(asm_path)" > "build/match/$func.c" && cat "build/match/$func.c" ;;
    build) build ;;
    score) build >/dev/null || { build; exit 1; }; $PY tools/funcdiff.py "$exe" "$func" ;;
    diff)  build >/dev/null || { build; exit 1; }
           DIFF_EXE="$exe" $PY tools/asm-differ/diff.py --no-pager --format plain --stop-at-ret "$func" "${@:4}" ;;
    watch) DIFF_EXE="$exe" $PY tools/asm-differ/diff.py -mw "$func" "${@:4}" ;;
    check) make -s check 2>&1 | grep -E '^(OK|FAIL)|rror' ;;
    *)     sed -n '2,12p' "$0"; exit 1 ;;
esac

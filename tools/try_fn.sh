#!/bin/bash
# Compile one game TU and disassemble it, without running the whole link/SHA gate.
# Usage: tools/try_fn.sh 800238BC
set -e
R="$(cd "$(dirname "$0")/.." && pwd)"
FN="$1"
cd "$R"
"$R/.tools/bin/ninja" "build/GEDE01/src/game/game_fn_${FN}.o" >/dev/null
"$R/build/binutils/powerpc-eabi-objdump" -d -r "$R/build/GEDE01/src/game/game_fn_${FN}.o"

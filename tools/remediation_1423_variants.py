#!/usr/bin/env python3
"""Compile all case-8/9 local-declaration permutations for fn_80196918."""
import itertools
import json
import re
import subprocess
from pathlib import Path

root = Path(__file__).resolve().parent.parent
source = root / "src/game/game_fn_80196918.c"
original = source.read_text()
pattern = re.compile(
    r"(?P<head>    case 8:\n    case 9: \{\n)"
    r"(?:        (?:void\* entry|u8 (?:first|second)\[6\]|u8 values\[196\]);\n){4}"
)
declarations = {
    "entry": "        void* entry;\n",
    "first": "        u8 first[6];\n",
    "second": "        u8 second[6];\n",
    "values": "        u8 values[196];\n",
}

try:
    for order in itertools.permutations(declarations):
        replacement = r"\g<head>" + "".join(declarations[name] for name in order)
        variant, count = pattern.subn(replacement, original, count=1)
        if count != 1:
            raise RuntimeError("declaration block not found")
        source.write_text(variant)
        subprocess.run(
            [str(root / ".tools/bin/ninja"), "build/GEDE01/src/game/game_fn_80196918.o"],
            cwd=root, check=True, stdout=subprocess.DEVNULL,
        )
        output = root / "build/GEDE01/remediation-1423-r2-variant.json"
        subprocess.run(
            [str(root / "build/tools/objdiff-cli"), "diff", "-p", str(root),
             "-u", "main/game/game_fn_80196918", "fn_80196918", "-o",
             str(output), "--format", "json"],
            cwd=root, check=True, stdout=subprocess.DEVNULL,
        )
        data = json.loads(output.read_text())
        symbol = next(s for s in data["left"]["symbols"] if s["name"] == "fn_80196918")
        diffs = sum(i.get("diff_kind") not in (None, "DIFF_NONE") for i in symbol["instructions"])
        print(f"order={','.join(order)} match_percent={symbol['match_percent']} differing_rows={diffs}")
finally:
    source.write_text(original)
    subprocess.run(
        [str(root / ".tools/bin/ninja"), "build/GEDE01/src/game/game_fn_80196918.o"],
        cwd=root, check=True, stdout=subprocess.DEVNULL,
    )

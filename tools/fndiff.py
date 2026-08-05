#!/usr/bin/env python3
"""Print a side-by-side objdiff instruction/relocation comparison for one function.

Usage: python3 tools/fndiff.py game/game_fn_800238BC.c fn_800238BC
"""
import json
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
OBJDIFF = ROOT / "build" / "tools" / "objdiff-cli"


def reloc_of(ins):
    rel = ins.get("relocation")
    if not rel:
        return ""
    tgt = rel.get("target", {})
    return f"[{tgt.get('name')}+{tgt.get('address', 0)} t{rel.get('type')}]"


def main():
    unit, symbol = sys.argv[1], sys.argv[2]
    out = ROOT / "build" / "GEDE01" / f"fndiff_{symbol}.json"
    subprocess.run(
        [str(OBJDIFF), "diff", "-p", str(ROOT), "-u", f"main/{unit[:-2]}",
         symbol, "-o", str(out), "--format", "json"],
        check=True, cwd=ROOT,
    )
    d = json.loads(out.read_text())

    def rows(side):
        s = d.get(side) or {}
        for sym in s.get("symbols", []):
            if sym.get("name") == symbol:
                return sym
        return {}

    left, right = rows("left"), rows("right")
    print(f"target {left.get('size')} bytes  base {right.get('size')} bytes  "
          f"match {left.get('match_percent')}")
    li = left.get("instructions", [])
    ri = right.get("instructions", [])
    for i in range(max(len(li), len(ri))):
        a = li[i] if i < len(li) else {}
        b = ri[i] if i < len(ri) else {}
        ai = a.get("instruction", {})
        bi = b.get("instruction", {})
        mark = " " if a.get("diff_kind") in (None, "DIFF_NONE") else "*"
        at = f"{ai.get('formatted','')} {reloc_of(ai)}".strip()
        bt = f"{bi.get('formatted','')} {reloc_of(bi)}".strip()
        print(f"{mark} {i*4:#06x}  {at:<52} | {bt}")


if __name__ == "__main__":
    main()

#!/usr/bin/env python3
"""Run Metrowerks under wibo and normalize constructor subsection names."""

from __future__ import annotations

import subprocess
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
WIBO = ROOT / ".tools" / "bin" / "wibo"


def output_object(args: list[str]) -> Path | None:
    if "-c" not in args or "-o" not in args:
        return None
    source = next((Path(arg) for arg in args if arg.endswith((".c", ".cpp"))), None)
    if source is None:
        return None
    output = Path(args[args.index("-o") + 1])
    return output / source.with_suffix(".o").name if output.suffix.lower() != ".o" else output


def normalize_runtime_sections(path: Path) -> None:
    payload = path.read_bytes()
    replacements = {
        b".ctors$10\0": b".ctors\0\0\0\0",
        b".dtors$10\0": b".dtors\0\0\0\0",
        b".dtors$15\0": b".dtors\0\0\0\0",
    }
    for old, new in replacements.items():
        if old not in payload:
            raise SystemExit(f"expected MWCC section name {old[:-1].decode()} in {path}")
        payload = payload.replace(old, new)
    path.write_bytes(payload)


def main() -> None:
    if not WIBO.is_file():
        raise SystemExit("wibo is missing; run: python3 tools/bootstrap.py")
    args = sys.argv[1:]
    result = subprocess.run([str(WIBO), *args], check=False)
    if result.returncode:
        raise SystemExit(result.returncode)
    output = output_object(args)
    if output is not None and output.name == "__init_cpp_exceptions.o":
        normalize_runtime_sections(output)


if __name__ == "__main__":
    main()

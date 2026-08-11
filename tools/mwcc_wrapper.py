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


def set_section_alignment(path: Path, section_name: bytes, alignment: int) -> None:
    """Correct split-object alignment metadata without changing generated code/data."""
    payload = bytearray(path.read_bytes())
    shoff = int.from_bytes(payload[32:36], "big")
    shentsize = int.from_bytes(payload[46:48], "big")
    shnum = int.from_bytes(payload[48:50], "big")
    shstrndx = int.from_bytes(payload[50:52], "big")
    shstr = shoff + shstrndx * shentsize
    names_offset = int.from_bytes(payload[shstr + 16 : shstr + 20], "big")
    for index in range(shnum):
        header = shoff + index * shentsize
        name_offset = int.from_bytes(payload[header : header + 4], "big")
        name_start = names_offset + name_offset
        name_end = payload.index(0, name_start)
        if payload[name_start:name_end] == section_name:
            payload[header + 32 : header + 36] = alignment.to_bytes(4, "big")
            path.write_bytes(payload)
            return
    raise SystemExit(f"section {section_name.decode()} not found in {path}")


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
    if output is not None and output.name in (
        "game_fn_8000EE9C.o",
        "game_fn_8000EFC4.o",
        "game_fn_800122F8.o",
        "game_fn_80015568.o",
        "game_fn_80015BE0.o",
        "game_fn_80015D40.o",
        "game_fn_8001C078.o",
        "game_fn_8001CC00.o",
        "game_fn_8001CE14.o",
        "game_fn_8001D3F8.o",
        "game_fn_8001D4C4.o",
        "game_data_8023D77C.o",
        "game_data_8023D884.o",
        "game_fn_8001E644.o",
        "game_data_8023DA2C.o",
        "game_fn_80020E94.o",
        "game_data_8023DAB4.o",
        "game_data_8023DD84.o",
        "game_data_8023DFAC.o",
        "game_data_8023E0E8.o",
        "game_fn_80037AF4.o",
    ):
        set_section_alignment(output, b".data", 4)
        payload = output.read_bytes().replace(b".comment\0", b".ignored\0")
        output.write_bytes(payload)


if __name__ == "__main__":
    main()

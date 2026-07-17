#!/usr/bin/env python3
"""Emit a copyright-neutral JSON section inventory from a GameCube DOL."""

from __future__ import annotations

import argparse
import hashlib
import json
import struct
from pathlib import Path


def words(header: bytes, offset: int, count: int) -> list[int]:
    return list(struct.unpack_from(f">{count}I", header, offset))


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("dol", type=Path)
    parser.add_argument("--output", type=Path)
    args = parser.parse_args()
    data = args.dol.read_bytes()
    if len(data) < 0x100:
        raise SystemExit("DOL is smaller than its header")
    offsets = words(data, 0x00, 7) + words(data, 0x1C, 11)
    addresses = words(data, 0x48, 7) + words(data, 0x64, 11)
    sizes = words(data, 0x90, 7) + words(data, 0xAC, 11)
    sections = []
    for index, (offset, address, size) in enumerate(zip(offsets, addresses, sizes)):
        if size == 0:
            continue
        if offset + size > len(data):
            raise SystemExit(f"Section {index} extends past end of file")
        sections.append({"kind": "text" if index < 7 else "data", "index": index if index < 7 else index - 7,
                         "offset": f"0x{offset:X}", "address": f"0x{address:08X}", "size": f"0x{size:X}"})
    report = {
        "size": len(data),
        "sha1": hashlib.sha1(data).hexdigest(),
        "entry_point": f"0x{words(data, 0xE0, 1)[0]:08X}",
        "bss": {"address": f"0x{words(data, 0xD8, 1)[0]:08X}", "size": f"0x{words(data, 0xDC, 1)[0]:X}"},
        "sections": sections,
    }
    rendered = json.dumps(report, indent=2) + "\n"
    if args.output:
        args.output.write_text(rendered, encoding="utf-8")
    else:
        print(rendered, end="")


if __name__ == "__main__":
    main()


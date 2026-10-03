#!/usr/bin/env python3
"""Synthetic fail-closed tests for the accepted static-pool helper."""

import importlib.util
import struct
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]
SPEC = importlib.util.spec_from_file_location(
    "undefine_elf_static_pool", ROOT / "tools/undefine_elf_static_pool.py"
)
MODULE = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(MODULE)
TARGET = "pool_80300000"


def fixture(*, pool_type=1, flags=3, pool=b"\0" * 8, target_size=8,
            owner=None, incoming=None, outgoing=False):
    names = b"\0pool_80300000\0owner\0"
    symbols = [(0, 0, 0, 0, 0, 0), (0, 0, 0, 3, 0, 1)]
    if owner is not None:
        symbols.append((15, owner[0], owner[1], 1, 0, 1))
    target_index = len(symbols)
    symbols.append((1, 0, target_size, 0x11, 0, 1))
    symbol_data = b"".join(struct.pack(">IIIBBH", *entry) for entry in symbols)
    text = b"\0" * 4
    reloc = b""
    reloc_owner = 1 if outgoing else 2
    if incoming is not None or outgoing:
        reference = target_index if incoming is None else incoming
        reloc = struct.pack(">III", 0, (reference << 8) | 1, 0)

    payloads = {
        1: pool if pool_type != 8 else b"", 2: text, 3: reloc,
        4: symbol_data, 5: names, 6: b"\0",
    }
    offsets = {}
    cursor = 52
    body = bytearray()
    for index in range(1, 7):
        value = payloads[index]
        offsets[index] = cursor
        body.extend(value)
        cursor += len(value)
    shoff = (cursor + 3) & ~3
    body.extend(b"\0" * (shoff - cursor))
    sections = [
        (0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
        (0, pool_type, flags, 0, offsets[1], len(pool), 0, 0, 4, 0),
        (0, 1, 6, 0, offsets[2], len(text), 0, 0, 4, 0),
        (0, 4, 0, 0, offsets[3], len(reloc), 4, reloc_owner, 4, 12),
        (0, 2, 0, 0, offsets[4], len(symbol_data), 5, target_index, 4, 16),
        (0, 3, 0, 0, offsets[5], len(names), 0, 0, 1, 0),
        (0, 3, 0, 0, offsets[6], 1, 0, 0, 1, 0),
    ]
    header = bytearray(52)
    header[:7] = b"\x7fELF\x01\x02\x01"
    struct.pack_into(">HHI", header, 16, 1, 20, 1)
    struct.pack_into(">I", header, 32, shoff)
    struct.pack_into(">HHHHHH", header, 40, 52, 0, 0, 40, len(sections), 6)
    return bytes(
        header + body + b"".join(struct.pack(">10I", *section) for section in sections)
    )


def mapping(extra="", size=8, address=0x80300000):
    return (
        f"{TARGET} = .bss:0x{address:08X}; // type:object size:0x{size:X}\n"
        f"{extra}"
    )


def rejects(label, data, symbols):
    try:
        MODULE.externalize(data, TARGET, symbols)
    except ValueError:
        return
    raise AssertionError(f"{label}: unsafe fixture was accepted")


def main():
    for section_type in (1, 8):
        result = MODULE.externalize(fixture(pool_type=section_type), TARGET, mapping())
        shoff = struct.unpack_from(">I", result, 32)[0]
        kind = struct.unpack_from(">I", result, shoff + 44)[0]
        size = struct.unpack_from(">I", result, shoff + 60)[0]
        assert kind == section_type and size == 0, "empty section type must be retained"

    cases = [
        ("nonzero PROGBITS", fixture(pool=b"\0" * 7 + b"x"), mapping()),
        ("executable PROGBITS", fixture(flags=7), mapping()),
        ("executable NOBITS", fixture(pool_type=8, flags=7), mapping()),
        ("incomplete owner", fixture(target_size=0, owner=(0, 4)), mapping()),
        ("incomplete NOBITS owner", fixture(pool_type=8, target_size=0, owner=(0, 4)), mapping()),
        ("overlapping owner", fixture(target_size=4, owner=(2, 6)), mapping()),
        ("incoming other owner", fixture(target_size=0, owner=(0, 8), incoming=2), mapping()),
        ("incoming NOBITS owner", fixture(pool_type=8, target_size=0, owner=(0, 8), incoming=2), mapping()),
        ("outgoing PROGBITS relocation", fixture(outgoing=True), mapping()),
        ("outgoing NOBITS relocation", fixture(pool_type=8, outgoing=True), mapping()),
        ("retail gap", fixture(), mapping(size=4)),
        ("retail overlap", fixture(), mapping("other = .bss:0x80300004; // type:object size:0x4\n")),
        ("retail section mismatch", fixture(), mapping("other = .data:0x80300004; // type:object size:0x4\n", size=4)),
        ("NAME_ADDRESS mismatch", fixture(), mapping(address=0x80300004)),
        ("truncated ELF", fixture()[:-1], mapping()),
    ]
    for label, data, symbols in cases:
        rejects(label, data, symbols)
    print(f"ok: {2 + len(cases)} static-pool fixtures")


if __name__ == "__main__":
    main()

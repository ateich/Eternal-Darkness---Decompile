#!/usr/bin/env python3
"""Synthetic fail-closed tests for the accepted shared static-pool repair."""

import importlib.util
import struct
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]
TOOL = ROOT / "tools/undefine_elf_static_pool.py"
SPEC = importlib.util.spec_from_file_location("static_pool_tool", TOOL)
POOL = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(POOL)


def fixture(kind=8, flags=3, other=False, relocation=0, reference=1,
            nonzero=False):
    names = b"\0pool\0other\0"
    header = bytearray(52)
    header[:7] = b"\x7fELF\x01\x02\x01"
    struct.pack_into(">HH", header, 16, 1, 20)
    struct.pack_into(">H", header, 40, 52)
    symbols = bytes(16) + struct.pack(">IIIBBH", 1, 0, 16, 1, 0, 1)
    if other:
        symbols += struct.pack(">IIIBBH", 6, 4, 4, 1, 0, 1)
    else:
        symbols += struct.pack(">IIIBBH", 0, 0, 0, 3, 0, 1)
    image = header + bytes([int(nonzero)]) + bytes(15) + symbols + names + bytes(4)
    reloc = b""
    if relocation:
        reloc = struct.pack(">II", 0, (reference << 8) | 1)
        if relocation == 4:
            reloc += bytes(4)
    reloc_offset = len(image)
    image += reloc
    sections = [
        (0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
        (0, kind, flags, 0, 52, 16, 0, 0, 4, 0),
        (0, 2, 0, 0, 68, len(symbols), 3, 3, 4, 16),
        (0, 3, 0, 0, 68 + len(symbols), len(names), 0, 0, 1, 0),
        (0, 1, 6, 0, 68 + len(symbols) + len(names), 4, 0, 0, 4, 0),
    ]
    if relocation:
        sections.append(
            (0, relocation, 0, 0, reloc_offset, len(reloc), 2, 1, 4,
             12 if relocation == 4 else 8)
        )
    section_offset = len(image)
    image += b"".join(struct.pack(">10I", *section) for section in sections)
    struct.pack_into(">I", image, 32, section_offset)
    struct.pack_into(">HHH", image, 46, 40, len(sections), 0)
    return image


MAPPING = "pool = .bss:0x80300000; type:object size:0x10"


def reject(label, image, symbols=MAPPING):
    before = bytes(image)
    try:
        POOL.externalize(image, "pool", symbols)
    except ValueError:
        pass
    else:
        raise AssertionError(f"unsafe fixture accepted: {label}")
    assert bytes(image) == before, f"rejected fixture mutated: {label}"


def main():
    # Both valid storage forms must retain a complete, owned, in-bounds range.
    for kind in (1, 8):
        result = POOL.externalize(fixture(kind), "pool", MAPPING)
        assert result != fixture(kind)

    reject("nonzero PROGBITS", fixture(1, nonzero=True))
    reject("executable pool", fixture(1, flags=7))
    reject("second symbol owner", fixture(8, other=True))
    reject("truncated ELF", fixture(8)[:-1])

    # Reject outgoing REL and RELA sections (sh_info names the removed pool).
    for relocation in (4, 9):
        reject(f"outgoing relocation {relocation}", fixture(8, relocation=relocation))

        # A relocation in another section may reference only the exact anchor.
        image = fixture(8, relocation=relocation, reference=2)
        section_offset = struct.unpack_from(">I", image, 32)[0]
        struct.pack_into(">I", image, section_offset + 5 * 40 + 28, 4)
        reject(f"incoming relocation to other owner {relocation}", image)

    # Exact retail coverage rejects overlaps, interior records, gaps, and aliases.
    adjacent = (
        "pool = .bss:0x80300000; type:object size:0x8\n"
        "next = .bss:0x80300008; type:object size:0x8"
    )
    assert POOL.externalize(fixture(8), "pool", adjacent)
    bad_mappings = [
        adjacent + "\ninterior = .bss:0x80300004; type:object size:0x4",
        adjacent + "\npreceding = .bss:0x802FFFFC; type:object size:0x8",
        adjacent + "\nalias = .bss:0x80300000; type:object size:0x8",
        adjacent.replace("0x80300008", "0x80300009"),
        adjacent.replace("next = .bss", "next = .sbss"),
    ]
    for index, symbols in enumerate(bad_mappings):
        reject(f"ambiguous retail coverage {index}", fixture(8), symbols)

    # The accepted fn_80088060 registration and shared-pool step must remain
    # byte-for-byte present while this PR adds two more pool users.
    configure = (ROOT / "configure.py").read_text()
    assert (
        'Object(Matching, "game/game_fn_80088060.c", mw_version="GC/1.3.2", '
        'extra_cflags=["-use_lmw_stmw on"])'
    ) in configure
    assert '"rule": "externalize_game_static_pool"' in configure
    assert '"inputs": [f"build/{VERSION}/src/game/game_fn_80088060.o"]' in configure
    print("static-pool positive and negative fixtures passed")


if __name__ == "__main__":
    main()

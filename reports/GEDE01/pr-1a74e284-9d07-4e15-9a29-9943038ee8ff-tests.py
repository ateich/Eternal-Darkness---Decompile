#!/usr/bin/env python3
"""Synthetic negative tests for PR e9ac8a58 tooling guards."""

import importlib.util
import struct
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
EXTERNALIZER = ROOT / "tools/externalize_elf_symbol.py"
POOL_TOOL = ROOT / "tools/undefine_elf_static_pool.py"


def elf(section_name=".sdata2", flags=2, relocation_type=None, pool=False,
        nonzero=False, extra_owner=False):
    names = ["", section_name, ".symtab", ".strtab", ".shstrtab"]
    if relocation_type is not None:
        names.append((".rela" if relocation_type == 4 else ".rel") + section_name)
    shstr = b"\0"
    name_offsets = {}
    for name in names[1:]:
        name_offsets[name] = len(shstr)
        shstr += name.encode() + b"\0"
    target = "lbl_80600000" if pool else "@51"
    strings = b"\0" + target.encode() + b"\0other\0"
    target_name = 1
    other_name = 2 + len(target)
    symbols = bytearray(16)
    symbols += struct.pack(">IIIBBH", target_name, 0, 4, 0x10, 0, 1)
    if extra_owner:
        symbols += struct.pack(">IIIBBH", other_name, 0, 4, 0x10, 0, 1)
    contents = bytearray(b"\1\0\0\0" if nonzero else b"\0" * 4)
    sections = [None]
    sections.append([name_offsets[section_name], 1, flags, contents, 0, 0, 4, 0])
    sections.append([name_offsets[".symtab"], 2, 0, symbols, 3, 1, 4, 16])
    sections.append([name_offsets[".strtab"], 3, 0, strings, 0, 0, 1, 0])
    sections.append([name_offsets[".shstrtab"], 3, 0, shstr, 0, 0, 1, 0])
    if relocation_type is not None:
        entry = struct.pack(">II", 0, (1 << 8) | 1)
        if relocation_type == 4:
            entry += struct.pack(">i", 0)
        rel_name = (".rela" if relocation_type == 4 else ".rel") + section_name
        sections.append([name_offsets[rel_name], relocation_type, 0, entry, 2, 1, 4,
                         12 if relocation_type == 4 else 8])
    data = bytearray(52)
    offsets = {}
    for index, section in enumerate(sections[1:], 1):
        while len(data) % max(section[6], 1):
            data.append(0)
        offsets[index] = len(data)
        data += section[3]
    while len(data) % 4:
        data.append(0)
    shoff = len(data)
    data += bytes(40 * len(sections))
    data[:16] = b"\x7fELF\x01\x02\x01" + bytes(9)
    struct.pack_into(">HHIIIIIHHHHHH", data, 16, 1, 20, 1, 0, 0, shoff, 0,
                     52, 0, 0, 40, len(sections), 4)
    for index, section in enumerate(sections[1:], 1):
        name, kind, section_flags, payload, link, info, align, entsize = section
        struct.pack_into(">10I", data, shoff + 40 * index, name, kind, section_flags,
                         0, offsets[index], len(payload), link, info, align, entsize)
    return bytes(data)


def expect_externalizer_rejection(label, image, options, expected):
    with tempfile.TemporaryDirectory() as directory:
        obj = Path(directory) / "fixture.o"
        obj.write_bytes(image)
        before = obj.read_bytes()
        result = subprocess.run(
            [sys.executable, str(EXTERNALIZER), str(obj), "@51", "lbl_80600000",
             str(Path(directory) / "missing.dol"), *options],
            text=True, capture_output=True,
        )
        assert result.returncode != 0, f"{label}: unexpectedly accepted"
        assert expected in result.stderr, (label, result.stderr)
        assert obj.read_bytes() == before, f"{label}: mutated rejected input"


def expect_pool_rejection(label, image, symbols, expected):
    spec = importlib.util.spec_from_file_location("pool_tool", POOL_TOOL)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    try:
        module.externalize(image, "lbl_80600000", symbols)
    except ValueError as error:
        assert expected in str(error), (label, str(error))
    else:
        raise AssertionError(f"{label}: unexpectedly accepted")


def main():
    whole = ["--require-whole-section", "--require-section=.sdata2",
             "--reject-section-relocations"]
    expect_externalizer_rejection(
        "wrong section", elf(".rodata"), whole, "expected unique .sdata2"
    )
    expect_externalizer_rejection(
        "executable section", elf(flags=6), whole, "executable section"
    )
    for kind, name in ((9, "REL"), (4, "RELA")):
        expect_externalizer_rejection(
            name + " sh_info", elf(relocation_type=kind), whole,
            "outgoing relocation section targets removed pool",
        )

    mapping = "lbl_80600000 = .bss:0x80600000; type:object size:0x4\n"
    expect_pool_rejection("nonzero PROGBITS", elf(pool=True, nonzero=True), mapping,
                          "not all zero")
    expect_pool_rejection("executable pool", elf(pool=True, flags=6), mapping,
                          "non-executable")
    expect_pool_rejection("outgoing relocation", elf(pool=True, relocation_type=9),
                          mapping, "targets removed pool")
    expect_pool_rejection("other owner", elf(pool=True, extra_owner=True), mapping,
                          "another symbol owner")
    overlap = mapping + "other = .bss:0x80600000; type:object size:0x4\n"
    expect_pool_rejection("overlapping retail owners", elf(pool=True), overlap,
                          "overlap or do not exactly cover")
    expect_pool_rejection("truncated object", elf(pool=True)[:-1], mapping,
                          "out-of-bounds")
    print("synthetic externalization rejection tests passed")


if __name__ == "__main__":
    main()

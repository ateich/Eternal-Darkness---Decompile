#!/usr/bin/env python3
"""Retarget relocations between carefully verified ELF32 symbols."""
import os
import re
import struct
import sys
import tempfile
from pathlib import Path


def die(message):
    raise SystemExit(message)


def addressed(name):
    match = re.fullmatch(r".*_([0-9A-Fa-f]{8})", name)
    if not match:
        die(f"invalid addressed symbol {name!r}")
    return int(match.group(1), 16)


def dol_bytes(dol, address, size):
    if len(dol) < 0x100:
        die("retail DOL is truncated")
    matches = []
    for off_base, addr_base, size_base, count in (
        (0, 0x48, 0x90, 7),
        (0x1C, 0x64, 0xAC, 11),
    ):
        for i in range(count):
            file_off = struct.unpack_from(">I", dol, off_base + i * 4)[0]
            start = struct.unpack_from(">I", dol, addr_base + i * 4)[0]
            length = struct.unpack_from(">I", dol, size_base + i * 4)[0]
            if start <= address and address + size <= start + length:
                end = file_off + address - start + size
                if end > len(dol):
                    die("retail DOL segment extends beyond file")
                matches.append(dol[file_off + address - start:end])
    if len(matches) != 1:
        die(f"retail address 0x{address:08X} is not in exactly one file-backed segment")
    return matches[0]


def parse_options(argv):
    if len(argv) == 4:
        return argv[1], argv[2], argv[3], None
    if len(argv) < 5 or argv[4] != "--allow-equal-value-different-offset":
        die("usage: retarget_elf_symbol.py OBJECT FROM TO [--allow-equal-value-different-offset guarded options]")
    required = {
        "--require-section",
        "--require-source",
        "--require-target",
        "--require-relocation",
        "--require-retail-dol",
        "--require-sda-base",
        "--require-retail-instruction",
        "--require-value",
    }
    values = {}
    for arg in argv[5:]:
        if "=" not in arg:
            die(f"guard option requires a value: {arg}")
        key, value = arg.split("=", 1)
        if key not in required or key in values or not value:
            die(f"invalid or duplicate guard option: {key}")
        values[key] = value
    if set(values) != required:
        die("different-offset mode requires exactly: " + ", ".join(sorted(required)))
    return argv[1], argv[2], argv[3], values


def special_retarget(path, src_name, dst_name, opts):
    original = path.read_bytes()
    data = bytearray(original)
    if len(data) < 52 or data[:16] != b"\x7fELF\x01\x02\x01\x00" + b"\x00" * 8:
        die(f"{path}: expected ELF32 big-endian current-version object")
    if struct.unpack_from(">H", data, 16)[0] != 1 or struct.unpack_from(">H", data, 18)[0] != 20:
        die(f"{path}: expected relocatable PowerPC ELF")
    shoff = struct.unpack_from(">I", data, 32)[0]
    shentsize, shnum, shstrndx = struct.unpack_from(">HHH", data, 46)
    if shentsize != 40 or not (0 < shnum <= 256) or shstrndx >= shnum:
        die(f"{path}: invalid section header table")
    if shoff + shentsize * shnum > len(data):
        die(f"{path}: truncated section table")
    sections = [struct.unpack_from(">IIIIIIIIII", data, shoff + i * 40) for i in range(shnum)]
    file_ranges = [(0, 52, "ELF header"), (shoff, shoff + shentsize * shnum, "section table")]
    for i, section in enumerate(sections):
        if section[1] != 8 and section[4] + section[5] > len(data):
            die(f"{path}: section {i} is out of range")
        if section[1] != 8 and section[5]:
            if section[8] and section[4] % section[8]:
                die(f"{path}: section {i} violates its file alignment")
            file_ranges.append((section[4], section[4] + section[5], f"section {i}"))
    for index, left in enumerate(file_ranges):
        for right in file_ranges[index + 1:]:
            if max(left[0], right[0]) < min(left[1], right[1]):
                die(f"{path}: overlapping file metadata: {left[2]} and {right[2]}")
    shstr = sections[shstrndx]
    if shstr[1] != 3:
        die("section-name table is not STRTAB")

    def cstr(base, size, index, kind):
        if index >= size:
            die(f"invalid {kind} string offset")
        end = data.find(0, base + index, base + size)
        if end < 0:
            die(f"unterminated {kind} string")
        try:
            return data[base + index:end].decode("ascii")
        except UnicodeDecodeError:
            die(f"non-ASCII {kind} string")

    names = [cstr(shstr[4], shstr[5], section[0], "section") for section in sections]
    pool_hits = [i for i, name in enumerate(names) if name == opts["--require-section"]]
    if len(pool_hits) != 1:
        die(f"expected one {opts['--require-section']} section")
    pool_i = pool_hits[0]
    pool = sections[pool_i]
    if pool[1] != 1 or pool[2] != 3 or pool[5] != 8 or pool[8] != 8:
        die("guarded pool must be PROGBITS, WA, size 8, alignment 8")
    symtabs = [(i, section) for i, section in enumerate(sections) if section[1] == 2]
    if len(symtabs) != 1:
        die("expected exactly one symbol table")
    sym_i, symtab = symtabs[0]
    if symtab[9] != 16 or symtab[5] % 16 or symtab[6] >= shnum:
        die("invalid symbol table")
    strtab = sections[symtab[6]]
    if strtab[1] != 3:
        die("symbol string table is not STRTAB")
    symbols = []
    for index in range(symtab[5] // 16):
        offset = symtab[4] + index * 16
        st_name, value, size, info, other, shndx = struct.unpack_from(">IIIBBH", data, offset)
        symbols.append({
            "index": index,
            "name": cstr(strtab[4], strtab[5], st_name, "symbol"),
            "value": value,
            "size": size,
            "bind": info >> 4,
            "type": info & 15,
            "other": other,
            "shndx": shndx,
        })

    def unique(name):
        hits = [symbol for symbol in symbols if symbol["name"] == name]
        if len(hits) != 1:
            die(f"expected exactly one symbol {name!r}")
        return hits[0]

    src, dst = unique(src_name), unique(dst_name)

    def owner_guard(spec):
        parts = spec.split(":")
        bindings, types = {"local": 0, "global": 1}, {"object": 1}
        if len(parts) != 4 or parts[0] not in bindings or parts[1] not in types:
            die("owner guard must be local|global:object:offset:size")
        return bindings[parts[0]], types[parts[1]], int(parts[2], 0), int(parts[3], 0)

    for label, spec, symbol in (
        ("source", opts["--require-source"], src),
        ("target", opts["--require-target"], dst),
    ):
        binding, symbol_type, value, size = owner_guard(spec)
        actual = (symbol["bind"], symbol["type"], symbol["value"], symbol["size"], symbol["shndx"], symbol["other"])
        if actual != (binding, symbol_type, value, size, pool_i, 0):
            die(f"{label} owner does not match exact guard")
    owners = [symbol for symbol in symbols if symbol["shndx"] == pool_i and symbol["size"]]
    if {symbol["index"] for symbol in owners} != {src["index"], dst["index"]}:
        die("pool has an unexpected nonempty owner")
    if sorted((symbol["value"], symbol["value"] + symbol["size"]) for symbol in owners) != [(0, 4), (4, 8)]:
        die("owners do not completely and uniquely cover pool")
    src_value = bytes(data[pool[4] + src["value"]:pool[4] + src["value"] + src["size"]])
    dst_value = bytes(data[pool[4] + dst["value"]:pool[4] + dst["value"] + dst["size"]])
    if src_value != dst_value:
        die("source and target values differ")
    try:
        guarded_value = bytes.fromhex(opts["--require-value"])
    except ValueError:
        die("required value is not hexadecimal")
    if len(guarded_value) != src["size"] or src_value != guarded_value:
        die("source and target values do not match exact value guard")
    dst_address = addressed(dst_name)
    if dst_address & 3:
        die("target address is not 4-byte aligned")
    dol = Path(opts["--require-retail-dol"]).read_bytes()
    if dol_bytes(dol, dst_address, dst["size"]) != dst_value:
        die("target bytes do not match retail DOL")
    relocation_guard = opts["--require-relocation"].split(":")
    if len(relocation_guard) != 4 or relocation_guard[2] != "R_PPC_EMB_SDA21":
        die("relocation guard must be section:offset:R_PPC_EMB_SDA21:addend")
    expected = (relocation_guard[0], int(relocation_guard[1], 0), 109, int(relocation_guard[3], 0))
    if expected[3] != 0:
        die("different-offset mode requires a zero relocation addend")
    incoming = []
    for section in sections:
        if section[1] not in (4, 9):
            continue
        if section[6] != sym_i or section[7] >= shnum:
            die("relocation section does not use the unique symbol table")
        if section[7] == pool_i:
            die("pool has outgoing relocations")
        entry_size = section[9] or (12 if section[1] == 4 else 8)
        if entry_size != (12 if section[1] == 4 else 8) or section[5] % entry_size:
            die("invalid relocation table")
        for entry in range(section[4], section[4] + section[5], entry_size):
            offset, info = struct.unpack_from(">II", data, entry)
            addend = struct.unpack_from(">i", data, entry + 8)[0] if section[1] == 4 else None
            symbol_index = info >> 8
            if symbol_index >= len(symbols):
                die("relocation has invalid symbol index")
            symbol = symbols[symbol_index]
            if symbol["shndx"] == pool_i:
                incoming.append((names[section[7]], offset, info & 255, addend, symbol, entry + 4, section[1] == 4))
    if len(incoming) != 1:
        die("expected exactly one incoming pool relocation")
    rel_section, rel_offset, rel_type, rel_addend, rel_symbol, info_offset, is_rela = incoming[0]
    if not is_rela or rel_symbol["index"] != src["index"] or (rel_section, rel_offset, rel_type, rel_addend) != expected:
        die("incoming relocation does not match exact source guard")
    text_hits = [i for i, name in enumerate(names) if name == rel_section]
    if len(text_hits) != 1:
        die("relocation target section is ambiguous")
    text = sections[text_hits[0]]
    if text[1] != 1 or text[2] != 6:
        die("relocation target is not executable read-only PROGBITS")
    if rel_offset % 4 or rel_offset + 4 > text[5]:
        die("instruction is unaligned or out of range")
    instruction_offset = text[4] + rel_offset
    word = struct.unpack_from(">I", data, instruction_offset)[0]
    if word >> 26 != 48 or ((word >> 16) & 31) != 0 or (word & 0xFFFF) != 0:
        die("relocation site is not an unrelocated lfs value load")
    sda_base = int(opts["--require-sda-base"], 0)
    displacement = dst_address - sda_base
    if not -0x8000 <= displacement <= 0x7FFF:
        die("target is outside signed SDA displacement")
    relocated_word = (word & ~0x001FFFFF) | (2 << 16) | (displacement & 0xFFFF)
    retail_instruction = int(opts["--require-retail-instruction"], 0)
    if retail_instruction & 3 or dol_bytes(dol, retail_instruction, 4) != struct.pack(">I", relocated_word):
        die("retail instruction does not encode the guarded lfs/SDA base/address")
    old_info = struct.unpack_from(">I", data, info_offset)[0]
    new_info = (dst["index"] << 8) | (old_info & 255)
    struct.pack_into(">I", data, info_offset, new_info)
    changed = {i for i, (before, after) in enumerate(zip(original, data)) if before != after}
    if not changed or not changed <= set(range(info_offset, info_offset + 3)):
        die("output differs outside selected relocation symbol-index bits")
    expected_output = bytearray(original)
    struct.pack_into(">I", expected_output, info_offset, new_info)
    if data != expected_output:
        die("output invariant failure")
    mode = path.stat().st_mode
    fd, temporary = tempfile.mkstemp(prefix=path.name + ".", dir=path.parent)
    try:
        with os.fdopen(fd, "wb") as output:
            output.write(data)
            output.flush()
            os.fsync(output.fileno())
        os.chmod(temporary, mode)
        os.replace(temporary, path)
    finally:
        if os.path.exists(temporary):
            os.unlink(temporary)
    print(f"{path}: 1 guarded relocation moved from {src_name} to {dst_name}")


def legacy(path, src_name, dst_name):
    # This is the installed three-argument implementation, intentionally unchanged.
    data = bytearray(path.read_bytes())
    if data[:6] != b"\x7fELF\x01\x02":
        die(f"{path}: not a big-endian ELF32 object")
    e_shoff, _, _, _, _, e_shentsize, e_shnum, _ = struct.unpack(">IIHHHHHH", data[32:52])
    sections = [struct.unpack(">IIIIIIIIII", data[e_shoff + i * e_shentsize:e_shoff + (i + 1) * e_shentsize]) for i in range(e_shnum)]
    symtab_index = next((i for i, section in enumerate(sections) if section[1] == 2), None)
    if symtab_index is None:
        die(f"{path}: no symbol table")
    symtab = sections[symtab_index]
    strtab = sections[symtab[6]]
    sym_off, sym_size, sym_ent = symtab[4], symtab[5], symtab[9]
    str_off = strtab[4]

    def name_at(index):
        end = data.index(b"\0", str_off + index)
        return data[str_off + index:end].decode("ascii")

    found = {}
    for i in range(sym_size // sym_ent):
        offset = sym_off + i * sym_ent
        st_name, st_value, _, _, _, st_shndx = struct.unpack(">IIIBBH", data[offset:offset + sym_ent])
        name = name_at(st_name)
        if name in (src_name, dst_name):
            found[name] = (i, st_value, st_shndx)
    if src_name not in found or dst_name not in found:
        die(f"{path}: need both symbols, found {sorted(found)}")
    (src_index, src_value, src_section), (dst_index, dst_value, dst_section) = found[src_name], found[dst_name]
    if src_section != dst_section or src_value != dst_value:
        die(f"{path}: {src_name!r} and {dst_name!r} are not the same address")
    count = 0
    for section in sections:
        if section[1] != 4 or section[6] != symtab_index:
            continue
        for offset in range(section[4], section[4] + section[5], section[9]):
            r_offset, r_info, r_addend = struct.unpack(">IIi", data[offset:offset + 12])
            if r_info >> 8 == src_index:
                struct.pack_into(">IIi", data, offset, r_offset, (dst_index << 8) | (r_info & 255), r_addend)
                count += 1
    path.write_bytes(bytes(data))
    print(f"{path}: {count} relocation(s) moved from {src_name} to {dst_name}")


object_path, source_name, target_name, options = parse_options(sys.argv)
if options is None:
    legacy(Path(object_path), source_name, target_name)
else:
    special_retarget(Path(object_path), source_name, target_name, options)

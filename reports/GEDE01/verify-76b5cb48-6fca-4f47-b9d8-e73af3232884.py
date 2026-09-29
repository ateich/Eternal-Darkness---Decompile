#!/usr/bin/env python3
"""Assignment-local byte/relocation/DOL verification; emits metadata only."""
import hashlib
import json
from pathlib import Path
import struct

ROOT = Path(__file__).resolve().parents[2]
TARGET = "fn_801E0088"
EXPECTED_DOL_SHA1 = "ea24b6af954876ce072562ff39cdb4c81d32be1f"


def read_elf(relative):
    raw = (ROOT / relative).read_bytes()
    assert raw[:6] == b"\x7fELF\x01\x02"
    offset = struct.unpack_from(">I", raw, 32)[0]
    entry_size, count, names_index = struct.unpack_from(">HHH", raw, 46)
    headers = [struct.unpack_from(">10I", raw, offset + i * entry_size)
               for i in range(count)]

    def section(index):
        h = headers[index]
        return raw[h[4]:h[4] + h[5]]

    def string(data, index):
        return data[index:data.index(0, index)].decode()

    names = [string(section(names_index), h[0]) for h in headers]
    text_index = names.index(".text")
    relocations = []
    for index, h in enumerate(headers):
        if h[1] != 4 or h[7] != text_index:
            continue
        symbol_header = headers[h[6]]
        symbols = section(h[6])
        strings = section(symbol_header[6])
        for pos in range(0, h[5], 12):
            address, info, addend = struct.unpack_from(">IIi", section(index), pos)
            name, value, size, flags, other, section_index = struct.unpack_from(
                ">IIIBBH", symbols, (info >> 8) * 16)
            symbol_name = string(strings, name)
            if not symbol_name and section_index < len(names):
                symbol_name = names[section_index]
            relocations.append((address, info & 255, symbol_name, addend))
    return section(text_index), sorted(relocations)


def dol_function(raw):
    offsets = struct.unpack_from(">18I", raw, 0)
    addresses = struct.unpack_from(">18I", raw, 0x48)
    sizes = struct.unpack_from(">18I", raw, 0x90)
    for offset, address, size in zip(offsets, addresses, sizes):
        if address <= 0x801E0088 and 0x801E1920 <= address + size:
            begin = offset + 0x801E0088 - address
            return raw[begin:begin + 6296]
    raise AssertionError("Function is absent from DOL sections")


def main():
    retail, retail_relocs = read_elf("build/GEDE01/obj/game/game_fn_801E0088.o")
    generated, generated_relocs = read_elf("build/GEDE01/src/game/game_fn_801E0088.o")
    original_dol = (ROOT / "orig/GEDE01/sys/main.dol").read_bytes()
    built_dol = (ROOT / "build/GEDE01/main.dol").read_bytes()
    dol_sha1 = hashlib.sha1(built_dol).hexdigest()
    assert len(retail) == len(generated) == 6296
    assert retail == generated, "Unrelocated .text bytes differ"
    assert retail_relocs == generated_relocs, "Relocation targets/types/addends differ"
    assert len(retail_relocs) == 212
    assert dol_sha1 == EXPECTED_DOL_SHA1
    assert original_dol == built_dol
    retail_function = dol_function(original_dol)
    generated_function = dol_function(built_dol)
    assert retail_function == generated_function
    print(json.dumps({
        "target": TARGET,
        "text_size": len(generated),
        "instructions": len(generated) // 4,
        "text_bytes_equal": True,
        "retail_text_sha256": hashlib.sha256(retail).hexdigest(),
        "generated_text_sha256": hashlib.sha256(generated).hexdigest(),
        "retail_relocation_count": len(retail_relocs),
        "generated_relocation_count": len(generated_relocs),
        "relocation_tuples_equal": True,
        "relocation_tuple_fields": ["offset", "type", "target_symbol", "addend"],
        "relocation_tuples_sha256": hashlib.sha256(
            json.dumps(retail_relocs, separators=(",", ":")).encode()).hexdigest(),
        "dol_sha1": dol_sha1,
        "dol_bytes_equal": True,
        "linked_function_bytes_equal": True,
        "linked_function_sha256": hashlib.sha256(generated_function).hexdigest(),
        "source_sha256": hashlib.sha256(
            (ROOT / "src/game/game_fn_801E0088.c").read_bytes()).hexdigest(),
        "compiler_sha256": hashlib.sha256(
            (ROOT / "compilers/GC/1.3/mwcceppc.exe").read_bytes()).hexdigest(),
    }, indent=2))


if __name__ == "__main__":
    main()

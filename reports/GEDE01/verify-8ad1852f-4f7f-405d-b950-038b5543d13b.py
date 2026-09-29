"""Run from eternal-darkness-decomp; verify this assignment's ELF and DOL."""
import hashlib
import json
import struct
from pathlib import Path

ASSIGNMENT = "8ad1852f-4f7f-405d-b950-038b5543d13b"
REPORTS = Path("reports/GEDE01")


def extract(path):
    blob = Path(path).read_bytes()
    assert blob[:6] == b"\x7fELF\x01\x02"
    offset = struct.unpack_from(">I", blob, 32)[0]
    entry_size, count, string_index = struct.unpack_from(">HHH", blob, 46)
    sections = [struct.unpack_from(">IIIIIIIIII", blob, offset + i * entry_size)
                for i in range(count)]

    def data(section):
        return blob[section[4]:section[4] + section[5]]

    def name(table, offset):
        return table[offset:table.index(b"\0", offset)].decode()

    strings = data(sections[string_index])
    names = [name(strings, section[0]) for section in sections]
    text_index = names.index(".text")
    relocations = []
    for section in sections:
        if section[1] != 4 or section[7] != text_index:
            continue
        symtab = sections[section[6]]
        symbols = data(symtab)
        symstrings = data(sections[symtab[6]])
        for offset in range(0, section[5], section[9]):
            address, info, addend = struct.unpack_from(">IIi", data(section), offset)
            symbol = struct.unpack_from(">IIIBBH", symbols, (info >> 8) * symtab[9])
            relocations.append({
                "offset": address,
                "type": info & 255,
                "symbol": name(symstrings, symbol[0]),
                "symbol_value": symbol[1],
                "addend": addend,
            })
    return data(sections[text_index]), relocations


paths = ["build/GEDE01/obj/game/game_fn_801DB9E0.o",
         "build/GEDE01/src/game/game_fn_801DB9E0.o"]
retail, retail_relocations = extract(paths[0])
candidate, candidate_relocations = extract(paths[1])
dol_paths = ["orig/GEDE01/sys/main.dol", "build/GEDE01/main.dol"]
dols = [Path(path).read_bytes() for path in dol_paths]
report = {
    "target": "fn_801DB9E0",
    "objects": paths,
    "text_size": [len(retail), len(candidate)],
    "text_sha256": [hashlib.sha256(text).hexdigest() for text in (retail, candidate)],
    "text_bytes_equal": retail == candidate,
    "relocation_counts": [len(retail_relocations), len(candidate_relocations)],
    "relocations_equal_including_targets_values_and_addends": retail_relocations == candidate_relocations,
    "retail_relocations": retail_relocations,
    "candidate_relocations": candidate_relocations,
    "dol_paths": dol_paths,
    "dol_sha1": [hashlib.sha1(dol).hexdigest() for dol in dols],
    "dol_bytes_equal": dols[0] == dols[1],
}
(REPORTS / f"bytes-relocations-{ASSIGNMENT}.json").write_text(json.dumps(report, indent=2) + "\n")
assert retail == candidate and retail_relocations == candidate_relocations
assert dols[0] == dols[1]
assert report["dol_sha1"] == ["ea24b6af954876ce072562ff39cdb4c81d32be1f"] * 2
for suffix in ("", "-reloc-strict"):
    result = json.loads((REPORTS / f"objdiff-{ASSIGNMENT}{suffix}.json").read_text())
    symbol = next(s for s in result["left"]["symbols"] if s["name"] == "fn_801DB9E0")
    assert symbol["match_percent"] == 100
    print(f"objdiff{suffix}: {symbol['match_percent']}%; {symbol['size']} bytes")
print("ELF .text: 2092 bytes equal; 123 relocation records equal including targets/values/addends")
print("DOL byte equality: passed; SHA-1 ea24b6af954876ce072562ff39cdb4c81d32be1f")

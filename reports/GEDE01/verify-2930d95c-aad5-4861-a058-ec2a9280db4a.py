"""Run from eternal-darkness-decomp after configure.py and ninja -j2."""
import hashlib
import json
from pathlib import Path
import struct
import subprocess

ASSIGNMENT = "2930d95c-aad5-4861-a058-ec2a9280db4a"
REPORTS = Path("reports/GEDE01")


def read_elf(path):
    data = Path(path).read_bytes()
    assert data[:6] == b"\x7fELF\x01\x02"
    header = struct.unpack_from(">16sHHIIIIIHHHHHH", data)
    offset, entry_size, count, string_index = (
        header[6], header[11], header[12], header[13]
    )
    sections = [
        struct.unpack_from(">10I", data, offset + i * entry_size)
        for i in range(count)
    ]

    def section_bytes(index):
        section = sections[index]
        return data[section[4]:section[4] + section[5]]

    def string(blob, index):
        return blob[index:blob.index(b"\0", index)].decode()

    names = [string(section_bytes(string_index), s[0]) for s in sections]
    text_index = names.index(".text")
    relocations = []
    for section in sections:
        if section[1] != 4 or section[7] != text_index:
            continue
        symbols = sections[section[6]]
        symbol_data = section_bytes(section[6])
        strings = section_bytes(symbols[6])
        for position in range(section[4], section[4] + section[5], section[9]):
            address, info, addend = struct.unpack_from(">IIi", data, position)
            symbol = struct.unpack_from(
                ">IIIBBH", symbol_data, (info >> 8) * symbols[9]
            )
            relocations.append({
                "offset": address,
                "type": info & 255,
                "target": string(strings, symbol[0]),
                "target_value": symbol[1],
                "addend": addend,
            })
    return section_bytes(text_index), relocations


commands = []
for mode, extra in (("canonical", []),
                    ("reloc-strict", ["-c", "function_reloc_diffs=name_address"])):
    output = REPORTS / f"objdiff-{ASSIGNMENT}-{mode}.raw.json"
    command = ["build/tools/objdiff-cli", "diff", "-p", ".", "-u",
               "main/game/game_fn_801D0050", "fn_801D0050", "-o",
               str(output), "--format", "json-pretty", *extra]
    result = subprocess.run(command, capture_output=True, text=True)
    commands.append({"argv": command, "exit_code": result.returncode,
                     "stdout": result.stdout, "stderr": result.stderr})
    assert result.returncode == 0
    report = json.loads(output.read_text())
    for side in ("left", "right"):
        symbol = next(s for s in report[side]["symbols"]
                      if s["name"] == "fn_801D0050")
        assert int(symbol["size"]) == 1860
        assert all(not row.get("diff_kind") or row["diff_kind"] == "DIFF_NONE"
                   for row in symbol["instructions"])
    assert report["left"]["symbols"][0]["match_percent"] == 100

retail, retail_relocations = read_elf("build/GEDE01/obj/game/game_fn_801D0050.o")
generated, generated_relocations = read_elf("build/GEDE01/src/game/game_fn_801D0050.o")
elf_result = {
    "text_equal": retail == generated,
    "retail_text_size": len(retail),
    "generated_text_size": len(generated),
    "retail_text_sha1": hashlib.sha1(retail).hexdigest(),
    "generated_text_sha1": hashlib.sha1(generated).hexdigest(),
    "relocations_equal": retail_relocations == generated_relocations,
    "retail_relocations": retail_relocations,
    "generated_relocations": generated_relocations,
}
(REPORTS / f"elf-{ASSIGNMENT}.raw.json").write_text(
    json.dumps(elf_result, indent=2) + "\n"
)
assert retail == generated and retail_relocations == generated_relocations
assert len(retail) == 1860 and len(retail_relocations) == 90

for command in (["sha1sum", "build/GEDE01/main.dol"],
                ["python3", "tools/legal_audit.py"],
                ["git", "diff", "--check", "--", "configure.py",
                 "src/game/game_fn_801D0050.c"]):
    result = subprocess.run(command, capture_output=True, text=True)
    commands.append({"argv": command, "exit_code": result.returncode,
                     "stdout": result.stdout, "stderr": result.stderr})
    assert result.returncode == 0
    if command[0] == "sha1sum":
        assert result.stdout.split()[0] == "ea24b6af954876ce072562ff39cdb4c81d32be1f"

(REPORTS / f"verification-{ASSIGNMENT}.raw.json").write_text(
    json.dumps({"commands": commands}, indent=2) + "\n"
)
print("PASS: canonical/strict 100%; 1860 identical text bytes; 90 identical relocations; DOL SHA-1; legal audit")

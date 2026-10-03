"""Generate assigned-object evidence for fn_80026DC8."""
import difflib
import hashlib
import json
import pathlib
import struct
import subprocess

assignment = "87516428-1ada-424c-9852-01081260309a"
retail_path = pathlib.Path("build/GEDE01/obj/game/game_fn_80026DC8.o")
candidate_path = pathlib.Path("build/GEDE01/src/game/game_fn_80026DC8.o")
report_dir = pathlib.Path("reports/GEDE01")


def elf(path):
    data = path.read_bytes()
    header = struct.unpack_from(">16sHHIIIIIHHHHHH", data)
    assert data[:7] == b"\x7fELF\x01\x02\x01"
    sections = [
        struct.unpack_from(">10I", data, header[6] + i * header[11])
        for i in range(header[12])
    ]
    names = data[
        sections[header[13]][4] : sections[header[13]][4] + sections[header[13]][5]
    ]

    def name(offset):
        return names[offset : names.index(0, offset)].decode()

    by_name = {name(section[0]): section for section in sections}
    text = data[by_name[".text"][4] : by_name[".text"][4] + by_name[".text"][5]]
    return data, text


retail_data, retail_text = elf(retail_path)
candidate_data, candidate_text = elf(candidate_path)
objdump = "build/binutils/powerpc-eabi-objdump"
readelf = "build/binutils/powerpc-eabi-readelf"


def output(command):
    return subprocess.run(command, check=True, text=True, stdout=subprocess.PIPE).stdout


retail_disassembly = output([objdump, "-dr", str(retail_path)]).splitlines()
candidate_disassembly = output([objdump, "-dr", str(candidate_path)]).splitlines()
# Drop the path banner; all actual disassembly and annotated relocations must match.
retail_normalized = retail_disassembly[2:]
candidate_normalized = candidate_disassembly[2:]
instruction_diff = list(
    difflib.unified_diff(
        retail_normalized,
        candidate_normalized,
        fromfile="retail-normalized-objdump",
        tofile="candidate-normalized-objdump",
        lineterm="",
    )
)
(report_dir / f"instruction-diff-{assignment}.txt").write_text(
    "command: powerpc-eabi-objdump -dr RETAIL CANDIDATE; path banners omitted\n"
    + ("\n".join(instruction_diff) + "\n" if instruction_diff else "no differences\n")
)

retail_relocations = output([readelf, "-r", str(retail_path)])
candidate_relocations = output([readelf, "-r", str(candidate_path)])
def relocation_entries(text):
    fields = [line.split() for line in text.splitlines() if "R_PPC_" in line]
    # Symbol-table indices and displayed symbol values are not relocation semantics.
    return [[row[0], row[2], *row[4:]] for row in fields]


retail_entries = relocation_entries(retail_relocations)
candidate_entries = relocation_entries(candidate_relocations)
relocations = (
    "retail command: powerpc-eabi-readelf -r " + str(retail_path) + "\n"
    + retail_relocations
    + "candidate command: powerpc-eabi-readelf -r " + str(candidate_path) + "\n"
    + candidate_relocations
)
(report_dir / f"relocations-{assignment}.txt").write_text(relocations)

objdiff_paths = [
    report_dir / f"objdiff-{assignment}.json",
    report_dir / f"objdiff-{assignment}-reloc-strict.json",
]
objdiff = [json.loads(path.read_text()) for path in objdiff_paths]
scores = [
    next(symbol for symbol in result["left"]["symbols"] if symbol["name"] == "fn_80026DC8")["match_percent"]
    for result in objdiff
]
source = pathlib.Path("src/game/game_fn_80026DC8.c").read_bytes()
report = {
    "assignment_id": assignment,
    "target": "fn_80026DC8",
    "source_sha256": hashlib.sha256(source).hexdigest(),
    "approved_candidate_source_sha256": "294f4e0925981390760671e9e0ec7d966965809ce975c2cff2dc1a4358681739",
    "source_preserved": hashlib.sha256(source).hexdigest() == "294f4e0925981390760671e9e0ec7d966965809ce975c2cff2dc1a4358681739",
    "text_sizes": [len(retail_text), len(candidate_text)],
    "text_bytes_equal": retail_text == candidate_text,
    "canonical_match_percent": scores[0],
    "relocation_strict_match_percent": scores[1],
    "relocation_counts": [len(retail_entries), len(candidate_entries)],
    "relocation_entries_equal": retail_entries == candidate_entries,
    "normalized_objdump_difference_count": len(instruction_diff),
    "retail_object_sha256": hashlib.sha256(retail_data).hexdigest(),
    "candidate_object_sha256": hashlib.sha256(candidate_data).hexdigest(),
}
assert report["source_preserved"]
assert report["text_sizes"] == [616, 616]
assert report["text_bytes_equal"]
assert scores == [100.0, 100.0]
assert report["relocation_counts"] == [24, 24]
assert report["relocation_entries_equal"]
assert not instruction_diff
(report_dir / f"verification-{assignment}.json").write_text(json.dumps(report, indent=2) + "\n")

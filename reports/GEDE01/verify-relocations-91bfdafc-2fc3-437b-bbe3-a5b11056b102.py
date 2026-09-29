"""Read ELF32 relocation records directly; run from the project root."""
from pathlib import Path
import hashlib
import json
import struct

ASSIGNMENT = '91bfdafc-2fc3-437b-bbe3-a5b11056b102'


def read_object(path):
    data = path.read_bytes()
    assert data[:6] == b'\x7fELF\x01\x02'
    header = struct.unpack_from('>HHIIIIIHHHHHH', data, 16)
    sections = [struct.unpack_from('>IIIIIIIIII', data, header[5] + i * header[10]) for i in range(header[11])]
    def contents(section):
        return data[section[4]:section[4]+section[5]]
    def string(table, offset):
        return table[offset:table.index(b'\0', offset)].decode()
    section_names = contents(sections[header[12]])
    names = [string(section_names, s[0]) for s in sections]
    text = contents(sections[names.index('.text')])
    records = []
    for relocation_section in sections:
        if relocation_section[1] != 4 or names[relocation_section[7]] != '.text':
            continue
        symbol_section = sections[relocation_section[6]]
        string_table = contents(sections[symbol_section[6]])
        for offset in range(0, relocation_section[5], relocation_section[9]):
            address, info, addend = struct.unpack_from('>IIi', contents(relocation_section), offset)
            symbol = struct.unpack_from('>IIIBBH', contents(symbol_section), (info >> 8) * symbol_section[9])
            records.append({'offset': address, 'type': info & 255,
                            'target': string(string_table, symbol[0]),
                            'target_value': symbol[1], 'target_section_index': symbol[5],
                            'addend': addend})
    return {'object': 'eternal-darkness-decomp/' + path.as_posix(),
            'text_size': len(text), 'text_sha1': hashlib.sha1(text).hexdigest(),
            'relocations': records}, text


def main():
    left, left_bytes = read_object(Path('build/GEDE01/obj/game/game_fn_800D9428.o'))
    right, right_bytes = read_object(Path('build/GEDE01/src/game/game_fn_800D9428.o'))
    assert len(left['relocations']) == len(right['relocations']) == 17
    assert left['relocations'] == right['relocations']
    assert len(left_bytes) == len(right_bytes) == 492
    differences = [{'offset': i, 'retail_word': left_bytes[i:i+4].hex(),
                    'generated_word': right_bytes[i:i+4].hex()}
                   for i in range(0, len(left_bytes), 4) if left_bytes[i:i+4] != right_bytes[i:i+4]]
    output = {'command': 'python3 reports/GEDE01/verify-relocations-' + ASSIGNMENT + '.py',
              'left': left, 'right': right, 'relocations_equal': True,
              'text_bytes_equal': left_bytes == right_bytes,
              'differing_instruction_words': len(differences), 'word_differences': differences}
    Path('reports/GEDE01/relocations-' + ASSIGNMENT + '.json').write_text(json.dumps(output, indent=2) + '\n')
    print('retail_size=492 generated_size=492 relocations=17 relocation_records_equal=True differing_instruction_words=' + str(len(differences)))


if __name__ == '__main__':
    main()

"""Independent ELF32 text/RELA verification for this assignment. Run from project root."""
import hashlib
import json
import struct
from pathlib import Path

ASSIGNMENT = '03e885a8-a029-436c-9c6d-bdb1322e9807'
TARGET = 'fn_8013A538'


def inspect(path):
    data = Path(path).read_bytes()
    assert data[:6] == b'\x7fELF\x01\x02', 'Expected big-endian ELF32'
    header = struct.unpack_from('>16sHHIIIIIHHHHHH', data)
    shoff, shentsize, shnum, shstrndx = header[6], header[11], header[12], header[13]
    sections = [struct.unpack_from('>10I', data, shoff + i * shentsize)
                for i in range(shnum)]

    def contents(section):
        return data[section[4]:section[4] + section[5]]

    def string(table, offset):
        return table[offset:table.index(b'\0', offset)].decode()

    names = contents(sections[shstrndx])
    text_index = next(i for i, s in enumerate(sections) if string(names, s[0]) == '.text')
    text = contents(sections[text_index])
    symtab = next(s for s in sections if s[1] == 2)
    strings = contents(sections[symtab[6]])
    symbols = []
    for offset in range(symtab[4], symtab[4] + symtab[5], symtab[9]):
        name, value, size, info, other, section = struct.unpack_from('>IIIBBH', data, offset)
        symbols.append({'name': string(strings, name), 'value': value, 'size': size,
                        'section_index': section, 'info': info})
    function = next(s for s in symbols if s['name'] == TARGET)
    assert function['section_index'] == text_index
    assert function['value'] == 0 and function['size'] == len(text) == 2064
    relocations = []
    for section in sections:
        if section[1] == 4 and section[7] == text_index:
            for offset in range(section[4], section[4] + section[5], section[9]):
                address, info, addend = struct.unpack_from('>IIi', data, offset)
                symbol = symbols[info >> 8]
                relocations.append({'offset': address, 'type': info & 255,
                                    'target': symbol['name'], 'target_value': symbol['value'],
                                    'addend': addend})
    relocations.sort(key=lambda r: (r['offset'], r['type'], r['target'], r['addend']))
    return text, {'path': 'eternal-darkness-decomp/' + path, 'text_bytes': len(text),
                  'text_sha256': hashlib.sha256(text).hexdigest(),
                  'relocation_count': len(relocations), 'relocations': relocations}


left_text, left = inspect('build/GEDE01/obj/game/game_fn_8013A538.o')
right_text, right = inspect('build/GEDE01/src/game/game_fn_8013A538.o')
result = {'version': 1, 'assignment_id': ASSIGNMENT, 'target': TARGET,
          'retail': left, 'generated': right,
          'text_bytes_equal': left_text == right_text,
          'relocation_targets_types_offsets_addends_equal': left['relocations'] == right['relocations']}
result['all_passed'] = result['text_bytes_equal'] and result['relocation_targets_types_offsets_addends_equal']
output = Path('reports/GEDE01/relocations-' + ASSIGNMENT + '.json')
output.write_text(json.dumps(result, indent=2) + '\n')
print(json.dumps({k: v for k, v in result.items() if k not in ('retail', 'generated')}, indent=2))
print('Compared %d bytes and %d relocation records per object.' % (len(left_text), len(left['relocations'])))
assert result['all_passed']

"""Read-only ELF byte/relocation audit; run from eternal-darkness-decomp."""
import json
import struct
from pathlib import Path


def inspect(path):
    data = Path(path).read_bytes()
    assert data[:6] == b'\x7fELF\x01\x02'
    shoff = struct.unpack_from('>I', data, 32)[0]
    entsize, count, names_index = struct.unpack_from('>HHH', data, 46)
    headers = [struct.unpack_from('>10I', data, shoff + i * entsize) for i in range(count)]
    def contents(h):
        return data[h[4]:h[4] + h[5]]
    def cstr(blob, offset):
        return blob[offset:blob.index(b'\0', offset)].decode()
    names = contents(headers[names_index])
    sections = [cstr(names, h[0]) for h in headers]
    payload = {sections[i]: contents(h).hex() for i, h in enumerate(headers) if sections[i] in ('.text', '.data')}
    relocations = []
    for h in headers:
        if h[1] != 4:
            continue
        symtab = headers[h[6]]
        strings = contents(headers[symtab[6]])
        for offset in range(h[4], h[4] + h[5], h[9]):
            at, info, addend = struct.unpack_from('>IIi', data, offset)
            name, value, size, flags, other, section = struct.unpack_from('>IIIBBH', data, symtab[4] + (info >> 8) * symtab[9])
            symbol_name = cstr(strings, name)
            # Local jump table names differ. Resolve both to their owned section
            # and offset; preserve relocation type, location and exact addend.
            target = sections[section] if 0 < section < len(sections) else symbol_name
            relocations.append({'section':sections[h[7]], 'offset':at, 'type':info & 255,
                                'target_section_or_external':target, 'symbol_value':value,
                                'addend':addend})
    return {'sections_hex':payload, 'relocations':relocations}


if __name__ == '__main__':
    left = inspect('build/GEDE01/obj/game/game_fn_801A6350.o')
    right = inspect('build/GEDE01/src/game/game_fn_801A6350.o')
    print(json.dumps({'retail':left, 'generated':right, 'exact_equal':left == right}, indent=2))
    assert len(left['relocations']) == 26
    assert left == right

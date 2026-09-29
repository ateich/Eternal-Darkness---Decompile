import re
from probe import HERE, SOURCE, measure
from probe_addresses import ORDERED, scoped

def accessor(s, kind):
    if kind == 'base':
        helper = 'static inline u8* block_base(BlockGlobals* globals, int bank)\n{\n    if (bank) return globals->first;\n    return globals->second;\n}\n\n'
        body = s.replace('globals->first + record.second_index', 'block_base(globals, 1) + record.second_index').replace('globals->second + record.first_index', 'block_base(globals, 0) + record.first_index').replace('globals->first + lbl_8064C3A8', 'block_base(globals, 1) + lbl_8064C3A8').replace('globals->second + lbl_8064C3A8', 'block_base(globals, 0) + lbl_8064C3A8')
    elif kind == 'address':
        helper = 'static inline u8* block_address(u8* base, u32 index)\n{\n    return base + index * 0x88;\n}\n\n'
        body = re.sub(r'globals->(first|second) \+ ([\w.]+) \* 0x88', r'block_address(globals->\1, \2)', s)
    else:
        helper = 'static inline u16 write_block(void* output, u8* base, u32 index, int bank)\n{\n    return fn_801FB3B4(output, base + index * 0x88, bank);\n}\n\n'
        body = re.sub(r'fn_801FB3B4\(\(u8\*\)output \+ offset,\n\s+globals->(first|second) \+ ([\w.]+) \* 0x88, ([01])\)', r'write_block((u8*)output + offset, globals->\1, \2, \3)', s)
    return body.replace('u32 fn_801FABA4(', helper + 'u32 fn_801FABA4(')

if __name__ == '__main__':
    variants = [(f'inline-{kind}', accessor(ORDERED, kind), 'C-only inline expansion may delay member-base/index reassociation; helper must disappear from final object.') for kind in ['base', 'address', 'writer']]
    s = scoped(ORDERED)
    variants += [
        ('scoped-register', s.replace('u8* base =', 'register u8* base ='), 'Storage-class hint on scoped member-base temporaries.'),
        ('scoped-array-pointer', s.replace('u8* base = globals->', 'u8 (*base)[0x660] = &globals->').replace('base + ', '*base + '), 'Pointer-to-whole-array temporary rather than decayed byte pointer.'),
        ('const-pointee', s.replace('BlockGlobals* const globals', 'const BlockGlobals* const globals').replace('u8* base =', 'const u8* base ='), 'Read-only pointee qualification changes alias information without adding loads.'),
    ]
    try:
        for args in variants:
            measure(*args)
    finally:
        SOURCE.write_text(s)

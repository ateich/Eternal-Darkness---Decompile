from probe import HERE, SOURCE, measure
from probe_addresses import ORDERED, scoped
from probe_scheduling import temporary_calls

if __name__ == '__main__':
    forms = {
        'displacement-first-step': 'u32 displacement = $INDEX * 0x88;\nu8* base = globals->$MEMBER;\nbase += displacement;\noffset += fn_801FB3B4((u8*)output + offset, base, $FLAG);',
        'signed-displacement-step': 'int displacement = $INDEX * 0x88;\nu8* base = globals->$MEMBER;\nbase += displacement;\noffset += fn_801FB3B4((u8*)output + offset, base, $FLAG);',
        'step-result': 'u8* base = globals->$MEMBER;\nu16 size;\nbase += $INDEX * 0x88;\nsize = fn_801FB3B4((u8*)output + offset, base, $FLAG);\noffset += size;',
        'step-result-u32': 'u8* base = globals->$MEMBER;\nu32 size;\nbase += $INDEX * 0x88;\nsize = fn_801FB3B4((u8*)output + offset, base, $FLAG);\noffset = (offset + size) & 0xFFFF;',
        'step-unsigned-index': 'u8* base = globals->$MEMBER;\nbase += (u32)$INDEX * 0x88;\noffset += fn_801FB3B4((u8*)output + offset, base, $FLAG);',
        'step-typed': 'Block* base = (Block*)globals->$MEMBER;\nbase += $INDEX;\noffset += fn_801FB3B4((u8*)output + offset, base, $FLAG);',
        'step-typed-result': 'Block* base = (Block*)globals->$MEMBER;\nu16 size;\nbase += $INDEX;\nsize = fn_801FB3B4((u8*)output + offset, base, $FLAG);\noffset += size;',
        'step-subscript': 'u8* base = globals->$MEMBER;\nbase = &base[$INDEX * 0x88];\noffset += fn_801FB3B4((u8*)output + offset, base, $FLAG);',
    }
    try:
        for name, form in forms.items():
            s = temporary_calls(ORDERED, form)
            if 'Block*' in s:
                s = s.replace('typedef struct BlockGlobals {', 'typedef struct Block { u8 data[0x88]; } Block;\ntypedef struct BlockGlobals {')
            measure(name, s, 'Refine successful split pointer increment using ' + name + ', preserving the callee ABI and canonical base symbol.')
    finally:
        SOURCE.write_text(scoped(ORDERED))

import re
from probe import HERE, SOURCE, measure
from probe_addresses import ORDERED, scoped

def temporary_calls(s, form):
    pattern = re.compile(r'(?m)^(\s*)offset \+= fn_801FB3B4\(\(u8\*\)output \+ offset,\n\s+globals->(first|second) \+ ([\w.]+) \* 0x88, ([01])\);')
    def repl(m):
        indent, member, index, flag = m.groups()
        indent = indent.lstrip('\n')
        lines = form.replace('$MEMBER', member).replace('$INDEX', index).replace('$FLAG', flag).split('\n')
        return indent + '{\n' + '\n'.join(indent + '    ' + line for line in lines) + '\n' + indent + '}'
    return pattern.sub(repl,s)

if __name__ == '__main__':
    forms = {
        'base-step': 'u8* base = globals->$MEMBER;\nbase += $INDEX * 0x88;\noffset += fn_801FB3B4((u8*)output + offset, base, $FLAG);',
        'displacement-base': 'u32 displacement = $INDEX * 0x88;\nu8* base = globals->$MEMBER;\noffset += fn_801FB3B4((u8*)output + offset, base + displacement, $FLAG);',
        'base-displacement': 'u8* base = globals->$MEMBER;\nu32 displacement = $INDEX * 0x88;\noffset += fn_801FB3B4((u8*)output + offset, base + displacement, $FLAG);',
        'base-index-step': 'u8* base = globals->$MEMBER;\nu32 index = $INDEX;\nbase += index * 0x88;\noffset += fn_801FB3B4((u8*)output + offset, base, $FLAG);',
        'dest-base-index': 'u8* dest = (u8*)output + offset;\nu8* base = globals->$MEMBER;\nu32 index = $INDEX;\noffset += fn_801FB3B4(dest, base + index * 0x88, $FLAG);',
        'index-base-dest': 'u32 index = $INDEX;\nu8* base = globals->$MEMBER;\nu8* dest = (u8*)output + offset;\noffset += fn_801FB3B4(dest, base + index * 0x88, $FLAG);',
        'index-dest-base': 'u32 index = $INDEX;\nu8* dest = (u8*)output + offset;\nu8* base = globals->$MEMBER;\noffset += fn_801FB3B4(dest, base + index * 0x88, $FLAG);',
        'base-dest-index': 'u8* base = globals->$MEMBER;\nu8* dest = (u8*)output + offset;\nu32 index = $INDEX;\noffset += fn_801FB3B4(dest, base + index * 0x88, $FLAG);',
        'base-displacement-step': 'u8* base = globals->$MEMBER;\nu32 displacement = $INDEX * 0x88;\nbase += displacement;\noffset += fn_801FB3B4((u8*)output + offset, base, $FLAG);',
    }
    try:
        for name, form in forms.items():
            measure('schedule-' + name, temporary_calls(ORDERED, form), 'Separate argument computations into ' + name + ' temporaries to constrain address folding and scratch-register scheduling.')
    finally:
        SOURCE.write_text(scoped(ORDERED))

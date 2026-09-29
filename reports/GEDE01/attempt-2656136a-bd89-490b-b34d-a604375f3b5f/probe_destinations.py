import json
import re
from probe import HERE, SOURCE, measure
from probe_addresses import ORDERED

EXPR = 'u8* base = globals->$MEMBER;\noffset += fn_801FB3B4((u8*)output + offset, base + $INDEX * 0x88, $FLAG);'
STEP = 'u8* base = globals->$MEMBER;\nbase += $INDEX * 0x88;\noffset += fn_801FB3B4((u8*)output + offset, base, $FLAG);'

def source_for(forms):
    n = [0]
    pattern = re.compile(r'(?m)^( +)offset \+= fn_801FB3B4\(\(u8\*\)output \+ offset,\n\s+globals->(first|second) \+ ([\w.]+) \* 0x88, ([01])\);')
    def repl(m):
        indent, member, index, flag = m.groups()
        form = forms[n[0]]
        n[0] += 1
        lines = form.replace('$MEMBER', member).replace('$INDEX', index).replace('$FLAG', flag).split('\n')
        return indent + '{\n' + '\n'.join(indent + '    ' + line for line in lines) + '\n' + indent + '}'
    return pattern.sub(repl, ORDERED)

if __name__ == '__main__':
    forms = {
        'dest-step': 'u8* dest = (u8*)output + offset;\nu8* base = globals->$MEMBER;\nbase += $INDEX * 0x88;\noffset += fn_801FB3B4(dest, base, $FLAG);',
        'base-dest-step': 'u8* base = globals->$MEMBER;\nu8* dest = (u8*)output + offset;\nbase += $INDEX * 0x88;\noffset += fn_801FB3B4(dest, base, $FLAG);',
        'step-dest': 'u8* base = globals->$MEMBER;\nu8* dest;\nbase += $INDEX * 0x88;\ndest = (u8*)output + offset;\noffset += fn_801FB3B4(dest, base, $FLAG);',
        'index-dest-step': 'u32 index = $INDEX;\nu8* dest = (u8*)output + offset;\nu8* base = globals->$MEMBER;\nbase += index * 0x88;\noffset += fn_801FB3B4(dest, base, $FLAG);',
        'dest-index-step': 'u8* dest = (u8*)output + offset;\nu32 index = $INDEX;\nu8* base = globals->$MEMBER;\nbase += index * 0x88;\noffset += fn_801FB3B4(dest, base, $FLAG);',
        'index-base-dest-step': 'u32 index = $INDEX;\nu8* base = globals->$MEMBER;\nu8* dest = (u8*)output + offset;\nbase += index * 0x88;\noffset += fn_801FB3B4(dest, base, $FLAG);',
    }
    best = json.loads((HERE / 'best-probe.json').read_text())
    try:
        for call in [0, 2]:
            for name, form in forms.items():
                chosen = [EXPR, EXPR, STEP, EXPR]
                chosen[call] = form
                result = measure('destination-' + str(call) + '-' + name, source_for(chosen), 'Separate destination formation from indexed pointer update at call ' + str(call) + ' using ' + name + ' ordering.')
                if result.get('left') and result['left']['match_percent'] > best['left']['match_percent']:
                    best = result
        (HERE / 'best-probe.json').write_text(json.dumps(best, indent=2) + '\n')
    finally:
        SOURCE.write_text(best['source'])

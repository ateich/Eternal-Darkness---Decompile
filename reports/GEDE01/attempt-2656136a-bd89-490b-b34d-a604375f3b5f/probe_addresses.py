import re
from probe import HERE, SOURCE, measure
from probe_const import CONST
from probe_registers import ordered, retail_loop

ORDERED = retail_loop(ordered(CONST))

def scoped(s, qualifier='', integer=False):
    pattern = re.compile(r'(        |    )offset \+= fn_801FB3B4\(\(u8\*\)output \+ offset,\n\s+globals->(first|second) \+ ([\w.]+) \* 0x88, ([01])\);')
    def repl(m):
        indent, member, index, flag = m.groups()
        typ = 'u32' if integer else 'u8*'
        init = '(u32)' if integer else ''
        expr = '(void*)(base + ' + index + ' * 0x88)' if integer else 'base + ' + index + ' * 0x88'
        return (indent + '{\n' + indent + '    ' + typ + ' ' + qualifier + 'base = ' + init + 'globals->' + member + ';\n' +
                indent + '    offset += fn_801FB3B4((u8*)output + offset, ' + expr + ', ' + flag + ');\n' + indent + '}')
    return pattern.sub(repl, s)

def expression(s, kind):
    pattern = re.compile(r'globals->(first|second) \+ ([\w.]+) \* 0x88')
    def repl(m):
        member, index = m.groups()
        if kind == 'integer':
            return '(void*)((u32)globals->' + member + ' + ' + index + ' * 0x88)'
        if kind == 'reverse':
            return index + ' * 0x88 + globals->' + member
        if kind == 'index':
            return '&globals->' + member + '[' + index + ' * 0x88]'
        if kind == 'cast-index':
            return '(void*)((u32)&globals->' + member + ' + ' + index + ' * 0x88)'
    return pattern.sub(repl, s)

if __name__ == '__main__':
    variants = [
        ('scoped-pointer', scoped(ORDERED), 'Limit each member-base temporary to its call site, separating base addition from scaled index.'),
        ('scoped-const-pointer', scoped(ORDERED, 'const '), 'Const local member address at each call site may retain symbol-plus-addend address form.'),
        ('scoped-integer', scoped(ORDERED, integer=True), 'Integer member-base temporary may block pointer-address reassociation while preserving PPC32 addresses.'),
        ('scoped-const-integer', scoped(ORDERED, 'const ', True), 'Const integer member-base temporary at each call site.'),
        ('integer-address', expression(ORDERED, 'integer'), 'Cast member address to integer before adding byte index to change address folding.'),
        ('reverse-address', expression(ORDERED, 'reverse'), 'Reverse commutative pointer-plus-byte-index operand order.'),
        ('subscript-address', expression(ORDERED, 'index'), 'Use address of byte array subscript.'),
        ('array-object-address', expression(ORDERED, 'cast-index'), 'Cast pointer to whole member array to integer before addition.'),
    ]
    try:
        for args in variants:
            measure(*args)
    finally:
        SOURCE.write_text(ORDERED)

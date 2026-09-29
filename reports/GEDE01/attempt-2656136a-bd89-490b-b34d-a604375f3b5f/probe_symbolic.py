import re
from probe import HERE, SOURCE, measure
from probe_addresses import ORDERED, scoped

def direct_members(s):
    return re.sub(r'globals->(first|second)\b', r'lbl_8063C6B8.\1', s)

def aliases(s, storage):
    s = direct_members(s)
    before, after = s.split('    header.field00', 1)
    for member in ['first', 'second']:
        before += '    ' + storage + 'u8* const ' + member + ' = lbl_8063C6B8.' + member + ';\n'
        after = re.sub(r'lbl_8063C6B8\.' + member + r'\b', member, after)
    return before + '    header.field00' + after

if __name__ == '__main__':
    variants = [
        ('direct-members-ordered', direct_members(ORDERED), 'Direct canonical member addresses with const retained global base and correct register order.'),
        ('scoped-direct-members', direct_members(scoped(ORDERED)), 'Separate direct canonical member-address materialization at each call site.'),
        ('scoped-direct-const', direct_members(scoped(ORDERED, 'const ')), 'Scoped const aliases initialized from direct canonical member addresses.'),
        ('static-const-members', aliases(ORDERED, 'static '), 'Function-local static const pointer aliases may preserve canonical symbol-plus-addend address constants; inspect for emitted data.'),
        ('auto-const-two-members', aliases(ORDERED, ''), 'Only first/second aliases, avoiding persistent primary/secondary pointer pressure.'),
    ]
    try:
        for args in variants:
            measure(args[0] + '-v2', *args[1:])
    finally:
        SOURCE.write_text(scoped(ORDERED))

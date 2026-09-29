from probe import BASE, HERE, SOURCE, measure, typed_blocks, typed_entries
from probe_arrays import ROUND, array_form

CONST = ROUND.replace('BlockGlobals* globals', 'BlockGlobals* const globals')

def member_constants(s, direct=False):
    text = '\n'
    for member in ['first', 'second', 'primary', 'secondary', 'entries']:
        text += '    u8* const ' + member + ' = ' + ('lbl_8063C6B8.' if direct else 'globals->') + member + ';\n'
    before, after = s.split('    header.field00', 1)
    for member in ['first', 'second', 'primary', 'secondary', 'entries']:
        after = after.replace('globals->' + member, member)
    return before + text + '    header.field00' + after

if __name__ == '__main__':
    variants = [
        ('const-typed-blocks', typed_blocks(CONST), 'Combine successful const base retention with typed block subscript addressing.'),
        ('const-block-array', array_form(ROUND, 'Block').replace('Block* globals', 'Block* const globals'), 'Const array base with canonical symbol targets.'),
        ('const-members', member_constants(CONST), 'Const member-pointer aliases may represent symbol-plus-addend constants rather than fold member offsets into variable indexing.'),
        ('const-members-direct', member_constants(CONST, True), 'Initialize const member pointers directly from canonical global member addresses.'),
        ('const-reverse-step', CONST.replace('i++, entry += 0x14', 'entry += 0x14, i++'), 'With the base now retained, reverse induction update order to match retail cursor-before-counter scheduling.'),
        ('const-offset-first', CONST.replace('entry = globals->entries;\n    offset = 0x40;', 'offset = 0x40;\n    entry = globals->entries;'), 'With const base retention, change induction definition order for register allocation.'),
        ('const-for-init', CONST.replace('    entry = globals->entries;\n    offset = 0x40;\n    for (i = 0;', '    for (entry = globals->entries, i = 0, offset = 0x40;'), 'Const base plus retail induction-definition order.'),
        ('const-offset-decl', CONST.replace('u16 offset;', 'u16 offset = 0x40;').replace('    offset = 0x40;\n', ''), 'Earlier output-offset lifetime with retained const global base.'),
        ('const-index-decl', CONST.replace('int i;', 'int i = 0;').replace('for (i = 0;', 'for (;'), 'Earlier index lifetime with retained const global base.'),
    ]
    try:
        for args in variants:
            measure(*args)
    finally:
        SOURCE.write_text(CONST)

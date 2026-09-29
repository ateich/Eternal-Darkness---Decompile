from probe import HERE, SOURCE, measure
from probe_const import CONST
from probe_arrays import ROUND, array_form

def ordered(s):
    return s.replace('u16 offset;\n    int i;\n    u8* entry;', 'u8* entry;\n    int i;\n    u16 offset;')

def retail_loop(s):
    return s.replace('    entry = globals->entries;\n    offset = 0x40;\n    for (i = 0;', '    for (entry = globals->entries, i = 0, offset = 0x40;').replace('i++, entry += 0x14', 'entry += 0x14, i++')

if __name__ == '__main__':
    variants = [
        ('const-declaration-order', ordered(CONST), 'MWCC appears to assign callee-saved registers in declaration order; declare cursor before index before u16 offset.'),
        ('const-order-loop', retail_loop(ordered(CONST)), 'Combine declaration order with cursor/index/offset initialization order and cursor-before-index update.'),
        ('array-declaration-order', ordered(array_form(ROUND, 'Block').replace('Block* globals', 'Block* const globals')), 'Apply corrected declaration order to const block array.'),
    ]
    try:
        for args in variants:
            measure(*args)
    finally:
        SOURCE.write_text(retail_loop(ordered(CONST)))

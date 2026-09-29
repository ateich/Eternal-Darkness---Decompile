import json
import re
from probe import BASE, HERE, SOURCE, measure

ROUND = BASE.replace('return (offset + 0x1F) & ~0x1F;', 'return (u16)(offset + 0x1F) & ~0x1F;')

def array_form(s, element):
    declaration = ('typedef struct Block { u8 data[0x88]; } Block;\nextern Block lbl_8063C6B8[];' if element == 'Block'
                   else 'extern u8 lbl_8063C6B8[][0x88];')
    s = re.sub(r'typedef struct BlockGlobals \{.*?extern BlockGlobals lbl_8063C6B8;', declaration, s, flags=re.S)
    s = s.replace('BlockGlobals* globals = &lbl_8063C6B8;', 'Block* globals = lbl_8063C6B8;' if element == 'Block' else 'u8 (*globals)[0x88] = lbl_8063C6B8;')
    s = s.replace('globals->entries', '(u8*)&globals[26]')
    s = s.replace('globals->primary', '&globals[24]').replace('globals->secondary', '&globals[25]')
    for field, index, addend in [('second','record.first_index',12),('first','record.second_index',0),('second','lbl_8064C3A8',12),('first','lbl_8064C3A8',0)]:
        s = s.replace(f'globals->{field} + {index} * 0x88', f'&globals[{index} + {addend}]')
    return s

if __name__ == '__main__':
    block = array_form(ROUND, 'Block')
    byte = array_form(ROUND, 'u8')
    variants = [
        ('block-array', block, 'Represent contiguous 0x88-byte global blocks as one canonical external array, including entry storage at block 26.'),
        ('byte-array-2d', byte, 'Use array decay on a two-dimensional canonical block array instead of aggregate members.'),
        ('array-member-local', block.replace('u8* entry;', 'u8* entry;\n    Block* first;\n    Block* second;').replace('    header.field00', '    first = &globals[0];\n    second = &globals[12];\n    header.field00', 1).replace('&globals[record.first_index + 12]', '&second[record.first_index]').replace('&globals[record.second_index + 0]', '&first[record.second_index]').replace('&globals[lbl_8064C3A8 + 12]', '&second[lbl_8064C3A8]').replace('&globals[lbl_8064C3A8 + 0]', '&first[lbl_8064C3A8]'), 'Separate typed first/second array bases from indexing to discourage folding the field offset into the variable index.'),
        ('aggregate-array-one', ROUND.replace('extern BlockGlobals lbl_8063C6B8;', 'extern BlockGlobals lbl_8063C6B8[];').replace('= &lbl_8063C6B8;', '= lbl_8063C6B8;'), 'Canonical object as array of aggregate, testing different address-expression representation.'),
        ('aggregate-pointer-const', ROUND.replace('BlockGlobals* globals', 'BlockGlobals* const globals'), 'Const pointer may allow different global CSE scheduling.'),
    ]
    try:
        for args in variants:
            measure(*args)
    finally:
        SOURCE.write_text(ROUND)

"""Run recorded single-TU experiments; invoke from eternal-darkness-decomp.

Restores the incoming source after each trial. Trial patches, command
outputs and raw objdiff function records are stored in the adjacent JSON.
"""
import difflib
import hashlib
import json
from pathlib import Path
import subprocess
import sys

REPORT = Path('reports/GEDE01/trials-f0b1560d-965d-463f-bbb3-a2a223e8b2be.json')
SOURCE = Path('src/game/game_fn_801EDE34.c')
OBJECT = Path('build/GEDE01/src/game/game_fn_801EDE34.o')
data = json.loads(REPORT.read_text())
base = data['baseline_source']

def compact_symbol(symbol, instructions=False):
    result = {k: symbol[k] for k in ['name', 'address', 'size', 'match_percent'] if k in symbol}
    if instructions:
        result['generated_disassembly'] = [row['instruction']['formatted'] for row in symbol.get('instructions', []) if row.get('instruction', {}).get('formatted')]
    return result

def run(name, source):
    entry = {'name': name, 'patch': ''.join(difflib.unified_diff(base.splitlines(True), source.splitlines(True), fromfile=str(SOURCE), tofile=str(SOURCE))), 'commands': []}
    incoming = SOURCE.read_text()
    SOURCE.write_text(source)
    try:
        commands = [
            ['.tools/bin/ninja', '-j2', str(OBJECT)],
            ['build/tools/objdiff-cli', 'diff', '-p', '.', '-u', 'main/game/game_fn_801EDE34', 'fn_801EDE34', '-o', 'build/GEDE01/trial-f0b1560d.json', '--format', 'json'],
        ]
        for cmd in commands:
            p = subprocess.run(cmd, text=True, capture_output=True)
            entry['commands'].append({'argv': cmd, 'returncode': p.returncode, 'stdout': p.stdout, 'stderr': p.stderr})
            if p.returncode:
                break
        else:
            result = json.loads(Path('build/GEDE01/trial-f0b1560d.json').read_text())
            for side in ['left', 'right']:
                entry[side] = compact_symbol(next(s for s in result[side]['symbols'] if s['name'] == 'fn_801EDE34'), side == 'right')
            entry['object_sha256'] = hashlib.sha256(OBJECT.read_bytes()).hexdigest()
            print(name, entry['left'].get('match_percent'), entry['right']['size'], flush=True)
    finally:
        data['trials'].append(entry)
        REPORT.write_text(json.dumps(data, indent=2) + '\n')
        SOURCE.write_text(incoming)

variants = {'baseline': base}
helper = 'static int get_value(int* values, int index) { return values[index]; }\nstatic void set_value(int* values, int index, int value) { values[index] = value; }\n\n'
s = base.replace('void fn_801EDE34(', helper + 'void fn_801EDE34(')
for array in ['values0', 'state->values1', 'state->values2']:
    n = array[-1]
    s = s.replace(array + '[index] = value' + n + ';', 'set_value(' + array + ', index, value' + n + ');')
    s = s.replace(array + '[index]', 'get_value(' + array + ', index)')
variants['inline_access_helpers'] = s
helper = 'static int* field_base(StateRegion* state, int field) { return (int*)((char*)state + 0x2938 + field * 0x40); }\n\n'
s = base.replace('void fn_801EDE34(', helper + 'void fn_801EDE34(')
for n in range(3):
    s = s.replace('state->values' + str(n), 'field_base(state, ' + str(n) + ')')
variants['inline_field_base_helper'] = s
helper = 'static int* element(int* values, int index) { return values + index; }\n\n'
s = base.replace('void fn_801EDE34(', helper + 'void fn_801EDE34(')
for array in ['values0', 'state->values1', 'state->values2']:
    s = s.replace(array + '[index]', '*element(' + array + ', index)')
variants['inline_element_helper'] = s
s = base.replace('int* values0 = state->values0;', 'int* values0 = state->values0;\n    unsigned int offset = (unsigned int)index * 4;')
for array in ['values0', 'state->values1', 'state->values2']:
    s = s.replace(array + '[index]', '*(int*)((unsigned int)' + array + ' + offset)')
variants['integer_address_arithmetic'] = s

# Keep the field address in a union, so member propagation happens at a
# different compiler stage from pointer arithmetic. No volatile side effects.
s = base.replace('int* values0 = state->values0;', 'union { int* p; unsigned int bits; } address;\n    int* values0;\n    address.p = state->values0;\n    values0 = (int*)address.bits;')
variants['union_field_address'] = s
helper = 'static int* field_address(int* p) { union { int* p; unsigned int bits; } u; u.p = p; return (int*)u.bits; }\n\n'
s = base.replace('void fn_801EDE34(', helper + 'void fn_801EDE34(')
for n in range(3):
    s = s.replace('state->values' + str(n), 'field_address(state->values' + str(n) + ')')
variants['union_all_field_addresses'] = s

# A pointer-valued inline helper returning an aggregate can exercise a
# different scalar-replacement/inlining path without changing the accesses.
helper = 'typedef struct Field { int* data; } Field;\nstatic Field field(int* p) { Field f; f.data = p; return f; }\n\n'
s = base.replace('void fn_801EDE34(', helper + 'void fn_801EDE34(')
for n in range(3):
    s = s.replace('state->values' + str(n), 'field(state->values' + str(n) + ').data')
variants['aggregate_return_field_addresses'] = s

s = base.replace('int* values0 = state->values0;', 'int* values0 = state->values0;\n    int* cursor;')
s = s.replace('values0[index] != value0', '*(cursor = values0 + index) != value0')
s = s.replace('value1 != state->values1[index]', 'value1 != *(cursor = state->values1 + index)')
s = s.replace('value2 != state->values2[index]', 'value2 != *(cursor = state->values2 + index)')
variants['short_circuit_cursor'] = s

# Access the fixed-width cache words as unsigned bits on the read side,
# preserving signed input bit patterns and the existing signed stores.
s = base
for array in ['values0', 'state->values1', 'state->values2']:
    n = array[-1]
    s = s.replace(array + '[index] != value' + n, '((unsigned int*)' + array + ')[index] != (unsigned int)value' + n)
    s = s.replace('value' + n + ' != ' + array + '[index]', '(unsigned int)value' + n + ' != ((unsigned int*)' + array + ')[index]')
variants['unsigned_read_signed_store'] = s

s = base.replace('values0[index]', 'index[values0]').replace('state->values1[index]', 'index[state->values1]').replace('state->values2[index]', 'index[state->values2]')
variants['commuted_subscripts'] = s

# Narrow only the array element type representation, not the public ABI.
s = base.replace('int values', 'long values').replace('int* values0', 'long* values0')
variants['long_cache_words'] = s

variants['register_union_addresses'] = variants['union_all_field_addresses'].replace('union { int* p; unsigned int bits; } u;', 'register union { int* p; unsigned int bits; } u;')
variants['union_pointer_members'] = variants['union_all_field_addresses'].replace('unsigned int bits;', 'void* bits;')
variants['union_same_pointer_members'] = variants['union_all_field_addresses'].replace('unsigned int bits;', 'int* bits;')
variants['register_union_pointer_members'] = variants['union_pointer_members'].replace('union {', 'register union {')
variants['register_aggregate_fields'] = variants['aggregate_return_field_addresses'].replace('Field f;', 'register Field f;')

# Return the union by value, separating assignment from member extraction.
helper = 'typedef union Field { int* p; unsigned int bits; } Field;\nstatic Field field(int* p) { Field f; f.p = p; return f; }\n\n'
s = base.replace('void fn_801EDE34(', helper + 'void fn_801EDE34(')
for n in range(3):
    s = s.replace('state->values' + str(n), '((int*)field(state->values' + str(n) + ').bits)')
variants['union_return_fields'] = s

# Address conversion through the address of a local pointer also exposes
# representation to the compiler without adding observable memory writes.
helper = 'static int* field_address(int* p) { return (int*)*(unsigned int*)&p; }\n\n'
s = base.replace('void fn_801EDE34(', helper + 'void fn_801EDE34(')
for n in range(3):
    s = s.replace('state->values' + str(n), 'field_address(state->values' + str(n) + ')')
variants['pointer_representation_load'] = s

# Reduce the scope of the new representation barrier to learn whether
# keeping just one address unindexed is enough to change other selections.
for fields in [(1,), (2,), (1, 2), (0, 1), (0, 2)]:
    helper = 'static int* field_address(int* p) { union { int* p; unsigned int bits; } u; u.p = p; return (int*)u.bits; }\n\n'
    s = base.replace('void fn_801EDE34(', helper + 'void fn_801EDE34(')
    for n in fields:
        s = s.replace('state->values' + str(n), 'field_address(state->values' + str(n) + ')')
    variants['union_fields_' + ''.join(map(str, fields))] = s

# Give the optimizer a matrix rather than three unrelated member arrays.
s = base.replace('int values0[16];\n    int values1[16];\n    int values2[16];', 'int values[3][16];')
for n in range(3):
    s = s.replace('state->values' + str(n), 'state->values[' + str(n) + ']')
variants['matrix_fields'] = s

# Read through a const view while writing through the state object; this
# changes the pointer expression lifetime without changing memory semantics.
s = base.replace('int* values0 = state->values0;', 'const int* values0 = state->values0;')
s = s.replace('values0[index] = value0;', 'state->values0[index] = value0;')
variants['const_read_view'] = s

# Preserve the explicit first field base, but use offsets relative to it
# on only one side of the external call.
for where in ['read', 'write', 'both']:
    a, b = base.split('        fn_8022A118(index, value0, value1, value2);')
    if where in ['read', 'both']:
        a = a.replace('state->values1[index]', 'values0[index + 16]').replace('state->values2[index]', 'values0[index + 32]')
    if where in ['write', 'both']:
        b = b.replace('state->values1[index]', 'values0[index + 16]').replace('state->values2[index]', 'values0[index + 32]')
    variants['relative_first_field_' + where] = a + '        fn_8022A118(index, value0, value1, value2);' + b

variants['union_initialized'] = variants['union_all_field_addresses'].replace('u; u.p = p;', 'u = { p };')
variants['union_reverse_conversion'] = variants['union_all_field_addresses'].replace('u.p = p; return (int*)u.bits;', 'u.bits = (unsigned int)p; return u.p;')
variants['union_reverse_initialized'] = variants['union_all_field_addresses'].replace('int* p; unsigned int bits;', 'unsigned int bits; int* p;').replace('u; u.p = p; return (int*)u.bits;', 'u = { (unsigned int)p }; return u.p;')
variants['union_integer_return'] = variants['union_all_field_addresses'].replace('static int* field_address(', 'static unsigned int field_address(').replace('return (int*)u.bits;', 'return u.bits;')
for n in range(3):
    variants['union_integer_return'] = variants['union_integer_return'].replace('field_address(state->values' + str(n) + ')', '((int*)field_address(state->values' + str(n) + '))')

# Union aggregate assignment has different optimization rules from scalar
# member writes, including a chance to remove otherwise dead stack stores.
variants['union_copy'] = variants['union_all_field_addresses'].replace('u; u.p = p; return (int*)u.bits;', 'u, v; u.p = p; v = u; return (int*)v.bits;')

# Round-tripping a word address through a scalar wider integer avoids union
# memory while testing whether integer/pointer reassociation is type-driven.
for cast in ['int', 'long', 'unsigned long long', 'long long']:
    helper = 'static int* field_address(int* p) { ' + cast + ' address = (' + cast + ')(unsigned int)p; return (int*)(unsigned int)address; }\n\n'
    s = base.replace('void fn_801EDE34(', helper + 'void fn_801EDE34(')
    for n in range(3):
        s = s.replace('state->values' + str(n), 'field_address(state->values' + str(n) + ')')
    variants['scalar_address_' + cast.replace(' ', '_')] = s

# Field-specific helpers with legal constant initializers isolate whether
# the nonconstant C89 initializer limitation was hiding a useful code shape.
helper = ''
for n in range(3):
    helper += 'static int* field' + str(n) + '(void) { union { int* p; unsigned int bits; } u = { &lbl_80639260.values' + str(n) + '[0] }; return (int*)u.bits; }\n'
s = base.replace('void fn_801EDE34(', helper + '\nvoid fn_801EDE34(')
for n in range(3):
    s = s.replace('state->values' + str(n), 'field' + str(n) + '()')
variants['constant_union_initializers'] = s

variants['union_full_width_bitfield'] = variants['union_all_field_addresses'].replace('unsigned int bits;', 'unsigned int bits : 32;')

# A single scratch union reused in the local scope can expose all field
# bases while allowing dead-store elimination across each successive use.
s = base.replace('int* values0 = state->values0;', 'union { int* p; unsigned int bits; } address;\n    int* values0;\n    address.p = state->values0;\n    values0 = (int*)address.bits;')
for n in [1, 2]:
    s = s.replace('state->values' + str(n) + '[index]', '((address.p = state->values' + str(n) + '), (int*)address.bits)[index]')
variants['shared_scratch_union'] = s

wide = variants['scalar_address_unsigned_long_long']
s = wide.replace('int* values0 = field_address(state->values0);', 'int* values0 = state->values0;').replace('values0[index]', 'field_address(values0)[index]')
variants['wide_first_address_at_access'] = s

for order in ['index_first', 'state_first', 'field_first']:
    declaration = {
        'index_first': 'unsigned int offset = (unsigned int)index * 4;\n    StateRegion* state = &lbl_80639260;\n    int* values0 = field_address(state->values0);',
        'state_first': 'StateRegion* state = &lbl_80639260;\n    unsigned int offset = (unsigned int)index * 4;\n    int* values0 = field_address(state->values0);',
        'field_first': 'StateRegion* state = &lbl_80639260;\n    int* values0 = field_address(state->values0);\n    unsigned int offset = (unsigned int)index * 4;',
    }[order]
    s = wide.replace('StateRegion* state = &lbl_80639260;\n    int* values0 = field_address(state->values0);', declaration)
    for array in ['values0', 'field_address(state->values1)', 'field_address(state->values2)']:
        s = s.replace(array + '[index]', '*(int*)((char*)' + array + ' + offset)')
    variants['wide_byte_offset_' + order] = s

# Express the conversion at the call sites instead of an inline C helper.
s = wide
s = s.replace('static int* field_address(int* p) { unsigned long long address = (unsigned long long)(unsigned int)p; return (int*)(unsigned int)address; }\n\n', '')
for n in range(3):
    s = s.replace('field_address(state->values' + str(n) + ')', '((int*)(unsigned int)(unsigned long long)(unsigned int)state->values' + str(n) + ')')
variants['wide_direct_cast'] = s

# Carry a widened address for the first field, then narrow at each access.
s = wide.replace('int* values0 = field_address(state->values0);', 'unsigned long long address0 = (unsigned int)state->values0;')
s = s.replace('values0[index]', '((int*)(unsigned int)address0)[index]')
variants['wide_first_address_variable'] = s

for order in ['index_first', 'state_first', 'field_first']:
    s = variants['wide_byte_offset_' + order]
    s = s.replace('int* values0 = field_address(state->values0);', 'int* values0 = state->values0;')
    s = s.replace('(char*)values0 + offset', '(char*)field_address(values0) + offset')
    variants['wide_access_byte_' + order] = s

s = variants['wide_first_address_at_access'].replace('int* values0 = state->values0;', 'int* values0;').replace('if (field_address(values0)[index]', 'if (field_address(values0 = state->values0)[index]')
variants['wide_first_assignment_at_access'] = s
s = variants['wide_first_address_at_access'].replace('int* values0 = state->values0;', 'int* values0 = state->values0;\n    int word_index = index;').replace('[index]', '[word_index]')
variants['wide_local_word_index'] = s

# Put the field conversion inside an element helper, with explicit byte
# offset creation before the field conversion in the inlined helper body.
helper = 'static int* indexed_address(int* p, int index) { unsigned int offset = (unsigned int)index * 4; unsigned long long address = (unsigned int)p; return (int*)((char*)(unsigned int)address + offset); }\n\n'
s = base.replace('void fn_801EDE34(', helper + 'void fn_801EDE34(')
for array in ['values0', 'state->values1', 'state->values2']:
    s = s.replace(array + '[index]', '*indexed_address(' + array + ', index)')
variants['wide_indexed_helper'] = s

for expr in ['((unsigned int)index * 4)', '(index * 4)', '(index << 2)', '((unsigned int)index << 2)']:
    s = variants['wide_access_byte_state_first'].replace('    unsigned int offset = (unsigned int)index * 4;\n', '').replace(' + offset)', ' + ' + expr + ')')
    variants['wide_inline_offset_' + str(len(variants))] = s

s = variants['wide_access_byte_state_first'].replace('unsigned int offset = (unsigned int)index * 4;', 'int offset = index * 4;')
variants['wide_signed_offset'] = s
variants['wide_register_field'] = variants['wide_access_byte_state_first'].replace('int* values0 =', 'register int* values0 =')
variants['wide_register_offset'] = variants['wide_access_byte_state_first'].replace('unsigned int offset =', 'register unsigned int offset =')

# Delay field address materialization by leaving the first field pointer
# assigned at the first load, while all later address uses remain explicit.
s = variants['wide_access_byte_state_first'].replace('int* values0 = state->values0;', 'int* values0;').replace('field_address(values0) + offset) !=', 'field_address(values0 = state->values0) + offset) !=')
variants['wide_byte_assignment_at_load'] = s

s = variants['wide_first_address_at_access']
for array in ['values0', 'state->values1', 'state->values2']:
    s = s.replace('field_address(' + array + ')[index]', 'index[field_address(' + array + ')]')
variants['wide_commuted_access'] = s

s = variants['wide_first_address_at_access']
for array in ['values0', 'state->values1', 'state->values2']:
    s = s.replace('field_address(' + array + ')[index]', '*(int*)((unsigned int)index * 4 + (char*)field_address(' + array + '))')
variants['wide_offset_before_base'] = s

# Make the preserved first-field pointer a byte pointer; pointer scaling
# and address-preserving conversion then stay in separate expression nodes.
s = variants['wide_access_byte_state_first'].replace('int* values0 = state->values0;', 'char* values0 = (char*)state->values0;').replace('field_address(values0)', 'field_address((int*)values0)')
variants['wide_byte_pointer'] = s

# Scope the offset to the condition and the update independently. The
# compiler may still share its value across the call as a temporary.
s = variants['wide_first_address_at_access'].replace('    if (', '    index *= 4;\n    if (').replace('fn_8022A118(index,', 'fn_8022A118(index / 4,')
for array in ['values0', 'state->values1', 'state->values2']:
    s = s.replace('field_address(' + array + ')[index]', '*(int*)((char*)field_address(' + array + ') + index)')
variants['wide_scaled_parameter'] = s

matched = variants['wide_byte_assignment_at_load']
variants['matched_inline_helper'] = matched.replace('static int* field_address(', 'static inline int* field_address(')
variants['matched_macro'] = matched.replace('static int* field_address(int* p) { unsigned long long address = (unsigned long long)(unsigned int)p; return (int*)(unsigned int)address; }', '#define field_address(p) ((int*)(unsigned int)(unsigned long long)(unsigned int)(p))')

if __name__ == '__main__':
    for name in sys.argv[1:] or list(variants):
        run(name, variants[name])

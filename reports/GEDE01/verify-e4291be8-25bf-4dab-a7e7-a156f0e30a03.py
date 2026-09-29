"""Replay the assignment's canonical build, byte, relocation, and legal checks."""
import hashlib
import json
from pathlib import Path
import struct
import subprocess

ROOT = Path(__file__).resolve().parents[2]
AID = 'e4291be8-25bf-4dab-a7e7-a156f0e30a03'
REPORT = ROOT / 'reports/GEDE01'
records = []

def run(args):
    p = subprocess.run(args, cwd=ROOT, text=True, capture_output=True)
    records.append(dict(command=args, cwd='eternal-darkness-decomp', exit_code=p.returncode,
                        stdout=p.stdout, stderr=p.stderr))
    if p.returncode:
        raise RuntimeError(records[-1])
    return p.stdout

def elf(path):
    data = (ROOT / path).read_bytes()
    assert data[:6] == b'\x7fELF\x01\x02'
    shoff = struct.unpack_from('>I', data, 32)[0]
    entsize, count, stridx = struct.unpack_from('>HHH', data, 46)
    headers = [struct.unpack_from('>10I', data, shoff + i * entsize) for i in range(count)]
    def contents(h):
        return data[h[4]:h[4]+h[5]]
    def string(buf, off):
        return buf[off:buf.index(b'\0', off)].decode()
    names = contents(headers[stridx])
    names = [string(names, h[0]) for h in headers]
    tidx = names.index('.text')
    relocs = []
    for h in headers:
        if h[1] != 4 or h[7] != tidx:
            continue
        symtab = headers[h[6]]
        strings = contents(headers[symtab[6]])
        for off in range(h[4], h[4]+h[5], h[9]):
            address, info, addend = struct.unpack_from('>IIi', data, off)
            so = symtab[4] + (info >> 8) * symtab[9]
            name, value, size, sym_info, other, section = struct.unpack_from('>IIIBBH', data, so)
            relocs.append(dict(offset=address, type=info & 255, target=string(strings, name),
                               symbol_value=value, addend=addend))
    text = contents(headers[tidx])
    return text, relocs

def dol_function(path):
    data = (ROOT / path).read_bytes()
    address, size = 0x8018437C, 964
    for i in range(7):
        offset = struct.unpack_from('>I', data, i*4)[0]
        start = struct.unpack_from('>I', data, 0x48+i*4)[0]
        length = struct.unpack_from('>I', data, 0x90+i*4)[0]
        if start <= address and address+size <= start+length:
            return data[offset+address-start:offset+address-start+size]
    raise ValueError('Function missing from DOL')

run(['python3', 'configure.py'])
# Force this one TU to compile and the canonical DOL to relink for captured evidence.
(ROOT / 'src/game/game_fn_8018437C.c').touch()
run(['.tools/bin/ninja', '-j2'])
for name, extra in [('objdiff-canonical', []), ('objdiff', ['-c', 'function_reloc_diffs=name_address'])]:
    out = f'reports/GEDE01/{name}-{AID}.json'
    run(['build/tools/objdiff-cli', 'diff', '-p', '.', '-u', 'main/game/game_fn_8018437C',
         'fn_8018437C', *extra, '-o', out, '--format', 'json-pretty'])
    diff = json.loads((ROOT / out).read_text())
    symbol = next(s for s in diff['left']['symbols'] if s['name'] == 'fn_8018437C')
    assert symbol['match_percent'] == 100.0
    assert not any(i.get('diff_kind') not in (None, 'DIFF_NONE') for i in symbol['instructions'])

target, target_relocs = elf('build/GEDE01/obj/game/game_fn_8018437C.o')
base, base_relocs = elf('build/GEDE01/src/game/game_fn_8018437C.o')
assert target == base and len(base) == 964
assert target_relocs == base_relocs and len(base_relocs) == 38
retail_fn = dol_function('orig/GEDE01/sys/main.dol')
built_fn = dol_function('build/GEDE01/main.dol')
assert retail_fn == built_fn
hashes = run(['sha1sum', 'orig/GEDE01/sys/main.dol', 'build/GEDE01/main.dol'])
assert all(line.split()[0] == 'ea24b6af954876ce072562ff39cdb4c81d32be1f' for line in hashes.splitlines())
run(['python3', 'tools/legal_audit.py'])
run(['git', 'diff', '--check'])
compile_command = run(['.tools/bin/ninja', '-t', 'commands', 'build/GEDE01/src/game/game_fn_8018437C.o'])
ninja = (ROOT / 'build.ninja').read_text().replace('$\n', '')
link_line = next(line for line in ninja.splitlines() if line.startswith('build build/GEDE01/main.elf:'))
source_object = 'build/GEDE01/src/game/game_fn_8018437C.o'
retail_object = 'build/GEDE01/obj/game/game_fn_8018437C.o'
assert source_object in link_line.split() and retail_object not in link_line.split()
link_mentions = dict(source_object=source_object, source_object_is_link_input=True,
                     retail_object_is_link_input=False)
result = dict(assignment_id=AID, target='fn_8018437C', commands=records,
    canonical_percent=100.0, relocation_strict_percent=100.0,
    text_size=964, object_text_bytes_equal=True,
    target_text_sha256=hashlib.sha256(target).hexdigest(), base_text_sha256=hashlib.sha256(base).hexdigest(),
    relocation_records_equal=True, relocation_count=38, target_relocations=target_relocs, base_relocations=base_relocs,
    linked_function_bytes_equal=True, linked_function_sha256=hashlib.sha256(built_fn).hexdigest(),
    dol_sha1='ea24b6af954876ce072562ff39cdb4c81d32be1f', registration='Matching', link_mentions=link_mentions,
    compiler='GC/1.3, unchanged canonical flags and existing object-local -use_lmw_stmw on',
    preserved_source_commit='49ee5dd7a47ba1cd54072d195edb0fdac9659efa',
    new_hypothesis='A u16 return declaration duplicates the explicit mask in the compiler IR and changes register coloring. Declaring the ABI return word u32 while retaining & 0xFFFF removes all eight remaining operand mismatches.',
    semantic_caveats=[
        'The pre-existing reconstruction passes point_x, point_y, and point_z before their first assignment. The matching retail instruction stream likewise consumes those registers before loading the converted coordinates. Undefined C first-use behavior remains explicitly disclosed in source; byte matching does not establish portable defined behavior.',
        'The neighboring fn_8011F760 reconstruction declares unsigned short. This caller declares u32; the callee machine code zero-extends a halfword into the same ABI return register. This is an ABI-compatible caller model, not a claim of ISO-C cross-translation-unit type compatibility. The neighboring TU was not edited.'
    ],
    scope='Only target C source, its configure.py registration, and assignment-specific reports changed. No assembly, new compiler policy, relocation rewriting, shared reconstruction, or neighboring source changes.')
(REPORT / f'verification-{AID}.json').write_text(json.dumps(result, indent=2)+'\n')
print(json.dumps({k:result[k] for k in ('canonical_percent','relocation_strict_percent','text_size','object_text_bytes_equal','relocation_count','linked_function_bytes_equal','dol_sha1')}, indent=2))

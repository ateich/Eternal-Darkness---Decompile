import json, subprocess, sys, hashlib
from pathlib import Path
ID = 'd35bc937-7b70-470d-986d-8001425fdebe'
R=Path('reports/GEDE01')
S=Path('src/game/game_fn_801A7958.c')
base=subprocess.check_output(['git','show','5748c98cfec612900aa400a10aa530a7b8b15e2f:eternal-darkness-decomp/src/game/game_fn_801A7958.c'],text=True)
variant=sys.argv[1]
s=base
if 'table' in variant:
 s=s.replace('extern char lbl_80251528[];', 'typedef struct DebugStrings { char sphere[0x10]; char box[0x1C]; char plane[1]; } DebugStrings;\nextern DebugStrings lbl_80251528;')
 s=s.replace('char* strings = lbl_80251528;', 'DebugStrings* strings = &lbl_80251528;')
 s=s.replace('strings, index', 'strings->sphere, index').replace('strings + 0x10', 'strings->box').replace('strings + 0x2C', 'strings->plane')
if 'entry' in variant:
 s=s.replace('*(s16*)(data + 0xC), *(s16*)(data + 0xE)', '*(s16*)(cursor->data + 0xC), *(s16*)(cursor->data + 0xE)')
if 'direct' in variant:
 s=s.replace('    DebugStrings* strings = &lbl_80251528;\n', '').replace('strings->', 'lbl_80251528.')
if 'cast' in variant:
 s=s.replace('extern char lbl_80251528[];', 'typedef struct DebugStrings { char sphere[0x10]; char box[0x1C]; char plane[1]; } DebugStrings;\nextern char lbl_80251528[];')
 s=s.replace('char* strings = lbl_80251528;', 'DebugStrings* strings = (DebugStrings*)lbl_80251528;')
 s=s.replace('strings, index', 'strings->sphere, index').replace('strings + 0x10', 'strings->box').replace('strings + 0x2C', 'strings->plane')
if 'order' in variant and 'retailorder' not in variant:
 import itertools
 declarations=['    u16 i;','    int index;','    int remainder;','    RegionEntry* cursor = entry;']
 for d in declarations: s=s.replace(d+'\n','')
 order=list(itertools.permutations(declarations))[int(variant.split('order')[1])]
 s=s.replace('    u8* data;', '\n'.join(order)+'\n    u8* data;')
if 'inside' in variant:
 s=s.replace('    char* strings = lbl_80251528;\n','')
 s=s.replace('        index = i;', '        char* strings = lbl_80251528;\n        index = i;')
if 'retailorder' in variant:
 declarations=['    int index;', '    u16 i;', '    RegionEntry* cursor = entry;', '    u8* data;', '    int remainder;']
 for d in declarations: s=s.replace(d+'\n','')
 s=s.replace('    Vec3 vertices[4];', '\n'.join(declarations)+'\n    Vec3 vertices[4];')
if 'literal' in variant:
 s=s.replace('    char* strings = lbl_80251528;\n', '')
 s=s.replace('strings, index', '"Rgn %d - Sphere", index').replace('strings + 0x10', '"Rgn %d - Box\\nEnt %d, Ext %d"').replace('strings + 0x2C', '"Rgn %d - Planes"')
if 'convert' in variant:
 s=s.replace('extern char lbl_80251528[];', 'extern char lbl_80251528[];\nextern double lbl_80650DE8;\ntypedef union UIntToDouble { double value; struct { u32 hi, lo; } words; } UIntToDouble;')
 s=s.replace('    Vec3 vertices[4];', '    UIntToDouble conversion;\n    Vec3 vertices[4];')
 s=s.replace('            fn_800EBA80(1, &position, &sphere_color, 0x78, (float)*(u32*)data);', '            conversion.words.hi = 0x43300000;\n            conversion.words.lo = *(u32*)data;\n            fn_800EBA80(1, &position, &sphere_color, 0x78, (float)(conversion.value - lbl_80650DE8));')
if 'member' in variant:
 s=s.replace('extern char lbl_80251528[];', 'typedef struct DebugStrings { char sphere[0x10]; char box[0x1C]; char plane[1]; } DebugStrings;\nextern char lbl_80251528[];')
 s=s.replace('strings, index', '((DebugStrings*)strings)->sphere, index')
if 'offset' in variant:
 offset=int(variant.split('offset')[1])
 s=s.replace('char* strings = lbl_80251528;', 'char* strings = lbl_80251528 - '+str(offset)+';')
 s=s.replace('strings, index', '(strings + '+str(offset)+'), index').replace('strings + 0x10', 'strings + '+str(16+offset)).replace('strings + 0x2C','strings + '+str(44+offset))
if 'array' in variant:
 s=s.replace('char* strings = lbl_80251528;', 'char (*strings)[0x98] = (char (*)[0x98])lbl_80251528;')
 s=s.replace('strings, index', '&(*strings)[0], index').replace('strings + 0x10','&(*strings)[0x10]').replace('strings + 0x2C','&(*strings)[0x2C]')
S.write_text(s)
log=R/f'experiments-{ID}.jsonl'
cmds=[['.tools/bin/ninja','-v','build/GEDE01/src/game/game_fn_801A7958.o'],['build/tools/objdiff-cli','diff','-p','.','-u','main/game/game_fn_801A7958','fn_801A7958','-o',str(R/f'objdiff-{ID}-{variant}.json'),'--format','json-pretty','-c','function_reloc_diffs=name_address']]
cmds += [['readelf', '-Wr', 'build/GEDE01/obj/game/game_fn_801A7958.o'], ['readelf', '-Wr', 'build/GEDE01/src/game/game_fn_801A7958.o']]
for cmd in cmds:
 p=subprocess.run(cmd,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,text=True)
 with log.open('a') as f: f.write(json.dumps(dict(variant=variant,source_sha256=hashlib.sha256(s.encode()).hexdigest(),command=cmd,returncode=p.returncode,output=p.stdout))+'\n')
 if p.returncode: print(p.stdout);sys.exit(p.returncode)
d=json.loads((R/f'objdiff-{ID}-{variant}.json').read_text())
l=next(x for x in d['left']['symbols'] if x['name']=='fn_801A7958')
r=next(x for x in d['right']['symbols'] if x['name']=='fn_801A7958')
print(variant,l['match_percent'],r['size'])

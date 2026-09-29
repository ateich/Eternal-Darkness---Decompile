"""Reproduce assignment 5 variants; run from eternal-darkness-decomp.
All variants derive from the accepted base source, never from each other.
Restores the best measured source and preserves raw objdiff and command logs.
"""
import pathlib, subprocess, json, difflib
A='3cec4cb7-490c-4f17-8458-d1354bb92fc3'
r=pathlib.Path('reports/GEDE01')
p=pathlib.Path('src/game/game_fn_801858E0.c')
base=subprocess.check_output(['git','show','bb6ce51b7ac9809a3d4fdfb5648d1106291f2ccc:eternal-darkness-decomp/src/game/game_fn_801858E0.c'],text=True)
log=open(r/f'commands-{A}.log','a')
def run(cmd):
    log.write('$ '+ ' '.join(cmd)+'\n'); log.flush()
    v=subprocess.run(cmd,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,text=True)
    log.write(v.stdout+'\nexit='+str(v.returncode)+'\n'); log.flush()
    if v.returncode: raise RuntimeError(cmd)
run(['python3','configure.py'])
variants={'frontier':base,'ordinary_loads':base.replace('extern const volatile','extern const')}
s=variants['ordinary_loads']
a=s.index('    *(u32*)(self + 0x3C)')
s=s[:a]+'''    {
        Words3 first;
        Words3 second;
        first.x = first_x;
        first.y = first_y;
        first.z = first_z;
        second.x = second_x;
        second.y = second_y;
        second.z = second_store.z;
        *(Words3*)(self + 0x3C) = first;
        *(Words3*)(self + 0x48) = first;
        *(Words3*)(self + 0x30) = second;
    }
}
'''
variants['typed_copies']=s
# Natural aggregate copies without volatile source barriers; Word1 tests
# whether the apparently scalar SDA load was an aggregate in the original C.
s=base.replace('extern const volatile','extern const')
a=s.index('    u32 first_x =')
b=s.index('    self[0] =',a)
s=s[:a]+"    Words3 first = lbl_8023B050;\n    Words3 second = lbl_8023B05C;\n    volatile u32 value = lbl_806509F4;\n\n"+s[b:]
a=s.index('    *(u32*)(self + 0x3C)')
s=s[:a]+"    *(Words3*)(self + 0x3C) = first;\n    *(Words3*)(self + 0x48) = first;\n    *(Words3*)(self + 0x30) = second;\n}\n"
variants['ordinary_aggregates']=s
s=s.replace('extern const u32 lbl_806509F4;', 'typedef struct Word1 { u32 x; } Word1;\nextern const Word1 lbl_806509F4;')
s=s.replace('volatile u32 value =', 'Word1 value =').replace('*(u32*)(self + 0x78) = value;', '*(Word1*)(self + 0x78) = value;')
variants['word1_aggregate']=s
s=s.replace('    self[2] = 250;\n    self[3] = 254;\n','').replace('    *(u16*)(self + 8) = 5;','    *(u16*)(self + 8) = 5;\n    self[2] = 250;\n    *(signed char*)(self + 3) = -2;')
variants['word1_store_order']=s
# Aggregate storage qualifiers and explicit cached members test whether
# alias analysis is responsible for reloading all six words after the call.
s=variants['word1_store_order']
variants['const_local_aggregates']=s.replace('    Words3 ', '    const Words3 ').replace('    Word1 value', '    const Word1 value')
variants['register_local_aggregates']=s.replace('    Words3 ', '    register Words3 ').replace('    Word1 value', '    register Word1 value')
s=variants['word1_store_order']
s=s.replace('    self[0] =', '    u32 az = first.z, ay = first.y, ax = first.x;\n    u32 by = second.y, bx = second.x;\n\n    self[0] =',1)
s=s.replace('    *(Words3*)(self + 0x3C) = first;\n    *(Words3*)(self + 0x48) = first;\n    *(Words3*)(self + 0x30) = second;', '    *(u32*)(self + 0x3C) = ax;\n    *(u32*)(self + 0x40) = ay;\n    *(u32*)(self + 0x44) = az;\n    *(u32*)(self + 0x48) = ax;\n    *(u32*)(self + 0x4C) = ay;\n    *(u32*)(self + 0x50) = az;\n    *(u32*)(self + 0x30) = bx;\n    *(u32*)(self + 0x34) = by;\n    *(u32*)(self + 0x38) = second.z;')
variants['cached_members']=s
results=[]
best=(-1,base)
try:
    for name,s in variants.items():
        p.write_text(s)
        patch=''.join(difflib.unified_diff(base.splitlines(True),s.splitlines(True),fromfile='accepted-base',tofile=name))
        (r/f'variant-{A}-{name}.patch').write_text(patch)
        run(['.tools/bin/ninja','-j2','build/GEDE01/src/game/game_fn_801858E0.o'])
        out=r/f'variant-{A}-{name}.json'
        run(['build/tools/objdiff-cli','diff','-p','.','-u','main/game/game_fn_801858E0','fn_801858E0','-o',str(out),'--format','json','-c','function_reloc_diffs=name_address'])
        data=json.loads(out.read_text())
        sym=next(x for x in data['left']['symbols'] if x['name']=='fn_801858E0')
        right=next(x for x in data['right']['symbols'] if x['name']=='fn_801858E0')
        score=sym['match_percent']
        results.append(dict(variant=name,score=score,size=right['size']))
        print(results[-1],flush=True)
        if score>best[0]: best=(score,s)
finally:
    p.write_text(best[1])
    (r/f'experiments-{A}.json').write_text(json.dumps(results,indent=2)+'\n')
    run(['.tools/bin/ninja','-j2','build/GEDE01/src/game/game_fn_801858E0.o'])

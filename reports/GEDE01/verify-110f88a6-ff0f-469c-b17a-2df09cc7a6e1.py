"""Assigned-object verification only. Run from eternal-darkness-decomp."""
from collections import Counter
import hashlib, json, struct, subprocess
from pathlib import Path
A='110f88a6-ff0f-469c-b17a-2df09cc7a6e1'
R=Path('reports/GEDE01')
T='fn_8002DAE0'
objects=['build/GEDE01/obj/game/game_fn_8002DAE0.o','build/GEDE01/src/game/game_fn_8002DAE0.o']
result={'assignment_id':A,'commands':[]}
def run(argv, logfile=None, append=False):
    p=subprocess.run(argv,capture_output=True,text=True)
    record={'argv':argv,'exit_code':p.returncode,'stdout':p.stdout,'stderr':p.stderr}
    result['commands'].append(record)
    if logfile:
        with (R/logfile).open('a' if append else 'w') as f:
            f.write('$ '+' '.join(argv)+'\n'+p.stdout+p.stderr+'\nEXIT_CODE='+str(p.returncode)+'\n')
    (R/f'verification-{A}.json').write_text(json.dumps(result,indent=2)+'\n')
    if p.returncode: raise RuntimeError(record)
    return p.stdout
run(['python3','configure.py'],f'configure-{A}.log',True)
# Force a fresh assigned-object compile without removing or touching private inputs.
Path('src/game/game_fn_8002DAE0.c').touch()
run(['.tools/bin/ninja','-v',objects[1].replace('.o','.externalized')],f'build-{A}.log',True)
for suffix,flags in [('',[]),('-reloc-strict',['-c','function_reloc_diffs=all'])]:
    run(['build/tools/objdiff-cli','diff','-1',objects[0],'-2',objects[1],T,*flags,'-o',str(R/f'objdiff{suffix}-{A}.json'),'--format','json-pretty'])
    data=json.loads((R/f'objdiff{suffix}-{A}.json').read_text())
    sides=[next(s for s in data[side]['symbols'] if s['name']==T) for side in ['left','right']]
    result['strict' if suffix else 'canonical']={'match_percent':sides[0]['match_percent'],'sizes':[s['size'] for s in sides],'instruction_diff_kinds':dict(Counter(i.get('diff_kind','DIFF_NONE') for i in sides[0]['instructions']))}
    if not suffix:
        with (R/f'instruction-diff-{A}.log').open('w') as f:
            f.write('Canonical raw objdiff instruction alignment; addresses are actual section offsets.\n')
            for left,right in zip(sides[0]['instructions'],sides[1]['instructions']):
                a,b=left.get('instruction',{}),right.get('instruction',{})
                f.write(f"{left.get('diff_kind','DIFF_NONE'):18} {int(a.get('address',0)):04x} {a.get('formatted',''):50} | {int(b.get('address',0)):04x} {b.get('formatted','')}\n")
for i,obj in enumerate(objects):
    run(['build/binutils/powerpc-eabi-readelf','-Wr',obj],f'relocations-{A}.log',i!=0)
    run(['build/binutils/powerpc-eabi-objdump','-dr',obj],f'disassembly-{A}.log',i!=0)
def relocs(path):
    data=Path(path).read_bytes()
    assert data[:6]==b'\x7fELF\x01\x02'
    off=struct.unpack_from('>I',data,32)[0]
    size,count=struct.unpack_from('>HH',data,46)
    sections=[struct.unpack_from('>10I',data,off+i*size) for i in range(count)]
    entries=[]
    for sh in sections:
        if sh[1]!=4: continue
        syms=sections[sh[6]]; strings=sections[syms[6]]
        for pos in range(sh[4],sh[4]+sh[5],sh[9]):
            address,info,addend=struct.unpack_from('>IIi',data,pos)
            name_offset=struct.unpack_from('>I',data,syms[4]+(info>>8)*syms[9])[0]
            start=strings[4]+name_offset
            name=data[start:data.index(b'\0',start)].decode()
            entries.append({'offset':address,'type':info&255,'target':name,'addend':addend})
    return entries
left,right=map(relocs,objects)
result['relocations']={'retail':left,'candidate':right,'counts':[len(left),len(right)],'all_offsets_types_targets_addends_equal':left==right}
result['source_sha256']=hashlib.sha256(Path('src/game/game_fn_8002DAE0.c').read_bytes()).hexdigest()
result['candidate_object_sha256']=hashlib.sha256(Path(objects[1]).read_bytes()).hexdigest()
result['acceptance']='Attempted NonMatching result only. Full deterministic build, full canonical/strict no-regression, legal audit, and measured retail DOL SHA-1 ea24b6af954876ce072562ff39cdb4c81d32be1f are deferred to the integrator after independent review, as assigned.'
(R/f'verification-{A}.json').write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps({k:result[k] for k in ['canonical','strict','candidate_object_sha256']},indent=2))
print('Relocation equality:',left==right,'counts:',len(left),len(right))

import pathlib, subprocess, json, difflib
A='c329826c-deb7-4153-b16a-70a265146f3c'
r=pathlib.Path('reports/GEDE01'); p=pathlib.Path('src/game/game_fn_8020860C.c'); baseline=p.read_text()
variants={'baseline':baseline}
typeptr=baseline.replace('    s32 busy;', '    s32 busy;\n    u32 *type;').replace('        if (si->type[chan] == 0x80)', '        type = &si->type[chan];\n        if (*type == 0x80)').replace('1, &si->type[chan], 3,','1, type, 3,')
variants['type_pointer']=typeptr
pollptr=typeptr.replace('    u32 poll;', '    u32 poll;\n    u32 *pollAddress;').replace('        interval = (si->poll >> 16)', '        pollAddress = &si->poll;\n        interval = (*pollAddress >> 16)').replace('        poll = si->poll;', '        poll = *pollAddress;')
variants['poll_pointer']=pollptr
clear= pollptr.replace('            response[i] = 0;', '            work->responseTime[i] = 0;')
variants['clear_base']=clear
for name,src in list(variants.items()):
    variants[name+'_next_split']=src.replace('            next = (next + 1) % 4;', '            ++next;\n            next %= 4;')
best=(-1,baseline,'retained')
with (r/f'pointers-{A}.log').open('w') as log:
    for name,source in variants.items():
        log.write('\nVARIANT '+name+'\n'+''.join(difflib.unified_diff(baseline.splitlines(True),source.splitlines(True)))); log.flush()
        p.write_text(source)
        subprocess.run(['.tools/bin/ninja','-j2','build/GEDE01/src/game/game_fn_8020860C.o'],stdout=log,stderr=subprocess.STDOUT,check=True)
        out=r/f'pointers-{A}-{name}.json'
        subprocess.run(['build/tools/objdiff-cli','diff','-p','.', '-u','main/game/game_fn_8020860C','SIInterruptHandler_8020860C','-o',str(out),'--format','json'],stdout=log,stderr=subprocess.STDOUT,check=True)
        data=json.loads(out.read_text()); sym=next(s for s in data['left']['symbols'] if s['name']=='SIInterruptHandler_8020860C')
        score=sym['match_percent']; size=next(s['size'] for s in data['right']['symbols'] if s['name']=='SIInterruptHandler_8020860C')
        log.write(f'RESULT {name} {score} {size}\n'); log.flush();print(name,score,size,flush=True)
        if score>best[0]:best=(score,source,name)
    p.write_text(best[1]);log.write(f'RETAINED {best[2]} {best[0]}\n')
    subprocess.run(['.tools/bin/ninja','-j2','build/GEDE01/src/game/game_fn_8020860C.o'],stdout=log,stderr=subprocess.STDOUT,check=True)

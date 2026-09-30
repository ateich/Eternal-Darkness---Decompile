import pathlib, subprocess, json, difflib
A='c329826c-deb7-4153-b16a-70a265146f3c'
r=pathlib.Path('reports/GEDE01'); p=pathlib.Path('src/game/game_fn_8020860C.c'); baseline=p.read_text()
baseline=baseline.replace('extern u32 __SIRegs','extern volatile u32 __SIRegs')
variants={'baseline':baseline}
combined=baseline.replace('        pollAddress = &si->poll;\n        interval = (*pollAddress >> 16)', '        interval = (*(pollAddress = &si->poll) >> 16)')
variants['poll_embedded_assignment']=combined
for name,s in list(variants.items()):
    variants[name+'_explicit_clear']=s.replace('        for (i = 0; i < 4; i++) {\n            response[i] = 0;\n        }', '        response[0] = 0;\n        work->responseTime[1] = 0;\n        work->responseTime[2] = 0;\n        work->responseTime[3] = 0;')
for name,s in list(variants.items()):
    variants[name+'_earlier_counter']=s.replace('        si->callback = 0;', '        i = 0;\n        si->callback = 0;').replace('        for (i = 0; i < 4; i++) {\n            ++next;', '        for (; i < 4; i++) {\n            ++next;')
best=(-1,baseline,'retained')
with (r/f'finish-{A}.log').open('w') as log:
    for name,source in variants.items():
        log.write('\nVARIANT '+name+'\n'+''.join(difflib.unified_diff(baseline.splitlines(True),source.splitlines(True)))); log.flush()
        p.write_text(source)
        subprocess.run(['.tools/bin/ninja','-j2','build/GEDE01/src/game/game_fn_8020860C.o'],stdout=log,stderr=subprocess.STDOUT,check=True)
        out=r/f'finish-{A}-{name}.json'
        subprocess.run(['build/tools/objdiff-cli','diff','-p','.', '-u','main/game/game_fn_8020860C','SIInterruptHandler_8020860C','-o',str(out),'--format','json'],stdout=log,stderr=subprocess.STDOUT,check=True)
        data=json.loads(out.read_text()); sym=next(s for s in data['left']['symbols'] if s['name']=='SIInterruptHandler_8020860C')
        score=sym['match_percent']; size=next(s['size'] for s in data['right']['symbols'] if s['name']=='SIInterruptHandler_8020860C')
        log.write(f'RESULT {name} {score} {size}\n'); log.flush();print(name,score,size,flush=True)
        if score>best[0]:best=(score,source,name)
    p.write_text(best[1]);log.write(f'RETAINED {best[2]} {best[0]}\n')
    subprocess.run(['.tools/bin/ninja','-j2','build/GEDE01/src/game/game_fn_8020860C.o'],stdout=log,stderr=subprocess.STDOUT,check=True)

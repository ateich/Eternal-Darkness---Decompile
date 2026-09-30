import pathlib, subprocess, json, difflib
A='c329826c-deb7-4153-b16a-70a265146f3c'
r=pathlib.Path('reports/GEDE01'); p=pathlib.Path('src/game/game_fn_8020860C.c'); baseline=p.read_text()
old='''        if (si->type[chan] == 0x80 &&
            (busy = 1,
             (work->packet[chan].chan == -1 && si->chan != chan) ?
                (busy = 0) : busy,
             !busy)) {'''
new='''        if (si->type[chan] == 0x80) {
            busy = 1;
            if (work->packet[chan].chan == -1 && si->chan != chan) {
                busy = 0;
            }
            if (!busy) {'''
nested=baseline.replace(old,new).replace('65) / 8);\n        }','65) / 8);\n            }\n        }')
variants={'retained':baseline,'nested':nested}
pointers=nested.replace('    s32 busy;', '    s32 busy;\n    volatile u32 *response;\n    SIPollingHandler *handlers;')
pointers=pointers.replace('        vcount = fn_802181F4() + 1;','        vcount = fn_802181F4() + 1;\n        response = work->responseTime;')
pointers=pointers.replace('work->responseTime[i]', 'response[i]')
pointers=pointers.replace('        for (i = 0; i < 4; i++) {\n            if (work->pollingHandler', '        handlers = work->pollingHandler;\n        for (i = 0; i < 4; i++) {\n            if (work->pollingHandler').replace('work->pollingHandler[i]','handlers[i]')
variants['array_bases']=pointers
for name,s in list(variants.items()):
    if name=='retained':continue
    variants[name+'_alarm']=s.replace('    u32 alarm[40];','    struct { u32 opaque[10]; } alarm[4];').replace('&work->alarm[next * 10]','&work->alarm[next]')
best=(-1,baseline,'retained')
with (r/f'refine-{A}.log').open('w') as log:
    for name,source in variants.items():
        log.write('\nVARIANT '+name+'\n'+''.join(difflib.unified_diff(baseline.splitlines(True),source.splitlines(True)))); log.flush()
        p.write_text(source)
        subprocess.run(['.tools/bin/ninja','-j2','build/GEDE01/src/game/game_fn_8020860C.o'],stdout=log,stderr=subprocess.STDOUT,check=True)
        out=r/f'refine-{A}-{name}.json'
        subprocess.run(['build/tools/objdiff-cli','diff','-p','.', '-u','main/game/game_fn_8020860C','SIInterruptHandler_8020860C','-o',str(out),'--format','json'],stdout=log,stderr=subprocess.STDOUT,check=True)
        data=json.loads(out.read_text()); sym=next(s for s in data['left']['symbols'] if s['name']=='SIInterruptHandler_8020860C')
        score=sym['match_percent']; size=next(s['size'] for s in data['right']['symbols'] if s['name']=='SIInterruptHandler_8020860C')
        log.write(f'RESULT {name} {score} {size}\n'); log.flush();print(name,score,size,flush=True)
        if score>best[0]:best=(score,source,name)
    p.write_text(best[1]);log.write(f'RETAINED {best[2]} {best[0]}\n')
    subprocess.run(['.tools/bin/ninja','-j2','build/GEDE01/src/game/game_fn_8020860C.o'],stdout=log,stderr=subprocess.STDOUT,check=True)

import pathlib, subprocess, json, difflib
A='c329826c-deb7-4153-b16a-70a265146f3c'
r=pathlib.Path('reports/GEDE01'); p=pathlib.Path('src/game/game_fn_8020860C.c'); baseline=p.read_text()
variants={'baseline':baseline}
for where in ['before','after']:
    s=baseline.replace('    SIWork *work =', '    s32 savedInterrupt = interrupt;\n    OSContext *savedContext = context;\n    SIWork *work =') if where=='before' else baseline.replace('    SIPollingHandler *handlers;', '    SIPollingHandler *handlers;\n    s32 savedInterrupt = interrupt;\n    OSContext *savedContext = context;')
    s=s.replace('callback(chan, error, context)', 'callback(chan, error, savedContext)').replace('handlers[i](interrupt, context)', 'handlers[i](savedInterrupt, savedContext)')
    variants['param_copies_'+where]=s
variants['short_interrupt']=baseline.replace('typedef signed int s32;', 'typedef signed int s32;\ntypedef signed short s16;').replace('s32 interrupt, OSContext *context','s16 interrupt, OSContext *context')
# The original SDK often declares block-local polling variables; test only the new array pointers.
s=baseline.replace('    volatile u32 *response;\n','').replace('    SIPollingHandler *handlers;\n','').replace('    if ((status & 0x18000000) == 0x18000000) {','    if ((status & 0x18000000) == 0x18000000) {\n        volatile u32 *response;\n        SIPollingHandler *handlers;')
variants['poll_pointer_scope']=s
# Reuse scalar variables only when their phase is over (the callback and vcount never overlap).
s=baseline.replace('    u32 vcount;\n','').replace('vcount','error')
variants['reuse_result']=s
best=(-1,baseline,'retained')
with (r/f'allocation-{A}.log').open('w') as log:
    for name,source in variants.items():
        log.write('\nVARIANT '+name+'\n'+''.join(difflib.unified_diff(baseline.splitlines(True),source.splitlines(True)))); log.flush()
        p.write_text(source)
        subprocess.run(['.tools/bin/ninja','-j2','build/GEDE01/src/game/game_fn_8020860C.o'],stdout=log,stderr=subprocess.STDOUT,check=True)
        out=r/f'allocation-{A}-{name}.json'
        subprocess.run(['build/tools/objdiff-cli','diff','-p','.', '-u','main/game/game_fn_8020860C','SIInterruptHandler_8020860C','-o',str(out),'--format','json'],stdout=log,stderr=subprocess.STDOUT,check=True)
        data=json.loads(out.read_text()); sym=next(s for s in data['left']['symbols'] if s['name']=='SIInterruptHandler_8020860C')
        score=sym['match_percent']; size=next(s['size'] for s in data['right']['symbols'] if s['name']=='SIInterruptHandler_8020860C')
        log.write(f'RESULT {name} {score} {size}\n'); log.flush();print(name,score,size,flush=True)
        if score>best[0]:best=(score,source,name)
    p.write_text(best[1]);log.write(f'RETAINED {best[2]} {best[0]}\n')
    subprocess.run(['.tools/bin/ninja','-j2','build/GEDE01/src/game/game_fn_8020860C.o'],stdout=log,stderr=subprocess.STDOUT,check=True)

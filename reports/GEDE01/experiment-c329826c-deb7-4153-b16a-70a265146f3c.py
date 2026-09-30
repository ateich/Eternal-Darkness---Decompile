import pathlib, subprocess, json, difflib
A='c329826c-deb7-4153-b16a-70a265146f3c'
r=pathlib.Path('reports/GEDE01')
p=pathlib.Path('src/game/game_fn_8020860C.c')
baseline=p.read_text()
variants={'baseline':baseline}
params=baseline.replace('SIInterruptHandler_8020860C(s32 interrupt, OSContext *context)', 'SIInterruptHandler_8020860C(register s32 interrupt, register OSContext *context)')
variants['register_params']=params
allreg=params
start=allreg.index('    SIWork *work =')
end=allreg.index('\n    if ((status',start)
allreg=allreg[:start]+''.join('    register '+line[4:] if line.startswith('    ') else line for line in allreg[start:end].splitlines(True))+allreg[end:]
variants['register_all']=allreg
old='''        busy = 1;
        if (work->packet[chan].chan == -1 && si->chan != chan) {
            busy = 0;
        }
        if (si->type[chan] == 0x80 && !busy) {'''
new='''        if (si->type[chan] == 0x80 &&
            (busy = 1,
             (work->packet[chan].chan == -1 && si->chan != chan) ?
                (busy = 0) : busy,
             !busy)) {'''
variants['type_first']=baseline.replace(old,new)
variants['type_first_register']=allreg.replace(old,new)
direct=baseline.replace('    SIWork *work = &Packet_80640B68;\n','').replace('    SIControl *si = &Si_802FCA20;\n','').replace('work->','Packet_80640B68.').replace('si->','Si_802FCA20.')
variants['direct_globals']=direct
variants['direct_globals_type_first']=baseline.replace(old,new).replace('    SIWork *work = &Packet_80640B68;\n','').replace('    SIControl *si = &Si_802FCA20;\n','').replace('work->','Packet_80640B68.').replace('si->','Si_802FCA20.')
for name,source in list(variants.items()):
    si='Si_802FCA20.' if 'direct_globals' in name else 'si->'
    source=source.replace('poll = '+si+'poll;\n        interval = (poll >> 16)', 'interval = ('+si+'poll >> 16)')
    source=source.replace('        for (i = 0; i < 4; i++) {\n            if (poll &', '        poll = '+si+'poll;\n        for (i = 0; i < 4; i++) {\n            if (poll &')
    variants[name]=source
best=(-1,baseline,'baseline')
with (r/f'experiment-{A}.log').open('w') as log:
    for name,source in variants.items():
        log.write('\nVARIANT '+name+'\n'+''.join(difflib.unified_diff(baseline.splitlines(True),source.splitlines(True))))
        log.flush()
        p.write_text(source)
        subprocess.run(['.tools/bin/ninja','-j2','build/GEDE01/src/game/game_fn_8020860C.o'],stdout=log,stderr=subprocess.STDOUT,check=True)
        out=r/f'experiment-{A}-{name}.json'
        subprocess.run(['build/tools/objdiff-cli','diff','-p','.', '-u','main/game/game_fn_8020860C','SIInterruptHandler_8020860C','-o',str(out),'--format','json'],stdout=log,stderr=subprocess.STDOUT,check=True)
        data=json.loads(out.read_text()); sym=next(s for s in data['left']['symbols'] if s['name']=='SIInterruptHandler_8020860C')
        score=sym['match_percent']; size=next(s['size'] for s in data['right']['symbols'] if s['name']=='SIInterruptHandler_8020860C')
        log.write(f'RESULT {name} {score} {size}\n'); log.flush()
        print(name,score,size,flush=True)
        if score>best[0]: best=(score,source,name)
    p.write_text(best[1]); log.write(f'RETAINED {best[2]} {best[0]}\n')

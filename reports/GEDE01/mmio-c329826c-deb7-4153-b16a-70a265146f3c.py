import pathlib, subprocess, json, difflib
A='c329826c-deb7-4153-b16a-70a265146f3c'
r=pathlib.Path('reports/GEDE01'); p=pathlib.Path('src/game/game_fn_8020860C.c'); baseline=p.read_text()
variants={'baseline':baseline}
vol=baseline.replace('extern u32 __SIRegs', 'extern volatile u32 __SIRegs')
variants['volatile_mmio']=vol
variants['volatile_clock']=vol.replace('extern u32 __OSBusClock', 'extern volatile u32 __OSBusClock')
# Preserve the memory-mapped register accesses through a typed register block.
regs=vol.replace('extern volatile u32 __SIRegs[64] : 0xCC006400;', 'typedef struct SIRegisters {\n    u32 unused[13];\n    u32 status;\n    u32 comcsr;\n    u32 tail[49];\n} SIRegisters;\nextern volatile SIRegisters __SIRegs : 0xCC006400;').replace('__SIRegs[13]', '__SIRegs.status').replace('__SIRegs[14]', '__SIRegs.comcsr')
variants['typed_mmio']=regs
# Array member addressing with an explicit byte offset retains exact hardware layout.
variants['alarm_byte_offset']=vol.replace('&work->alarm[next * 10]', '(void *)((char *)work + next * 40 + 128)')
variants['type_comma_pointer']=vol.replace('if (*(type = &si->type[chan]) == 0x80)', 'if ((type = si->type + chan, *type) == 0x80)')
best=(-1,baseline,'retained')
with (r/f'mmio-{A}.log').open('w') as log:
    for name,source in variants.items():
        log.write('\nVARIANT '+name+'\n'+''.join(difflib.unified_diff(baseline.splitlines(True),source.splitlines(True)))); log.flush()
        p.write_text(source)
        subprocess.run(['.tools/bin/ninja','-j2','build/GEDE01/src/game/game_fn_8020860C.o'],stdout=log,stderr=subprocess.STDOUT,check=True)
        out=r/f'mmio-{A}-{name}.json'
        subprocess.run(['build/tools/objdiff-cli','diff','-p','.', '-u','main/game/game_fn_8020860C','SIInterruptHandler_8020860C','-o',str(out),'--format','json'],stdout=log,stderr=subprocess.STDOUT,check=True)
        data=json.loads(out.read_text()); sym=next(s for s in data['left']['symbols'] if s['name']=='SIInterruptHandler_8020860C')
        score=sym['match_percent']; size=next(s['size'] for s in data['right']['symbols'] if s['name']=='SIInterruptHandler_8020860C')
        log.write(f'RESULT {name} {score} {size}\n'); log.flush();print(name,score,size,flush=True)
        if score>best[0]:best=(score,source,name)
    p.write_text(best[1]);log.write(f'RETAINED {best[2]} {best[0]}\n')
    subprocess.run(['.tools/bin/ninja','-j2','build/GEDE01/src/game/game_fn_8020860C.o'],stdout=log,stderr=subprocess.STDOUT,check=True)

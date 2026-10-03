import json, subprocess, pathlib, struct, hashlib
root=pathlib.Path(__file__).resolve().parents[2]
aid='5e482c0d-542b-4bc1-8e67-8d4b0d92a4de'
reports=pathlib.Path('reports/GEDE01')
def command(args, f):
    f.write('COMMAND: '+' '.join(args)+'\n');f.flush()
    result=subprocess.run(args,cwd=root,stdout=f,stderr=subprocess.STDOUT)
    f.write(f'EXIT: {result.returncode}\n');f.flush()
    result.check_returncode()
with (root/reports/f'build-final-{aid}.txt').open('w') as f:
    command(['python3','configure.py','--no-progress'],f)
    (root/'src/game/game_fn_8002BFE0.c').touch()
    command(['.tools/bin/ninja','-v','build/GEDE01/src/game/game_fn_8002BFE0.externalized'],f)
    for mode in ['', '-reloc-strict']:
        command(['build/tools/objdiff-cli','diff','-p','.', '-u','main/game/game_fn_8002BFE0','fn_8002BFE0','-o',str(reports/f'objdiff{mode}-{aid}.json'),'--format','json-pretty']+(['-c','function_reloc_diffs=name_address'] if mode else []),f)
objects=['build/GEDE01/obj/game/game_fn_8002BFE0.o','build/GEDE01/src/game/game_fn_8002BFE0.o']
with (root/reports/f'relocations-{aid}.txt').open('w') as f:
    for obj in objects:
        command(['build/binutils/powerpc-eabi-readelf','-rWs',obj],f)
        command(['build/binutils/powerpc-eabi-readelf','-SW',obj],f)
with (root/reports/f'instruction-diff-{aid}.txt').open('w') as f:
    for obj in objects:
        command(['build/binutils/powerpc-eabi-objdump','-dr',obj],f)
    for mode in ['', '-reloc-strict']:
        d=json.loads((root/reports/f'objdiff{mode}-{aid}.json').read_text())
        sides=[next(s for s in d[side]['symbols'] if s['name']=='fn_8002BFE0') for side in ['left','right']]
        assert sides[0]['match_percent']==100.0
        assert int(sides[0]['size'])==int(sides[1]['size'])==384
        assert all(not i.get('diff_kind') for side in sides for i in side['instructions'])
        f.write(f'{mode or "canonical"}: 100%; 384 bytes; no instruction/argument/relocation differences\n')
    def text_section(obj):
        data=(root/obj).read_bytes()
        shoff=struct.unpack_from('>I',data,32)[0]
        shsize,shnum,shstr=struct.unpack_from('>HHH',data,46)
        headers=[struct.unpack_from('>10I',data,shoff+i*shsize) for i in range(shnum)]
        h=headers[shstr];names=data[h[4]:h[4]+h[5]]
        for h in headers:
            if names[h[0]:].split(b'\0')[0]==b'.text': return data[h[4]:h[4]+h[5]]
    text=[text_section(obj) for obj in objects]
    assert text[0]==text[1]
    f.write(f'Raw .text sections byte-identical: {len(text[0])} bytes; SHA-256 {hashlib.sha256(text[0]).hexdigest()}\n')
print('Final canonical and relocation-strict: 100%; raw .text bytes identical.')

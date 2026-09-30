import subprocess, json, hashlib, shlex
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
A='f1f83eb2-71cf-4a55-8967-371fb37ba94f'
P=Path('reports/GEDE01')
def run(name, args):
    with (ROOT/P/(name+'-'+A+'.log')).open('w') as log:
        log.write('$ '+shlex.join(args)+'\n'); log.flush()
        r=subprocess.run(args,cwd=ROOT,stdout=log,stderr=subprocess.STDOUT)
        log.write('exit status: '+str(r.returncode)+'\n')
    if r.returncode: raise RuntimeError(name+' failed: '+str(r.returncode))
run('configure',['python3','configure.py'])
run('build',['.tools/bin/ninja','-j2'])
run('dol-sha1',['sha1sum','build/GEDE01/main.dol'])
assert hashlib.sha1((ROOT/'build/GEDE01/main.dol').read_bytes()).hexdigest()=='ea24b6af954876ce072562ff39cdb4c81d32be1f'
run('legal-audit',['python3','tools/legal_audit.py'])
common=['build/tools/objdiff-cli','diff','-p','.', '-u','main/game/game_fn_802093FC','GetTypeCallback_802093FC','--format','json']
run('canonical-command',common+['-o',str(P/('objdiff-'+A+'.json'))])
run('reloc-strict-command',common+['-c','function_reloc_diffs=name_address','-o',str(P/('objdiff-'+A+'-reloc-strict.json'))])
run('fndiff',['python3','tools/fndiff.py','game/game_fn_802093FC.c','GetTypeCallback_802093FC'])
with (ROOT/P/('relocations-'+A+'.txt')).open('w') as log:
    for kind in ['obj','src']:
        args=['build/binutils/powerpc-eabi-readelf','-rW','build/GEDE01/'+kind+'/game/game_fn_802093FC.o']
        log.write('$ '+shlex.join(args)+'\n');log.flush()
        r=subprocess.run(args,cwd=ROOT,stdout=log,stderr=subprocess.STDOUT)
        log.write('exit status: '+str(r.returncode)+'\n');assert r.returncode==0
run('disassembly',['build/binutils/powerpc-eabi-objdump','-dr','build/GEDE01/obj/game/game_fn_802093FC.o','build/GEDE01/src/game/game_fn_802093FC.o'])
run('compiler-command',['.tools/bin/ninja','-t','commands','build/GEDE01/src/game/game_fn_802093FC.o'])
for suffix in ['', '-reloc-strict']:
    d=json.loads((ROOT/P/('objdiff-'+A+suffix+'.json')).read_text())
    for side in ['left','right']:
        s=next(s for s in d[side]['symbols'] if s['name']=='GetTypeCallback_802093FC')
        print(suffix or 'canonical', side, s['size'], s.get('match_percent'))

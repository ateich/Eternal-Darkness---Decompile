"""Run from eternal-darkness-decomp; capture fresh final measurements."""
from pathlib import Path
import subprocess, json, struct, hashlib
P=Path('reports/GEDE01/attempt-61afaba5-babf-43ee-baf7-21601adfce5c')
A='61afaba5-babf-43ee-baf7-21601adfce5c'
with (P/'verification.log').open('w') as log:
 def run(cmd):
  r=subprocess.run(cmd,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,text=True)
  log.write('$ '+' '.join(cmd)+'\n'+r.stdout+'\nexit_code='+str(r.returncode)+'\n');log.flush()
  assert r.returncode == 0, cmd
  return r.stdout
 run(['.tools/bin/ninja','-j2'])
 run(['.tools/bin/ninja','-j2','-v','build/GEDE01/src/game/game_fn_8011C0F0.o'])
 for output,extra in [(Path('reports/GEDE01/objdiff-'+A+'.json'),[]),(P/'final-strict.json',['-c','function_reloc_diffs=name_address'])]:
  run(['build/tools/objdiff-cli','diff','-p','.','-u','main/game/game_fn_8011C0F0','fn_8011C0F0','-o',str(output),'--format','json']+extra)
 out=run(['sha1sum','build/GEDE01/main.dol'])
 assert out.split()[0]=='ea24b6af954876ce072562ff39cdb4c81d32be1f'
 run(['python3','tools/legal_audit.py'])
 run(['git','diff','--exit-code','c2e15a40929be33380ff2ce31c9e6bed3e788359','--','src/game/game_fn_8011C0F0.c','configure.py','config/GEDE01/splits.txt'])
 for obj in ['build/GEDE01/obj/game/game_fn_8011C0F0.o','build/GEDE01/src/game/game_fn_8011C0F0.o']:
  run(['readelf','-Wr','-Ws',obj])
 run(['sha256sum','src/game/game_fn_8011C0F0.c','compilers/GC/1.3/mwcceppc.exe','build/tools/objdiff-cli'])
 # Read-only provenance for existing declarations and link selection.
 run(['rg','-n','8011C0F0','configure.py','config/GEDE01/splits.txt'])
 run(['cat','src/game/game_fn_8011C0F0.c','src/game/game_data_8023A670.c'])

def text_section(path):
 b=Path(path).read_bytes();assert b[:6]==b'\x7fELF\x01\x02'
 off=struct.unpack_from('>I',b,32)[0];size,count,names=struct.unpack_from('>HHH',b,46)
 headers=[struct.unpack_from('>10I',b,off+i*size) for i in range(count)]
 h=headers[names];strings=b[h[4]:h[4]+h[5]]
 for h in headers:
  name=strings[h[0]:].split(b'\0',1)[0]
  if name==b'.text':return b[h[4]:h[4]+h[5]]
 raise ValueError('missing .text')
a=text_section('build/GEDE01/obj/game/game_fn_8011C0F0.o');b=text_section('build/GEDE01/src/game/game_fn_8011C0F0.o')
(P/'bytes.json').write_text(json.dumps({'raw_unrelocated_text_equal':a==b,'target_size':len(a),'generated_size':len(b),'target_sha256':hashlib.sha256(a).hexdigest(),'generated_sha256':hashlib.sha256(b).hexdigest(),'differing_word_offsets':[hex(i) for i in range(0,min(len(a),len(b)),4) if a[i:i+4]!=b[i:i+4]],'scope':'Raw ELF .text comparison; relocation records are separately preserved in verification.log.'},indent=2)+'\n')
d=json.loads(Path('reports/GEDE01/objdiff-'+A+'.json').read_text())
with (P/'instructions.txt').open('w') as f:
 for side in ['left','right']:
  f.write(side+' (left=retail, right=generated)\n')
  symbol=next(s for s in d[side]['symbols'] if s['name']=='fn_8011C0F0')
  for row in symbol['instructions']:
   if 'instruction' in row:
    i=row['instruction'];f.write('%04x  %s\n' % (int(i.get('address',0)),i['formatted']))
print('Verified final 188-byte NonMatching candidate; DOL hash and legal audit pass.')

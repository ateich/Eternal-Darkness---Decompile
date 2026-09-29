"""Capture the final canonical build, independent diffs, and relocation audit."""
from pathlib import Path
import hashlib,json,re,subprocess
folder=Path(__file__).parent
assignment='1e4bad38-468b-4a9f-9ca7-70cb57e3161d'
with (folder/'verification.log').open('w') as log:
 def run(cmd):
  log.write('$ '+' '.join(cmd)+'\n');log.flush()
  proc=subprocess.run(cmd,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,text=True)
  log.write(proc.stdout);log.write('exit_code='+str(proc.returncode)+'\n');log.flush()
  if proc.returncode:raise SystemExit(proc.returncode)
  return proc.stdout
 run(['date','-u'])
 run(['python3','configure.py'])
 run(['.tools/bin/ninja','-j2'])
 run(['.tools/bin/ninja','-j2','build/GEDE01/src/game/game_fn_801F1A38.externalized'])
 run(['.tools/bin/ninja','-t','commands','build/GEDE01/src/game/game_fn_801F1A38.externalized'])
 run(['sha256sum','compilers/GC/1.3/mwcceppc.exe','src/game/game_fn_801F1A38.c'])
 run(['sha1sum','build/GEDE01/main.dol','orig/GEDE01/sys/main.dol'])
 actual=hashlib.sha1(Path('build/GEDE01/main.dol').read_bytes()).hexdigest()
 assert actual=='ea24b6af954876ce072562ff39cdb4c81d32be1f',actual
 common=['build/tools/objdiff-cli','diff','-p','.', '-u','main/game/game_fn_801F1A38','fn_801F1A38']
 for kind,output,config in [('canonical',folder/'canonical.json',[]),('strict',folder.parent/('objdiff-'+assignment+'.json'),['-c','function_reloc_diffs=name_address'])]:
  output.unlink(missing_ok=True)
  run(common+config+['-o',str(output),'--format','json'])
  data=json.loads(output.read_text())
  sym=next(s for s in data['left']['symbols'] if s['name']=='fn_801F1A38')
  log.write(kind+' match_percent='+str(sym['match_percent'])+'\n')
 objects=['build/GEDE01/obj/game/game_fn_801F1A38.o','build/GEDE01/src/game/game_fn_801F1A38.o']
 relocs=[]
 for obj in objects:
  raw=run(['build/binutils/powerpc-eabi-readelf','-rW',obj])
  rows=[]
  for line in raw.splitlines():
   m=re.match(r'^([0-9a-f]+)\s+[0-9a-f]+\s+(R_PPC_\S+)\s+([0-9a-f]+)\s+(\S+)\s+([+-])\s+([0-9a-f]+)$',line)
   if m:
    offset,typ,value,symbol,sign,addend=m.groups()
    rows.append({'offset':int(offset,16),'type':typ,'symbol_value':int(value,16),'symbol':symbol,'addend':int(addend,16)*(1 if sign=='+' else -1)})
  assert len(rows)==39,(obj,len(rows))
  relocs.append(rows)
 audit={'objects':objects,'count_each':39,'targets_addends_types_offsets_equal':relocs[0]==relocs[1],'retail':relocs[0],'candidate':relocs[1]}
 (folder/'relocations.json').write_text(json.dumps(audit,indent=2)+'\n')
 assert audit['targets_addends_types_offsets_equal']
 log.write('PASS: all 39 relocation offsets, types, symbol names, symbol values, and addends agree.\n')
 log.write('NonMatching candidate is excluded from the DOL link; hash validates the canonical link, not candidate inclusion.\n')

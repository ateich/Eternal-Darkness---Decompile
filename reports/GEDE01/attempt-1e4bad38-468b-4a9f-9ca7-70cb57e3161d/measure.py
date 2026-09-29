"""Run from eternal-darkness-decomp; measure current TU and preserve a base-relative patch."""
import difflib, json, subprocess, sys, re
from pathlib import Path
folder=Path(__file__).parent
name=sys.argv[1]
source=Path('src/game/game_fn_801F1A38.c')
base=subprocess.check_output(['git','show','3707b9066fe42f247654c4c60dedceb0b1728f70:eternal-darkness-decomp/'+str(source)],text=True)
(folder/(name+'.patch')).write_text(''.join(difflib.unified_diff(base.splitlines(True),source.read_text().splitlines(True),fromfile='a/eternal-darkness-decomp/'+str(source),tofile='b/eternal-darkness-decomp/'+str(source))))
with (folder/(name+'.log')).open('w') as log:
 def run(cmd):
  log.write('$ '+' '.join(cmd)+'\n'); log.flush()
  result=subprocess.run(cmd,stdout=log,stderr=subprocess.STDOUT)
  log.write('exit_code='+str(result.returncode)+'\n'); log.flush()
  if result.returncode: raise SystemExit(result.returncode)
 run(['.tools/bin/ninja','-j2','build/GEDE01/src/game/game_fn_801F1A38.o'])
 nm=subprocess.check_output(['build/binutils/powerpc-eabi-nm','build/GEDE01/src/game/game_fn_801F1A38.o'],text=True)
 symbols=re.findall(r'^[0-9a-f]+ d (@[0-9]+)$',nm,re.M)
 if symbols:
  assert len(symbols)==1, symbols
  config=Path('configure.py'); text=config.read_text()
  start=text.index('"name": "externalize_game_801F1A38_signed_bias"')
  end=text.index('"description"',start)
  text=text[:start]+re.sub(r'@[0-9]+',symbols[0],text[start:end])+text[end:]
  config.write_text(text)
  run(['python3','configure.py'])
 configbase=subprocess.check_output(['git','show','3707b9066fe42f247654c4c60dedceb0b1728f70:eternal-darkness-decomp/configure.py'],text=True)
 with (folder/(name+'.patch')).open('a') as patch:
  patch.write(''.join(difflib.unified_diff(configbase.splitlines(True),Path('configure.py').read_text().splitlines(True),fromfile='a/eternal-darkness-decomp/configure.py',tofile='b/eternal-darkness-decomp/configure.py')))
 run(['.tools/bin/ninja','-j2','build/GEDE01/src/game/game_fn_801F1A38.externalized'])
 output=folder/(name+'.json')
 output.unlink(missing_ok=True)
 run(['build/tools/objdiff-cli','diff','-p','.', '-u','main/game/game_fn_801F1A38','fn_801F1A38','-c','function_reloc_diffs=name_address','-o',str(output),'--format','json'])
 data=json.loads(output.read_text())
 for side in ['left','right']:
  sym=next(s for s in data[side]['symbols'] if s['name']=='fn_801F1A38')
  result={k:sym.get(k) for k in ['name','size','match_percent']}
  result['relocations']=sum(bool(i.get('instruction',{}).get('relocation')) for i in sym['instructions'])
  log.write(side+' '+json.dumps(result)+'\n')
  print(name,side,result)

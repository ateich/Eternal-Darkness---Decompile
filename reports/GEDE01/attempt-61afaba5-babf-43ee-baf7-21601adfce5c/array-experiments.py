"""Reproduce scoped experiments; run from eternal-darkness-decomp. Restores source."""
from pathlib import Path
import subprocess, json, difflib
REPORT = Path('reports/GEDE01/attempt-61afaba5-babf-43ee-baf7-21601adfce5c')
SOURCE = Path('src/game/game_fn_8011C0F0.c')
base = subprocess.check_output(['git','show','c2e15a40929be33380ff2ce31c9e6bed3e788359:eternal-darkness-decomp/src/game/game_fn_8011C0F0.c'],text=True)
assert SOURCE.read_text() == base, 'Start with accepted source'
# Array lvalues versus scalar/member lvalues expose different MWCC alias shapes.
variants={'array_color':base.replace('int color;', 'int color[1];').replace('color = lbl_8064C2BC','color[0] = lbl_8064C2BC').replace('&color','color')}
flat=base.replace('Quad quad = lbl_8023A670;', 'union { Quad records; short fields[8]; } quad;').replace('    int color;', '    int color;\n    quad.records = lbl_8023A670;')
for i,field in enumerate(['x','y','width','height']):
 flat=flat.replace('quad.entry[index].'+field,'quad.fields[index * 4 + %d]' % i)
variants['flat_halfword_indices']=flat
variants['flat_halfword_indices_array_color']=flat.replace('int color;', 'int color[1];').replace('color = lbl_8064C2BC','color[0] = lbl_8064C2BC').replace('&color','color')
results=[]
def run(cmd, log):
 r=subprocess.run(cmd, stdout=subprocess.PIPE,stderr=subprocess.STDOUT,text=True)
 log.write('$ '+' '.join(cmd)+'\n'+r.stdout+'\nexit_code='+str(r.returncode)+'\n')
 if r.returncode: raise RuntimeError(cmd)
try:
 for name,source in variants.items():
  SOURCE.write_text(source)
  (REPORT/(name+'.patch')).write_text(''.join(difflib.unified_diff(base.splitlines(True),source.splitlines(True),fromfile=str(SOURCE),tofile=str(SOURCE))))
  with (REPORT/(name+'.log')).open('w') as log:
   run(['.tools/bin/ninja','-j2','-v','build/GEDE01/src/game/game_fn_8011C0F0.o'],log)
   for basis, extra in [('canonical',[]),('strict',['-c','function_reloc_diffs=name_address'])]:
    output=REPORT/(name+'-'+basis+'.json')
    run(['build/tools/objdiff-cli','diff','-p','.','-u','main/game/game_fn_8011C0F0','fn_8011C0F0','-o',str(output),'--format','json']+extra,log)
    d=json.loads(output.read_text())
    s=next(x for x in d['left']['symbols'] if x['name']=='fn_8011C0F0')
    right=next(x for x in d['right']['symbols'] if x['name']=='fn_8011C0F0')
    row={'variant':name,'basis':basis,'score':s.get('match_percent'),'target_size':s['size'],'generated_size':right['size']}
    results.append(row)
    print(row,flush=True)
  (REPORT/'array-results.json').write_text(json.dumps(results,indent=2)+'\n')
finally:
 SOURCE.write_text(base)
 with (REPORT/'array-restore.log').open('w') as log:
  run(['.tools/bin/ninja','-j2','-v','build/GEDE01/src/game/game_fn_8011C0F0.o'],log)

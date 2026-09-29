"""Reproduce scoped experiments; run from eternal-darkness-decomp. Restores source."""
from pathlib import Path
import subprocess, json, difflib
REPORT = Path('reports/GEDE01/attempt-61afaba5-babf-43ee-baf7-21601adfce5c')
SOURCE = Path('src/game/game_fn_8011C0F0.c')
base = subprocess.check_output(['git','show','c2e15a40929be33380ff2ce31c9e6bed3e788359:eternal-darkness-decomp/src/game/game_fn_8011C0F0.c'],text=True)
assert SOURCE.read_text() == base, 'Start with accepted source'
variants={'baseline':base}
frame=base.replace('Quad quad = lbl_8023A670;\n    int color;', 'struct { int color; Quad quad; } frame;\n    frame.quad = lbl_8023A670;').replace('quad.entry','frame.quad.entry').replace('color = lbl_8064C2BC','frame.color = lbl_8064C2BC').replace('&color','&frame.color')
variants['shared_stack_frame']=frame
# Control for field offset ordering versus membership/alias analysis.
variants['shared_stack_frame_reversed']=frame.replace('int color; Quad quad;', 'Quad quad; int color;')
# Same int ABI/address type, different representation of address-taken local.
variants['boxed_color']=base.replace('int color;', 'struct { int value; } color;').replace('color = lbl_8064C2BC','color.value = lbl_8064C2BC').replace('&color','&color.value')
variants['union_color_halfwords']=base.replace('int color;', 'union { int value; short parts[2]; } color;').replace('color = lbl_8064C2BC','color.value = lbl_8064C2BC').replace('&color','&color.value')
variants['union_color_bytes']=base.replace('int color;', 'union { int value; unsigned char parts[4]; } color;').replace('color = lbl_8064C2BC','color.value = lbl_8064C2BC').replace('&color','&color.value')
# Adding an overlapping word-array view may affect the aggregate alias set.
variants['union_quad_words']=base.replace('Quad quad = lbl_8023A670;', 'union { Quad records; int words[4]; } storage;\n    Quad *unused;').replace('    Quad *unused;', '    /* copy after declarations */').replace('quad.entry','storage.records.entry')
variants['union_quad_words']=variants['union_quad_words'].replace('    int color;', '    int color;\n    storage.records = lbl_8023A670;')
results=[]
def run(cmd, log):
 r=subprocess.run(cmd, stdout=subprocess.PIPE,stderr=subprocess.STDOUT,text=True)
 log.write('$ '+' '.join(cmd)+'\n'+r.stdout+'\nexit_code='+str(r.returncode)+'\n')
 if r.returncode: raise RuntimeError(cmd)
try:
 for name,source in variants.items():
  if not name.startswith("union_"): continue
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
  (REPORT/'union-results.json').write_text(json.dumps(results,indent=2)+'\n')
finally:
 SOURCE.write_text(base)
 with (REPORT/'restore.log').open('w') as log:
  run(['.tools/bin/ninja','-j2','-v','build/GEDE01/src/game/game_fn_8011C0F0.o'],log)

"""Assignment-local evidence capture. Run from eternal-darkness-decomp."""
import hashlib,json,pathlib,subprocess,sys
root=pathlib.Path('reports/GEDE01/ae1a3cbf-707e-44e2-af75-58343697538e')
label=sys.argv[1]
source=pathlib.Path('src/game/game_fn_801DDB84.c')
record={'label':label,'source_sha256':hashlib.sha256(source.read_bytes()).hexdigest(),'commands':[]}
record['source_patch_from_base']=subprocess.check_output(['git','diff','1723a051c4b5a0d01fba640e5b1fa338411cbfda','--',str(source)],text=True)
def run(args):
 r=subprocess.run(args,capture_output=True,text=True)
 record['commands'].append({'argv':args,'exit_code':r.returncode,'stdout':r.stdout,'stderr':r.stderr})
 (root/(label+'-commands.json')).write_text(json.dumps(record,indent=2)+'\n')
 if r.returncode: print(r.stdout,r.stderr);sys.exit(r.returncode)
run(['.tools/bin/ninja','-j2','build/GEDE01/src/game/game_fn_801DDB84.o'])
for policy in ['canonical','strict']:
 args=['build/tools/objdiff-cli','diff','-p','.','-u','main/game/game_fn_801DDB84','fn_801DDB84','-o',str(root/(label+'-'+policy+'.json')),'--format','json-pretty']
 if policy=='strict':args+=['-c','function_reloc_diffs=name_address']
 run(args)
 d=json.loads((root/(label+'-'+policy+'.json')).read_text())
 for side in ['left','right']:
  s=next(x for x in d[side]['symbols'] if x['name']=='fn_801DDB84')
  ins=[x['instruction'] for x in s['instructions'] if 'instruction' in x]
  print(label,policy,side,'size',s['size'],'score',s.get('match_percent'),'relocations',sum('relocation' in x for x in ins),'frame',ins[0]['formatted'])
  if policy=='strict':(root/(label+'-'+side+'.txt')).write_text('\n'.join(f"{int(x.get('address',0)):04x} {x['formatted']}" for x in ins)+'\n')

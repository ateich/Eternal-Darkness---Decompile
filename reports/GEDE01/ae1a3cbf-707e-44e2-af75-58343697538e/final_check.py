"""Read-only final verification; run only after the full Ninja build finishes."""
import hashlib,json,pathlib,subprocess
root=pathlib.Path('reports/GEDE01/ae1a3cbf-707e-44e2-af75-58343697538e')
records=[]
def run(args):
 r=subprocess.run(args,capture_output=True,text=True)
 records.append({'argv':args,'exit_code':r.returncode,'stdout':r.stdout,'stderr':r.stderr})
 (root/'final-check-commands.json').write_text(json.dumps(records,indent=2)+'\n')
 print(args[0],r.returncode,r.stdout[-1600:],r.stderr[-1000:])
 assert r.returncode==0
 return r.stdout
for kind in ['canonical','strict']:
 args=['build/tools/objdiff-cli','diff','-p','.','-u','main/game/game_fn_801DDB84','fn_801DDB84','-o',str(root/('final-'+kind+'.json')),'--format','json-pretty']
 if kind=='strict':args+=['-c','function_reloc_diffs=name_address']
 run(args)
 d=json.loads((root/('final-'+kind+'.json')).read_text())
 sym=next(s for s in d['left']['symbols'] if s['name']=='fn_801DDB84')
 print(kind,sym['match_percent']);assert sym['match_percent']==100.0
run(['python3',str(root/'verify_elf.py')])
s=run(['sha1sum','build/GEDE01/main.dol']);assert s.split()[0]=='ea24b6af954876ce072562ff39cdb4c81d32be1f'
run(['git','diff','--check','--','src/game/game_fn_801DDB84.c','configure.py'])
assert (root/'final-canonical.json').read_bytes()==(root/'final-strict.json').read_bytes()
meta={'assignment_id':'ae1a3cbf-707e-44e2-af75-58343697538e','target':'fn_801DDB84','compiler':'GC/1.3','canonical_and_relocation_strict_percent':100.0,'canonical_and_strict_outputs_byte_equal':True,'relocation_policy':'function_reloc_diffs=name_address; independent ELF verification checks exact symbol targets and addends','source_sha256':hashlib.sha256(pathlib.Path('src/game/game_fn_801DDB84.c').read_bytes()).hexdigest(),'source_and_registration_patch':subprocess.check_output(['git','diff','1723a051c4b5a0d01fba640e5b1fa338411cbfda','--','configure.py','src/game/game_fn_801DDB84.c','config/GEDE01/splits.txt'],text=True),'final_commands':records,'build_raw_output':json.loads((root/'final-build.json').read_text()),'configure_raw_output':json.loads((root/'interleaved-build-failure.json').read_text())[0],'elf_byte_and_relocation_verification':json.loads((root/'elf-verification.json').read_text()),'experiment_directory':'eternal-darkness-decomp/'+str(root),'constant_externalization':'Target-only registration in existing game_section_externalizations, using unchanged byte-verification rules. All compiler flags unchanged.'}
u=next(u for u in json.load(open('objdiff.json'))['units'] if u['name']=='main/game/game_fn_801DDB84');meta['canonical_settings']=u['scratch']
d['evidence_metadata']=meta
path=pathlib.Path('reports/GEDE01/objdiff-ae1a3cbf-707e-44e2-af75-58343697538e.json');path.write_text(json.dumps(d,indent=2)+'\n')
envelope={'version':1,'assignment_id':meta['assignment_id'],'attempt':5,'base_commit':'1723a051c4b5a0d01fba640e5b1fa338411cbfda','target':'fn_801DDB84','status':'matched','evidence':['eternal-darkness-decomp/'+str(path)],'divergence':''}
pathlib.Path('reports/GEDE01/durable-ae1a3cbf-707e-44e2-af75-58343697538e.json').write_text(json.dumps(envelope,indent=2)+'\n')

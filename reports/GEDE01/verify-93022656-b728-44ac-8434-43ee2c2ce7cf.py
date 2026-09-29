"""Reproduce final assignment measurements without changing build policy."""
import hashlib,json,pathlib,struct,subprocess
N='93022656-b728-44ac-8434-43ee2c2ce7cf'; R=pathlib.Path('reports/GEDE01'); PREFIX='eternal-darkness-decomp/'
report={'version':1,'assignment_id':N,'target':'fn_801DC778','working_directory':'eternal-darkness-decomp','commands':[]}
def run(args):
 p=subprocess.run(args,text=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
 e={'command':args,'exit_code':p.returncode,'raw_output':p.stdout};report['commands'].append(e)
 assert p.returncode==0,e
 return e
run(['python3','configure.py'])
run(['.tools/bin/ninja','-j2'])
run(['build/tools/objdiff-cli','--version'])
report['compiler']=run(['.tools/bin/ninja','-t','commands','build/GEDE01/src/game/game_fn_801DC778.o'])
report['comparisons']=[]
for mode,options in [('canonical',[]),('reloc-strict',['-c','function_reloc_diffs=name_address'])]:
 path=R/f'objdiff-{N}-{mode}.raw.json'
 e=run(['build/tools/objdiff-cli','diff','-p','.','-u','main/game/game_fn_801DC778','fn_801DC778','-o',str(path),'--format','json-pretty']+options)
 x=json.loads(path.read_text());a,b=[next(s for s in x[k]['symbols'] if s['name']=='fn_801DC778') for k in ['left','right']]
 report['comparisons'].append({'mode':mode,'settings':options,'invocation':e,'artifact':PREFIX+str(path),'sha256':hashlib.sha256(path.read_bytes()).hexdigest(),'match_percent':a['match_percent'],'retail_bytes':int(a['size']),'generated_bytes':int(b['size']),'retail_objdiff_relocations':sum('relocation' in i.get('instruction',{}) for i in a['instructions']),'generated_objdiff_relocations':sum('relocation' in i.get('instruction',{}) for i in b['instructions'])})
report['dol_sha1']=run(['sha1sum','build/GEDE01/main.dol'])
report['dol_sha1']['expected']='ea24b6af954876ce072562ff39cdb4c81d32be1f'
assert report['dol_sha1']['raw_output'].split()[0]==report['dol_sha1']['expected']
report['legal_audit']=run(['python3','tools/legal_audit.py'])
# Read ELF relocation records directly, preserving symbol targets AND signed addends.
def elf(path):
 b=pathlib.Path(path).read_bytes();assert b[:6]==b'\x7fELF\x01\x02'
 h=struct.unpack_from('>HHIIIIIHHHHHH',b,16); shoff,shsize,n,shstr=h[5],h[10],h[11],h[12]
 sh=[struct.unpack_from('>IIIIIIIIII',b,shoff+i*shsize) for i in range(n)]
 def data(s):return b[s[4]:s[4]+s[5]]
 def string(t,o):return t[o:t.index(b'\0',o)].decode()
 names=data(sh[shstr]);sections={string(names,s[0]):s for s in sh}
 sym=sections['.symtab'];strings=data(sh[sym[6]]);symbols=[]
 for off in range(sym[4],sym[4]+sym[5],sym[9]):
  v=struct.unpack_from('>IIIBBH',b,off);symbols.append(string(strings,v[0]))
 rs=sections['.rela.text'];relocs=[]
 for off in range(rs[4],rs[4]+rs[5],rs[9]):
  addr,info,addend=struct.unpack_from('>IIi',b,off);relocs.append({'offset':addr,'type':info&255,'target':symbols[info>>8],'addend':addend})
 return data(sections['.text']),relocs
left,lr=elf('build/GEDE01/obj/game/game_fn_801DC778.o');right,rr=elf('build/GEDE01/src/game/game_fn_801DC778.o')
report['byte_comparison']={'equal':left==right,'retail_size':len(left),'generated_size':len(right),'retail_sha256':hashlib.sha256(left).hexdigest(),'generated_sha256':hashlib.sha256(right).hexdigest(),'equal_bytes_at_same_offsets':sum(a==b for a,b in zip(left,right))}
report['elf_relocations']={'retail_count':len(lr),'generated_count':len(rr),'retail':lr,'generated':rr,'ordered_target_type_addend_mismatches':[{'ordinal':i,'retail':a,'generated':b} for i,(a,b) in enumerate(zip(lr,rr)) if any(a[k]!=b[k] for k in ['type','target','addend'])]}
source=pathlib.Path('src/game/game_fn_801DC778.c')
report['source']={'path':PREFIX+str(source),'sha256':hashlib.sha256(source.read_bytes()).hexdigest(),'independent_c_translation_unit':True,'registration':'NonMatching, GC/1.3, -use_lmw_stmw on; unchanged from accepted base','inline_or_whole_function_assembly':False}
report['preserved_attempt_review']={'recovered_commit':'3e1cc8fc923eaa051e4e01252fcc21b6feb4b194','accepted_base_already_contains_identical_source':True,'previous_score':88.77797,'new_hypothesis':'State 153 has a by-value Vec3 ABI, with one retained local vector and compiler-generated argument copies; field-aware aggregate copying and independent loop-index scopes influence allocation.','semantic_corrections':['state 152 is a no-op','state 173 uses 0x493E0','state 151 passes fn_801D38E8 result to fn_801D38BC','owner comparison and negative descriptor byte are signed','state 153 retains x/y across first effect call and updates only z'],'experiments':PREFIX+str(R/f'experiments-{N}.json')}
report['divergence']='Canonical and relocation-strict objdiff both measure 99.0472%. Generated .text is 2284 bytes versus 2288 retail bytes; the 0x200-byte frame and by-value Vec3 stack copies match. Remaining differences are long-lived-register assignment and loop induction/coalescing (including the missing cursor copy before state 153), plus nine conversion-bias relocations to compiler-generated @115 instead of lbl_806511A8. Both sides contain 72 ELF relocations (76 relocation-bearing objdiff instructions); the nine constant targets differ, while paired relocation types and addends agree. The source remains NonMatching and the verified DOL links retail code for this function.'
(R/f'objdiff-{N}.json').write_text(json.dumps(report,indent=2)+'\n')
envelope={'version':1,'assignment_id':N,'attempt':5,'base_commit':'f0258cfe5e1b1a53ffc7c410cc1ed378ca9d8215','target':'fn_801DC778','status':'attempted','evidence':[PREFIX+str(R/f'objdiff-{N}.json'),PREFIX+str(R/f'objdiff-{N}-canonical.raw.json'),PREFIX+str(R/f'objdiff-{N}-reloc-strict.raw.json'),PREFIX+str(R/f'experiments-{N}.json')],'divergence':report['divergence']}
(R/f'durable-{N}.json').write_text(json.dumps(envelope,indent=2)+'\n')
print(json.dumps({'scores':[c['match_percent'] for c in report['comparisons']],'bytes':report['byte_comparison'],'relocation_mismatches':len(report['elf_relocations']['ordered_target_type_addend_mismatches']),'elf_counts':[len(lr),len(rr)],'dol':report['dol_sha1'],'legal':report['legal_audit']},indent=2))

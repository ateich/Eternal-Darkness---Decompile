"""Read-only verification of the final claimed TU; run from project directory."""
import json, struct, hashlib, re
from pathlib import Path
r=Path('reports/GEDE01/attempt-20db5870-8c89-4ca2-a3d4-482eebecd142')
d=json.loads(Path('reports/GEDE01/objdiff-20db5870-8c89-4ca2-a3d4-482eebecd142.json').read_text())
summary={}
for side in ['left','right']:
 syms=d[side]['symbols']; sym=next(s for s in syms if s['name']=='fn_801A53C4'); relocs=[]
 targets={}
 for row in sym['instructions']:
  ins=row.get('instruction',{}); rel=ins.get('relocation')
  match=re.search(r', ([A-Za-z_][A-Za-z_0-9]*)@',ins.get('formatted',''))
  if rel and match:targets[rel['target_symbol']]=match.group(1)
 for i in sym['instructions']:
  ins=i.get('instruction',{}); rel=ins.get('relocation')
  if rel:
   relocs.append(dict(address=int(ins.get('address',0)),instruction=ins['formatted'],type=rel.get('type',0),type_name=rel['type_name'],target=targets[rel['target_symbol']],addend=int(rel.get('addend',0))))
 summary[side]={'size':int(sym['size']),'score':sym.get('match_percent'),'relocations':relocs}
summary['relocation_multisets_equal']=sorted((x['type'],x['target'],x['addend']) for x in summary['left']['relocations'])==sorted((x['type'],x['target'],x['addend']) for x in summary['right']['relocations'])
def text_section(p):
 data=p.read_bytes(); hdr=struct.unpack_from('>16sHHIIIIIHHHHHH',data); off=hdr[6]; ents=hdr[11]; n=hdr[12]; idx=hdr[13]
 sections=[struct.unpack_from('>IIIIIIIIII',data,off+i*ents) for i in range(n)]
 st=sections[idx]; names=data[st[4]:st[4]+st[5]]
 for s in sections:
  name=names[s[0]:].split(b'\0')[0]
  if name==b'.text':return data[s[4]:s[4]+s[5]]
 raise ValueError('Missing .text')
a=text_section(Path('build/GEDE01/obj/game/game_fn_801A53C4.o')); b=text_section(Path('build/GEDE01/src/game/game_fn_801A53C4.o'))
summary['raw_text']={'retail_sha256':hashlib.sha256(a).hexdigest(),'generated_sha256':hashlib.sha256(b).hexdigest(),'equal_bytes':sum(x==y for x,y in zip(a,b)),'total_bytes':len(a),'different_words':[{'offset':hex(i),'retail':a[i:i+4].hex(),'generated':b[i:i+4].hex()} for i in range(0,len(a),4) if a[i:i+4]!=b[i:i+4]],'bytes_after_offset_44_identical':a[44:]==b[44:]}
summary['note']='The lhz reference is an objdiff-inferred R_PPC_NONE relocation with addend 2. Three actual ELF relocation records plus this inferred reference agree in type, target and addend. NonMatching TU is not linked; the DOL hash validates the canonical project, not this candidate.'
(r/'verification.json').write_text(json.dumps(summary,indent=2)+'\n')
print(json.dumps(summary,indent=2))

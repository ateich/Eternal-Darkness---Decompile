"""Verify the assigned ELF's section bytes and resolved relocation identities."""
import hashlib,json,struct
from pathlib import Path
root=Path('reports/GEDE01/ae1a3cbf-707e-44e2-af75-58343697538e')
def read(path):
 b=Path(path).read_bytes()
 assert b[:6]==b'\x7fELF\x01\x02'
 shoff=struct.unpack_from('>I',b,32)[0]
 entsize,count,names=struct.unpack_from('>HHH',b,46)
 headers=[struct.unpack_from('>10I',b,shoff+i*entsize) for i in range(count)]
 def data(i):
  h=headers[i];return b[h[4]:h[4]+h[5]]
 def string(blob,offset):return blob[offset:blob.index(b'\0',offset)].decode()
 section_names=[string(data(names),h[0]) for h in headers]
 sections={n:data(i) for i,n in enumerate(section_names)}
 relocs=[]
 for i,h in enumerate(headers):
  if h[1]!=4:continue
  symbol_header=headers[h[6]]
  strings=data(symbol_header[6])
  symbols=[struct.unpack_from('>IIIBBH',data(h[6]),j) for j in range(0,symbol_header[5],symbol_header[9])]
  for j in range(0,h[5],h[9]):
   offset,info,addend=struct.unpack_from('>IIi',data(i),j)
   symbol=symbols[info>>8]
   name=string(strings,symbol[0]);shndx=symbol[5]
   if shndx==0:target={'external':name,'addend':addend}
   elif shndx<len(section_names):target={'section':section_names[shndx],'offset':symbol[1]+addend}
   else:target={'special_section_index':shndx,'symbol':name,'value':symbol[1],'addend':addend}
   relocs.append({'section':section_names[h[7]],'offset':offset,'type':info&255,'target':target})
 return sections,sorted(relocs,key=lambda x:(x['section'],x['offset']))
left='build/GEDE01/obj/game/game_fn_801DDB84.o';right='build/GEDE01/src/game/game_fn_801DDB84.o'
a,ar=read(left);b,br=read(right)
r={'command':'python3 reports/GEDE01/ae1a3cbf-707e-44e2-af75-58343697538e/verify_elf.py','target_object':left,'candidate_object':right,'sections':{},'target_relocations':ar,'candidate_relocations':br,'relocations_equal':ar==br,'elf_relocation_count':len(ar),'constant_pool_note':'The final object uses the existing byte-verified game_section_externalizations registration; see owned-pool-elf-verification.json for raw pre-externalization constant bytes and final-build.json for each guarded mapping.'}
for name in ['.text']:
 r['sections'][name]={'target_size':len(a[name]),'candidate_size':len(b[name]),'target_sha256':hashlib.sha256(a[name]).hexdigest(),'candidate_sha256':hashlib.sha256(b[name]).hexdigest(),'bytes_equal':a[name]==b[name]}
(root/'elf-verification.json').write_text(json.dumps(r,indent=2)+'\n')
print(json.dumps({k:v for k,v in r.items() if k not in ['target_relocations','candidate_relocations']},indent=2))
assert ar==br and all(x['bytes_equal'] for x in r['sections'].values())

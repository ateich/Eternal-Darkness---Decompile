"""Compare this assignment's final text and relocation identities directly."""
import hashlib,json,struct
from pathlib import Path
ID='d958531b-4cde-4fa1-bcc3-010967e124a7'
def elf(path):
 b=path.read_bytes();assert b[:6]==b'\x7fELF\x01\x02'
 off=struct.unpack_from('>I',b,32)[0];sz,n,strings=struct.unpack_from('>HHH',b,46)
 sections=[struct.unpack_from('>10I',b,off+i*sz) for i in range(n)]
 def data(s):return b[s[4]:s[4]+s[5]]
 def cstr(buf,i):return buf[i:buf.index(0,i)].decode()
 names=data(sections[strings]);text_i=next(i for i,s in enumerate(sections) if cstr(names,s[0])=='.text')
 rel=[]
 for s in sections:
  if s[1]!=4 or s[7]!=text_i:continue
  syms=sections[s[6]];snames=data(sections[syms[6]])
  for pos in range(s[4],s[4]+s[5],s[9]):
   addr,info,addend=struct.unpack_from('>IIi',b,pos)
   sym=struct.unpack_from('>IIIBBH',b,syms[4]+(info>>8)*syms[9])
   rel.append({'offset':addr,'type':info&255,'target':cstr(snames,sym[0]),'addend':addend})
 return data(sections[text_i]),rel
left=Path('build/GEDE01/obj/game/game_fn_801F2370.o');right=Path('build/GEDE01/src/game/game_fn_801F2370.o')
a,ar=elf(left);b,br=elf(right)
result={'target':'fn_801F2370','retail_object':str(left),'generated_object':str(right),'retail_text_bytes':len(a),'generated_text_bytes':len(b),'retail_text_sha256':hashlib.sha256(a).hexdigest(),'generated_text_sha256':hashlib.sha256(b).hexdigest(),'text_bytes_equal':a==b,'retail_relocations':ar,'generated_relocations':br,'relocation_offset_type_target_addend_equal':ar==br,'source_sha256':hashlib.sha256(Path('src/game/game_fn_801F2370.c').read_bytes()).hexdigest(),'full_build_and_dol_verification':'Deferred to integrator after independent review; no DOL identity claim from this session.'}
print(json.dumps(result,indent=2));assert a==b and ar==br

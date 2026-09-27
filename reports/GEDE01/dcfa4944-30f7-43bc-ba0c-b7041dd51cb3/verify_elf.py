"""Read-only ELF32/PPC byte and explicit relocation target/addend audit."""
import struct, json, pathlib, hashlib
root=pathlib.Path("reports/GEDE01/dcfa4944-30f7-43bc-ba0c-b7041dd51cb3")
def cstr(b,o): return b[o:b.index(b"\0",o)].decode()
def elf(path):
 b=pathlib.Path(path).read_bytes()
 assert b[:6] == b"\x7fELF\x01\x02"
 shoff=struct.unpack_from(">I",b,32)[0]
 entsize,count,names=struct.unpack_from(">HHH",b,46)
 sh=[struct.unpack_from(">10I",b,shoff+i*entsize) for i in range(count)]
 def data(s):return b[s[4]:s[4]+s[5]]
 sn=data(sh[names]);sections={cstr(sn,s[0]):s for s in sh}
 rel=sections[".rela.text"];sym=sh[rel[6]];strings=data(sh[sym[6]])
 syms=[struct.unpack_from(">IIIBBH",data(sym),i) for i in range(0,sym[5],sym[9])]
 rr=[]
 for i in range(0,rel[5],rel[9]):
  offset,info,addend=struct.unpack_from(">IIi",data(rel),i)
  target=syms[info>>8]
  rr.append(dict(offset=hex(offset),type=info&255,target=cstr(strings,target[0]),addend=addend,symbol_value=target[1]))
 return data(sections[".text"]),rr,sections,b,sh,data
left="build/GEDE01/obj/game/game_fn_80150400.o"
right="build/GEDE01/src/game/game_fn_80150400.o"
a,ar,*_=elf(left)
b,br,sections,blob,sh,data=elf(right)
assert len(ar)==len(br)==40
mismatch=[dict(retail=x,generated=y) for x,y in zip(ar,br) if x!=y]
bias=data(sections[".sdata2"])
dol=pathlib.Path("orig/GEDE01/sys/main.dol").read_bytes()
retail_bias=None
for i in range(18):
 fileoff=struct.unpack_from(">I",dol,i*4)[0]
 addr=struct.unpack_from(">I",dol,0x48+i*4)[0]
 size=struct.unpack_from(">I",dol,0x90+i*4)[0]
 if addr<=0x80650588 and 0x80650590<=addr+size:
  o=fileoff+0x80650588-addr;retail_bias=dol[o:o+8]
assert retail_bias is not None
out=dict(command="python3 "+str(root/"verify_elf.py"),retail_object=left,generated_object=right,text_equal=a==b,retail_text_size=len(a),generated_text_size=len(b),retail_text_sha256=hashlib.sha256(a).hexdigest(),generated_text_sha256=hashlib.sha256(b).hexdigest(),byte_differences=[i for i,(x,y) in enumerate(zip(a,b)) if x!=y],retail_relocations=ar,generated_relocations=br,relocation_mismatches=mismatch,generated_sdata2_hex=bias.hex(),retail_bias_address="0x80650588",retail_bias_hex=retail_bias.hex(),bias_equal=bias==retail_bias)
print(json.dumps(out,indent=2))

"""Independently compare function text and ELF relocation targets/addends."""
import hashlib, json, struct
from pathlib import Path
root = Path(__file__).resolve().parents[3]
out = Path(__file__).resolve().parent

def read_elf(path):
    data = path.read_bytes()
    assert data[:6] == b'\x7fELF\x01\x02'
    shoff = struct.unpack_from('>I', data, 32)[0]
    entsize, count, names = struct.unpack_from('>HHH', data, 46)
    sections = [struct.unpack_from('>10I', data, shoff + i*entsize) for i in range(count)]
    def content(s): return data[s[4]:s[4]+s[5]]
    def string(table, offset): return table[offset:table.index(0,offset)].decode()
    shstr=content(sections[names])
    text_index=next(i for i,s in enumerate(sections) if string(shstr,s[0])=='.text')
    text=content(sections[text_index])
    symbol_section=next(s for s in sections if s[1]==2)
    strings=content(sections[symbol_section[6]])
    symbols=[]
    for pos in range(symbol_section[4],symbol_section[4]+symbol_section[5],symbol_section[9]):
        name,value,size,info,other,index=struct.unpack_from('>IIIBBH',data,pos)
        symbols.append({'name':string(strings,name),'value':value,'size':size,'section':index})
    relocs=[]
    for s in sections:
        if s[1]!=4 or s[7]!=text_index: continue
        for pos in range(s[4],s[4]+s[5],s[9]):
            offset,info,addend=struct.unpack_from('>IIi',data,pos)
            relocs.append({'offset':offset,'type':info&255,'target':symbols[info>>8]['name'],'addend':addend})
    return text, sorted(relocs,key=lambda r:r['offset'])

paths=['build/GEDE01/obj/game/game_fn_801DE8B4.o','build/GEDE01/src/game/game_fn_801DE8B4.o']
a,ar=read_elf(root/paths[0]);b,br=read_elf(root/paths[1])
result={'target':'fn_801DE8B4','retail_object':paths[0],'generated_object':paths[1],
        'retail_text_size':len(a),'generated_text_size':len(b),'text_bytes_equal':a==b,
        'retail_text_sha256':hashlib.sha256(a).hexdigest(),'generated_text_sha256':hashlib.sha256(b).hexdigest(),
        'retail_relocations':ar,'generated_relocations':br,'relocations_equal':ar==br}
(out/'elf-verification.json').write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps({k:v for k,v in result.items() if k not in ['retail_relocations','generated_relocations']},indent=2))
assert a==b and ar==br

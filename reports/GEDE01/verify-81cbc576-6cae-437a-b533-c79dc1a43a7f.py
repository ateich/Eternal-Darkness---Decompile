"""Read-only final object/retail evidence; run from eternal-darkness-decomp."""
import hashlib,json,pathlib,struct
ID='81cbc576-6cae-437a-b533-c79dc1a43a7f'
def elf(path):
    b=pathlib.Path(path).read_bytes()
    assert b[:6]==b'\x7fELF\x01\x02'
    h=struct.unpack_from('>16sHHIIIIIHHHHHH',b)
    sh=[struct.unpack_from('>10I',b,h[6]+i*h[11]) for i in range(h[12])]
    def payload(s):return b[s[4]:s[4]+s[5]]
    def string(table,off):return table[off:table.index(0,off)].decode()
    names=payload(sh[h[13]])
    sections={string(names,s[0]):s for s in sh}
    syms=[]
    for s in sh:
        if s[1]==2:
            strings=payload(sh[s[6]])
            for i in range(0,s[5],s[9]):
                a=struct.unpack_from('>IIIBBH',payload(s),i)
                syms.append(dict(name=string(strings,a[0]),address=a[1],size=a[2],section=a[5]))
    rel=[]
    s=sections['.rela.text']
    for i in range(0,s[5],s[9]):
        offset,info,addend=struct.unpack_from('>IIi',payload(s),i)
        rel.append(dict(offset=hex(offset),type=info&255,target=syms[info>>8]['name'],addend=addend))
    return dict(bytes=b,sh=sh,sections=sections,symbols=syms,relocations=rel,text=payload(sections['.text']))
a=elf('build/GEDE01/obj/game/game_fn_80026DC8.o')
b=elf('build/GEDE01/src/game/game_fn_80026DC8.o')
dol=pathlib.Path('orig/GEDE01/sys/main.dol').read_bytes()
def retail(addr,size):
    for i in range(18):
        off=struct.unpack_from('>I',dol,i*4)[0]
        base=struct.unpack_from('>I',dol,0x48+i*4)[0]
        length=struct.unpack_from('>I',dol,0x90+i*4)[0]
        if base<=addr and addr+size<=base+length:return dol[off+addr-base:off+addr-base+size]
    raise ValueError(hex(addr))
constants=[]
for local,addr in [('@4',0x80238C4C),('@38',0x8064DF80)]:
    sym=next(s for s in b['symbols'] if s['name']==local)
    sec=b['sh'][sym['section']];off=sec[4]+sym['address'];value=b['bytes'][off:off+sym['size']]
    target=retail(addr,sym['size'])
    constants.append(dict(local=local,retail_address=hex(addr),size=sym['size'],bytes_equal=value==target,generated_sha256=hashlib.sha256(value).hexdigest(),retail_sha256=hashlib.sha256(target).hexdigest()))
report=dict(target='fn_80026DC8',text_sizes=[len(a['text']),len(b['text'])],text_bytes_equal=a['text']==b['text'],text_sha256=[hashlib.sha256(x['text']).hexdigest() for x in [a,b]],relocation_counts=[len(a['relocations']),len(b['relocations'])],equal_relocation_entries=sum(x==y for x,y in zip(a['relocations'],b['relocations'])),relocation_differences=[dict(retail=x,candidate=y) for x,y in zip(a['relocations'],b['relocations']) if x!=y],constants=constants,source_sha256=hashlib.sha256(pathlib.Path('src/game/game_fn_80026DC8.c').read_bytes()).hexdigest())
print(json.dumps(report,indent=2))
assert report['text_bytes_equal']
assert report['text_sizes']==[616,616]
assert report['equal_relocation_entries']==21
assert all(c['bytes_equal'] for c in constants)

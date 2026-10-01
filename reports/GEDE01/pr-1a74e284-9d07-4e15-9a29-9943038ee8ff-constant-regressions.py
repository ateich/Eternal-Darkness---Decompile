import struct,subprocess,sys,tempfile
from pathlib import Path

def fixture(rel=0,name='@51',section='.sdata2',flags=2,extra=None,incoming=False):
    strings=b'\0'+name.encode()+b'\0'
    symbols=bytes(16)+struct.pack('>IIIBBH',1,0,16,1,0,1)
    if extra is not None:
        symbols+=struct.pack('>IIIBBH',len(strings),0,extra[0],extra[1],0,1)
        strings+=b'other\0'
    data=bytearray(52)+bytes(16)+symbols+strings
    data[:7]=b'\x7fELF\x01\x02\x01';struct.pack_into('>HH',data,16,1,20);struct.pack_into('>H',data,40,52)
    relocoff=len(data)
    if rel:data+=struct.pack('>II',0,((2 if incoming else 1)<<8)|1)+(bytes(4) if rel==4 else b'')
    sourceoff=len(data)
    if incoming:data+=bytes(16)
    names=b'\0'+section.encode()+b'\0'; namesoff=len(data);data+=names
    shoff=len(data)
    sections=[(0,0,0,0,0,0,0,0,0,0),(1,1,flags,0,52,16,0,0,4,0),
      (0,2,0,0,68,len(symbols),3,len(symbols)//16,4,16),(0,3,0,0,68+len(symbols),len(strings),0,0,1,0)]
    if rel:sections.append((0,rel,0,0,relocoff,12 if rel==4 else 8,2,5 if incoming else 1,4,12 if rel==4 else 8))
    if incoming:sections.append((0,1,6,0,sourceoff,16,0,0,4,0))
    namesindex=len(sections);sections.append((0,3,0,0,namesoff,len(names),0,0,1,0))
    data+=b''.join(struct.pack('>10I',*s) for s in sections)
    struct.pack_into('>I',data,32,shoff);struct.pack_into('>HHH',data,46,40,len(sections),namesindex)
    return data

tool=sys.argv[1]
with tempfile.TemporaryDirectory() as tmp:
    obj,dol=Path(tmp)/'pool.o',Path(tmp)/'retail.dol'
    retail=bytearray(0x110);struct.pack_into('>I',retail,0x1C,0x100);struct.pack_into('>I',retail,0x64,0x80300000);struct.pack_into('>I',retail,0xAC,16)
    def invoke(data,flags,name='@51',retail_bytes=None):
        obj.write_bytes(data)
        if retail_bytes is None:dol.unlink(missing_ok=True)
        else:dol.write_bytes(retail_bytes)
        r=subprocess.run([sys.executable,tool,str(obj),name,'lbl_80300000',str(dol),*flags],capture_output=True)
        return r,obj.read_bytes()
    for guard in ('--require-whole-section','--require-section-symbols=@51'):
        r,after=invoke(fixture(),[guard,"--reject-section-relocations"],retail_bytes=retail)
        assert r.returncode==0 and after!=fixture()
        for kind in (4,9):
            data=fixture(kind)
            r,after=invoke(data,[guard,"--reject-section-relocations"])
            assert r.returncode!=0 and after==data and b'relocation' in r.stderr
        for section,flags in (('.rodata',2),('.sdata2',6)):
            data=fixture(section=section,flags=flags)
            r,after=invoke(data,[guard,'--reject-section-relocations','--require-section=.sdata2'],retail_bytes=retail)
            assert r.returncode!=0 and after==data
        r,after=invoke(fixture(),[guard,'--reject-section-relocations','--require-section=.sdata2'],retail_bytes=retail)
        assert r.returncode==0 and after!=fixture()
        data=fixture(); shoff=struct.unpack_from('>I',data,32)[0]
        data+=data[shoff+40:shoff+80]
        struct.pack_into('>H',data,48,struct.unpack_from('>H',data,48)[0]+1)
        r,after=invoke(data,[guard,'--reject-section-relocations','--require-section=.sdata2'],retail_bytes=retail)
        assert r.returncode!=0 and after==data
        for kind in (0,4,9):
            data=fixture(kind,name='lbl_80300000',flags=6)
            struct.pack_into('>H',data,98,0)
            data[52:68]=b'X'*16
            r,after=invoke(data,[guard,'--reject-section-relocations','--require-section=.sdata2'],retail_bytes=retail)
            assert r.returncode!=0 and after==data and b'retry' in r.stderr
        data=fixture(name='lbl_80300000',section='.rodata')
        struct.pack_into('>H',data,98,0)
        r,after=invoke(data,[guard,'--reject-section-relocations','--require-section=.sdata2'])
        assert r.returncode==0 and after==data
        for extra in ((16,1),(0,1)):
            data=fixture(extra=extra)
            r,after=invoke(data,[guard,'--reject-section-relocations','--require-section=.sdata2'],retail_bytes=retail)
            assert r.returncode!=0 and after==data
        for kind in (4,9):
            data=fixture(kind,extra=(0,3),incoming=True)
            r,after=invoke(data,[guard,'--reject-section-relocations','--require-section=.sdata2'],retail_bytes=retail)
            assert r.returncode!=0 and after==data and b'incoming' in r.stderr
        data=fixture(extra=(0,3))
        r,after=invoke(data,[guard,'--reject-section-relocations','--require-section=.sdata2'],retail_bytes=retail)
        assert r.returncode==0
        for field,value in ((4,3),(16,0x100000),(16,68),(20,0x100000)):
            data=fixture();shoff=struct.unpack_from('>I',data,32)[0]
            struct.pack_into('>I',data,shoff+40+field,value)
            badretail=bytearray(retail);struct.pack_into('>I',badretail,0x1C,0x100000)
            r,after=invoke(data,[guard,'--reject-section-relocations','--require-section=.sdata2'],retail_bytes=badretail)
            assert r.returncode!=0 and after==data
        badretail=bytearray(retail);struct.pack_into('>I',badretail,0x1C,0x100000)
        r,after=invoke(fixture(),[guard,'--reject-section-relocations','--require-section=.sdata2'],retail_bytes=badretail)
        assert r.returncode!=0 and after==fixture()
    for kind in (4,9):
        data=fixture(kind,'lbl_80301000');pointer=bytearray(retail);struct.pack_into('>I',pointer,0x100,0x80301000)
        r,after=invoke(data,['--require-whole-section','--require-relocation-match'],'lbl_80301000',pointer)
        assert r.returncode==0 and after!=data
        r,after=invoke(data,['--require-whole-section','--require-relocation-match'],'lbl_80301000',retail)
        assert r.returncode!=0 and after==data
print('constant-pool relocation guards passed')

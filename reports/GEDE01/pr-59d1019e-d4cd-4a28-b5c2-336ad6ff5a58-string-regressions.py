import runpy
import struct
import subprocess
import sys
import tempfile
from pathlib import Path

string_tool, static_tool = sys.argv[1:]
sys.argv = [__file__, static_tool]
raw_fixture = runpy.run_path(str(Path(__file__).with_name('pr-59d1019e-d4cd-4a28-b5c2-336ad6ff5a58-aggregate-regressions.py')))['fixture']
def fixture(**kwargs):
    data=raw_fixture(**kwargs)
    data[68+16+12]=17  # Global object; the string-pool API requires a linker anchor.
    shoff=struct.unpack_from('>I',data,32)[0];count=struct.unpack_from('>H',data,48)[0]
    headers=data[shoff:shoff+count*40];data=data[:shoff]
    namesoff=len(data);names=b'\0.rodata\0';data+=names
    headers+=struct.pack('>10I',0,3,0,0,namesoff,len(names),0,0,1,0)
    struct.pack_into('>I',headers,40,1)
    struct.pack_into('>I',data,32,len(data));struct.pack_into('>HH',data,48,count+1,count)
    data+=headers
    return data
with tempfile.TemporaryDirectory() as root:
    obj, dol = Path(root)/'pool.o', Path(root)/'retail.dol'
    retail = bytearray(0x110)
    struct.pack_into('>I', retail, 0x1C, 0x100)
    struct.pack_into('>I', retail, 0x64, 0x80300000)
    struct.pack_into('>I', retail, 0xAC, 16)
    def invoke(data, retail_bytes=retail, flags=()):
        obj.write_bytes(data); dol.write_bytes(retail_bytes)
        result = subprocess.run([sys.executable, string_tool, str(obj), 'lbl_80300000', str(dol),*flags], capture_output=True)
        return result.returncode, obj.read_bytes()
    for kind in (4,9):
        original = fixture(kind=1,rel=kind,incoming=2,name='lbl_80300000')
        code, changed = invoke(original)
        assert code == 0 and changed != original
        code,changed=invoke(original,flags=['--require-section=.rodata'])
        assert code==0 and changed!=original
        code,changed=invoke(original,flags=['--require-section=.data'])
        assert code!=0 and changed==original
        shoff=struct.unpack_from('>I',original,32)[0];namesidx=struct.unpack_from('>H',original,50)[0]
        badnames=[]
        duplicate=bytearray(original);struct.pack_into('>I',duplicate,shoff+4*40,1);badnames.append(duplicate)
        for field,value in ((4,1),(16,len(original)+1),(20,len(original)+1)):
            malformed=bytearray(original);struct.pack_into('>I',malformed,shoff+namesidx*40+field,value);badnames.append(malformed)
        malformed=bytearray(original);struct.pack_into('>H',malformed,50,0);badnames.append(malformed)
        malformed=bytearray(original);malformed[shoff-1]=88;badnames.append(malformed)
        for malformed in badnames:
            code,changed=invoke(malformed,flags=['--require-section=.rodata'])
            assert code!=0 and changed==malformed
        cases = [(fixture(kind=1,flags=7,rel=kind,incoming=2,name='lbl_80300000'),retail),
                 (original[:-1],retail),(original,retail[:-1]),
                 (fixture(kind=1,rel=kind,incoming=2,nonzero=True,name='lbl_80300000'),retail)]
        sda = bytearray(original); headers=struct.unpack_from('>I',sda,32)[0]
        roff=struct.unpack_from('>I',sda,headers+5*40+16)[0]
        struct.pack_into('>II',sda,roff,0,(2<<8)|109)
        code,changed=invoke(sda)
        assert code==0 and changed!=sda
        struct.pack_into('>I',sda,roff,1);cases.append((sda,retail))
        outgoing = bytearray(original); headers=struct.unpack_from('>I',outgoing,32)[0]
        struct.pack_into('>I',outgoing,headers+5*40+28,1); cases.append((outgoing,retail))
        truncated = bytearray(original); roff=struct.unpack_from('>I',truncated,headers+5*40+16)[0]
        struct.pack_into('>I',truncated,roff,3); cases.append((truncated,retail))
        overlap=bytearray(original);struct.pack_into('>I',overlap,headers+4*40+16,68+16);cases.append((overlap,retail))
        overlap=bytearray(original);struct.pack_into('>I',overlap,headers+2*40+16,20);cases.append((overlap,retail))
        for data, retail_bytes in cases:
            code, after = invoke(data,retail_bytes)
            assert code != 0 and after == data
print('string-pool fixtures passed')

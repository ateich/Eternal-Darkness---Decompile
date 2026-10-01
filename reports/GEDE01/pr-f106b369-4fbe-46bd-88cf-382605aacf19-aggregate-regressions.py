
import importlib.util, struct, sys
spec=importlib.util.spec_from_file_location('pool',sys.argv[1])
m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
def fixture(kind=8,flags=3,other=False,rel=0,incoming=1,nonzero=False,name='pool'):
    names=b'\0'+name.encode()+b'\0other\0'; header=bytearray(52)
    header[:7]=b'\x7fELF\x01\x02\x01';struct.pack_into('>H',header,40,52);struct.pack_into('>HH',header,16,1,20)
    syms=bytes(16)+struct.pack('>IIIBBH',1,0,16,1,0,1)
    if other: syms+=struct.pack('>IIIBBH',len(name)+2,4,4,1,0,1)
    else: syms+=struct.pack('>IIIBBH',0,0,0,3,0,1)
    blob=header+bytes([int(nonzero)])+bytes(15)+syms+names+bytes(4)
    relocation=struct.pack('>II',0,(incoming<<8)|1)+(bytes(4) if rel==4 else b'') if rel else b''
    relocoff=len(blob);blob+=relocation
    sections=[(0,0,0,0,0,0,0,0,0,0),(0,kind,flags,0,52,16,0,0,4,0),
      (0,2,0,0,68,len(syms),3,3,4,16),(0,3,0,0,68+len(syms),len(names),0,0,1,0),
      (0,1,6,0,68+len(syms)+len(names),4,0,0,4,0)]
    if rel:sections.append((0,rel,0,0,relocoff,len(relocation),2,4,4,12 if rel==4 else 8))
    shoff=len(blob);blob+=b''.join(struct.pack('>10I',*s) for s in sections)
    struct.pack_into('>I',blob,32,shoff);struct.pack_into('>HHH',blob,46,40,len(sections),0)
    return blob
mapping='pool = .bss:0x80300000; // type:object size:0x10'
for kind in (1,8):
    for rel in (0,4,9):
        original=fixture(kind,rel=rel); result=m.externalize(original,'pool',mapping)
        assert result != original
        assert struct.unpack_from('>H',result,68+32+14)[0]==0
        shoff=struct.unpack_from('>I',result,32)[0]
        assert struct.unpack_from('>I',result,shoff+2*40+28)[0]==2
        assert result[68+16+12]>>4==0 and result[68+32+12]>>4==1
        if rel:
            roff=struct.unpack_from('>I',result,shoff+5*40+16)[0]
            assert struct.unpack_from('>I',result,roff+4)[0]>>8==2
    global_pool=fixture(kind,rel=9)
    global_shoff=struct.unpack_from('>I',global_pool,32)[0]
    struct.pack_into('>IIIBBH',global_pool,68+16,0,0,0,3,0,1)
    struct.pack_into('>IIIBBH',global_pool,68+32,1,0,16,17,0,1)
    struct.pack_into('>I',global_pool,global_shoff+2*40+28,2)
    global_roff=struct.unpack_from('>I',global_pool,global_shoff+5*40+16)[0]
    struct.pack_into('>I',global_pool,global_roff+4,(2<<8)|1)
    global_result=m.externalize(global_pool,'pool',mapping)
    assert struct.unpack_from('>I',global_result,global_shoff+2*40+28)[0]==2
    assert struct.unpack_from('>I',global_result,global_roff+4)[0]>>8==2
    malformed_order=fixture(kind)
    struct.pack_into('>I',malformed_order,struct.unpack_from('>I',malformed_order,32)[0]+2*40+28,1)
    cases=[(malformed_order,mapping),(fixture(kind,flags=7),mapping),(fixture(kind,other=True),mapping),
      (fixture(kind),mapping+' scope:local'),(fixture(kind),mapping.replace('0x10','0x8')),(fixture(kind),mapping.replace('pool =','pool_extra =')),
      (fixture(kind)[:-1],mapping),(fixture(kind),mapping+'\n'+mapping)]
    for rel in (4,9):
        data=fixture(kind,rel=rel,incoming=2);cases.append((data,mapping))
        data=fixture(kind,rel=rel);shoff=struct.unpack_from('>I',data,32)[0];roff=struct.unpack_from('>I',data,shoff+5*40+16)[0];struct.pack_into('>I',data,roff,3);cases.append((data,mapping))
        data=fixture(kind,rel=rel);shoff=struct.unpack_from('>I',data,32)[0];roff=struct.unpack_from('>I',data,shoff+5*40+16)[0];struct.pack_into('>I',data,roff+4,(1<<8)|255);cases.append((data,mapping))
        data=fixture(kind,rel=rel);shoff=struct.unpack_from('>I',data,32)[0];struct.pack_into('>I',data,shoff+5*40+28,1);cases.append((data,mapping))
    data=fixture(kind,rel=9);shoff=struct.unpack_from('>I',data,32)[0];roff=struct.unpack_from('>I',data,shoff+5*40+16)[0]
    struct.pack_into('>II',data,roff,2,(1<<8)|32)
    assert m.externalize(data,'pool',mapping)!=data
    struct.pack_into('>I',data,roff,3);cases.append((data,mapping))
    overlap=fixture(kind);shoff=struct.unpack_from('>I',overlap,32)[0];struct.pack_into('>I',overlap,shoff+4*40+16,68+16);cases.append((overlap,mapping))
    overlap=fixture(kind);shoff=struct.unpack_from('>I',overlap,32)[0];struct.pack_into('>I',overlap,shoff+2*40+16,20);cases.append((overlap,mapping))
    if kind==1:cases.append((fixture(kind,nonzero=True),mapping))
    for data,symbols in cases:
        before=bytes(data)
        try:m.externalize(data,'pool',symbols)
        except ValueError:pass
        else:raise AssertionError('unsafe fixture accepted')
        assert bytes(data)==before
# Whole-section coverage may span adjacent retail objects, never overlapping owners.
merged_mapping='pool = .bss:0x80300000; // type:object size:0x8\nnext = .bss:0x80300008; // type:object size:0x8'
for kind in (1,8):
    data=fixture(kind)
    assert m.externalize(data,'pool',merged_mapping)!=data
    for bad in [
        merged_mapping+'\ninterior = .bss:0x80300004; // type:object size:0x4',
        merged_mapping+'\npreceding = .bss:0x802FFFFC; // type:object size:0x8',
        merged_mapping+'\nalias = .bss:0x80300000; // type:object size:0x8',
        merged_mapping.replace('0x80300008','0x80300009'),
        merged_mapping.replace('next = .bss','next = .sbss'),
    ]:
        before=bytes(data)
        try:m.externalize(data,'pool',bad)
        except ValueError:pass
        else:raise AssertionError('ambiguous retail coverage accepted')
        assert bytes(data)==before
print('static-pool fixtures passed')
# fn_80088060's actual MWCC shape: global zero-sized NOTYPE anchor, three
# 20-byte local arrays, and a 60-byte pool covered by 20+44 retail bytes.
def aggregate_fixture():
    names=b'\0pool\0row0\0row1\0row2\0'
    syms=bytes(16)+struct.pack('>IIIBBH',0,0,0,3,0,1)
    for offset,name_offset in [(0,6),(20,11),(40,16)]:
        syms+=struct.pack('>IIIBBH',name_offset,offset,20,1,0,1)
    syms+=struct.pack('>IIIBBH',1,0,0,16,0,1)
    data=bytearray(52)+syms+names+bytes(4)+struct.pack('>II',0,(5<<8)|1)
    data[:7]=b'\x7fELF\x01\x02\x01'
    struct.pack_into('>HH',data,16,1,20);struct.pack_into('>H',data,40,52)
    shoff=len(data)
    sections=[(0,0,0,0,0,0,0,0,0,0),(0,8,3,0,52,60,0,0,4,0),
      (0,2,0,0,52,len(syms),3,5,4,16),(0,3,0,0,52+len(syms),len(names),0,0,1,0),
      (0,1,6,0,52+len(syms)+len(names),4,0,0,4,0),
      (0,9,0,0,shoff-8,8,2,4,4,8)]
    data+=b''.join(struct.pack('>10I',*s) for s in sections)
    struct.pack_into('>I',data,32,shoff);struct.pack_into('>HHH',data,46,40,len(sections),0)
    return data,shoff
aggregate_mapping='pool = .bss:0x80300000; // type:object size:0x14\nnext = .bss:0x80300014; // type:object size:0x2C'
data,shoff=aggregate_fixture()
assert m.externalize(data,'pool',aggregate_mapping)!=data
for defect in ('overlap','gap','global','incoming','extent','retail-overlap'):
    data,shoff=aggregate_fixture();symbols=aggregate_mapping
    if defect=='overlap':struct.pack_into('>I',data,52+3*16+4,16)
    if defect=='gap':struct.pack_into('>I',data,52+3*16+4,24)
    if defect=='global':data[52+3*16+12]=17
    if defect=='incoming':struct.pack_into('>I',data,shoff-4,(3<<8)|1)
    if defect=='extent':struct.pack_into('>I',data,52+4*16+8,24)
    if defect=='retail-overlap':symbols+='\nalias = .bss:0x80300038; // type:object size:0x4'
    before=bytes(data)
    try:m.externalize(data,'pool',symbols)
    except ValueError:pass
    else:raise AssertionError('unsafe aggregate accepted: '+defect)
    assert bytes(data)==before
print('aggregate fn_80088060 fixtures passed')

# Empty PROGBITS aggregates must not leave symbol extents beyond section size.
data,shoff=aggregate_fixture()
data=data[:52]+bytes(60)+data[52:];shoff+=60
struct.pack_into('>I',data,32,shoff)
for index in range(2,6):
    offset=struct.unpack_from('>I',data,shoff+index*40+16)[0]
    struct.pack_into('>I',data,shoff+index*40+16,offset+60)
struct.pack_into('>I',data,shoff+40+4,1)
result=m.externalize(data,'pool',aggregate_mapping)
assert struct.unpack_from('>I',result,shoff+40+4)[0]==1
assert struct.unpack_from('>I',result,shoff+40+20)[0]==0
for index in range(6):
    _,value,size,_,_,owner=struct.unpack_from('>IIIBBH',result,112+index*16)
    if owner==1:assert value==size==0

# R_PPC_EMB_SDA21 patches a complete instruction, including its base register.
for kind in (1,8):
    data=fixture(kind,rel=9);shoff=struct.unpack_from('>I',data,32)[0];roff=struct.unpack_from('>I',data,shoff+5*40+16)[0]
    struct.pack_into('>II',data,roff,0,(1<<8)|109)
    assert m.externalize(data,'pool',mapping)!=data
    struct.pack_into('>I',data,roff,1)
    try:m.externalize(data,'pool',mapping)
    except ValueError:pass
    else:raise AssertionError('truncated SDA21 accepted')

# A named first object followed by local tables (fn_801BC240 shape).
data,shoff=aggregate_fixture()
# Reclassify the first local array as the target; old anchor becomes SECTION.
struct.pack_into('>IIIBBH',data,52+5*16,1,0,20,17,0,1)
struct.pack_into('>IIIBBH',data,52+2*16,0,0,0,3,0,1)
assert m.externalize(data,'pool',aggregate_mapping)!=data
# The first object cannot overlap the next owner's extent.
struct.pack_into('>I',data,52+5*16+8,24)
try:m.externalize(data,'pool',aggregate_mapping)
except ValueError:pass
else:raise AssertionError('overlapping first-object anchor accepted')

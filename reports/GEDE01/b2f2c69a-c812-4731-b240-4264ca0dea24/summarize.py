"""Generate assignment evidence indexes from the committed raw measurements."""
from pathlib import Path
import json, re, hashlib
r = Path(__file__).parent
rows=[]
for p in sorted(r.glob('*.json')):
    d=json.loads(p.read_text())
    if 'left' not in d or 'right' not in d: continue
    rows.append({'experiment':p.stem,'retail_size':int(d['left']['sections'][0]['size']),'generated_size':int(d['right']['sections'][0]['size']),'canonical_or_strict_percent':d['left']['sections'][0]['match_percent']})
(r/'measurements.json').write_text(json.dumps(rows,indent=2)+'\n')
d=json.loads((r/'final.json').read_text())
l=d['left']['symbols'][0]['instructions']; rr=d['right']['symbols'][0]['instructions']
with (r/'instruction-diff.txt').open('w') as f:
    f.write('RAW ALIGNED ROWS from final.json; canonical objdiff is authoritative.\n')
    f.write('row diff_kind | retail offset instruction | generated offset instruction\n')
    for n,(a,b) in enumerate(zip(l,rr)):
        def fmt(row):
            i=row.get('instruction')
            return '<none>' if i is None else f"{int(i.get('address',0)):04x} {i['formatted']}"
        f.write(f"{n:03} {a.get('diff_kind','DIFF_NONE')} | {fmt(a)} | {fmt(b)}\n")

def relocs(name):
    result=[]
    for line in (r/(name+'-relocations.txt')).read_text().splitlines():
        m=re.match(r'^([0-9a-f]{8})\s+[0-9a-f]+\s+(R_PPC_\w+)\s+[0-9a-f]+\s+(\w+)\s+\+\s+(\w+)$',line)
        if m: result.append({'offset':int(m[1],16),'type':m[2],'target':m[3],'addend':int(m[4],16)})
    return result
l,rr=relocs('retail'),relocs('generated')
assert len(l)==len(rr)==20
metadata_equal=all({k:v for k,v in a.items() if k!='offset'}=={k:v for k,v in b.items() if k!='offset'} for a,b in zip(l,rr))
(r/'relocation-comparison.json').write_text(json.dumps({'count':20,'types_targets_addends_equal':metadata_equal,'all_offsets_equal':l==rr,'pairs':[{'retail':a,'generated':b} for a,b in zip(l,rr)]},indent=2)+'\n')
src=Path('src/game/game_fn_801A872C.c')
(r/'source-sha256.txt').write_text(hashlib.sha256(src.read_bytes()).hexdigest()+'  eternal-darkness-decomp/'+str(src)+'\n')

"""Compare .text bytes and classify instruction differences from the strict diff."""
import json,re,struct
from pathlib import Path
folder=Path(__file__).parent
j=json.loads((folder/'final.json').read_text())
syms=[next(s for s in j[side]['symbols'] if s['name']=='fn_801F1A38') for side in ['left','right']]
rows=[[r['instruction'] for r in s['instructions'] if 'instruction' in r] for s in syms]
normalize=lambda text:re.sub(r'\b[rf][0-9]+\b','REG',text)
diffs=[];nonregister=[]
for a,b in zip(*rows):
 if a['formatted']!=b['formatted']:
  row={'offset':int(a['address']),'retail':a['formatted'],'candidate':b['formatted']}
  diffs.append(row)
  if normalize(a['formatted'])!=normalize(b['formatted']):nonregister.append(row)
def text_section(path):
 data=Path(path).read_bytes();assert data[:6]==b'\x7fELF\x01\x02'
 shoff=struct.unpack_from('>I',data,0x20)[0]
 entsize,count,strings=struct.unpack_from('>HHH',data,0x2e)
 sections=[struct.unpack_from('>10I',data,shoff+i*entsize) for i in range(count)]
 strings=sections[strings];names=data[strings[4]:strings[4]+strings[5]]
 for s in sections:
  name=names[s[0]:].split(b'\0',1)[0]
  if name==b'.text':return data[s[4]:s[4]+s[5]]
 raise ValueError('missing .text')
a,b=[text_section('build/GEDE01/'+path+'/game/game_fn_801F1A38.o') for path in ['obj','src']]
assert len(a)==len(b)==1796
result={'size_each':1796,'instruction_count_each':[len(x) for x in rows],'differing_bytes':sum(x!=y for x,y in zip(a,b)),'differing_instruction_words':sum(a[i:i+4]!=b[i:i+4] for i in range(0,len(a),4)),'nonregister_instruction_differences':nonregister,'formatted_instruction_differences':diffs}
(folder/'codegen.json').write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps({k:v for k,v in result.items() if k!='formatted_instruction_differences'},indent=2))

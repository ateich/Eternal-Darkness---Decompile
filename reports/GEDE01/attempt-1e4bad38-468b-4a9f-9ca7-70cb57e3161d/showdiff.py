import json,sys
from pathlib import Path
j=json.loads((Path(__file__).parent/(sys.argv[1]+'.json')).read_text())
a=[next(s for s in j[x]['symbols'] if s['name']=='fn_801F1A38') for x in ['left','right']]
for n,(l,r) in enumerate(zip(a[0]['instructions'],a[1]['instructions'])):
 li=l.get('instruction',{});ri=r.get('instruction',{})
 if len(sys.argv)>2 and not int(sys.argv[2])<=n<int(sys.argv[3]): continue
 print(f"{int(li.get('address',0)):03x} {li.get('formatted',''):42} | {ri.get('formatted','')}")

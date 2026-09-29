"""Restore only the function source from a saved base-relative experiment patch."""
from pathlib import Path
import re,subprocess,sys
source=Path('src/game/game_fn_801F1A38.c')
base=subprocess.check_output(['git','show','3707b9066fe42f247654c4c60dedceb0b1728f70:eternal-darkness-decomp/'+str(source)],text=True).splitlines(True)
patch=(Path(__file__).parent/(sys.argv[1]+'.patch')).read_text().splitlines(True)
out=[]; cursor=0; active=False
for line in patch:
 if line.startswith('--- '):
  if active: break
  continue
 if line.startswith('+++ '): continue
 if line.startswith('@@ '):
  start=int(re.match(r'@@ -(\d+)',line).group(1))-1
  out.extend(base[cursor:start]);cursor=start;active=True
 elif active:
  if line[0]==' ': assert base[cursor]==line[1:];out.append(line[1:]);cursor+=1
  elif line[0]=='-': assert base[cursor]==line[1:];cursor+=1
  elif line[0]=='+': out.append(line[1:])
out.extend(base[cursor:]);source.write_text(''.join(out))

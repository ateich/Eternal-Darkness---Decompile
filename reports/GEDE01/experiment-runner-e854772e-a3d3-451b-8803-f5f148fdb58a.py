"""Run this assignment's object experiment, preserving raw output and source delta.
Run from eternal-darkness-decomp; argv[1] is the experiment label.
Only the existing target's generated constant symbol is reconciled in configure.py.
"""
import difflib, hashlib, json, re, subprocess, sys
from pathlib import Path
ID='e854772e-a3d3-451b-8803-f5f148fdb58a'
label=sys.argv[1]
r=Path('reports/GEDE01')
p=Path('src/game/game_fn_80033180.c')
o='build/GEDE01/src/game/game_fn_80033180.o'
t='build/GEDE01/obj/game/game_fn_80033180.o'
log=(r/f'build-{label}-{ID}.txt').open('a')
def run(args):
    log.write('$ '+' '.join(args)+'\n');log.flush()
    z=subprocess.run(args,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,text=True)
    log.write(z.stdout);log.write(f'Exit status: {z.returncode}\n');log.flush()
    if z.returncode: raise SystemExit(z.returncode)
    return z.stdout
base=subprocess.check_output(['git','show','HEAD:eternal-darkness-decomp/src/game/game_fn_80033180.c'],text=True)
(r/f'source-{label}-{ID}.patch').write_text(''.join(difflib.unified_diff(base.splitlines(True),p.read_text().splitlines(True),fromfile='accepted-base',tofile=label)))
run(['.tools/bin/ninja','-v',o])
nm=run(['build/binutils/powerpc-eabi-nm',o])
constants=re.findall(r'^\w+\s+[rd]\s+(@\d+)$',nm,re.M)
cfg=Path('configure.py');c=cfg.read_text()
start=c.index('"name": "externalize_game_80033180_bias"')
end=c.index('"description"',start)
if len(constants)==1:
    local=constants[0]
    command=(f"python3 tools/externalize_elf_symbol.py $in {local} lbl_8064E038 orig/GEDE01/sys/main.dol --require-whole-section --require-section=.sdata2 --reject-section-relocations && "
             f"build/binutils/powerpc-eabi-objcopy --redefine-sym={local}=lbl_8064E038 --remove-section=.sdata2 $in && touch $out")
elif len(constants)==2:
    # Discover exact-sized generated scalar and bias from the raw symbol table.
    table=run(['build/binutils/powerpc-eabi-objdump','-t','-s',o])
    scalar=re.search(r'^\w+\s+l\s+O \.sdata2\s+00000004 (@\d+)$',table,re.M).group(1)
    bias=re.search(r'^\w+\s+l\s+O \.sdata2\s+00000008 (@\d+)$',table,re.M).group(1)
    # The first check verifies the whole pool ownership, zero padding, and absence
    # of outgoing relocations; each command verifies its constant against retail.
    command=(f"python3 tools/externalize_elf_symbol.py $in {scalar} lbl_8064E1F4 orig/GEDE01/sys/main.dol --require-section-symbols={scalar},{bias} --require-section=.sdata2 --reject-section-relocations && "
             f"python3 tools/externalize_elf_symbol.py $in {bias} lbl_8064E038 orig/GEDE01/sys/main.dol --require-section=.sdata2 && "
             f"build/binutils/powerpc-eabi-objcopy --redefine-sym={scalar}=lbl_8064E1F4 --redefine-sym={bias}=lbl_8064E038 --remove-section=.sdata2 $in && touch $out")
else:
    raise SystemExit('Expected scalar/bias constant pool')
replacement='"name": "externalize_game_80033180_bias",\n        "command": (\n            '+repr(command)+'\n        ),\n        '
c=c[:start]+replacement+c[end:]
if c!=cfg.read_text():
    cfg.write_text(c)
    run(['python3','configure.py','--no-progress'])
run(['.tools/bin/ninja','-v',o.replace('.o','.externalized')])
for strict in (False,True):
    output=r/f'objdiff-{label}{"-strict" if strict else ""}-{ID}.json'
    args=['build/tools/objdiff-cli','diff','-1',t,'-2',o,'fn_80033180','--format','json-pretty','-o',str(output)]
    if strict: args+=['-c','function_reloc_diffs=name_address']
    run(args)
    d=json.loads(output.read_text());sym=next(x for x in d['left']['symbols'] if x['name']=='fn_80033180')
    print(label,'strict' if strict else 'canonical',sym.get('match_percent'))
for side,obj in [('retail',t),('generated',o)]:
    for kind,flag in [('disassembly','-dr'),('relocations','-r')]:
        (r/f'{kind}-{side}-{label}-{ID}.txt').write_text(run(['build/binutils/powerpc-eabi-objdump',flag,obj]))
left=(r/f'disassembly-retail-{label}-{ID}.txt').read_text()
right=(r/f'disassembly-generated-{label}-{ID}.txt').read_text()
(r/f'instruction-diff-{label}-{ID}.txt').write_text(''.join(difflib.unified_diff(left.splitlines(True),right.splitlines(True),fromfile='retail',tofile='generated')))
log.write('Source SHA-256: '+hashlib.sha256(p.read_bytes()).hexdigest()+'\n')
log.write('Object SHA-256: '+hashlib.sha256(Path(o).read_bytes()).hexdigest()+'\n')

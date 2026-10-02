from pathlib import Path
import subprocess, json, difflib
root = Path(__file__).resolve().parents[2]
src = root/'src/game/game_fn_801A94E4.c'
reports = root/'reports/GEDE01'
assignment = '9ae9700e-7c00-4afe-8703-69ab9e1ff461'
base = subprocess.check_output(['git','show','HEAD:eternal-darkness-decomp/src/game/game_fn_801A94E4.c'],cwd=root,text=True)
old = '''            changed = 1;
            if (enabled != 1) {
                s32 discriminator;
                discriminator = enabled == 1 ? 10 : 29;'''
variants = {
'cached-equality': '''            s32 one = enabled == 1;
            changed = 1;
            if (!one) {
                s32 discriminator;
                changed = 1;
                discriminator = one ? 10 : 29;''',
'cached-inequality': '''            s32 other = enabled != 1;
            changed = 1;
            if (other) {
                s32 discriminator;
                changed = 1;
                discriminator = !other ? 10 : 29;''',
'conditional-assignment': '''            changed = 1;
            if (enabled != 1) {
                s32 discriminator;
                discriminator = enabled == 1 ? (changed = 1, 10) : (changed = 1, 29);''',
'comma-condition': '''            changed = 1;
            if (enabled != 1) {
                s32 discriminator;
                discriminator = (changed = 1, enabled == 1) ? 10 : 29;''',
}
variants.update({
'switch-discriminator': old.replace('discriminator = enabled == 1 ? 10 : 29;', 'changed = 1;\n                switch (enabled) { case 1: discriminator = 10; break; default: discriminator = 29; break; }'),
'goto-exit': old.replace('if (enabled != 1) {', 'if (enabled == 1) goto selection_done;\n            {').replace('s32 discriminator;', 's32 discriminator;\n                changed = 1;'),
'switch-guard': old.replace('if (enabled != 1) {', 'switch (enabled) { case 1: break; default: {').replace('s32 discriminator;', 's32 discriminator;\n                changed = 1;'),
'combined-guard': old.replace('changed = 1;\n            if (enabled != 1)', 'if ((changed = 1) && enabled != 1)').replace('s32 discriminator;', 's32 discriminator;\n                changed = 1;'),
'outer-else': old.replace('changed = 1;\n            if (enabled != 1)', 'if (enabled == 1) { changed = 1; } else').replace('s32 discriminator;', 's32 discriminator;\n                changed = 1;'),
})
variants.update({
'int-guard': old.replace('if (enabled != 1)', 'if ((int)enabled != 1)').replace('s32 discriminator;', 's32 discriminator;\n                changed = 1;'),
'int-selector': old.replace('enabled == 1 ?', '(int)enabled == 1 ?').replace('s32 discriminator;', 's32 discriminator;\n                changed = 1;'),
'inline-selector': old.replace('enabled == 1 ? 10 : 29', 'select_discriminator(enabled)').replace('s32 discriminator;', 's32 discriminator;\n                changed = 1;'),
'unsigned-selector': old.replace('enabled == 1 ?', '(unsigned long)enabled == 1UL ?').replace('s32 discriminator;', 's32 discriminator;\n                changed = 1;'),
})
def run(args, file):
    p = subprocess.run(args,cwd=root,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,text=True)
    (reports/file).write_text('$ '+ ' '.join(args)+'\n'+p.stdout+'\nexit_code='+str(p.returncode)+'\n')
    if p.returncode: raise RuntimeError(args)
try:
    for name, block in variants.items():
        if (reports/(f"experiment-{assignment}-{name}.json")).exists(): continue
        candidate = base.replace(old,block)
        if name == 'inline-selector':
            candidate = candidate.replace('s32 fn_801A94E4(', 'static inline s32 select_discriminator(s32 enabled) { return enabled == 1 ? 10 : 29; }\n\ns32 fn_801A94E4(')
        if name == 'goto-exit':
            candidate = candidate.replace('    if (enabled != 0) {\n        if (fade', 'selection_done:\n    if (enabled != 0) {\n        if (fade')
        if name == 'switch-guard':
            candidate = candidate.replace('                lbl_8064D298 = next;', '                lbl_8064D298 = next;\n                break; }')
        assert candidate != base
        src.write_text(candidate)
        prefix = f'experiment-{assignment}-{name}'
        (reports/(prefix+'.patch')).write_text(''.join(difflib.unified_diff(base.splitlines(True),candidate.splitlines(True),fromfile='baseline',tofile=name)))
        run(['.tools/bin/ninja','-v','build/GEDE01/src/game/game_fn_801A94E4.o'],prefix+'-build.txt')
        run(['build/tools/objdiff-cli','diff','-p','.','-u','main/game/game_fn_801A94E4','fn_801A94E4','-o','reports/GEDE01/'+prefix+'.json','--format','json-pretty','-c','function_reloc_diffs=name_address'],prefix+'-objdiff.txt')
        run(['python3','tools/fndiff.py','game/game_fn_801A94E4.c','fn_801A94E4'],prefix+'-instructions.txt')
        run(['build/binutils/powerpc-eabi-readelf','-Wr','build/GEDE01/src/game/game_fn_801A94E4.o'],prefix+'-relocations.txt')
        d=json.loads((reports/(prefix+'.json')).read_text())
        a=next(s for s in d['left']['symbols'] if s['name']=='fn_801A94E4')
        b=next(s for s in d['right']['symbols'] if s['name']=='fn_801A94E4')
        print(name,a['match_percent'],b['size'],flush=True)
finally:
    src.write_text(base)

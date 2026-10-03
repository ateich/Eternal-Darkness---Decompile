import subprocess, json, pathlib, difflib
root=pathlib.Path(__file__).resolve().parents[2]
report=root/'reports/GEDE01'
aid='5e482c0d-542b-4bc1-8e67-8d4b0d92a4de'
src=root/'src/game/game_fn_8002BFE0.c'
baseline=subprocess.check_output(['git','show','eff5553f551b44d3cf4057385bd44556e9c53989:eternal-darkness-decomp/src/game/game_fn_8002BFE0.c'],cwd=root,text=True)

def run(name, source):
    src.write_text(source)
    log=report/f'experiment-{name}-{aid}.txt'
    with log.open('w') as f:
        f.write(''.join(difflib.unified_diff(baseline.splitlines(True),source.splitlines(True),fromfile='baseline',tofile=name)))
        f.write('\nCOMMAND: .tools/bin/ninja -v build/GEDE01/src/game/game_fn_8002BFE0.o\n'); f.flush()
        p=subprocess.run(['.tools/bin/ninja','-v','build/GEDE01/src/game/game_fn_8002BFE0.o'],cwd=root,stdout=f,stderr=subprocess.STDOUT)
        f.write(f'BUILD EXIT: {p.returncode}\n'); f.flush()
        if p.returncode: return
        cmd=['build/tools/objdiff-cli','diff','-p','.', '-u','main/game/game_fn_8002BFE0','fn_8002BFE0','-o',str(report/f'objdiff-{name}-{aid}.json'),'--format','json-pretty']
        f.write('COMMAND: '+' '.join(cmd).replace(str(root)+'/','')+'\n'); f.flush()
        p=subprocess.run(cmd,cwd=root,stdout=f,stderr=subprocess.STDOUT)
        f.write(f'OBJDIFF EXIT: {p.returncode}\n')
        data=json.loads((report/f'objdiff-{name}-{aid}.json').read_text())
        l=next(s for s in data['left']['symbols'] if s['name']=='fn_8002BFE0')
        r=next(s for s in data['right']['symbols'] if s['name']=='fn_8002BFE0')
        summary=f"{name}: target={l['size']} candidate={r['size']} score={l['match_percent']}"
        print(summary,flush=True); f.write(summary+'\n')
        for a,b in zip(l['instructions'],r['instructions']):
            ai=a.get('instruction',{});bi=b.get('instruction',{})
            f.write(f"{ai.get('address',0)} {ai.get('formatted',''):<48} | {bi.get('formatted','')}\n")
        for obj in ['build/GEDE01/obj/game/game_fn_8002BFE0.o','build/GEDE01/src/game/game_fn_8002BFE0.o']:
            f.write('\nCOMMAND: build/binutils/powerpc-eabi-readelf -rW '+obj+'\n');f.flush()
            subprocess.run(['build/binutils/powerpc-eabi-readelf','-rW',obj],cwd=root,stdout=f,stderr=subprocess.STDOUT)
    return l['match_percent']

if __name__=='__main__':
    variants={
        'baseline':baseline,
        'literal_locals':baseline.replace('float one = lbl_8064E064;', 'float one = 1.0f;').replace('float zero = lbl_8064E068;', 'float zero = 0.0f;'),
        'register_locals':baseline.replace('void* object)', 'register void* object)').replace('float* component =', 'register float* component =').replace('s32 i;', 'register s32 i;'),
        'scalar_declarations_first':baseline.replace('    Vec4 second;', '    s32 i;\n    float* component;\n    Vec4 second;').replace('    float* component = &direction.x;\n    s32 i;', '    component = &direction.x;'),
    }
    try:
        for name,source in variants.items(): run(name,source)
    finally: src.write_text(baseline)
    variants2={
        'scalar_first_fixed':baseline.replace('    Vec4 second;', '    s32 i;\n    float* component;\n    Vec4 second;').replace('    float* component = &direction.x;\n    s32 i;\n','').replace('    for (i =', '    component = &direction.x;\n    for (i ='),
        'hoist_loop_locals':baseline.replace('    Vec4 second;', '    float scale;\n    s32 random;\n    Vec4 second;').replace('        float scale;\n        s32 random;\n',''),
        'index_direction':baseline.replace('    float* component = &direction.x;\n','').replace('i++, component++','i++').replace('*component','((float*)&direction)[i]'),
        'do_loop':baseline.replace('    for (i = 0; i < 3; i++, component++) {', '    i = 0;\n    do {').replace('        fn_8012D0D0(object);\n    }','        fn_8012D0D0(object);\n        i++;\n        component++;\n    } while (i < 3);'),
        'swap_cached_constants':baseline.replace('    float one = lbl_8064E064;\n    float zero = lbl_8064E068;', '    float zero = lbl_8064E068;\n    float one = lbl_8064E064;'),
        'const_external':baseline.replace('extern float lbl_', 'extern const float lbl_'),
        'component_increment_first':baseline.replace('i++, component++','component++, i++'),
    }
    try:
        for name,source in variants2.items(): run(name,source)
    finally: src.write_text(baseline)
    hoisted=baseline.replace('    Vec4 second;', '    float scale;\n    s32 random;\n    Vec4 second;').replace('        float scale;\n        s32 random;\n','')
    variants3={
      'hoist_random_only':baseline.replace('    Vec4 second;', '    s32 random;\n    Vec4 second;').replace('        s32 random;\n',''),
      'hoist_scale_only':baseline.replace('    Vec4 second;', '    float scale;\n    Vec4 second;').replace('        float scale;\n',''),
      'hoist_swap_i_component':hoisted.replace('    float* component = &direction.x;\n    s32 i;', '    s32 i;\n    float* component = &direction.x;'),
      'hoist_scale_last':hoisted.replace('    float scale;\n','').replace('    float zero = lbl_8064E068;', '    float zero = lbl_8064E068;\n    float scale;'),
      'hoist_literals':hoisted.replace('= lbl_8064E064;', '= 1.0f;').replace('= lbl_8064E068;', '= 0.0f;'),
      'const_direct_conversion_first':hoisted.replace('extern float lbl_', 'extern const float lbl_').replace('    float one = lbl_8064E064;\n    float zero = lbl_8064E068;\n','').replace('scale = one / (float)random;', 'scale = (float)random;\n        scale = lbl_8064E064 / scale;').replace('*component = one;', '*component = lbl_8064E064;').replace('*component = zero;', '*component = lbl_8064E068;'),
      'literal_conversion_first':hoisted.replace('    float one = lbl_8064E064;\n    float zero = lbl_8064E068;\n','').replace('scale = one / (float)random;', 'scale = (float)random;\n        scale = 1.0f / scale;').replace('*component = one;', '*component = 1.0f;').replace('*component = zero;', '*component = 0.0f;'),
    }
    try:
        for name,source in variants3.items(): run(name,source)
    finally: src.write_text(baseline)
    variants4={}
    for kind in ['literal_conversion_first','const_direct_conversion_first']:
        s=variants3[kind].replace('    float* component = &direction.x;\n    s32 i;', '    s32 i;\n    float* component = &direction.x;')
        variants4[kind+'_swap']=s
    try:
        for name,source in variants4.items(): run(name,source)
    finally: src.write_text(baseline)

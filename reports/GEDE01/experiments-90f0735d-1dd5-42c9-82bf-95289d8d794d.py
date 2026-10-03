import json, subprocess, pathlib, sys
root=pathlib.Path(__file__).resolve().parents[2]
aid='90f0735d-1dd5-42c9-82bf-95289d8d794d'
src=root/'src/game/game_fn_80017FF8.c'
reports=root/'reports/GEDE01'
def baseline():
    return subprocess.check_output(['git','show','982e44656e518d97f55798eb33bd7ae45753b767:eternal-darkness-decomp/src/game/game_fn_80017FF8.c'],cwd=root,text=True)
def run(name,text):
    src.write_text(text)
    cmd=['.tools/bin/ninja','-v','build/GEDE01/src/game/game_fn_80017FF8.o']
    r=subprocess.run(cmd,cwd=root,text=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
    (reports/f'build-{name}-{aid}.log').write_text('COMMAND: '+' '.join(cmd)+'\n'+r.stdout)
    if r.returncode: print(name,'BUILD FAILED',r.stdout); return
    cmd=['build/tools/objdiff-cli','diff','-p','.','-u','main/game/game_fn_80017FF8','fn_80017FF8','--format','json','-o',f'reports/GEDE01/objdiff-{name}-{aid}.json']
    r=subprocess.run(cmd,cwd=root,text=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
    with (reports/f'build-{name}-{aid}.log').open('a') as f: f.write('COMMAND: '+' '.join(cmd)+'\n'+r.stdout)
    d=json.loads((reports/f'objdiff-{name}-{aid}.json').read_text())
    s=[s for s in d['left']['symbols'] if s['name']=='fn_80017FF8'][0]
    t=[s for s in d['right']['symbols'] if s['name']=='fn_80017FF8'][0]
    print(name,s.get('match_percent'),t['size'],flush=True)
def switch(s):
    z='    case 0:\n        flags = 0x100;\n        break;\n'
    return s.replace(z,'').replace('        flags = 0x40;\n        break;','        flags = 0x40;\n        break;\n'+z.rstrip())
def typed(s):
    s=s.replace('typedef struct {\n    u8 bytes[144];\n} SpawnHeader;','typedef union {\n    u8 bytes[144];\n    struct { u8 prefix[40]; u8 body[104]; } layout;\n} SpawnHeader;')
    return s.replace('body = &header.bytes[40];','body = header.layout.body;')
def combined(s): return typed(switch(s))
def local_script(s, first=False):
    s=s.replace('fn_80017FF8(void* script)','fn_80017FF8(void* argument)')
    loc='    void* script;\n'
    if first: s=s.replace('    SpawnHeader header;',loc+'    SpawnHeader header;')
    else: s=s.replace('    f32 best_high;','    f32 best_high;\n'+loc)
    return s.replace('    handle = -1;', '    script = argument;\n    handle = -1;')
def reverse_locals(s):
    a=s.index('    u8* body;'); b=s.index('    f32 min_z;')
    return s[:a]+''.join(reversed(s[a:b].splitlines(True)))+s[b:]
def endpoints_first(s):
    return s.replace('        width = (s16)(max_z - min_z);\n','').replace('        if (mode != 0)', '        width = (s16)(max_z - min_z);\n        if (mode != 0)')
def aligned(s): return s.replace('    u8 bytes[144];','    u8 bytes[144];\n    double alignment;')
def initialized(s, name, expr, typ='s32'):
    return s.replace('    '+typ+' '+name+';\n','').replace('    '+name+' = '+expr+';', '    '+typ+' '+name+' = '+expr+';')
def top_object(s):
    return s.replace('    s32 width;', '    void* object;\n    s32 width;').replace('        void* object =', '        object =')
def top_point(s):
    return s.replace('        Vec3s* point;\n','').replace('    s32 width;', '    Vec3s* point;\n    s32 width;')
def top_distance(s):
    return s.replace('        f32 distance;\n','').replace('    s32 width;', '    f32 distance;\n    s32 width;')
def reordered(s, names):
    a=s.index('    u8* body;'); b=s.index('    f32 min_z;')
    return s[:a]+''.join('    '+('u8*' if n=='body' else 's32')+' '+n+';\n' for n in names)+s[b:]
def else_body(s):
    s=s.replace('        return 1;\n    }', '    } else {')
    return s.replace('    return 1;\n}', '    }\n    return 1;\n}')
def scoped_success(s):
    a=s.index('    SpawnHeader header;'); e=s.index('    handle = -1;')
    block=s[a:e].replace('    s32 count;\n','').replace('    s32 handle;\n','')
    s=s[:a]+'    s32 count;\n    s32 handle;\n'+s[e:]
    s=s.replace('    flags = 0;', '    {\n'+block+'    flags = 0;')
    return s.replace('    return 1;\n}', '    }\n    return 1;\n}')
def reuse_kind_index(s):
    import re
    return re.sub(r'\bi\b','kind',s.replace('    s32 i;\n',''))
def reuse_index_kind(s):
    import re
    return re.sub(r'\bkind\b','i',s.replace('    s32 kind;\n',''))
def reuse_object_index(s):
    import re
    s=s.replace('        void* object = *(void**)&info.bytes[148];', '        i = *(s32*)&info.bytes[148];')
    return re.sub(r'\bobject\b', '(void*)i',s)
def late_handle(s,loc):
    return s.replace('    handle = -1;\n','').replace(loc,'    handle = -1;\n'+loc)
def external_constants(s):
    s=s.replace('extern double lbl_8064DE68;', 'extern const f32 lbl_8064DCF4;\nextern const f32 lbl_8064DE70;\nextern const f32 lbl_8064DE74;\nextern double lbl_8064DE68;')
    return s.replace('direction[2] = 0.0f;', 'direction[2] = lbl_8064DCF4;').replace('best_low = 1000000.0f;', 'best_low = lbl_8064DE70;').replace('best_high = -1000000.0f;', 'best_high = lbl_8064DE74;')

# Exact transformations tested in this assignment, including rejected syntax
# experiments. No alternate translation units are retained. All use GC/1.3
# through the existing configured assigned-object Ninja rule.
def variants():
    initial=baseline()
    c=combined(initial)
    b=aligned(endpoints_first(c))
    order=['kind','count','handle','user_value','mode','body','flags','width','i']
    reg=b
    for decl in ['s32','u8*','f32']:
        reg=reg.replace('    '+decl+' ', '    register '+decl+' ')
    scalar_reg=b[:b.index('s32 fn_80017FF8')]+b[b.index('s32 fn_80017FF8'):].replace('    s32 ', '    register s32 ').replace('    u8* body;', '    register u8* body;')
    return {
        'baseline':initial,
        'switch-order':switch(initial),
        'typed-body':typed(initial),
        'register-script':initial.replace('fn_80017FF8(void* script)','fn_80017FF8(register void* script)'),
        'combined':c,
        'script-local-first':local_script(c,True),
        'script-local-last':local_script(c),
        'reverse-locals':reverse_locals(c),
        'endpoints-before-width':endpoints_first(c),
        'aligned-header':b,
        'declare-handle':initialized(b,'handle','-1'),
        'declare-count':initialized(b,'count','(s32)fn_8016A694(script, 1)'),
        'declare-flags':initialized(b,'flags','0'),
        'declare-kind':initialized(b,'kind','(s32)fn_8016A694(script, 2)'),
        'handle-first':b.replace('    s32 handle;\n','').replace('    SpawnHeader header;','    s32 handle;\n    SpawnHeader header;'),
        'scope-loop-index':b.replace('    s32 i;\n','').replace('    for (i = 0;', '    { s32 i;\n    for (i = 0;').replace('    *(SpawnHeader*)&info', '    }\n    *(SpawnHeader*)&info'),
        'object-function-scope':top_object(b),
        'point-function-scope':top_point(b),
        'distance-function-scope':top_distance(b),
        'all-function-scope':top_distance(top_point(top_object(b))),
        'register-locals':reg,
        'register-flags':b.replace('    s32 flags;','    register s32 flags;'),
        'retail-order':reordered(b,order),
        'retail-order-reversed':reordered(b,list(reversed(order))),
        'register-scalars':scalar_reg,
        'else-success':else_body(b),
        'goto-return':b.replace('        return 1;', '        goto done;').replace('    return 1;\n}', 'done:\n    return 1;\n}'),
        'scoped-success':scoped_success(b),
        'reuse-kind-index':reuse_kind_index(b),
        'reuse-index-kind':reuse_index_kind(b),
        'reuse-object-index':reuse_object_index(b),
        'reuse-all-three':reuse_object_index(reuse_index_kind(b)),
        'reuse-kind-index-corrected':reuse_kind_index(b).replace('%kind','%i'),
        'handle-before-create':late_handle(b,'    *(SpawnHeader*)&info'),
        'handle-after-check':late_handle(b,'    flags = 0;'),
        'external-constants':external_constants(b),
    }
if __name__=='__main__':
    import argparse
    parser=argparse.ArgumentParser(description='Reproduce a recorded source experiment; default lists experiments.')
    parser.add_argument('--run',choices=list(variants()))
    args=parser.parse_args()
    if args.run:
        saved=src.read_text()
        try: run(args.run,variants()[args.run])
        finally: src.write_text(saved)
    else:
        print('\n'.join(variants()))

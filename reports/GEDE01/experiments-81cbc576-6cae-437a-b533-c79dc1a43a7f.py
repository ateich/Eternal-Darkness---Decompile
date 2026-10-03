"""Scoped attempt-5 source experiments; invoke from eternal-darkness-decomp."""
import difflib,json,pathlib,subprocess,sys
ID='81cbc576-6cae-437a-b533-c79dc1a43a7f'
R=pathlib.Path('reports/GEDE01'); S=pathlib.Path('src/game/game_fn_80026DC8.c')
BASE=subprocess.check_output(['git','show','67198d35d583f63c2ff0cd316377a06edb0660b7:eternal-darkness-decomp/src/game/game_fn_80026DC8.c'],text=True)
COPY='    for (i = 0; i < 4; i++) {\n        color[i] = lbl_80238C4C[i];\n    }'

def measure(name,source):
    S.write_text(source)
    stem=ID if name=='final' else f'{name}-{ID}'
    (R/f'source-{stem}.patch').write_text(''.join(difflib.unified_diff(BASE.splitlines(True),source.splitlines(True),fromfile='accepted-base',tofile=name)))
    commands=[['.tools/bin/ninja','-v','build/GEDE01/src/game/game_fn_80026DC8.o']]
    with (R/f'build-{stem}.txt').open('w') as out:
        for cmd in commands:
            out.write('$ '+' '.join(cmd)+'\n');out.flush()
            p=subprocess.run(cmd,stdout=out,stderr=subprocess.STDOUT)
            out.write(f'exit={p.returncode}\n')
            if p.returncode:return
    for suffix,extra in [('',[]),('-reloc-strict',['-c','function_reloc_diffs=name_address'])]:
        cmd=['build/tools/objdiff-cli','diff','-p','.','-u','main/game/game_fn_80026DC8','fn_80026DC8','-o',str(R/f'objdiff-{stem}{suffix}.json'),'--format','json-pretty']+extra
        with (R/f'build-{stem}.txt').open('a') as out:
            out.write('$ '+' '.join(cmd)+'\n');out.flush()
            p=subprocess.run(cmd,stdout=out,stderr=subprocess.STDOUT);out.write(f'exit={p.returncode}\n')
    with (R/f'instruction-diff-{stem}.txt').open('w') as out:
        subprocess.run(['python3','tools/fndiff.py','game/game_fn_80026DC8.c','fn_80026DC8'],stdout=out,stderr=subprocess.STDOUT,check=True)
    with (R/f'relocations-{stem}.txt').open('w') as out:
        for obj in ['obj','src']:
            cmd=['build/binutils/powerpc-eabi-readelf','-Wr',f'build/GEDE01/{obj}/game/game_fn_80026DC8.o']
            out.write('$ '+' '.join(cmd)+'\n');out.flush();subprocess.run(cmd,stdout=out,stderr=subprocess.STDOUT,check=True)
    d=json.loads((R/f'objdiff-{stem}.json').read_text())
    print(name,[(s['name'],s.get('size'),s.get('match_percent')) for s in d['left']['symbols'] if s['name']=='fn_80026DC8'],flush=True)

if __name__=='__main__':
    name=sys.argv[1]
    if name=='baseline':source=BASE
    elif name=='aggregate-copy':
        source=BASE.replace('extern const u32 lbl_80238C4C[4];','typedef struct { u32 entry[4]; } Palette;\nextern const Palette lbl_80238C4C;').replace('    u32 color[4];','    Palette palette;').replace(COPY,'    palette = lbl_80238C4C;').replace('color[','palette.entry[')
    elif name=='scalar-copy':
        source=BASE.replace(COPY,'\n'.join(f'    color[{i}] = lbl_80238C4C[{i}];' for i in range(4)))
    elif name=='array-initializer':
        source=BASE.replace('    s16 x[4];', '    s32 width = right - left;\n    s32 clip = left + (s32)(fraction * width);\n    s16 x[4] = {left, (s32)(left + lbl_8064DFA8 * width),\n                (s32)(left + lbl_8064DFAC * width), right};').replace('    s32 width;\n    s32 clip;\n','')
        start=source.index('    width = right - left;')
        end=source.index('    for (i = 0; i < 4; i++)', start)
        source=source[:start]+source[end:]
        source=source.replace(COPY,'\n'.join(f'    color[{i}] = lbl_80238C4C[{i}];' for i in range(4)))
    elif name=='palette-initializer':
        source=BASE.replace('    u32 color[4];','    u32 color[4] = {lbl_80238C4C[0], lbl_80238C4C[1], lbl_80238C4C[2], lbl_80238C4C[3]};').replace(COPY,'')
    elif name.startswith('register-'):
        source=BASE.replace(COPY,'\n'.join(f'    color[{i}] = lbl_80238C4C[{i}];' for i in range(4)))
        var=name[len('register-'):]
        source=source.replace('    s32 '+var+';', '    register s32 '+var+';')
    elif name in ('scalar-alpha','do-alpha','long-locals','color-first-decl','late-clip'):
        source=BASE.replace(COPY,'\n'.join(f'    color[{i}] = lbl_80238C4C[{i}];' for i in range(4)))
        alpha='    for (i = 0; i < 4; i++) {\n        color[i] |= alpha;\n    }'
        if name=='scalar-alpha':source=source.replace(alpha,'\n'.join(f'    color[{i}] |= alpha;' for i in range(4)))
        if name=='do-alpha':source=source.replace(alpha,'    i = 0;\n    do {\n        color[i] |= alpha;\n    } while (++i < 4);')
        if name=='long-locals':source=source.replace('    s32 width;', '    long width;').replace('    s32 clip;', '    long clip;')
        if name=='color-first-decl':source=source.replace('    s16 x[4];\n    u32 color[4];','    u32 color[4];\n    s16 x[4];')
        if name=='late-clip':source=source.replace('    clip = left + (s32)(fraction * width);\n','').replace('    x[3] = right;','    x[3] = right;\n    clip = left + (s32)(fraction * width);')
    elif name=='literal-palette':
        source=BASE.replace('    u32 color[4];','    u32 color[4] = {0xff000000, 0xffdc0000, 0xdcff0000, 0x00ff0000};').replace(COPY,'')
    elif name=='final':
        source=BASE.replace('extern const u32 lbl_80238C4C[4];\n','').replace('    u32 color[4];','    u32 color[4] = {0xff000000, 0xffdc0000, 0xdcff0000, 0x00ff0000};').replace(COPY+'\n','')
    else:raise SystemExit(name)
    measure(name,source)

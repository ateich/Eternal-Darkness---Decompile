import os, json, subprocess, hashlib, struct, datetime
from pathlib import Path
ID = 'b98a13d3-bf60-4994-b846-b6f52ade83cc'
ROOT = Path(__file__).resolve().parents[2]
os.chdir(ROOT)
SOURCE = Path('src/game/game_fn_801F85A4.c')
REPORT = Path('reports/GEDE01/objdiff-' + ID + '.json')

def run(args):
    p = subprocess.run(args, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    return {'argv': args, 'cwd': 'eternal-darkness-decomp', 'exit_code': p.returncode, 'stdout': p.stdout, 'stderr': p.stderr}

def text_bytes():
    b = Path('build/GEDE01/src/game/game_fn_801F85A4.o').read_bytes()
    endian = '>' if b[5] == 2 else '<'
    shoff = struct.unpack_from(endian + 'I', b, 32)[0]
    shentsize, shnum, shstrndx = struct.unpack_from(endian + 'HHH', b, 46)
    sections = [struct.unpack_from(endian + '10I', b, shoff + i*shentsize) for i in range(shnum)]
    strings = sections[shstrndx]
    names = b[strings[4]:strings[4]+strings[5]]
    for sec in sections:
        if names[sec[0]:].split(b'\0')[0] == b'.text':
            data = b[sec[4]:sec[4]+sec[5]]
            return {'length':len(data), 'sha256':hashlib.sha256(data).hexdigest(), 'hex':data.hex()}

def measure(name, source, hypothesis):
    SOURCE.write_text(source)
    record = {'name':name, 'hypothesis':hypothesis, 'source':source, 'source_sha256':hashlib.sha256(source.encode()).hexdigest(), 'build':run(['.tools/bin/ninja','-j2','-v','build/GEDE01/src/game/game_fn_801F85A4.o'])}
    if record['build']['exit_code'] == 0:
        record['text_bytes'] = text_bytes()
        record['comparisons'] = {}
        for mode in ['none', 'name_address', 'all']:
            r = run(['build/tools/objdiff-cli','diff','-p','.','-u','main/game/game_fn_801F85A4','fn_801F85A4','-o','-','--format','json','-c','function_reloc_diffs='+mode])
            record['comparisons'][mode] = r
            if r['exit_code'] == 0:
                d=json.loads(r['stdout'])
                symbol=next(s for s in d['left']['symbols'] if s['name']=='fn_801F85A4')
                r['score']=symbol.get('match_percent')
        print(name, record['text_bytes']['length'], {k:v.get('score') for k,v in record['comparisons'].items()}, flush=True)
    else:
        print(name, 'BUILD FAILED', record['build'], flush=True)
    report=json.loads(REPORT.read_text()) if REPORT.exists() else {'version':1, 'assignment_id':ID, 'target':'fn_801F85A4', 'started_at':datetime.datetime.now(datetime.timezone.utc).isoformat(), 'experiments':[]}
    report['experiments'].append(record)
    REPORT.write_text(json.dumps(report, indent=2)+'\n')
    return record

if __name__ == '__main__':
    base = subprocess.check_output(['git','show','ff977f359c17f8a46ab9f390459942a26c2eb8be:eternal-darkness-decomp/src/game/game_fn_801F85A4.c'],text=True)
    measure('baseline',base,'Reproduce accepted-base measurement with none, name_address, and all relocation settings.')
    s=base.replace('typedef struct SavedState {','typedef struct FloatValue { float scalar; } FloatValue;\ntypedef struct HandleValue { unsigned int scalar; } HandleValue;\n\ntypedef struct SavedState {')
    s=s.replace('    float value;','    FloatValue value;').replace('    unsigned int handle;','    HandleValue handle;')
    s=s.replace('        float first_value;','        FloatValue first_value;').replace('        float second_value;','        FloatValue second_value;').replace('        unsigned int first_handle;','        HandleValue first_handle;').replace('        unsigned int second_handle;','        HandleValue second_handle;')
    for n in ['first_value','second_value','first_handle','second_handle']:
        s=s.replace('        '+n+' = saved->','        '+n+'.scalar = saved->')
    measure('aggregate_member_copies',s,'Use single-member structure copies for live value/handle fields. Aggregate assignment lowering may retain destination addresses beyond scalar address folding without touching padding.')
    s=base.replace('        LiveState* first;\n        LiveState* second;','        union LivePointers {\n            struct { LiveState* first; LiveState* second; } input;\n            struct { LiveState* first; LiveState* second; } output;\n        } live;')
    s=s.replace('        first =','        live.input.first =').replace('        second =','        live.input.second =').replace('        first->','        live.output.first->').replace('        second->','        live.output.second->')
    measure('union_common_initial_sequence',s,'Access destination pointers through the common initial sequence of two union structures. This legal C union boundary may force pointer address materialization while eliminating local aggregate storage.')
    s=base.replace('LiveState* first;', 'LiveState* __restrict first;').replace('LiveState* second;', 'LiveState* __restrict second;')
    measure('restrict_destinations',s,'Assert that the two non-overlapping live subobjects are accessed through independent restrict pointers, testing whether MWCC retains distinct restricted address bases.')
    s=base.replace('        token = saved->token;\n        first->value = first_value;', '        first->value = first_value;\n        token = saved->token;')
    measure('token_after_first_store',s,'Place the token load after the first floating-point store, as in retail, retaining saved-record volatile load ordering and testing the resulting scheduler dependencies.')
    measure('final',base,'Restore the best accepted-base source after rejected variants; independently remeasure all comparison settings.')

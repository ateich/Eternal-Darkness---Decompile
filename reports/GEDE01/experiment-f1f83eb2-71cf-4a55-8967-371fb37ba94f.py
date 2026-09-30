import subprocess, json, re, difflib
from pathlib import Path
root = Path(__file__).resolve().parents[2]
source = root / 'src/game/game_fn_802093FC.c'
base = subprocess.check_output(['git', 'show', '8835a572:eternal-darkness-decomp/src/game/game_fn_802093FC.c'], cwd=root, text=True)
report = Path(__file__).with_suffix('.log')
def run(label, text):
    source.write_text(text)
    with report.open('a') as log:
        log.write('\n=== '+label+' ===\n')
        log.writelines(difflib.unified_diff(base.splitlines(True), text.splitlines(True), fromfile='preserved', tofile=label))
        log.flush()
        p = subprocess.run(['.tools/bin/ninja','-j2','build/GEDE01/src/game/game_fn_802093FC.o'],cwd=root,stdout=log,stderr=subprocess.STDOUT)
        log.write('build exit status: '+str(p.returncode)+'\n'); log.flush()
        if p.returncode: return
        out = root / 'build/GEDE01/f1f83eb2-experiment.json'
        p = subprocess.run(['build/tools/objdiff-cli','diff','-p','.', '-u','main/game/game_fn_802093FC','GetTypeCallback_802093FC','-o',str(out.relative_to(root)),'--format','json'],cwd=root,stdout=log,stderr=subprocess.STDOUT)
        if p.returncode: return
        d=json.loads(out.read_text())
        for side in ['left','right']:
            sym=next(s for s in d[side]['symbols'] if s['name']=='GetTypeCallback_802093FC')
            log.write(side+' size='+str(sym.get('size'))+' score='+str(sym.get('match_percent'))+'\n')
            log.write('\n'.join(i.get('instruction',{}).get('formatted','') for i in sym.get('instructions',[]))+'\n')
        log.flush()
pattern = r'work->cmdFixDevice\[chan\] =\s*(.*?);\s*Type_802FCA34\[chan\] = 0x80;\s*SITransfer\(chan, &work->cmdFixDevice\[chan\], 3,\s*&Type_802FCA34\[chan\], 3,\s*GetTypeCallback_802093FC, 0\);'
helper = """void GetTypeCallback_802093FC(s32 chan, u32 error, OSContext *context);
static inline void FixDevice(SIWork *work, s32 chan, u32 command)
{
    u32 *output = &work->cmdFixDevice[chan];
    *output = command;
    Type_802FCA34[chan] = 0x80;
    SITransfer(chan, output, 3, &Type_802FCA34[chan], 3,
               GetTypeCallback_802093FC, 0);
}

"""
for label, h in [('inline_command',helper),('inline_channel_view',helper.replace('u32 *output = &work->cmdFixDevice[chan];','u32 *output = (u32 *)((u8 *)work + chan * sizeof(u32));').replace('*output = command;', '*(output += 0x1F0 / sizeof(u32)) = command;'))]:
    text = re.sub(pattern, lambda m: 'FixDevice(work, chan, '+m.group(1)+');',base,flags=re.S)
    assert text.count('FixDevice(work, chan,') == 3
    text = text.replace('void GetTypeCallback_802093FC(s32 chan, u32 error, OSContext *context)\n{',h+'void GetTypeCallback_802093FC(s32 chan, u32 error, OSContext *context)\n{')
    run(label,text)
import itertools
h = helper.replace('u32 *output = &work->cmdFixDevice[chan];','u32 *output = (u32 *)((u8 *)work + chan * sizeof(u32));').replace('*output = command;', '*(output += 0x1F0 / sizeof(u32)) = command;')
params = {'work': 'SIWork *work', 'chan': 's32 chan', 'command': 'u32 command'}
for order in itertools.permutations(params):
    if order == ('work', 'chan', 'command'): continue
    ordered = h.replace('SIWork *work, s32 chan, u32 command', ', '.join(params[x] for x in order))
    def replace(m):
        args = {'work':'work','chan':'chan','command':m.group(1)}
        return 'FixDevice('+', '.join(args[x] for x in order)+');'
    text = re.sub(pattern, replace, base, flags=re.S)
    text = text.replace('void GetTypeCallback_802093FC(s32 chan, u32 error, OSContext *context)\n{', ordered+'void GetTypeCallback_802093FC(s32 chan, u32 error, OSContext *context)\n{')
    run('helper_parameter_order_'+'_'.join(order), text)
text = re.sub(pattern, lambda m: 'FixDevice(work, chan, '+m.group(1)+');',base,flags=re.S)
text = text.replace('void GetTypeCallback_802093FC(s32 chan, u32 error, OSContext *context)\n{',h+'void GetTypeCallback_802093FC(s32 chan, u32 error, OSContext *context)\n{')
for name, old, new in [
    ('work_last', '    SIWork *work = &Packet_80640B68;\n    u32 type;\n    u32 chanBit;\n    s32 fix;\n    u32 id;', '    u32 type;\n    u32 chanBit;\n    s32 fix;\n    u32 id;\n    SIWork *work = &Packet_80640B68;'),
    ('register_work', 'SIWork *work = &Packet_80640B68;', 'register SIWork *work = &Packet_80640B68;'),
    ('id_first', '    u32 type;\n    u32 chanBit;\n    s32 fix;\n    u32 id;', '    u32 id;\n    s32 fix;\n    u32 chanBit;\n    u32 type;')]:
    run(name, text.replace(old,new))
source.write_text(base)

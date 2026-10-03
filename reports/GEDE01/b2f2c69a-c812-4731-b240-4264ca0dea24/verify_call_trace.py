"""Bounded instruction-level argument comparison; not a full PPC/runtime emulator."""
import itertools, json, random, re
from pathlib import Path
report = Path(__file__).parent
data = json.loads((report / 'final.json').read_text())
mask = 0xffffffff

def program(side):
    return [row['instruction']['formatted'] for row in data[side]['symbols'][0]['instructions'] if 'instruction' in row]

def execute(code, args):
    regs = [0]*32
    regs[1] = 0x81000000
    regs[3:9] = [v & mask for v in args]
    regs[9] = 0x90000000
    mem = {regs[9]: 0x12345678}
    trace = []
    def reg(s): return int(s[1:])
    def addr(s):
        m = re.fullmatch(r'(-?0x[0-9a-f]+)\(r(\d+)\)',s)
        return (int(m[1],0) + regs[int(m[2])]) & mask
    for text in code:
        op, _, operands = text.partition(' ')
        a = operands.split(', ')
        if op in ('mflr','stmw'): continue
        if op in ('lmw','blr'): break
        if op == 'stwu':
            address = addr(a[1]); mem[address] = regs[reg(a[0])]; regs[1] = address
        elif op == 'stw': mem[addr(a[1])] = regs[reg(a[0])]
        elif op == 'lwz': regs[reg(a[0])] = mem[addr(a[1])]
        elif op == 'mr': regs[reg(a[0])] = regs[reg(a[1])]
        elif op == 'extsh':
            value = regs[reg(a[1])] & 0xffff
            regs[reg(a[0])] = (value if value < 0x8000 else value - 0x10000) & mask
        elif op in ('li','lis'): regs[reg(a[0])] = (int(a[1],0) << (16 if op=='lis' else 0)) & mask
        elif op == 'add': regs[reg(a[0])] = (regs[reg(a[1])] + regs[reg(a[2])]) & mask
        elif op == 'addi': regs[reg(a[0])] = ((regs[reg(a[1])] if a[1]!='r0' else 0) + int(a[2],0)) & mask
        elif op == 'subf': regs[reg(a[0])] = (regs[reg(a[2])] - regs[reg(a[1])]) & mask
        elif op == 'bl':
            symbol = a[0]
            count = {'fn_801A852C':4,'fn_801ECF50':1,'fn_80226AB4':3,'fn_801A9454':3,'fn_801A9450':0}[symbol]
            values = regs[3:3+count]
            if symbol == 'fn_801A852C': values[0] = mem[values[0]]
            trace.append((symbol,values))
            # Poison caller-clobbered registers to ensure no accidental reliance on them.
            for i in [0,*range(3,13)]: regs[i] = (0xa5a50000 + 37*len(trace) + i) & mask
        else: raise AssertionError(text)
    return trace

bounds = [0,1,-1,32767,32768,-32768,-32769,65535,65536,0x7fffffff,-0x80000000]
cases = [(x,y,32767,-32768,0x80000001,inset) for x,y,inset in itertools.product(bounds,repeat=3)]
rng = random.Random(0x801A872C)
cases += [tuple(rng.getrandbits(32) for _ in range(6)) for _ in range(4096)]
l,r = program('left'),program('right')
for args in cases:
    lt,rt = execute(l,args),execute(r,args)
    assert lt == rt, (args,lt,rt)
    assert len(lt)==20
print(json.dumps({'cases':len(cases),'seed':'0x801A872C','all_call_arguments_equal':True,'calls_per_case':20,'limitation':'Bounded straight-line instruction interpreter; callees are represented only by their argument traces. Does not replace legal audit, full build, strict acceptance gates, or DOL SHA-1 verification.'},indent=2))

import json
import re
from probe import HERE, SOURCE, measure
from probe_addresses import ORDERED, scoped

if __name__ == '__main__':
    best = None
    pattern = re.compile(r'offset \+= fn_801FB3B4\(\(u8\*\)output \+ offset, base \+ ([\w.]+) \* 0x88, ([01])\);')
    try:
        for mask in range(16):
            n = [0]
            def repl(m):
                step = mask & (1 << n[0])
                n[0] += 1
                if not step:
                    return m.group(0)
                index, flag = m.groups()
                return f'base += {index} * 0x88;\n            offset += fn_801FB3B4((u8*)output + offset, base, {flag});'
            source = pattern.sub(repl, scoped(ORDERED))
            result = measure('combined-' + str(mask), source, 'Four-bit mask selects split pointer increment versus scoped address expression at the four indexed calls, in source order: ' + str(mask))
            if result.get('left') and (best is None or result['left']['match_percent'] > best['left']['match_percent']):
                best = result
        (HERE / 'best-probe.json').write_text(json.dumps(best, indent=2) + '\n')
    finally:
        SOURCE.write_text(best['source'] if best else scoped(ORDERED))

"""Replay source snapshots from this assignment's experiment report.

Run from eternal-darkness-decomp with --all or a zero-based experiment index.
Only the assigned source, its build output, and assignment reports are written.
The current candidate is restored and rebuilt, even if an experiment fails.
"""
from pathlib import Path
import hashlib
import json
import subprocess
import sys

ASSIGNMENT = '91bfdafc-2fc3-437b-bbe3-a5b11056b102'
REPORTS = Path('reports/GEDE01')
RECORD = REPORTS / ('experiments-' + ASSIGNMENT + '.json')
SOURCE = Path('src/game/game_fn_800D9428.c')
TEMP = REPORTS / ('measurement-' + ASSIGNMENT + '.json')
BUILD = ['.tools/bin/ninja', '-j2', 'build/GEDE01/src/game/game_fn_800D9428.o']
DIFF = ['build/tools/objdiff-cli', 'diff', '-p', '.', '-u', 'main/game/game_fn_800D9428', '-o', str(TEMP), '--format', 'json-pretty', 'fn_800D9428']


def run(command):
    result = subprocess.run(command, capture_output=True, text=True)
    return {'command': command, 'exit_code': result.returncode,
            'stdout': result.stdout, 'stderr': result.stderr}


def main():
    data = json.loads(RECORD.read_text())
    indices = range(len(data['experiments'])) if sys.argv[1] == '--all' else [int(sys.argv[1])]
    original = SOURCE.read_text()
    raw = data.setdefault('raw_reports', {})
    try:
        for index in indices:
            entry = data['experiments'][index]
            SOURCE.write_text(entry['source'])
            entry['replay_build'] = run(BUILD)
            if entry['replay_build']['exit_code'] == 0:
                entry['replay_diff'] = run(DIFF)
                if entry['replay_diff']['exit_code'] != 0:
                    raise RuntimeError(entry['replay_diff'])
                report = json.loads(TEMP.read_text())
                digest = hashlib.sha256(json.dumps(report, sort_keys=True).encode()).hexdigest()
                raw[digest] = report
                entry['raw_report_sha256'] = digest
                symbols = [next(s for s in report[side]['symbols'] if s['name'] == 'fn_800D9428') for side in ('left', 'right')]
                entry['replayed_score'] = symbols[0]['match_percent']
                entry['replayed_sizes'] = [s['size'] for s in symbols]
                if entry.get('score') is not None:
                    assert entry['score'] == entry['replayed_score'], (index, entry['score'], entry['replayed_score'])
            print(index, entry['name'], entry.get('replayed_score'), entry.get('replayed_sizes'))
    finally:
        SOURCE.write_text(original)
        data['restore_build'] = run(BUILD)
        if TEMP.exists():
            TEMP.unlink()
        # Full tool JSON is preserved, deduplicated by content digest.
        RECORD.write_text(json.dumps(data, separators=(',', ':')) + '\n')


if __name__ == '__main__':
    main()

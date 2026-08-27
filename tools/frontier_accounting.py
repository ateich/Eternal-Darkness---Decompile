#!/usr/bin/env python3
"""Derive frontier byte accounting from DTK splits and configure registrations."""

from __future__ import annotations

import argparse
import re
from pathlib import Path


SPLIT_HEADER = re.compile(r"^(?P<path>[^\s].+):$")
TEXT_RANGE = re.compile(
    r"^\s*\.text\s+start:(?P<start>0x[0-9A-Fa-f]+)\s+end:(?P<end>0x[0-9A-Fa-f]+)\s*$"
)
OBJECT = re.compile(
    r'^\s*Object\((?P<status>Matching|NonMatching),\s*"(?P<path>[^"]+)"'
)


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser()
    parser.add_argument("--splits", type=Path, required=True)
    parser.add_argument("--configure", type=Path, required=True)
    parser.add_argument("--start", type=lambda value: int(value, 0), required=True)
    parser.add_argument("--end", type=lambda value: int(value, 0), required=True)
    return parser.parse_args()


def read_statuses(path: Path) -> dict[str, str]:
    statuses: dict[str, str] = {}
    for line in path.read_text().splitlines():
        match = OBJECT.match(line)
        if match:
            statuses[match.group("path")] = match.group("status")
    return statuses


def read_text_spans(path: Path) -> list[tuple[str, int, int]]:
    spans: list[tuple[str, int, int]] = []
    current_path: str | None = None
    for line in path.read_text().splitlines():
        header = SPLIT_HEADER.match(line)
        if header:
            current_path = header.group("path")
            continue
        text_range = TEXT_RANGE.match(line)
        if text_range and current_path:
            spans.append(
                (
                    current_path,
                    int(text_range.group("start"), 16),
                    int(text_range.group("end"), 16),
                )
            )
    return spans


def main() -> None:
    args = parse_args()
    statuses = read_statuses(args.configure)
    spans = [
        (path, start, end, statuses[path])
        for path, start, end in read_text_spans(args.splits)
        if start >= args.start and end <= args.end
    ]

    if not spans or spans[0][1] != args.start or spans[-1][2] != args.end:
        raise SystemExit("selected split spans do not cover the requested range")
    for previous, current in zip(spans, spans[1:]):
        if previous[2] != current[1]:
            raise SystemExit("selected split spans contain a gap or overlap")

    print(
        " ".join(
            f"{start:#010x}-{end:#010x}={end - start}:{status}"
            for _, start, end, status in spans
        )
    )
    matched = sum(end - start for _, start, end, status in spans if status == "Matching")
    nonmatching = sum(
        end - start for _, start, end, status in spans if status == "NonMatching"
    )
    accounted = sum(end - start for _, start, end, _ in spans)
    print(
        f"matched_bytes={matched} nonmatching_bytes={nonmatching} "
        f"range_bytes={args.end - args.start} accounted_bytes={accounted} "
        f"next_target={args.end:#010x}"
    )


if __name__ == "__main__":
    main()

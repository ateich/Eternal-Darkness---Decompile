#!/usr/bin/env python3
"""Validate declaration counts and call-site evidence in a drift proposal."""

from __future__ import annotations

import argparse
import json
from pathlib import Path

import declaration_drift_proposal
import signature_audit


ROOT = Path(__file__).resolve().parents[1]


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--report", type=Path, required=True)
    parser.add_argument("--source", type=Path, default=ROOT / "src/game")
    parser.add_argument(
        "--retail-evidence",
        type=Path,
        default=ROOT / "config/GEDE01/retail-return-shapes.json",
    )
    args = parser.parse_args()

    report = json.loads(args.report.read_text(encoding="utf-8"))
    source = args.source.resolve()
    retail_evidence = args.retail_evidence.resolve()
    audit = signature_audit.audit(source, retail_evidence)
    by_symbol = {
        item["symbol"]: item for item in audit["return_register_contradictions"]
    }
    print(f"AUDIT declarations={audit['declarations']} symbols={audit['symbols']}")

    variant_total = 0
    declaration_total = 0
    call_total = 0
    believed_total = 0
    for item in report["symbols"]:
        symbol = item["symbol"]
        measured = by_symbol[symbol]
        assert item["declaration_count"] == measured["declarations"]
        assert item["total_affected_tu_count"] == measured["affected_translation_units"]
        assert item["affected_translation_units"] == measured["translation_units"]
        assert item["estimated_blast_radius_tus"] == measured["affected_translation_units"]
        measured_variants = {
            (variant["signature"], variant["count"])
            for variant in measured["variants"]
        }

        union: set[str] = set()
        for variant in item["competing_declarations"]:
            assert (variant["declaration"], variant["count"]) in measured_variants
            declaration_sites = variant["declaration_sites"]
            declaring_tus = sorted({
                site.rsplit(":", 1)[0] for site in declaration_sites
            })
            expected_calls = sorted(
                call
                for tu in declaring_tus
                for call in declaration_drift_proposal.call_sites(
                    ROOT / tu, symbol, tu
                )
            )
            assert variant["count"] == len(declaration_sites)
            assert variant["call_site_evidence"] == expected_calls
            assert not (set(declaration_sites) & set(expected_calls))
            variant_total += 1
            declaration_total += len(declaration_sites)
            call_total += len(expected_calls)
            union.update(expected_calls)

        believed_calls = item["believed_correct_reading"]["call_site_evidence"]
        assert believed_calls == sorted(union)
        believed_total += len(union)
        print(
            f"SYMBOL name={symbol} declarations={measured['declarations']} "
            f"affected_tus={measured['affected_translation_units']} "
            f"variants={len(item['competing_declarations'])} "
            f"variant_call_sites={sum(len(v['call_site_evidence']) for v in item['competing_declarations'])} "
            f"believed_correct_call_sites={len(union)} status=valid"
        )

    print(
        f"TOTAL symbols={len(report['symbols'])} variants={variant_total} "
        f"declaration_sites={declaration_total} variant_call_sites={call_total} "
        f"believed_correct_call_sites={believed_total} invalid_call_sites=0 "
        f"source_rewrites={report['proposal_summary']['source_rewrites_applied']}"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

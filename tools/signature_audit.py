#!/usr/bin/env python3
"""Audit TU-local extern function declarations for PPC EABI disagreements.

The game translation units intentionally declare their dependencies locally.  That
makes it easy for two already-matching callers to acquire source-level signatures
which look plausible in isolation but cannot both describe the retail callee.  This
tool groups those declarations by symbol and compares the parts of a prototype
which affect PowerPC EABI register assignment.

This is a declaration audit, not a C parser.  It accepts the deliberately small
prototype dialect used below src/game, including multiline declarations and
function-pointer parameters.
"""

from __future__ import annotations

import argparse
import json
import re
from collections import Counter, defaultdict
from dataclasses import dataclass
from pathlib import Path
from typing import Iterable


ROOT = Path(__file__).resolve().parents[1]
DEFAULT_SOURCE = ROOT / "src" / "game"
FUNCTION_NAME = re.compile(r"\b(fn_[0-9A-Fa-f]+)\s*\(")
EXTERN_STATEMENT = re.compile(r"\bextern\b(?P<body>.*?);", re.DOTALL)
COMMENTS = re.compile(r"/\*.*?\*/|//[^\n]*", re.DOTALL)

FLOAT_TYPES = {"float", "f32"}
DOUBLE_TYPES = {"double", "f64"}
INT64_TYPES = {
    "long long", "signed long long", "unsigned long long", "s64", "u64",
    "int64_t", "uint64_t",
}
TYPE_WORDS = {
    "void", "char", "short", "int", "long", "float", "double", "signed",
    "unsigned", "const", "volatile", "restrict", "struct", "union", "enum",
    "s8", "u8", "s16", "u16", "s32", "u32", "s64", "u64", "f32", "f64",
    "int8_t", "uint8_t", "int16_t", "uint16_t", "int32_t", "uint32_t",
    "int64_t", "uint64_t", "size_t", "ptrdiff_t", "bool", "_Bool",
}
AGGREGATE_TYPES: set[str] = set()
AGGREGATE_TYPEDEF = re.compile(
    r"\btypedef\s+(?:struct|union)\b[^;{]*\{.*?\}\s*([A-Za-z_]\w*)\s*;",
    re.DOTALL,
)


@dataclass(frozen=True)
class Declaration:
    symbol: str
    return_type: str
    parameters: tuple[str, ...]
    variadic: bool
    unspecified_parameters: bool
    path: str
    line: int

    @property
    def signature(self) -> str:
        params = list(self.parameters)
        if self.variadic:
            params.append("...")
        if not params and not self.unspecified_parameters:
            params.append("void")
        return f"{self.return_type} {self.symbol}({', '.join(params)})"

    @property
    def return_shape(self) -> str:
        return return_register_shape(self.return_type)

    @property
    def abi_shape(self) -> tuple[str, tuple[str, ...], bool, bool]:
        parameter_shapes = tuple(parameter_register_shape(p) for p in self.parameters)
        if is_aggregate(self.return_type):
            parameter_shapes = ("GPR:1(hidden-result)",) + parameter_shapes
        return (
            self.return_shape,
            parameter_shapes,
            self.variadic,
            self.unspecified_parameters,
        )


def squash_space(text: str) -> str:
    text = re.sub(r"\s+", " ", text.strip())
    text = re.sub(r"\s*\*\s*", "*", text)
    text = re.sub(r"\s*\[\s*", "[", text)
    text = re.sub(r"\s*\]\s*", "]", text)
    return text


def split_parameters(text: str) -> list[str]:
    """Split a parameter list while retaining nested function declarators."""
    result: list[str] = []
    start = 0
    parens = brackets = 0
    for index, char in enumerate(text):
        if char == "(":
            parens += 1
        elif char == ")":
            parens -= 1
        elif char == "[":
            brackets += 1
        elif char == "]":
            brackets -= 1
        elif char == "," and parens == 0 and brackets == 0:
            result.append(text[start:index])
            start = index + 1
    result.append(text[start:])
    return [squash_space(item) for item in result if item.strip()]


def parameter_type(declaration: str) -> str:
    """Remove a declarator name where present; names do not affect the ABI."""
    declaration = squash_space(declaration)
    if "(*" in declaration or re.search(r"\(\s*\*", declaration):
        return "function-pointer"
    if "[" in declaration:
        # Array parameters are adjusted to pointers by C.
        return re.sub(r"\s+[A-Za-z_]\w*(?=\[)", "", declaration) + "*"

    match = re.search(r"\b([A-Za-z_]\w*)$", declaration)
    if not match:
        return declaration
    final = match.group(1)
    prefix = declaration[: match.start()].rstrip()
    if not prefix or final in TYPE_WORDS:
        return declaration
    prefix_words = prefix.split()
    # Do not mistake the tag in `struct Foo` or the type in `const Foo` for a
    # parameter name.  In all other multi-token spellings used by this tree, the
    # trailing non-keyword identifier is the optional declarator name.
    if prefix_words[-1] in {"struct", "union", "enum"}:
        return declaration
    if all(word in {"const", "volatile", "restrict"} for word in prefix_words):
        return declaration
    return squash_space(prefix)


def base_type(type_name: str) -> str:
    type_name = parameter_type(type_name)
    type_name = re.sub(r"\b(const|volatile|restrict)\b", "", type_name)
    return squash_space(type_name)


def return_register_shape(type_name: str) -> str:
    base = base_type(type_name)
    if base == "void":
        return "none"
    if "*" in base or base == "function-pointer":
        return "GPR:r3"
    if base in FLOAT_TYPES | DOUBLE_TYPES:
        return "FPR:f1"
    if base in INT64_TYPES:
        return "GPR:r3-r4"
    if is_aggregate(type_name):
        return "none"
    return "GPR:r3"


def is_aggregate(type_name: str) -> bool:
    base = base_type(type_name)
    return base.startswith(("struct ", "union ")) or base in AGGREGATE_TYPES


def parameter_register_shape(type_name: str) -> str:
    base = base_type(type_name)
    if "*" in base or base == "function-pointer":
        return "GPR:1"
    if base in FLOAT_TYPES | DOUBLE_TYPES:
        return "FPR:1"
    if base in INT64_TYPES:
        return "GPR:2"
    if base.startswith(("struct ", "union ")):
        return "aggregate"
    return "GPR:1"


def declarations_in(path: Path, source_root: Path) -> Iterable[Declaration]:
    original = path.read_text(encoding="utf-8")
    text = COMMENTS.sub(lambda match: "\n" * match.group(0).count("\n"), original)
    for statement in EXTERN_STATEMENT.finditer(text):
        body = statement.group("body")
        function = FUNCTION_NAME.search(body)
        if function is None:
            continue

        return_type = squash_space(body[: function.start()])
        cursor = function.end()
        depth = 1
        while cursor < len(body) and depth:
            if body[cursor] == "(":
                depth += 1
            elif body[cursor] == ")":
                depth -= 1
            cursor += 1
        if depth:
            continue

        parameter_text = body[function.end(): cursor - 1]
        unspecified_parameters = not parameter_text.strip()
        raw_parameters = split_parameters(parameter_text)
        variadic = bool(raw_parameters and raw_parameters[-1] == "...")
        if variadic:
            raw_parameters.pop()
        if raw_parameters == ["void"]:
            raw_parameters = []
        parameters = tuple(parameter_type(item) for item in raw_parameters)
        line = text.count("\n", 0, statement.start()) + 1
        yield Declaration(
            symbol=function.group(1),
            return_type=return_type,
            parameters=parameters,
            variadic=variadic,
            unspecified_parameters=unspecified_parameters,
            path=str(path.relative_to(ROOT)),
            line=line,
        )


def audit(source_root: Path) -> dict[str, object]:
    grouped: dict[str, list[Declaration]] = defaultdict(list)
    paths = sorted(
        path
        for path in source_root.rglob("*")
        if path.is_file() and path.suffix in {".c", ".h"}
    )
    AGGREGATE_TYPES.clear()
    for path in paths:
        AGGREGATE_TYPES.update(AGGREGATE_TYPEDEF.findall(path.read_text(encoding="utf-8")))
    for path in paths:
        for declaration in declarations_in(path, source_root):
            grouped[declaration.symbol].append(declaration)

    categories: dict[str, list[dict[str, object]]] = {
        "return_register_contradictions": [],
        "abi_divergent": [],
        "cosmetic": [],
    }
    for symbol, declarations in sorted(grouped.items()):
        signatures = Counter(item.signature for item in declarations)
        if len(signatures) < 2:
            continue
        return_shapes = {item.return_shape for item in declarations}
        abi_shapes = {item.abi_shape for item in declarations}
        # `void` versus a value result is still a return-register contradiction:
        # although a void caller simply ignores the physical register, both
        # declarations cannot be the callee's true C signature.  Likewise, two
        # value declarations which select different EABI register files cannot
        # both be correct.  Spellings which select the same register file remain
        # cosmetic and are separated below.
        if len(return_shapes) > 1:
            category = "return_register_contradictions"
        elif len(abi_shapes) > 1:
            category = "abi_divergent"
        else:
            category = "cosmetic"
        categories[category].append({
            "symbol": symbol,
            "declarations": len(declarations),
            "return_shapes": sorted(return_shapes),
            "variants": [
                {
                    "signature": signature,
                    "count": count,
                    "abi": next(
                        {
                            "return": item.return_shape,
                            "parameters": list(item.abi_shape[1]),
                            "variadic": item.variadic,
                            "unspecified_parameters": item.unspecified_parameters,
                        }
                        for item in declarations if item.signature == signature
                    ),
                    "sites": [
                        f"{item.path}:{item.line}"
                        for item in declarations if item.signature == signature
                    ],
                }
                for signature, count in signatures.most_common()
            ],
        })

    for entries in categories.values():
        entries.sort(key=lambda item: (-int(item["declarations"]), str(item["symbol"])))
    return {
        "source": str(source_root.relative_to(ROOT)),
        "declarations": sum(len(items) for items in grouped.values()),
        "symbols": len(grouped),
        **categories,
    }


def print_report(report: dict[str, object], limit: int | None) -> None:
    print(
        f"Audited {report['declarations']} extern declarations for "
        f"{report['symbols']} symbols under {report['source']}"
    )
    headings = (
        ("return_register_contradictions", "RETURN-REGISTER CONTRADICTIONS"),
        ("abi_divergent", "ABI-DIVERGENT DECLARATIONS"),
        ("cosmetic", "COSMETIC DECLARATION DIFFERENCES"),
    )
    for key, heading in headings:
        entries = report[key]
        assert isinstance(entries, list)
        shown = entries if limit is None else entries[:limit]
        print(f"\n{heading}: {len(entries)} symbol(s)")
        for entry in shown:
            print(f"  {entry['symbol']} ({entry['declarations']} declarations)")
            for variant in entry["variants"]:
                abi = variant["abi"]
                params = ",".join(abi["parameters"]) or "none"
                suffix = ",variadic" if abi["variadic"] else ""
                if abi["unspecified_parameters"]:
                    suffix += ",unspecified"
                variant_sites = variant["sites"]
                sites = ", ".join(variant_sites[:8])
                if len(variant_sites) > 8:
                    sites += f", ... {len(variant_sites) - 8} more"
                print(
                    f"    [{variant['count']}x; return={abi['return']}; "
                    f"params={params}{suffix}] {variant['signature']}"
                )
                print(f"      {sites}")
        if limit is not None and len(entries) > limit:
            print(f"  ... {len(entries) - limit} more (use --limit 0 to show all)")


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--source", type=Path, default=DEFAULT_SOURCE)
    parser.add_argument("--json", action="store_true", help="emit machine-readable JSON")
    parser.add_argument(
        "--limit", type=int, default=10,
        help="maximum symbols shown per category (0 means unlimited; default: 10)",
    )
    args = parser.parse_args()
    source = args.source.resolve()
    report = audit(source)
    if args.json:
        print(json.dumps(report, indent=2))
    else:
        print_report(report, None if args.limit == 0 else args.limit)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

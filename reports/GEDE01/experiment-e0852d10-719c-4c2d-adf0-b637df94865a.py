import subprocess, pathlib, sys, json, hashlib, difflib
root = pathlib.Path(__file__).resolve().parents[2]
label = sys.argv[1]
ident = "e0852d10-719c-4c2d-adf0-b637df94865a"
reports = root / "reports/GEDE01"
prefix = reports / (label + "-" + ident)
source = root / "src/game/game_fn_80026768.c"
base = subprocess.check_output(["git", "show", "5b25b98ef20713314ce120c6edfb240548d98c6c:eternal-darkness-decomp/src/game/game_fn_80026768.c"], cwd=root).decode()
prefix.with_suffix(".patch").write_text("".join(difflib.unified_diff(base.splitlines(True), source.read_text().splitlines(True), fromfile="accepted-base", tofile=label)))
with prefix.with_suffix(".build.txt").open("w") as log:
    def run(args):
        log.write("COMMAND: " + " ".join(args) + "\n"); log.flush()
        p = subprocess.run(args,cwd=root,stdout=log,stderr=subprocess.STDOUT)
        log.write("EXIT: " + str(p.returncode) + "\n"); log.flush()
        if p.returncode: raise SystemExit(p.returncode)
    run(["python3", "configure.py", "--version", "GEDE01", "--no-progress"])
    source.touch()
    run([".tools/bin/ninja", "-v", "build/GEDE01/src/game/game_fn_80026768.o"])
    for suffix, flags in [("canonical", []), ("strict", ["-c", "function_reloc_diffs=name_address"])]:
        out = str(prefix.relative_to(root)) + "-" + suffix + ".json"
        run(["build/tools/objdiff-cli", "diff", "-p", ".", "-u", "main/game/game_fn_80026768", "fn_80026768", "--format", "json", *flags, "-o", out])
    for kind, obj in [("retail", "build/GEDE01/obj/game/game_fn_80026768.o"), ("generated", "build/GEDE01/src/game/game_fn_80026768.o")]:
        for suffix, command in [("disassembly", ["build/binutils/powerpc-eabi-objdump", "-dr", obj]), ("relocations", ["build/binutils/powerpc-eabi-readelf", "-rW", obj])]:
            text = subprocess.check_output(command,cwd=root).decode()
            pathlib.Path(str(prefix) + "-" + kind + "-" + suffix + ".txt").write_text(text)
        log.write(kind + " object SHA256: " + hashlib.sha256((root/obj).read_bytes()).hexdigest() + "\n")
    log.write("source SHA256: " + hashlib.sha256(source.read_bytes()).hexdigest() + "\n")
a=pathlib.Path(str(prefix)+"-retail-disassembly.txt").read_text()
b=pathlib.Path(str(prefix)+"-generated-disassembly.txt").read_text()
pathlib.Path(str(prefix)+"-instruction-diff.txt").write_text("".join(difflib.unified_diff(a.splitlines(True),b.splitlines(True),fromfile="retail",tofile=label)))
d=json.loads(pathlib.Path(str(prefix)+"-canonical.json").read_text())
print(label, json.dumps(d)[:300])

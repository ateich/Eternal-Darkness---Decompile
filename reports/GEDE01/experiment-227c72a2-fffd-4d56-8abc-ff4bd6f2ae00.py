import subprocess,json,hashlib
from pathlib import Path
ID="227c72a2-fffd-4d56-8abc-ff4bd6f2ae00"
src=Path("src/game/game_fn_801F7C78.c")
base=subprocess.check_output(["git","show","64fa9c91606c412b5fbbc1176028a7d7c163c43f:eternal-darkness-decomp/src/game/game_fn_801F7C78.c"],text=True)
records=[]
best=(0,base)
def run(name,code):
 global best
 src.write_text(code)
 cmd=[".tools/bin/ninja","-j2","build/GEDE01/src/game/game_fn_801F7C78.o"]
 p=subprocess.run(cmd,text=True,capture_output=True)
 rec={"name":name,"source_sha256":hashlib.sha256(code.encode()).hexdigest(),"build_command":cmd,"build_exit":p.returncode,"build_output":p.stdout+p.stderr}
 if p.returncode==0:
  out="reports/GEDE01/objdiff-"+ID+"-trial.json"
  cmd=["build/tools/objdiff-cli","diff","-p",".","-u","main/game/game_fn_801F7C78","fn_801F7C78","-o",out,"--format","json","-c","function_reloc_diffs=name_address"]
  p=subprocess.run(cmd,text=True,capture_output=True)
  d=json.loads(Path(out).read_text()); l=next(s for s in d["left"]["symbols"] if s["name"]=="fn_801F7C78"); r=next(s for s in d["right"]["symbols"] if s["name"]=="fn_801F7C78")
  rec.update(score=l["match_percent"],size=r["size"],diff_command=cmd,diff_output=p.stdout+p.stderr)
  rec["generated_instructions"]=[i.get("instruction",{}).get("formatted","") for i in r["instructions"]]
  if l["match_percent"]>best[0]:best=(l["match_percent"],code)
 records.append(rec)
 print(name,rec.get("score"),rec.get("size"),flush=True)
 Path("reports/GEDE01/experiments-"+ID+".json").write_text(json.dumps(records,indent=2))
 return rec
run("baseline",base)
run("register_base",base.replace("Globals* globals", "register Globals* globals"))
for typ,init in [("unsigned char*","(unsigned char*)&lbl_8063C6B8"),("unsigned int","(unsigned int)&lbl_8063C6B8")]:
 c=base.replace("Globals* globals = &lbl_8063C6B8;",typ+" globals = "+init+";")
 for field,off in [("current_first",0xcc0),("current_second",0xd48)]:
  c=c.replace("&globals->"+field,"((Obj*)(globals + "+hex(off)+"))")
  c=c.replace("globals->"+field+".","((Obj*)(globals + "+hex(off)+"))->")
 c=c.replace("globals->second","((Obj*)(globals + 0x660))").replace("globals->first","((Obj*)(globals + 0))")
 run("base_"+typ,c)

c=base.replace("void fn_801F7C78(void)","static inline void initialize(Globals* globals)").replace("    Globals* globals = &lbl_8063C6B8;\n", "")
c=c.replace("#pragma use_lmw_stmw off", "void fn_801F7C78(void) { initialize(&lbl_8063C6B8); }\n#pragma use_lmw_stmw off")
run("inline_parameter_base",c)
# Separate integer base from object pointer expression to limit address folding.
c=base.replace("Globals* globals = &lbl_8063C6B8;", "unsigned int address = (unsigned int)&lbl_8063C6B8;\n    Globals* globals = (Globals*)address;")
run("integer_roundtrip",c)
# A single-element array local gives the base an independently addressable lifetime.
c=base.replace("Globals* globals = &lbl_8063C6B8;", "Globals* bases[1];\n    Globals* globals;")
c=c.replace("    ((Vec3Bits*)&initial)->x", "    bases[0] = &lbl_8063C6B8;\n    globals = bases[0];\n    ((Vec3Bits*)&initial)->x",1)
run("local_base_array",c)

for mode in ["calls", "current", "tail", "all_casts"]:
 c=base
 for field,off in [("current_first",0xcc0),("current_second",0xd48)]:
  expr="((Obj*)((unsigned int)globals + "+hex(off)+"))"
  if mode in ("calls","current","all_casts"):c=c.replace("&globals->"+field,expr)
  if mode in ("current","all_casts"):c=c.replace("globals->"+field+".",expr+"->")
 if mode in ("tail","all_casts"):
  c=c.replace("second = globals->second;", "second = (Obj*)((unsigned int)globals + 0x660);")
  c=c.replace("VEC(globals->first", "VEC((Obj*)(unsigned int)globals").replace("FLT(globals->first", "FLT((Obj*)(unsigned int)globals")
 run("integer_"+mode,c)
for mode in ["callbacks", "flag", "both", "all_current"]:
 c=base
 if mode in ("flag","both"):c=c.replace("extern int lbl_8064D7BC;","extern volatile int lbl_8064D7BC;")
 if mode in ("callbacks","both","all_current"):
  for field in ["current_first","current_second"]:
   c=c.replace("globals->"+field+".callback", "((volatile Obj*)&globals->"+field+")->callback")
 if mode=="all_current":
  for field in ["current_first","current_second"]:
   c=c.replace("globals->"+field+".","((volatile Obj*)&globals->"+field+")->")
 run("volatile_"+mode,c)

for typ,init in [("unsigned char*","(unsigned char*)&lbl_8063C6B8"),("unsigned int","(unsigned int)&lbl_8063C6B8")]:
 for loc in ["after_initial","after_flags"]:
  c=base.replace("Globals* globals = &lbl_8063C6B8;",typ+" globals;")
  anchor="    lbl_8064C3A0 = 2;" if loc=="after_initial" else "    fn_801F7034(&globals->current_first, 1);"
  c=c.replace(anchor,"    globals = "+init+";\n"+anchor)
  for field,off in [("current_first",0xcc0),("current_second",0xd48)]:
   c=c.replace("&globals->"+field,"((Obj*)(globals + "+hex(off)+"))")
   c=c.replace("globals->"+field+".","((Obj*)(globals + "+hex(off)+"))->")
  c=c.replace("globals->second","((Obj*)(globals + 0x660))").replace("globals->first","((Obj*)(globals + 0))")
  run("late_"+typ+loc,c)
# Keep casts just on call arguments, not the link assignment.
for count in [1,2,3]:
 c=base
 for field,off in [("current_first",0xcc0),("current_second",0xd48)]:
  if count==1 and field=="current_second":continue
  if count==2 and field=="current_first":continue
  c=c.replace("fn_801F7034(&globals->"+field+", 1)","fn_801F7034((Obj*)((unsigned int)globals + "+hex(off)+"), 1)")
 run("call_only_"+str(count),c)
# Inline accessors may preserve derived-pointer form through inline expansion.
for block in ["tail","target","both"]:
 c=base
 helper=""
 for kind in ["target","tail"]:
  if block not in (kind,"both"):continue
  start=c.index("    second = globals->second;" if kind=="tail" else "    if (globals->current_first.target")
  end=c.index("\n}",start) if kind=="tail" else c.index("\n    second = globals->second;",start)
  body=c[start:end]
  if kind=="tail":
   body=body.replace("    second = globals->second;\n","").replace("globals->first","first")
   helper+="static inline void finish(Obj* second, Obj* first) {\n"+body+"\n}\n"
   c=c[:start]+"    finish(globals->second, globals->first);\n"+c[end:]
  else:
   body=body.replace("globals->current_first.","current->")
   helper+="static inline void copy_target(Obj* current) {\n"+body+"\n}\n"
   c=c[:start]+"    copy_target(&globals->current_first);\n"+c[end:]
 c=c.replace("#pragma use_lmw_stmw on",helper+"\n#pragma use_lmw_stmw on")
 run("inline_"+block,c)

seed=base
for field,off in [("current_first",0xcc0),("current_second",0xd48)]:
 seed=seed.replace("fn_801F7034(&globals->"+field+", 1)","fn_801F7034((Obj*)((unsigned int)globals + "+hex(off)+"), 1)")
for mode in ["value", "link", "callbacks", "loop", "value_link", "setup", "all"]:
 c=seed
 if mode in ("value","value_link","setup","all"):
  c=c.replace("globals->current_second.value", "((Obj*)((unsigned int)globals + 0xd48))->value")
 if mode in ("link","value_link","setup","all"):
  c=c.replace("globals->current_first.link", "((Obj*)((unsigned int)globals + 0xcc0))->link")
 if mode in ("callbacks","setup","all"):
  for field,off in [("current_first",0xcc0),("current_second",0xd48)]:
   c=c.replace("globals->"+field+".callback", "((Obj*)((unsigned int)globals + "+hex(off)+"))->callback")
 if mode in ("loop","all"):
  c=c.replace("first = globals->second;", "first = (Obj*)((unsigned int)globals + 0x660);").replace("second = globals->first;", "second = (Obj*)(unsigned int)globals;")
 run("combined_"+mode,c)

# Union-member reads separate pointer provenance from the global symbol.
for kind in ["pointer", "integer", "bytes"]:
 c=base
 typ={"pointer":"Globals*", "integer":"unsigned int", "bytes":"unsigned char*"}[kind]
 c=c.replace("Globals* globals = &lbl_8063C6B8;", "union { Globals* object; "+typ+" address; } base_address;\n    Globals* globals;")
 c=c.replace("    ((Vec3Bits*)&initial)->x", "    base_address.object = &lbl_8063C6B8;\n    globals = (Globals*)base_address.address;\n    ((Vec3Bits*)&initial)->x",1)
 run("union_base_"+kind,c)
# Preserve derivations through typed inline return values.
for kind in ["byte", "integer", "index"]:
 c=base
 expr={"byte":"(Obj*)((unsigned char*)g + offset)","integer":"(Obj*)((unsigned int)g + offset)","index":"((Obj*)g) + offset"}[kind]
 helper="static inline Obj* entry(Globals* g, int offset) { return "+expr+"; }\n"
 c=c.replace("#pragma use_lmw_stmw on",helper+"#pragma use_lmw_stmw on")
 for field,off in [("current_first",0xcc0),("current_second",0xd48)]:
  if kind=="index":off//=0x88
  c=c.replace("&globals->"+field,"entry(globals, "+str(off)+")")
  c=c.replace("globals->"+field+".","entry(globals, "+str(off)+")->")
 c=c.replace("globals->second","entry(globals, "+str(12 if kind=="index" else 0x660)+")").replace("globals->first","entry(globals, 0)")
 run("inline_entry_"+kind,c)
# Store the global base as a union representation, then derive each address.
for expr in ["((Globals*)(unsigned int)globals)", "((Globals*)(void*)globals)"]:
 c=seed.replace("globals->",expr+"->")
 run("cast_member_base_"+expr,c)

for variant in ["named_current", "register_current", "loop_current", "named_tail", "typed_tail"]:
 c=seed
 if variant in ("named_current","register_current","loop_current"):
  c=c.replace("    if (globals->current_first.target != 0) {\n        globals->current_first.vector = ((Obj*)globals->current_first.target)->vector;\n    }", "    {\n        "+("register " if variant=="register_current" else "")+"Obj* current = "+("first" if variant=="loop_current" else "&globals->current_first")+";\n        Obj* target = (Obj*)current->target;\n        if (target) current->vector = target->vector;\n    }")
 if variant=="named_tail":
  c=c.replace("    second = globals->second;", "    first = globals->first;\n    second = globals->second;")
  c=c.replace("VEC(globals->first", "VEC(first").replace("FLT(globals->first", "FLT(first")
 if variant=="typed_tail":
  c=c.replace("    float value;\n    unsigned char pad04[0x44];", "    Vec3 origin;\n    unsigned char pad0c[0x28];\n    float extra;\n    unsigned char pad38[0x10];")
  c=c.replace(".value", ".origin.x").replace("->value", "->origin.x")
  for off,field in [("0x440","origin.x"),("0x444","origin.y"),("0x448","origin.z"),("0x474","extra")]:c=c.replace("FLT(second, "+off+")", "second[8]."+field)
  c=c.replace("CB(second, 0x6C)","second[0].callback").replace("CB(second, 0xF4)","second[1].callback")
  c=c.replace("VEC(globals->first, 0x440)","globals->first[8].origin").replace("VEC(second, 0x440)","second[8].origin").replace("FLT(globals->first, 0x440)","globals->first[8].origin.x")
 run(variant,c)
src.write_text(best[1])

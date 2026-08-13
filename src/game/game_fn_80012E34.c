typedef int s32;

extern const char lbl_8023BEF8[];
char lbl_8023CA98[] =
    "Invalid Alignment of %i\0"
    "( Error: pStartVert is NULL )\0\0\0"
    "( Error: pEndVert is NULL )";
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void *fn_80201814();
extern void fn_800355F0(void*, s32);
extern int fn_80201B44();
extern void fn_800427E0(s32);

s32 fn_80012E34(void* script)
{
    register s32 object_id;
    register s32 mode;
    register void* object;
    register void* parser = script;

    if (fn_8016A598(parser) != 2) {
        fn_80163BB4(parser, lbl_8023BEF8, 2, fn_8016A598(parser));
        return 0;
    }

    object_id = (s32)fn_8016A694(parser, 1);
    object = fn_80201814(object_id);
    if (object != 0) {
        mode = (s32)fn_8016A694(parser, 2);
        if (mode < 0 || mode > 4) {
            fn_80163BB4(parser, lbl_8023CA98, mode);
            return 0;
        }

        fn_800355F0(object, mode);
        if (fn_80201B44() == object_id) {
            fn_800427E0(mode);
        }
    }
    return 0;
}

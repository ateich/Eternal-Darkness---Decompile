typedef int s32;

extern const char lbl_8023BEF8[];
extern s32 lbl_8064D18C;
extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void *fn_80201B9C();
extern void *fn_80201B8C();
extern int fn_80201B54();
extern int fn_80201B5C(void*);
#define fn_80201B5C(a) fn_80201B5C((void*)(a))

extern int fn_80201EB8();
extern void fn_802020B4(void*, int);
extern void* fn_80201BC0(void*);

s32 fn_8000C618(void* script)
{
    s32 id;
    void* owner;
    s32 type;
    s32 kind;

    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }

    id = (s32)fn_8016A694(script, 1);
    script = fn_80201B9C();
    while (script != 0) {
        owner = fn_80201B8C(script);
        fn_80201B54(script);
        type = fn_80201B5C(script);
        kind = fn_80201EB8(script);
        if (owner != 0 && lbl_8064D18C == kind &&
            (type == 5 || type == 0x24 || type == 0x56 || type == 0x59)) {
            fn_802020B4(script, id);
        }
        script = fn_80201BC0(script);
    }
    return 0;
}

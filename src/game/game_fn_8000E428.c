typedef int s32;

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void *fn_80201814();
extern void fn_80201C2C(void);
extern void fn_80204A8C(void);
extern void fn_8020525C(void);

s32 fn_8000E428(void* script)
{
    s32 object_id;

    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }

    object_id = (s32)fn_8016A694(script, 1);
    if (object_id == -1) {
        fn_80204A8C();
        fn_8020525C();
    } else if (fn_80201814(object_id) != 0) {
        fn_80201C2C();
        fn_8020525C();
    }

    return 0;
}

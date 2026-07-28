typedef int s32;

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, s32);
extern void fn_80163BB4(void*, const char*, s32, s32, ...);
extern void* fn_80201814(s32);
extern void* fn_80201BC8(void*);
extern s32 fn_80201EB8(void*);
extern void fn_8016A830(void*, double);

s32 fn_8000B36C(void* script)
{
    void* object;
    s32 value = -1;

    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }

    object = fn_80201814((s32)fn_8016A694(script, 1));
    if (object != 0) {
        fn_80201BC8(object);
    }
    if (object != 0) {
        value = fn_80201EB8(object);
    }
    fn_8016A830(script, value);
    return 1;
}

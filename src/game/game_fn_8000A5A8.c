typedef int s32;

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, s32);
extern void fn_80163BB4(void*, const char*, s32, s32, ...);
extern void* fn_80201814(s32);
extern void* fn_80201BC8(void*);
extern void fn_801288DC(void*, s32);

s32 fn_8000A5A8(void* script)
{
    s32 first;
    s32 second;
    void* object;
    void* result;

    if (fn_8016A598(script) != 2) {
        fn_80163BB4(script, lbl_8023BEF8, 2, fn_8016A598(script));
        return 0;
    }
    first = (s32)fn_8016A694(script, 1);
    second = (s32)fn_8016A694(script, 2);
    object = fn_80201814(first);
    if (object != 0) {
        result = fn_80201BC8(object);
    } else {
        result = 0;
    }
    if (result != 0) {
        fn_801288DC(result, second);
    }
    return 0;
}

typedef unsigned int u32;
typedef int s32;

extern const char lbl_8023BEF8[];
extern float lbl_8064DCF0;
extern float lbl_8064DCF4;
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, s32);
extern void fn_80163BB4(void*, const char*, s32, s32, ...);
extern void* fn_80201814(s32);
extern void* fn_80201BC8(void*);
extern u32 fn_80036D5C(void*);
extern void fn_80036DA4(void*, u32);
extern void fn_801261F4(void*);
extern void fn_80120AD0(void*, s32, s32, s32, float, float);

s32 fn_80009BE8(void* script)
{
    register void* object;
    register void* target;
    register s32 value;
    register u32 flags;

    if (fn_8016A598(script) != 2) {
        fn_80163BB4(script, lbl_8023BEF8, 2, fn_8016A598(script));
        return 0;
    }

    value = (s32)fn_8016A694(script, 1);
    fn_8016A694(script, 2);
    object = fn_80201814(value);
    if (object != 0) {
        target = fn_80201BC8(object);
    } else {
        target = 0;
    }
    if (object != 0 && target != 0) {
        flags = fn_80036D5C(object);
        fn_80036DA4(object, flags | 0x01000000);
        fn_801261F4(target);
        fn_80120AD0(target, 0, 100, 522, lbl_8064DCF0, lbl_8064DCF4);
    }
    return 0;
}

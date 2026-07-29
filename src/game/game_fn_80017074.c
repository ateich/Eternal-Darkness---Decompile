typedef unsigned int u32;
typedef int s32;

extern const char lbl_8023BEF8[];

extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, s32);
extern void fn_80163BB4(void*, const char*, s32, ...);
extern u32 fn_800F5C54(double);
extern void fn_8020123C(s32, u32, u32, s32);

s32 fn_80017074(void* script)
{
    u32 value;

    if (fn_8016A598(script) != 2) {
        fn_80163BB4(script, lbl_8023BEF8, 2, fn_8016A598(script));
        return 0;
    }

    value = fn_800F5C54(fn_8016A694(script, 1));
    if (fn_800F5C54(fn_8016A694(script, 2)) == 1) {
        fn_8020123C(0xB1, value, value, 0);
    } else {
        fn_8020123C(0xD0, value, value, 0);
    }
    return 0;
}

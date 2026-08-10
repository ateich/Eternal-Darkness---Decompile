typedef unsigned int u32;
typedef int s32;

extern const char lbl_8023BEF8[];

extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern unsigned int fn_800F5C54();
extern unsigned long long fn_8020123C();

s32 fn_80016FE8(void* script)
{
    u32 value;

    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }

    value = fn_800F5C54(fn_8016A694(script, 1));
    fn_8020123C(0x9B, value, value, 0);
    return 0;
}

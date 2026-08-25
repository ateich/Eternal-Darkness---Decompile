typedef unsigned int u32;
typedef int s32;

extern const char lbl_8023BEF8[];

extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern unsigned int fn_800F5C54(double);
extern unsigned long long fn_8020123C();

s32 fn_80017134(void* script)
{
    u32 value;

    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }

    value = fn_800F5C54(fn_8016A694(script, 1));
    fn_8020123C(0xC6, value, value, 0);
    return 0;
}

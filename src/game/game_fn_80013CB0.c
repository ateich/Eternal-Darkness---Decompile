typedef int s32;

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, s32);
extern void fn_8016A830(void*, double);
extern void fn_80163BB4(void*, const char*, s32, s32, ...);
extern s32 fn_801D3C5C(s32);

s32 fn_80013CB0(void* script)
{
    s32 value;
    s32 result;

    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }

    value = (s32)fn_8016A694(script, 1);
    result = fn_801D3C5C(value);
    fn_8016A830(script, (double)result);
    return 1;
}

typedef int s32;

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void* fn_80201AE4(void);
extern void fn_801D7E70(void*, s32);

s32 fn_80019B88(void* script)
{
    s32 value;

    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }

    value = (s32)fn_8016A694(script, 1);
    fn_801D7E70(fn_80201AE4(), value);
    return 0;
}

typedef int s32;

extern const char lbl_8023BEF8[];

extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_801CEADC(s32, s32);

s32 fn_80019808(void* script)
{
    s32 first;

    if (fn_8016A598(script) != 2) {
        fn_80163BB4(script, lbl_8023BEF8, 2, fn_8016A598(script));
        return 0;
    }

    first = (s32)fn_8016A694(script, 1);
    fn_801CEADC(first, (s32)fn_8016A694(script, 2));
    return 0;
}

typedef int s32;

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, s32, s32, ...);
extern double fn_8016A694(void*, s32);
extern void fn_8016A830(void*, double);
extern s32 fn_800A4F98(s32);

s32 fn_8000FFD8(void* script)
{
    s32 result;

    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }

    result = fn_800A4F98((s32)fn_8016A694(script, 1));
    fn_8016A830(script, (double)result);
    return 1;
}

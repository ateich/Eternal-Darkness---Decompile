typedef int s32;

extern const char lbl_8023BEF8[];

extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, s32);
extern void fn_80163BB4(void*, const char*, s32, ...);
extern void fn_801DB8A0(s32, s32);

s32 fn_800198A4(void* script)
{
    s32 first;

    if (fn_8016A598(script) != 2) {
        fn_80163BB4(script, lbl_8023BEF8, 2, fn_8016A598(script));
        return 0;
    }

    first = (s32)fn_8016A694(script, 1);
    fn_801DB8A0(first, (s32)fn_8016A694(script, 2));
    return 0;
}

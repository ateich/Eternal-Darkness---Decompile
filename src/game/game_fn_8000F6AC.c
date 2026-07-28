typedef int s32;

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, s32, s32, ...);
extern double fn_8016A694(void*, s32);
extern void fn_800CC140(s32, s32, s32, s32, s32);

s32 fn_8000F6AC(void* script)
{
    s32 first;
    s32 second;
    s32 third;

    if (fn_8016A598(script) != 3) {
        fn_80163BB4(script, lbl_8023BEF8, 3, fn_8016A598(script));
        return 0;
    }

    first = (s32)fn_8016A694(script, 1);
    second = (s32)fn_8016A694(script, 2);
    third = (s32)fn_8016A694(script, 3);
    fn_800CC140(first, second, third, 2, 0);
    return 0;
}

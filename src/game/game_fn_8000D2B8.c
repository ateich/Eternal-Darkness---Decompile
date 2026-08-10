typedef int s32;

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_800DE4D8(s32, s32);

s32 fn_8000D2B8(void* script)
{
    s32 first;
    s32 second;

    if (fn_8016A598(script) != 2) {
        fn_80163BB4(script, lbl_8023BEF8, 2, fn_8016A598(script));
        return 0;
    }

    first = (s32)fn_8016A694(script, 1);
    second = (s32)fn_8016A694(script, 2);
    fn_800DE4D8(first, second);
    return 0;
}

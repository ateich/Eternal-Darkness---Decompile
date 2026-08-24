typedef int s32;

extern const char lbl_8023BEF8[];
extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_800C1B50(s32, s32, float, float, s32);

s32 fn_8000CDEC(void* script)
{
    s32 second;
    s32 first;
    float amount;
    float duration;

    if (fn_8016A598(script) != 4) {
        fn_80163BB4(script, lbl_8023BEF8, 4, fn_8016A598(script));
        return 0;
    }

    first = (s32)fn_8016A694(script, 1);
    second = (s32)fn_8016A694(script, 2);
    amount = (float)fn_8016A694(script, 3);
    duration = (float)fn_8016A694(script, 4);
    fn_800C1B50(first, second, amount, duration, 0);
    return 0;
}

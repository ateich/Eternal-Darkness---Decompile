typedef int s32;

extern const char lbl_8023BEF8[];
extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern s32 fn_801E2068(s32);
extern void fn_8016A830(void*, double);

s32 fn_8000C17C(void* script)
{
    s32 result;

    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }

    result = fn_801E2068((s32)fn_8016A694(script, 1));
    fn_8016A830(script, result);
    return 1;
}

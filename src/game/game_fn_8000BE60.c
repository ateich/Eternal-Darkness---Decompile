typedef int s32;

extern const char lbl_8023BEF8[];
extern s32 lbl_8064C598;
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);

s32 fn_8000BE60(void* script)
{
    s32 value = (s32)fn_8016A694(script, 1);

    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }

    lbl_8064C598 = value != 0;
    return 0;
}

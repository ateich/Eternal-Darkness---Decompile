typedef int s32;

extern const char lbl_8023BEF8[];
extern s32 lbl_8064C614;
extern s32 lbl_8064D5A8;
extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern int fn_80201B44();
extern void fn_8000E84C(s32, s32);

s32 fn_8000E764(void* script)
{
    s32 current;
    s32 first;

    if (fn_8016A598(script) != 2) {
        fn_80163BB4(script, lbl_8023BEF8, 2, fn_8016A598(script));
        return 0;
    }

    first = (s32)fn_8016A694(script, 1);
    if (first == fn_80201B44()) {
        s32 elapsed;

        current = lbl_8064D5A8;
        elapsed = current - lbl_8064C614;
        if (elapsed > 120 ||
            (elapsed < 0 && elapsed + (s32)0x80000000 - 1 > 119)) {
            fn_8000E84C(first, (s32)fn_8016A694(script, 2));
            lbl_8064C614 = current;
        }
    }
    return 0;
}

typedef int s32;

extern const char lbl_8023BEF8[];
extern const double lbl_8064DCF8;
extern s32 fn_8007FAC0(void);
extern s32 fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_8016A7D8(void*);
extern void fn_8016A830(void*, double);

s32 fn_8000DFCC(void* script)
{
    if (fn_8016A598(script) != 0) {
        fn_80163BB4(script, lbl_8023BEF8, 0, fn_8016A598(script));
        return 0;
    }

    if (fn_8007FAC0() != 0) {
        fn_8016A830(script, lbl_8064DCF8);
    } else {
        fn_8016A7D8(script);
    }
    return 1;
}

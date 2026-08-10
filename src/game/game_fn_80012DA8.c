typedef int s32;

extern const char lbl_8023BEF8[];
extern const double lbl_8064DCE8;
extern s32 fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern s32 fn_80027F3C(void);
extern void fn_8016A830(void*, double);

s32 fn_80012DA8(void* script)
{
    s32 value;

    if (fn_8016A598(script) != 0) {
        fn_80163BB4(script, lbl_8023BEF8, 0, fn_8016A598(script));
        return 0;
    }

    value = fn_80027F3C();
    fn_8016A830(script, (double)value);
    return 1;
}

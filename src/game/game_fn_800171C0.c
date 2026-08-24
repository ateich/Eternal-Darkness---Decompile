typedef int s32;

extern const char lbl_8023BEF8[];
extern s32 lbl_8064CDC8;

extern int fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_8016A830(void*, double);

s32 fn_800171C0(void* script)
{
    s32 value = lbl_8064CDC8 == 3;

    if (fn_8016A598(script) != 0) {
        fn_80163BB4(script, lbl_8023BEF8, 0, fn_8016A598(script));
        return 0;
    }

    fn_8016A830(script, value);
    return 1;
}

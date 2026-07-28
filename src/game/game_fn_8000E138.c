typedef int s32;

extern s32 lbl_8064C558;
extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_8016A830(void*, double);

s32 fn_8000E138(void* script)
{
    if (fn_8016A598(script) != 0) {
        fn_80163BB4(script, lbl_8023BEF8, 0, fn_8016A598(script));
        return 0;
    }

    fn_8016A830(script, (double)lbl_8064C558);
    return 1;
}

typedef int s32;

extern const char lbl_8023BEF8[];
extern s32 lbl_8064CD30;

extern int fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_801139D4(void);

s32 fn_80016F78(void* script)
{
    if (fn_8016A598(script) != 0) {
        fn_80163BB4(script, lbl_8023BEF8, 0, fn_8016A598(script));
        return 0;
    }

    fn_801139D4();
    lbl_8064CD30 = 1;
    return 0;
}

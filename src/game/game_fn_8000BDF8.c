typedef int s32;

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_800DE704(void);

s32 fn_8000BDF8(void* script)
{
    if (fn_8016A598(script) != 0) {
        fn_80163BB4(script, lbl_8023BEF8, 0, fn_8016A598(script));
        return 0;
    }

    fn_800DE704();
    return 0;
}

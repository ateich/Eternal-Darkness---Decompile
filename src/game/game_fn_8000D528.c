typedef int s32;

extern const char lbl_8023BEF8[];
extern int fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_800068E0(void);

s32 fn_8000D528(void* script)
{
    if (fn_8016A598(script) != 0) {
        fn_80163BB4(script, lbl_8023BEF8, 0, fn_8016A598(script));
        return 0;
    }

    fn_800068E0();
    return 0;
}

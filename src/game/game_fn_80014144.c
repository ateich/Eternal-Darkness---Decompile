typedef int s32;

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern int fn_80201B44();
extern void *fn_80201814();

s32 fn_80014144(void* script)
{
    fn_80201814(fn_80201B44());
    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }

    return 0;
}

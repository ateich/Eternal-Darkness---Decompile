typedef int s32;

extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_80046E98(s32);
extern char lbl_8023BEF8[];

s32 fn_8001CE14(void* script)
{
    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }

    fn_80046E98((s32)fn_8016A694(script, 1));
    return 0;
}

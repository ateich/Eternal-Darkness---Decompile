typedef int s32;

extern const char lbl_8023BEF8[];

extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, s32);
extern void fn_80163BB4(void*, const char*, s32, ...);
extern void fn_8014B990(s32, s32);
extern void fn_8014B928(void);

s32 fn_80018C14(void* script)
{
    if (fn_8016A598(script) == 1) {
        fn_8014B990((s32)fn_8016A694(script, 1), 0);
    } else if (fn_8016A598(script) == 0) {
        fn_8014B928();
    } else if (fn_8016A598(script) != 0) {
        fn_80163BB4(script, lbl_8023BEF8, 0, fn_8016A598(script));
        return 0;
    }
    return 1;
}

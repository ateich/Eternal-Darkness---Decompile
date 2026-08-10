typedef int s32;

extern const char lbl_8023BEF8[];
extern const double lbl_8064DCE8;

extern s32 fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern void* fn_80201B9C(void);
extern void fn_80204844(void*, s32);
extern void fn_8006D444(void);
extern s32 fn_8006BCB4(void);
extern void fn_8016A830(void*, double);

s32 fn_80017AE4(void* script)
{
    s32 value;

    if (fn_8016A598(script) != 0) {
        fn_80163BB4(script, lbl_8023BEF8, 0, fn_8016A598(script));
        return 0;
    }

    fn_80204844(fn_80201B9C(), 0x20);
    fn_8006D444();
    value = fn_8006BCB4();
    fn_8016A830(script, (double)value);
    return 1;
}

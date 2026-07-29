typedef int s32;

extern const char lbl_8023BEF8[];
extern const double lbl_8064DCE8;

extern s32 fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, s32, ...);
extern void* fn_80201B9C(void);
extern void fn_80204844(void*, s32);
extern void fn_8006D444(void);
extern s32 fn_8006BCE4(void);
extern void fn_8016A830(void*, double);

s32 fn_80017A3C(void* script)
{
    s32 value;

    if (fn_8016A598(script) != 0) {
        fn_80163BB4(script, lbl_8023BEF8, 0, fn_8016A598(script));
        return 0;
    }

    fn_80204844(fn_80201B9C(), 0x20);
    fn_8006D444();
    value = fn_8006BCE4();
    if (value == -1) {
        value = 0;
    }
    fn_8016A830(script, (double)value);
    return 1;
}

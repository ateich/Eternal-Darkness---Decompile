typedef int s32;

extern const char lbl_8023BEF8[];
extern int fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_8016A830(void*, double);
extern void* fn_80201B3C();
extern void* fn_80205288(void);
extern int fn_80201B54();

s32 fn_8000DA50(void* script)
{
    s32 value;
    void* object;

    if (fn_8016A598(script) != 0) {
        fn_80163BB4(script, lbl_8023BEF8, 0, fn_8016A598(script));
        return 0;
    }

    fn_80201B3C();
    object = fn_80205288();
    value = object != 0 ? fn_80201B54(object) : 0;
    fn_8016A830(script, (double)value);
    return 1;
}

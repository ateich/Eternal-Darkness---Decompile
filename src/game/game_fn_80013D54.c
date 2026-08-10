typedef int s32;

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern void fn_8016A830(void*, double);
extern void fn_80163BB4(void*, const char*, ...);
extern s32 fn_801D10B8(void);

s32 fn_80013D54(void* script)
{
    s32 result;

    if (fn_8016A598(script) != 0) {
        fn_80163BB4(script, lbl_8023BEF8, 0, fn_8016A598(script));
        return 0;
    }

    result = fn_801D10B8() != 0;
    fn_8016A830(script, (double)result);
    return 1;
}

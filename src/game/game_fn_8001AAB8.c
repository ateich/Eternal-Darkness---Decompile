typedef int s32;

extern const char lbl_8023BEF8[];

extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_8016A830(void*, double);
extern void fn_8016A7D8(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern s32 fn_800835CC(s32);

s32 fn_8001AAB8(void* script)
{
    s32 value;

    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }

    value = fn_800835CC((s32)fn_8016A694(script, 1));
    if (value >= 0) {
        fn_8016A830(script, (double)value);
    } else {
        fn_8016A7D8(script);
    }
    return 1;
}

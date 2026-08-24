typedef int s32;

extern const char lbl_8023BEF8[];
extern const double lbl_8064DCE8;

extern int fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern double fn_8016A694(void*, int);
extern void* fn_8016A784(void*, int);
extern s32 fn_80046378(s32, void*, s32);
extern void fn_8016A830(void*, double);

s32 fn_80017CC8(void* script)
{
    s32 first;
    void* second;
    s32 third;
    s32 value;

    if (fn_8016A598(script) != 3) {
        fn_80163BB4(script, lbl_8023BEF8, 3, fn_8016A598(script));
        return 0;
    }

    first = (s32)fn_8016A694(script, 1);
    second = fn_8016A784(script, 2);
    third = (s32)fn_8016A694(script, 3);
    value = fn_80046378(first, second, third);
    fn_8016A830(script, (double)value);
    return 1;
}

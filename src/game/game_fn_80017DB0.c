typedef int s32;

extern const char lbl_8023BEF8[];
extern const double lbl_8064DCE8;

extern s32 fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern double fn_8016A694(void*, int);
extern s32 fn_80046398(s32, s32, s32, s32);
extern void fn_8016A830(void*, double);

s32 fn_80017DB0(void* script)
{
    s32 first;
    s32 second;
    s32 third;
    s32 fourth;
    s32 value;

    if (fn_8016A598(script) != 4) {
        fn_80163BB4(script, lbl_8023BEF8, 4, fn_8016A598(script));
        return 0;
    }

    first = (s32)fn_8016A694(script, 1);
    second = (s32)fn_8016A694(script, 2);
    third = (s32)fn_8016A694(script, 3);
    fourth = (s32)fn_8016A694(script, 4);
    if (first != 0) {
        second = 0xFFFF;
    }
    value = fn_80046398(first, second, third, fourth);
    fn_8016A830(script, (double)value);
    return 1;
}

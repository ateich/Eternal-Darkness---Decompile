typedef int s32;

#pragma use_lmw_stmw on

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern double fn_8016A694(void*, int);
extern void fn_8016A830(void*, double);
extern s32 fn_800CB098(s32, s32, s32, s32, s32, s32);

s32 fn_8000F4B0(void* script)
{
    s32 third;
    s32 fourth;
    s32 first;
    s32 second;
    s32 fifth;
    s32 result;

    if (fn_8016A598(script) != 5) {
        fn_80163BB4(script, lbl_8023BEF8, 5, fn_8016A598(script));
        return 0;
    }

    first = (s32)fn_8016A694(script, 1);
    second = (s32)fn_8016A694(script, 2);
    third = (s32)fn_8016A694(script, 3);
    fourth = (s32)fn_8016A694(script, 4);
    fifth = (s32)fn_8016A694(script, 5);
    result = fn_800CB098(first, second, third, fourth, fifth, 0);
    fn_8016A830(script, (double)result);
    return 1;
}

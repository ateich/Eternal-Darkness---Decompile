typedef int s32;

extern const char lbl_8023BEF8[];

extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_80087840(s32, float, s32, float, s32);

s32 fn_8001AC70(void* script)
{
    s32 arg1;
    float arg2;
    float arg4;
    s32 arg3;
    s32 arg5;

    if (fn_8016A598(script) != 5) {
        fn_80163BB4(script, lbl_8023BEF8, 5, fn_8016A598(script));
        return 0;
    }

    arg1 = (s32)fn_8016A694(script, 1);
    arg2 = (float)fn_8016A694(script, 2);
    arg4 = (float)fn_8016A694(script, 3);
    arg3 = (s32)fn_8016A694(script, 4);
    arg5 = (s32)fn_8016A694(script, 5);
    fn_80087840(arg1, arg2, arg3, arg4, arg5);
    return 0;
}

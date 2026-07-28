typedef int s32;

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, s32);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_800C1B50(s32, s32, float, float, s32);

s32 fn_8000CED4(void* script)
{
    s32 object;
    float value0;
    float value1;
    float value2;
    float value3;
    float value4;

    if (fn_8016A598(script) != 6) {
        fn_80163BB4(script, lbl_8023BEF8, 6, fn_8016A598(script));
        return 0;
    }

    object = (s32)fn_8016A694(script, 1);
    value0 = (float)fn_8016A694(script, 2);
    value1 = (float)fn_8016A694(script, 3);
    value2 = (float)fn_8016A694(script, 4);
    value3 = (float)fn_8016A694(script, 5);
    value4 = (float)fn_8016A694(script, 6);
    fn_800C1B50(object, 15, value0, value0, 0);
    fn_800C1B50(object, 0, value1, value1, 0);
    fn_800C1B50(object, 1, value2, value2, 0);
    fn_800C1B50(object, 2, value3, value3, 0);
    fn_800C1B50(object, 3, value4, value4, 0);
    return 0;
}

typedef int s32;

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern unsigned int fn_800F5C54();
extern void fn_800C9508(s32, s32);

s32 fn_80009D54(void* script)
{
    s32 value;
    register s32 current;

    if (fn_8016A598(script) != 2) {
        fn_80163BB4(script, lbl_8023BEF8, 2, fn_8016A598(script));
        return 0;
    }
    value = (s32)fn_8016A694(script, 1);
    fn_8016A694(script, 2);
    current = fn_800F5C54();
    fn_800C9508(value, current);
    return 0;
}

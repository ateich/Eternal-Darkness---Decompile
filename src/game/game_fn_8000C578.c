typedef int s32;
typedef unsigned char u8;

extern const char lbl_8023BEF8[];
extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_801E1B04(s32, u8);

s32 fn_8000C578(void* script)
{
    s32 value;

    if (fn_8016A598(script) != 2) {
        fn_80163BB4(script, lbl_8023BEF8, 2, fn_8016A598(script));
        return 0;
    }

    value = (s32)fn_8016A694(script, 1);
    fn_801E1B04(value, (u8)(s32)fn_8016A694(script, 2));
    return 0;
}

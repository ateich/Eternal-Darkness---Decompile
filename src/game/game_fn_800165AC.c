typedef int s32;

extern const char lbl_8023BEF8[];
extern const char lbl_8023CB70[];
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, s32);
extern void fn_80163BB4(void*, const char*, s32, ...);
extern void fn_80052580(s32, s32, s32, s32, s32);

s32 fn_800165AC(void* script)
{
    s32 value;

    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }

    value = (s32)fn_8016A694(script, 1);
    if (value < 0) {
        fn_80163BB4(script, lbl_8023CB70, value);
    }
    fn_80052580(2, value, 1, -1, 0);
    return 0;
}

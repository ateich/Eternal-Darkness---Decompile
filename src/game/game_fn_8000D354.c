typedef int s32;

extern const char lbl_8023BEF8[];
extern s32 lbl_8064C55C;
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, s32);
extern void fn_80163BB4(void*, const char*, ...);

s32 fn_8000D354(void* script)
{
    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }

    lbl_8064C55C = (s32)fn_8016A694(script, 1);
    return 0;
}

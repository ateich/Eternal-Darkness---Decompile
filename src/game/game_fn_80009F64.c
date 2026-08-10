typedef int s32;

extern const char lbl_8023BEF8[];
extern s32 lbl_8064C58C;
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);

s32 fn_80009F64(void* script)
{
    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }
    lbl_8064C58C = (s32)fn_8016A694(script, 1);
    return 0;
}

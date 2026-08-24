typedef int s32;

extern const char lbl_8023BEF8[];
extern void* lbl_8064C4E0;
extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_801E7974(void*, int);
extern void fn_801E79A0(void*, s32);

s32 fn_80016C48(void* script)
{
    s32 enabled;

    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }

    enabled = (s32)fn_8016A694(script, 1);
    if (enabled != 0) {
        fn_801E7974(lbl_8064C4E0, 0x2ED);
    } else {
        fn_801E79A0(lbl_8064C4E0, 0x2ED);
    }
    return 0;
}

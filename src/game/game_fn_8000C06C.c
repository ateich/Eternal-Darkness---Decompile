typedef int s32;

extern const char lbl_8023BEF8[];
extern const char lbl_8023C11C[];
extern void* lbl_8064D5A8;
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, s32);
extern void fn_80163BB4(void*, const char*, ...);
extern void* fn_80201814(s32);
extern s32 fn_800DE298(void*);
extern void fn_8016A830(void*, double);

s32 fn_8000C06C(void* script)
{
    void* handle = 0;
    s32 result = 0;
    s32 id;

    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }

    id = (s32)fn_8016A694(script, 1);
    if (id > 0) {
        handle = fn_80201814(id);
    }
    if (handle != 0 || id == 0) {
        result = fn_800DE298(handle);
    } else {
        fn_80163BB4(script, lbl_8023C11C, id, lbl_8064D5A8);
    }
    fn_8016A830(script, result);
    return 1;
}

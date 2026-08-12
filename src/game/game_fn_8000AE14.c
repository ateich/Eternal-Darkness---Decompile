typedef int s32;

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void *fn_80201814();
extern void *fn_80201BC8();
extern void fn_80120B4C(void*);

s32 fn_8000AE14(void* script)
{
    void* entry;
    void* info;

    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }
    entry = fn_80201814((s32)fn_8016A694(script, 1));
    if (entry != 0) {
        info = fn_80201BC8(entry);
    } else {
        info = 0;
    }
    if (info != 0) {
        fn_80120B4C(info);
    }
    return 0;
}

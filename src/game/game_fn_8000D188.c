typedef int s32;

extern const char lbl_8023BEF8[];
extern char lbl_80302060[];
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void* fn_80201814();
extern void fn_80201E78(void*, void*);

s32 fn_8000D188(void* script)
{
    void* object;

    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }

    object = fn_80201814((s32)fn_8016A694(script, 1));
    fn_80201E78(lbl_80302060, object);
    return 0;
}

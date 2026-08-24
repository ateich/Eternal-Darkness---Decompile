typedef int s32;

extern const char lbl_8023BEF8[];
extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void *fn_80201814();
extern void *fn_80201BC8();
extern void fn_80048708(void*);

s32 fn_8000BB98(void* script)
{
    void* handle;
    void* object;

    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }

    handle = fn_80201814((s32)fn_8016A694(script, 1));
    object = handle != 0 ? fn_80201BC8(handle) : 0;
    if (handle != 0 && object != 0) {
        fn_80048708(object);
    }
    return 0;
}

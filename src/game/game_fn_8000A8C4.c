typedef int s32;

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, s32);
extern void fn_80163BB4(void*, const char*, s32, s32, ...);
extern void* fn_80201814(s32);
extern void* fn_80201B94(void*);
extern s32 fn_80201CD4(void);
extern void fn_80201E60(void*, s32);

s32 fn_8000A8C4(void* script)
{
    s32 first;
    s32 second;
    void* object;
    s32 flags;
    s32 mode;

    if (fn_8016A598(script) != 2) {
        fn_80163BB4(script, lbl_8023BEF8, 2, fn_8016A598(script));
        return 0;
    }
    first = (s32)fn_8016A694(script, 1);
    second = (s32)fn_8016A694(script, 2);
    object = fn_80201814(first);
    if (object != 0) {
        object = fn_80201B94(object);
    } else {
        object = 0;
    }
    if (object != 0) {
        flags = fn_80201CD4();
        mode = flags & ~4;
        if (second != 0) {
            mode = flags | 4;
        }
        fn_80201E60(object, mode);
    }
    return 0;
}

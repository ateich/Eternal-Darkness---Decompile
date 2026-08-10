typedef int s32;

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void* fn_80201814();
extern void* fn_80201B8C();
extern unsigned int fn_80036D5C(void*);
extern void fn_80036DA4(void*, s32);

s32 fn_8000DCF8(void* script)
{
    void* object;
    s32 object_id;
    s32 flags;

    if (fn_8016A598(script) != 2) {
        fn_80163BB4(script, lbl_8023BEF8, 2, fn_8016A598(script));
        return 0;
    }

    object_id = (s32)fn_8016A694(script, 1);
    fn_8016A694(script, 2);
    object = fn_80201814(object_id);
    if (object != 0) {
        fn_80201B8C();
        flags = fn_80036D5C(object);
        fn_80036DA4(object, flags | 0x200);
    }
    return 0;
}

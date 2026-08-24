typedef int s32;
typedef unsigned short u16;

extern const char lbl_8023BEF8[];

extern int fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern double fn_8016A694(void*, int);
extern void fn_8014B888(s32, void**, s32*);
extern void fn_801978F8(void*, u16);

s32 fn_80018598(void* script)
{
    s32 object_id;
    s32 value;
    void* object;
    s32 unused;

    if (fn_8016A598(script) != 2) {
        fn_80163BB4(script, lbl_8023BEF8, 2, fn_8016A598(script));
        return 0;
    }

    object_id = (s32)fn_8016A694(script, 1);
    value = (s32)fn_8016A694(script, 2);
    fn_8014B888(object_id, &object, &unused);
    if (object != 0) {
        fn_801978F8(object, (u16)value);
    }
    return 0;
}

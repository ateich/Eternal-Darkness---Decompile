typedef int s32;
typedef unsigned int u32;

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, s32);
extern void fn_80163BB4(void*, const char*, s32, s32, ...);
extern u32 fn_800F5C54(double);
extern void* fn_80201814(s32);
extern void* fn_80201C24(void);
extern void fn_80157B6C(void*, u32);

s32 fn_80013614(void* script)
{
    s32 object_id;
    u32 value;
    void* parser = script;

    if (fn_8016A598(parser) != 2) {
        fn_80163BB4(parser, lbl_8023BEF8, 2, fn_8016A598(parser));
        return 0;
    }

    object_id = (s32)fn_8016A694(parser, 1);
    value = fn_800F5C54(fn_8016A694(parser, 2));
    if (fn_80201814(object_id) != 0) {
        fn_80157B6C(fn_80201C24(), value);
    }
    return 0;
}

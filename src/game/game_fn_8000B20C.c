typedef int s32;
typedef unsigned int u32;

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, s32);
extern void fn_80163BB4(void*, const char*, s32, s32, ...);
extern void* fn_80201814(s32);
extern void* fn_80201BC8(void*);
extern u32 fn_8011FAEC(void*);
extern void fn_8011FADC(void*, u32);
extern void fn_80048708(void*);

s32 fn_8000B20C(void* script)
{
    void* object;
    void* info;
    u32 flags;
    u32 first_flags;
    s32 first_flag;
    s32 second_flag;
    s32 third_flag;
    s32 object_id;

    if (fn_8016A598(script) != 4) {
        fn_80163BB4(script, lbl_8023BEF8, 4, fn_8016A598(script));
        return 0;
    }

    object_id = (s32)fn_8016A694(script, 1);
    first_flag = (s32)fn_8016A694(script, 2);
    second_flag = (s32)fn_8016A694(script, 3);
    third_flag = (s32)fn_8016A694(script, 4);
    object = fn_80201814(object_id);
    info = object != 0 ? fn_80201BC8(object) : 0;

    if (object != 0 && info != 0) {
        first_flags = fn_8011FAEC(info);
        flags = first_flags | 2;
        if (first_flag != 0) {
            flags = first_flags & ~2;
        }
        first_flags = flags & ~0x80;
        if (second_flag != 0) {
            first_flags = flags | 0x80;
        }
        fn_8011FADC(
            info,
            third_flag != 0 ? first_flags | 0x40 : first_flags & ~0x40);
        if (second_flag != 0 || third_flag != 0) {
            fn_80048708(info);
        }
    }
    return 0;
}

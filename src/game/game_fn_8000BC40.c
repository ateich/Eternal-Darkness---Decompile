typedef int s32;
typedef signed short s16;

typedef struct Vec3s {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

typedef struct Vec3f {
    float x;
    float y;
    float z;
} Vec3f;

extern const char lbl_8023BEF8[];
extern const char lbl_8023C0F0[];
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, s32);
extern void fn_80163BB4(void*, const char*, ...);
extern s32 fn_800F5C54(double);
extern void* fn_80201814(s32);
extern void* fn_80201BC8(void*);
extern void* fn_8015C4A4(s32, s32);
extern Vec3s* fn_80158ABC(void*, s32, s32);
extern void fn_8011F114(Vec3f*, void*);
extern s32 fn_80178E94(Vec3f*, Vec3f*);
extern void fn_8016A830(void*, double);

s32 fn_8000BC40(void* script)
{
    s32 result = -1;
    s32 object_id;
    s32 effect_id;
    void* handle;
    void* object;
    Vec3s* offset;
    Vec3f delta;
    Vec3f base;
    Vec3f position;

    if (fn_8016A598(script) != 2) {
        fn_80163BB4(script, lbl_8023BEF8, 2, fn_8016A598(script));
        return 0;
    }

    object_id = (s32)fn_8016A694(script, 1);
    effect_id = fn_800F5C54(fn_8016A694(script, 2));
    handle = fn_80201814(object_id);
    object = handle != 0 ? fn_80201BC8(handle) : 0;
    if (handle != 0 && object != 0) {
        offset = fn_80158ABC(fn_8015C4A4(effect_id, 2), 2, 0);
        if (offset != 0) {
            fn_8011F114(&position, object);
            base = position;
            delta.x = offset->x;
            delta.y = offset->y;
            delta.z = offset->z;
            result = fn_80178E94(&base, &delta);
        } else {
            fn_80163BB4(script, lbl_8023C0F0, effect_id);
        }
    }
    fn_8016A830(script, result);
    return 1;
}

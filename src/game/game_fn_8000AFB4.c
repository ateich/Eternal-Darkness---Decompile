typedef short s16;
typedef int s32;
typedef unsigned int u32;

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
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, s32);
extern void fn_80163BB4(void*, const char*, s32, s32, ...);
extern u32 fn_800F5C54(double);
extern s32 fn_8015C4A4(u32, s32);
extern Vec3s* fn_80158ABC(s32, s32, void*);
extern void fn_801F49EC(Vec3f*, float, float);

s32 fn_8000AFB4(void* script)
{
    u32 object_id;
    float first;
    float second;
    Vec3f converted;
    Vec3f position;
    Vec3s* source;

    if (fn_8016A598(script) != 3) {
        fn_80163BB4(script, lbl_8023BEF8, 3, fn_8016A598(script));
        return 0;
    }
    object_id = fn_800F5C54(fn_8016A694(script, 1));
    first = (s32)fn_8016A694(script, 2);
    second = fn_8016A694(script, 3);
    source = fn_80158ABC(fn_8015C4A4(object_id, 2), 2, 0);
    converted.x = source->x;
    converted.y = source->y;
    converted.z = source->z;
    position = converted;
    fn_801F49EC(&position, first, second);
    return 1;
}

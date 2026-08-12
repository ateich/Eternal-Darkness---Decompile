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
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void* fn_8016A784(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void *fn_80201814();
extern void *fn_80201BC8();
extern void fn_8011F0E8(void*, Vec3f*);

s32 fn_8000BAA0(void* script)
{
    s32 object_id;
    Vec3s* input;
    Vec3f position;

    if (fn_8016A598(script) != 2) {
        fn_80163BB4(script, lbl_8023BEF8, 2, fn_8016A598(script));
        return 0;
    }

    object_id = (s32)fn_8016A694(script, 1);
    input = fn_8016A784(script, 2);
    position.x = input->x;
    position.y = input->y;
    position.z = input->z;
    fn_8011F0E8(fn_80201BC8(fn_80201814(object_id)), &position);
    return 0;
}

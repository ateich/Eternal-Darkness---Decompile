typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct Vec4 {
    float x;
    float y;
    float z;
    float w;
} Vec4;

extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern unsigned int fn_800F5C54(double);
extern void fn_80163BB4(void*, const char*, ...);
extern void *fn_80201814();
extern void *fn_80201BC8();
extern int fn_8015C524(unsigned int, int);
extern int fn_801589AC(int, int, Vec3*, Vec3*, float*);
extern void fn_8017A244(Vec3*, Vec4*, float);
extern void fn_8017A34C(Vec4*, Vec4*, Vec4*);
extern void* fn_8011FE34(void*);
extern void fn_8011F0E8(void*, Vec3*);
extern const char lbl_8024FF00[];
extern const float lbl_806506C8;

int fn_8016FA08(void* state)
{
    const char* string_pool = lbl_8024FF00;
    int object_id;
    unsigned int resource_id;
    void* object;
    void* runtime;
    int resource_index;
    Vec3 direction;
    Vec3 position;
    float scale;
    Vec4 base_rotation;
    Vec4 rotation;

    if (fn_8016A598(state) != 2) {
        fn_80163BB4(state, string_pool, 2, fn_8016A598(state));
        return 0;
    }

    object_id = (int)fn_8016A694(state, 1);
    object = fn_80201814(object_id);
    if (object != 0) {
        runtime = fn_80201BC8(object);
        resource_id = fn_800F5C54(fn_8016A694(state, 2));
        resource_index = fn_8015C524(resource_id, 2);
        if (resource_index != -1 &&
            fn_801589AC(resource_index, 2, &position, &direction, &scale)) {
            direction.x = -direction.x;
            direction.y = -direction.y;
            direction.z = -direction.z;
            fn_8017A244(&direction, &rotation, scale);
            fn_8017A244((Vec3*)(string_pool + 0x1F0), &base_rotation,
                        lbl_806506C8);
            fn_8017A34C(&rotation, &base_rotation, fn_8011FE34(runtime));
            fn_8011F0E8(runtime, &position);
        } else {
            fn_80163BB4(state, string_pool + 0x1FC, resource_id);
        }
    } else {
        fn_80163BB4(state, string_pool + 0x218, object_id);
    }
    return 0;
}

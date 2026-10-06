typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern unsigned int fn_800F5C54(double);
extern void fn_80163BB4(void*, const char*, ...);
extern void *fn_80201814();
extern void *fn_80201BC8();
extern int fn_8015C4A4(int, int);
extern int fn_80158B20(int, int, Vec3*, Vec3*, float*);
extern float fn_8012B7D0(void*, Vec3*);
extern void* fn_8011FE34(void*);
extern void fn_8017A244(const char*, void*, float);
extern const char lbl_8024FF00[];

int fn_8016F78C(void* state)
{
    const char* string_pool = lbl_8024FF00;
    int object_id;
    unsigned int resource_id;
    void* object;
    void* runtime;
    int resource_index;
    Vec3 angles;
    Vec3 position;
    float scale;
    Vec3 position_copy;
    float facing;

    if (fn_8016A598(state) != 2) {
        fn_80163BB4(state, string_pool, 2, fn_8016A598(state));
        return 0;
    }

    object_id = (int)fn_8016A694(state, 1);
    object = fn_80201814(object_id);
    if (object != 0) {
        runtime = fn_80201BC8(object);
        resource_id = fn_800F5C54(fn_8016A694(state, 2));
        resource_index = fn_8015C4A4(resource_id, 2);
        if (resource_index != -1 &&
            fn_80158B20(resource_index, 2, &position, &angles, &scale)) {
            position_copy = position;
            facing = fn_8012B7D0(runtime, &position_copy);
            fn_8017A244(string_pool + 0x190, fn_8011FE34(runtime), facing);
        } else {
            fn_80163BB4(state, string_pool + 0x19C, resource_id);
        }
    } else {
        fn_80163BB4(state, string_pool + 0x1B8, object_id);
    }
    return 0;
}

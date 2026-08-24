typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct StringBlock {
    char argument_error[0x190];
    char facing_format[0xC];
    char resource_error[0x1C];
    char object_error[1];
} StringBlock;

extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern unsigned int fn_800F5C54(double);
extern void fn_80163BB4(void*, const char*, ...);
extern void* fn_80201814(int);
extern void* fn_80201BC8(void*);
extern int fn_8015C4A4(int, int);
extern int fn_80158B20(int, int, Vec3*, Vec3*, float*);
extern float fn_8012B7D0(void*, Vec3*);
extern void* fn_8011FE34(void*);
extern void fn_8017A244(const char*, void*, float);
extern StringBlock lbl_8024FF00;

int fn_8016F78C(void* state)
{
    StringBlock* const strings = &lbl_8024FF00;
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
        fn_80163BB4(state, strings->argument_error, 2, fn_8016A598(state));
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
            fn_8017A244(strings->facing_format, fn_8011FE34(runtime), facing);
        } else {
            fn_80163BB4(state, strings->resource_error, resource_id);
        }
    } else {
        fn_80163BB4(state, strings->object_error, object_id);
    }
    return 0;
}

typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct Entry80201814 Entry80201814;

extern int lbl_8064D18C;
extern u32 lbl_8064C8A8;
extern float lbl_8064E7B0;
extern float lbl_8064E7B4;

extern int fn_80201B54(int *object);
extern int fn_802019EC(int resource, int manager);
extern Entry80201814 *fn_80201814(int id);
extern void *fn_80201BC8(void *object);
extern void fn_8011F114(Vec3 *destination, Vec3 *source);
extern void fn_8011F0E8(Vec3 *destination, Vec3 *source);
extern u64 fn_8020123C(int kind, int source, int target, int value);
extern void fn_801AC980(u32 key, int value);

void fn_8006ADD8(int *object)
{
    Vec3 position;
    int object_id;
    int id;
    Entry80201814 *entry;
    Vec3 *runtime;

    object_id = fn_80201B54(object);
    id = fn_802019EC(0x54, lbl_8064D18C);
    if (id != -1 && (entry = fn_80201814(id)) != 0 &&
        (runtime = fn_80201BC8(entry)) != 0) {
        fn_8011F114(&position, runtime);
        position.z -= lbl_8064E7B0;
        fn_8011F0E8(runtime, &position);
        if (position.z <= lbl_8064E7B4) {
            fn_8020123C(0x11, object_id, object_id, 0);
            if (lbl_8064C8A8 != 0) {
                fn_801AC980(lbl_8064C8A8, 0x3C);
                lbl_8064C8A8 = 0;
            }
        }
    }
}

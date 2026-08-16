typedef unsigned int u32;

typedef struct Vec3 {
    float x, y, z;
} Vec3;

extern void fn_80204810(void);

extern void *fn_801294DC(void *, int, int, int);
extern void **fn_80201B8C();
extern void fn_8011F114();
extern float fn_8012B750(void *);
extern void fn_80128C28(void *, void *, u32);
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);

#pragma use_lmw_stmw on

void fn_800C262C(void *context, void *object, int object_id,
                 int unused, int *result)
{
    void *entry = fn_801294DC(object, 143, 32, 8);

    if (entry != 0) {
        void **state_ref = fn_80201B8C(context);
        if (state_ref != 0) {
            unsigned char *state = (unsigned char *)state_ref[0];
            if (state != 0) {
                Vec3 position;
                fn_8011F114(&position, object);
                *(Vec3 *)(state + 0x44) = position;
                *(float *)(state + 0x50) = fn_8012B750(object);
            }
        }
        fn_80128C28(entry, fn_80204810, ((u32)object_id << 8) | 5);
        if (result != 0) {
            *result = 1;
        }
        fn_80201D2C(context, 74);
        fn_80201D14(context, 1);
    }
}

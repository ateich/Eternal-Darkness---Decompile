typedef struct Vec3 {
    float x, y, z;
} Vec3;

extern void* fn_80201B94();
extern void *fn_80201C48(void *);
extern void *fn_80201BC8();
extern void *fn_80201814();
extern int fn_8011FB4C(void *);
extern int fn_8011F598(void *, int, int, int, void *, int);
extern int fn_80201EB8();
extern void fn_80201E78(Vec3 *, void *);
extern void fn_800C849C(void *, Vec3 *, float);
extern int lbl_8064D18C;
extern float lbl_8064F240;

void fn_800C80E8(void *object, int arg1, int arg2)
{
    void *owner = fn_80201C48(fn_80201B94(object));
    void *runtime = fn_80201BC8(object);
    char hit[48];
    Vec3 target;
    Vec3 position;

    if (fn_8011FB4C(runtime) == lbl_8064D18C &&
        fn_8011F598(runtime, arg1, arg2, -1, &hit, 1) != -1) {
        void *other = fn_80201814(owner);
        if (other != 0 && fn_80201EB8(other) == fn_8011FB4C(runtime)) {
            fn_80201E78(&position, other);
            target = position;
            fn_800C849C(runtime, &target, lbl_8064F240);
        }
    }
}

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct Runtime {
    unsigned char pad[0x8C];
    void* resource;
} Runtime;

extern void* lbl_8064C4E4;
extern int lbl_8064D5A8;
extern float lbl_8064EC2C;
extern float lbl_8064EC30;

extern Runtime* fn_80201B8C();
extern void fn_8011F114();
extern void fn_802045AC(void*, Vec3*);
extern int fn_80201C48(void*);
extern void fn_80201D2C();
extern void fn_80201D14();
extern unsigned int fn_80178E94(void*, Vec3*);
extern void fn_80038308(void*, int, short*);
extern void fn_80038464(void*, int, short*);
extern int fn_800BE2CC(void*, void*, Vec3*);
extern void fn_800BE390(void*, void*);
extern int fn_8012AFC4(void*);
extern void fn_80129928(void*, Vec3*);
extern void fn_8012976C(void*, int, int, Vec3*, float);

void fn_8008E88C(void* object, void* actor, void* unused, void* distance_ctx,
                 void* unused2, void* status)
{
    Runtime* runtime = fn_80201B8C(object);
    void* resource = runtime->resource;
    Vec3 position;
    Vec3 hit;
    Vec3 reference;
    short value1;
    short value2;

    fn_8011F114(&reference, lbl_8064C4E4);
    fn_802045AC(object, &position);
    if (fn_80201C48(status) != -1) {
        fn_80201D2C(object, 1);
        fn_80201D14(object, 1);
    }
    if (reference.z < lbl_8064EC2C && (unsigned char)lbl_8064D5A8 == 0) {
        fn_80201D2C(object, 1);
        fn_80201D14(object, 1);
    }
    if (fn_80178E94(distance_ctx, &position) < 100) {
        fn_80038308(object, 0, &value1);
        fn_80038464(object, 0, &value2);
        fn_80201D2C(object, 1);
        fn_80201D14(object, 1);
    } else if (fn_800BE2CC(object, resource, &hit)) {
        if (fn_80178E94(distance_ctx, &hit) < 80) {
            fn_800BE390(object, resource);
        } else if (fn_8012AFC4(actor)) {
            fn_80129928(actor, &hit);
        } else {
            fn_8012976C(actor, 3, 33, &hit, lbl_8064EC30);
        }
    } else {
        fn_80201D2C(object, 1);
        fn_80201D14(object, 1);
    }
}

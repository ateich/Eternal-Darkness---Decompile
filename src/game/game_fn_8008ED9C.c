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
extern float lbl_8064EC20;
extern float lbl_8064EC30;
extern float lbl_8064EC34;

extern void fn_8011F114(Vec3*, void*);
extern unsigned int fn_80178E94(Vec3*, void*);
extern void* fn_80201B54(void*);
extern Runtime* fn_80201B8C(void*);
extern float fn_8011F6F8(void*);
extern int fn_8003E1F0(void*, Vec3*, int, float);
extern unsigned char fn_80204434(void*, Vec3*, int, float);
extern int fn_8008D4B4(void*, void*, void*);
extern int fn_800CA7D4(void*, void*, void*, void*, int, int);
extern void* fn_80201B44(void);
extern void fn_8008D31C(void*, void*, void*, Runtime*, void*, int, void*);
extern int fn_8012AFC4(void*);
extern void fn_80129928(void*, Vec3*);
extern void fn_8012976C(void*, int, int, Vec3*, float);
extern void fn_80201D2C(void*, int);
extern void fn_80201D14(void*, int);

void fn_8008ED9C(void* object, void* actor, void* distance_ctx, void* callback)
{
    unsigned int distance;
    Runtime* runtime;
    void* resource;
    void* owner;
    Vec3 reference;
    Vec3 source;

    fn_8011F114(&source, lbl_8064C4E4);
    reference = source;
    distance = fn_80178E94(&reference, distance_ctx);
    owner = fn_80201B54(object);
    runtime = fn_80201B8C(object);
    resource = runtime->resource;
    if (distance < 500 &&
        fn_8003E1F0(object, &reference, 1,
                    fn_8011F6F8(actor) - lbl_8064EC34)) {
        if (fn_80204434(actor, &reference, 0, lbl_8064EC20) &&
            fn_8008D4B4(object, actor, callback)) {
            return;
        }
        if (fn_800CA7D4(owner, object, resource, actor, 30, 1)) {
            fn_8008D31C(object, owner, fn_80201B44(), runtime, actor, 5,
                        distance_ctx);
        } else if (fn_8012AFC4(actor)) {
            fn_80129928(actor, &reference);
        } else {
            fn_8012976C(actor, 3, 33, &reference, lbl_8064EC30);
        }
    } else {
        fn_80201D2C(object, 3);
        fn_80201D14(object, 1);
    }
}

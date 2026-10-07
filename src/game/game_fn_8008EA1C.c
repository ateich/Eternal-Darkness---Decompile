typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct Runtime {
    unsigned char pad[0x8C];
    void* resource;
} Runtime;

typedef struct Status {
    unsigned char pad[0x1C];
    short busy;
} Status;

extern void* lbl_8064C4E4;
extern float lbl_8064EC10;
extern float lbl_8064EC30;
extern float lbl_8064EC34;
extern float lbl_8064EC38;

extern void *fn_80201B8C();
extern int fn_80201C48(void*);
extern void *fn_80201814();
extern unsigned int fn_80036D5C(void*);
extern int fn_800CA7D4(void*, void*, void*, void*, int, int);
extern void fn_8008D31C(void*, void*, void*, Runtime*, void*, int, void*);
extern int fn_80036E50(void*);
extern void fn_80201E78(Vec3*, void*);
extern void fn_8011F114();
extern int fn_80178E94(void*, Vec3*);
extern float fn_8011F6F8(void*);
extern int fn_8003E1F0(void*, Vec3*, int, float);
extern float fn_8012B7D0(void*, Vec3);
extern float fn_8012B750(void*);
extern void fn_8017A12C(float*, float, float);
extern int fn_8008DD78(void*, void*, void*);
extern int fn_8012AFC4(void*);
extern void fn_80129928(void*, Vec3*);
extern void fn_8012976C(void*, int, int, Vec3*, float);
extern int fn_800BE2CC(void*, void*, Vec3*);
extern void fn_800BE390(void*, void*);
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);

void fn_8008EA1C(void* object, void* actor, void* owner, void* distance_ctx,
                 Status* status, void* target_id, void* callback)
{
    Runtime* runtime;
    void* resource;
    void* target_obj;
    int target;
    int flag;
    int target_dist;
    int player_dist;
    int player_hidden;
    int target_hidden;
    float angle;
    Vec3 target_pos;
    Vec3 hit;
    Vec3 player_pos;
    Vec3 tmp2;
    Vec3 tmp;

    runtime = (Runtime*)fn_80201B8C(object);
    resource = runtime->resource;
    target = fn_80201C48(target_id);
    target_obj = fn_80201814(target);
    flag = fn_80036D5C(object) & 0x100000;

    if (fn_800CA7D4(owner, object, resource, actor, 30, 1)) {
        fn_8008D31C(object, owner, (void*)target, runtime, actor, 5, distance_ctx);
        return;
    }

    if (target != 0 && target_obj != 0 && fn_80036E50(target_obj) != 6) {
        fn_80201E78(&tmp2, target_obj);
        target_pos = tmp2;
        fn_8011F114(&tmp, lbl_8064C4E4);
        player_pos = tmp;
        target_dist = fn_80178E94(distance_ctx, &target_pos);
        player_dist = fn_80178E94(distance_ctx, &player_pos);
        player_hidden = !fn_8003E1F0(object, &player_pos, 1,
                                     fn_8011F6F8(actor) - lbl_8064EC34);
        target_hidden = !fn_8003E1F0(object, &target_pos, 1,
                                     fn_8011F6F8(actor) - lbl_8064EC34);
        if (flag == 0 && status->busy == 0 && player_dist < 500 &&
            !player_hidden) {
            fn_80201D2C(object, 0x3D);
            fn_80201D14(object, 1);
            return;
        }
        if (target_dist < 155 || (target_dist < 750 && !target_hidden)) {
            float f = fn_8012B7D0(actor, target_pos);
            fn_8017A12C(&angle, fn_8012B750(actor), f);
            if (target_dist < 155) {
                float a = angle;
                if (a < lbl_8064EC10) {
                    a = -a;
                }
                if (a <= lbl_8064EC38) {
                    if (fn_8008DD78(object, actor, callback) == 0) {
                        fn_80201D2C(object, 1);
                        fn_80201D14(object, 1);
                    }
                    return;
                }
            }
            if (fn_8012AFC4(actor)) {
                fn_80129928(actor, &target_pos);
            } else {
                fn_8012976C(actor, 3, 0x21, &target_pos, lbl_8064EC30);
            }
        } else if (fn_800BE2CC(object, resource, &hit)) {
            if ((unsigned int)fn_80178E94(distance_ctx, &hit) < 80) {
                fn_800BE390(object, resource);
            } else if (fn_8012AFC4(actor)) {
                fn_80129928(actor, &hit);
            } else {
                fn_8012976C(actor, 3, 0x21, &hit, lbl_8064EC30);
            }
        } else {
            fn_80201D2C(object, 1);
            fn_80201D14(object, 1);
        }
    } else {
        fn_80201D2C(object, 1);
        fn_80201D14(object, 1);
    }
}

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

#pragma use_lmw_stmw on

extern int lbl_8064D18C;
extern float lbl_8064F7E8;
extern float lbl_8064F7F4;
extern int fn_80201B54();
extern int fn_80201EB8();
extern int fn_802006D4(int, int, int, int, int);
extern void fn_80201138(int, void *, int, int, int, float);
extern void* fn_80201B94();
extern int fn_80201C48(void *);
extern void *fn_80201814();
extern void *fn_801A717C(void);
#define FN_80201E78_RETURN void
#define FN_80201E78_PARAMETERS Vec3 *, void *
extern FN_80201E78_RETURN fn_80201E78(FN_80201E78_PARAMETERS);extern void fn_801A74A0(void *, int);
extern void fn_801A74A8(void *, int);
extern void fn_801A7538(void *, int);
extern void fn_801A7518(void *, int);
extern void fn_801A7550(void *, int);
extern void fn_801A764C(void *, Vec3 *);
extern void fn_801A7470(void *, int);
extern unsigned long long fn_8020123C();
extern void fn_801A7228(void *);
extern void fn_800E828C(void *, int, int, float);

int fn_800E8130(void *object)
{
    int handle;
    int result;
    void *target;
    int id;

    result = 0;
    handle = fn_80201B54(object);

    if (lbl_8064D18C != fn_80201EB8(object)) {
        fn_802006D4(handle, handle, 6, 201, 0);
        fn_80201138(201, object, 6, 57, 0, lbl_8064F7E8);
    } else {
        id = fn_80201C48(fn_80201B94(object));
        target = fn_80201814(id);

        if (target != 0) {
            int owner = fn_80201EB8(object);
            if (fn_80201EB8(target) == owner) {
                void *effect = fn_801A717C();
                Vec3 position;

                fn_80201E78(&position, object);
                fn_801A74A0(effect, handle);
                fn_801A74A8(effect, id);
                fn_801A7538(effect, 2);
                fn_801A7518(effect, 1);
                fn_801A7550(effect, 12);
                fn_801A764C(effect, &position);
                fn_801A7470(effect, -1);
                fn_8020123C(39, handle, id, effect);
                fn_801A7228(effect);
                fn_800E828C(object, 5, 0, lbl_8064F7F4);
                result = 1;
            }
        }
    }
    return result;
}

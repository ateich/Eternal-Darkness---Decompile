typedef unsigned int u32;

typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct State80091124 {
    unsigned char pad00[0xC];
    int value0C;
    int value10;
    int target_id;
} State80091124;

extern int lbl_8064C570;
extern float lbl_8064EC44;
extern float lbl_8064EC48;

extern void fn_8011F114();
extern u32 fn_80036D5C(void*);
extern int fn_80201B54();
extern void fn_8008CC84(void*);
extern void fn_8008F860(int);
extern int fn_801261F4(void*);
extern void fn_800DD314(void*, int, int, int);
extern void *fn_80201814();
extern void fn_80201E78(Vec3*, void*);
extern u32 fn_80178E94(Vec3*, Vec3*);
extern void fn_80201DD8(void*, int);
extern void fn_8020104C(int, void*, void*, int, float);
#define fn_8020104C(a,b,c,d,e) fn_8020104C((int)(a),(void*)(b),(void*)(c),(int)(d),(float)(e))
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);
extern void fn_80036DA4(void*, u32);
extern void fn_8011F778(void*, float);
extern void fn_8011F788(void*, float);
extern void fn_8011F798(void*, float);

void fn_80091124(register void* object, register void* motion,
                 register void* target, register State80091124* state)
{
    Vec3 original_position;
    Vec3 target_position;
    Vec3 position;
    register u32 flags;
    register int owner;
    void* target_object;
    u32 distance;

    fn_8011F114(&position);
    original_position = position;
    flags = fn_80036D5C(object);
    owner = fn_80201B54(object);
    fn_8008CC84(object);
    lbl_8064C570 = 0;
    fn_8008F860(owner);
    fn_801261F4(motion);
    fn_800DD314(object, 15, 255, 0);

    if (flags & 0x00100000) {
        target_object = fn_80201814(state->target_id);
        fn_80201E78(&target_position, target_object);
        distance = fn_80178E94(&original_position, &target_position);
        if (state->value0C != 0 || state->value10 != 0) {
            state->value10 = 0;
            state->value0C = 0;
        }
        if (distance < 500 && !(flags & 0x02000000)) {
            fn_80201DD8(target, state->target_id);
            fn_8020104C(6, owner, owner, 0, lbl_8064EC44);
            fn_80201D2C(object, 59);
            fn_80201D14(object, 1);
        } else {
            fn_80201DD8(target, state->target_id);
            fn_80201D2C(object, 3);
            fn_80201D14(object, 1);
        }
    } else {
        fn_80201D2C(object, 1);
        fn_80201D14(object, 1);
    }
    fn_80036DA4(object, flags & ~0x02000000);
    fn_8011F778(motion, lbl_8064EC48);
    fn_8011F788(motion, lbl_8064EC48);
    fn_8011F798(motion, lbl_8064EC48);
}

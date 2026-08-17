typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct Locals {
    unsigned char reference[12];
    char search[8];
    Vec3 position;
    Vec3 direction;
} Locals;

#pragma use_lmw_stmw on

extern void *fn_80201BC8();
extern int fn_8011F598(void *, int, int, int, void *, int);
extern void* fn_80201B94();
extern void *fn_80201C48(void *);
extern void *fn_80201814();
extern int fn_8011EB04(void *);
extern void fn_8011F0E8(void *, Vec3 *);
extern int fn_80201B54();
extern int fn_80201B44();
extern unsigned long long fn_8020123C();
extern unsigned int lbl_8064D5A8;
extern void *fn_801A717C(void);
extern void fn_801441C0(int, int, int);
extern float lbl_8064F230;
extern float lbl_8064F234;
extern float lbl_8064F238;
extern unsigned char lbl_802FC5BC[];
extern void fn_800CEA1C(int, int, Vec3 *, int, int, int, float, float,
                       float, void *);
extern void fn_8014D478(void *, Vec3 *, Vec3 *, int, int, void *, int);
extern void fn_80201E78(void *, void *);
extern void fn_801A74A0(void *, void *);
extern void fn_801A74A8(void *, void *);
extern void fn_801A7538(void *, int);
extern void fn_801A7518(void *, int);
extern void fn_801A764C(void *, void *);
extern void fn_801A7228(void *);

void fn_800C7C0C(void *object)
{
    void *constant;
    register Vec3 *position_ptr;
    void *runtime;
    void *parent;
    void *other;
    void *other_runtime;
    void *relation;
    void *sound;
    Locals locals;

    runtime = fn_80201BC8(object);
    if (fn_8011F598(runtime, 2, 15, -1, locals.search, 1) == -1) {
        return;
    }

    parent = fn_80201C48(fn_80201B94(object));
    other = fn_80201814(parent);
    if (other == 0) {
        return;
    }
    other_runtime = fn_80201BC8(other);
    relation = other_runtime;

    if (fn_8011EB04(runtime) != 0xFB) {
        fn_8011F0E8(relation, &locals.position);
    }

    relation = ((void *)fn_80201B54(object));
    if ((int)parent != (int)((void *)fn_80201B44(relation))) {
        fn_8020123C(0x24, parent, relation, 0);
        fn_8020123C(8, relation, parent, 0);
        return;
    }

    if ((lbl_8064D5A8 & 0x3F) != 0) {
        return;
    }

    sound = fn_801A717C();
    fn_801441C0(1, 1, 0x32);
    position_ptr = &locals.position;
    constant = lbl_802FC5BC + 0x18;
    fn_800CEA1C(0x17, 3, position_ptr, 0, 3, 1, lbl_8064F230,
                lbl_8064F234, lbl_8064F238, constant);
    fn_8014D478(runtime, position_ptr, &locals.direction, 6, 2, constant, 3);
    fn_80201E78(locals.reference, object);
    fn_801A74A0(sound, relation);
    fn_801A74A8(sound, parent);
    fn_801A7538(sound, 1);
    fn_801A7518(sound, 5);
    fn_801A764C(sound, locals.reference);
    fn_8020123C(0x27, relation, parent, sound);
    fn_801A7228(sound);
}

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

#pragma use_lmw_stmw on

extern Vec3 lbl_802399B8;

extern int fn_80201B54(void *);
extern void fn_800BD194(void *, Vec3 *);
extern void fn_8011F0E8(void *, Vec3 *);
extern void fn_80048708(void *);
extern int fn_800DE298(void *);
extern void fn_801261F4(void *);
extern void fn_8020123C(int, int, int, int);

void fn_800DFEB0(void *object, void *resource, Vec3 *position,
                 int *first_delay, int *second_delay)
{
    Vec3 direction = lbl_802399B8;
    int owner = fn_80201B54(object);

    fn_800BD194(object, position);
    *first_delay = 500;
    *second_delay = 300;
    fn_8011F0E8(resource, &direction);
    fn_80048708(resource);
    if (fn_800DE298(object) != 0) {
        fn_801261F4(resource);
        fn_8020123C(0x1B, owner, owner, 1);
    }
}

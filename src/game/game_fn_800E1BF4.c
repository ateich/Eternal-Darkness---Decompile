typedef struct Vec3 {
    float x, y, z;
} Vec3;

extern int lbl_8064D18C;
extern int fn_80201B54();
extern int fn_80201B44();
extern int fn_802066E0(void *, int);
extern void fn_8011DD8C(int, int);
extern void fn_8011E26C(int);
extern void fn_80201E78(Vec3 *, void *);
extern void fn_801B05E8(int, int, int, int, Vec3 *, int, int, int);
extern void fn_80154570(void *);

void fn_800E1BF4(void *object)
{
    void *id = ((void *)fn_80201B54(object));
    Vec3 position;

    if (lbl_8064D18C == 0x99) {
        if (fn_802066E0(((void *)fn_80201B44()), 0x36793917)) {
            fn_8011DD8C(4, 0);
            fn_8011E26C(1);
        }
    }
    fn_80201E78(&position, object);
    fn_801B05E8(0x258, 100, 6, 1, &position, 2, 0, 0);
    fn_80154570(id);
}

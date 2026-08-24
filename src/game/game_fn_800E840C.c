extern int lbl_8064D18C;
extern float lbl_8064F7FC;
extern int fn_80201B54();
extern int fn_80201EB8();
extern int fn_802006D4(int, int, int, int, int);
extern void fn_80201138(int, void *, int, int, int, float);
extern void *fn_80201BC8();
extern void *fn_8011F130(void *);
extern void fn_801F74C8(int, int, int);
extern void fn_801441C0(int, int, int);
extern void fn_801AC9F4(int, int, void *, int);
extern void *fn_801294DC(void *, int, int, int);
extern void fn_80128C28();
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);
extern void fn_800E8634(void);

void fn_800E840C(void *object)
{
    int handle = fn_80201B54(object);

    if (lbl_8064D18C != fn_80201EB8(object)) {
        fn_802006D4(handle, handle, 1, 215, 0);
        fn_80201138(215, object, 1, 57, 0, lbl_8064F7FC);
    } else {
        void *state = fn_80201BC8(object);
        void *position = fn_8011F130(state);
        void *created;

        fn_801F74C8(174, 1, 5);
        fn_801441C0(1, 1, 174);
        fn_801AC9F4(618, 127, position, 2);
        created = fn_801294DC(state, 25, 52, 1);
        fn_80128C28(created, fn_800E8634, object);
        fn_80201D2C(object, 15);
        fn_80201D14(object, 1);
    }
}

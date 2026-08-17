extern int fn_8011B864(void);
extern int fn_800462C8(int);
extern int fn_8006BE44(void);
extern int fn_80070CD8(int);
extern int fn_800460EC(void);
extern int fn_801A5CE0(void);
extern int fn_80201B44(void);
extern void fn_80201814(void);
extern int fn_80201B9C(void);
extern void fn_80204844(int, int);
extern void fn_8006D444(void);
extern void fn_8006BCB4(void);
extern unsigned long long fn_8020123C(int, int, int, int);
extern int fn_801D1374(void);
extern int fn_80070A6C(int);
extern void fn_801EFE84(int);
extern void fn_800073DC(int);
extern void fn_8001D9FC(int);
extern void fn_8011B740(void);
extern void fn_801453FC(void);

void fn_8011B74C(void)
{
    int keep = 1;

    if (fn_8011B864() != 0 && fn_800462C8(0) == 0 && fn_8006BE44() >= 2 &&
        fn_80070CD8(0) != 0 && fn_800460EC() == 0 && fn_801A5CE0() != 0) {
        int value = fn_80201B44();
        fn_80201814();
        fn_80204844(fn_80201B9C(), 32);
        fn_8006D444();
        fn_8006BCB4();
        if ((unsigned int)(fn_8020123C(135, 0, value, 0) & 0xFFFFFFFFULL) == 1 &&
            fn_801D1374() == 0 && fn_80070A6C(1) == 0) {
            keep = 0;
            fn_801EFE84(1);
            fn_800073DC(2);
            fn_8001D9FC(12);
        }
    }
    if (keep != 0 && fn_8011B864() != 0) {
        fn_8011B740();
        fn_801453FC();
    }
}

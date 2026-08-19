extern volatile int lbl_8064CDA8;
extern volatile int lbl_8064CDA0;
extern void (*lbl_8064CD8C)(void);
extern void (*lbl_8064CD88)(void);
extern int lbl_8064CDC0;
extern int lbl_8064CA40;
extern int lbl_8064CE44;
extern int lbl_8064C9E8;
extern int lbl_8064C4E0;
extern unsigned char lbl_8024EAA0[];

extern void fn_8011BD54(void);
extern void fn_8011BB48(void);
extern void fn_8011BD20(void);
extern int fn_80144628(int, void *, int);
extern void fn_800B177C(int, void *);
extern void fn_800B2548(int, int);
extern void fn_8017B7C8(void);
extern void fn_80042DA8(void);
extern int fn_800AF844(void);
extern int fn_8006BE44(void);
extern int fn_801E79FC(void*, int);
extern void fn_801E79A0(int, int);
extern void fn_800B25AC(void);
extern void fn_800B689C(int, int);

void fn_8011BA1C(void)
{
    while (lbl_8064CDA8 == 0 || lbl_8064CDA0 == 0) {
    }
    lbl_8064CD8C = fn_8011BD54;
    lbl_8064CD88 = fn_8011BB48;
    lbl_8064CDC0 = fn_80144628(5, lbl_8024EAA0, 0);
    fn_800B177C(0, fn_8011BD20);
    fn_800B2548(0, 0);
    fn_8017B7C8();
    fn_80042DA8();
    lbl_8064CA40 = fn_800AF844();
    lbl_8064CE44 = 0;
    lbl_8064C9E8 = 0;
    if (fn_8006BE44() >= 2 && fn_801E79FC((void *)lbl_8064C4E0, 476) == 0 &&
        fn_801E79FC((void *)lbl_8064C4E0, 475) != 0) {
        lbl_8064CE44 = 1;
        fn_801E79A0(lbl_8064C4E0, 475);
    }
    if (fn_801E79FC((void *)lbl_8064C4E0, 823) != 0) {
        if (lbl_8064CA40 != 0) {
            fn_800B25AC();
            fn_800B689C(0, 1);
            fn_800B2548(1, 0);
        }
        fn_801E79A0(lbl_8064C4E0, 823);
    }
}

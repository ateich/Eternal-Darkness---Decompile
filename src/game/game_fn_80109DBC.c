extern void* lbl_8064CCA0;
extern int fn_801E8D34(void*);
extern void fn_801A98F4(int, int);
extern void fn_80109C5C(void);
extern void fn_8011CD00(void);
extern void fn_8011C1AC(void);
extern void fn_8011D470(void);
extern void fn_8011BA1C(void);
extern void fn_80144C40(void);

void fn_80109DBC(void)
{
    int mode = fn_801E8D34(lbl_8064CCA0);

    fn_801A98F4(0x222, 100);
    fn_80109C5C();
    switch (mode) {
    case 1:
        fn_8011CD00();
        break;
    case 0:
        fn_8011C1AC();
        break;
    case 2:
        fn_8011D470();
        break;
    case 3:
        fn_8011BA1C();
        break;
    }
    fn_80144C40();
}

extern unsigned char lbl_803324D0[];
extern int lbl_8064B9C0;

extern void* memset(void*, int, unsigned long);
extern void fn_8011DD8C(int, int);
extern void fn_8011DF6C(void);

void fn_8011E1C4(void)
{
    int i;

    lbl_8064B9C0 = -1;
    memset(lbl_803324D0, 0, 28);
    *(int*)(lbl_803324D0 + 8) = -1;
    for (i = 0; i < 6; i++) {
        fn_8011DD8C(i, 1);
    }
    fn_8011DF6C();
}

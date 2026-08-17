extern void *lbl_8064CDC0;
extern void (*lbl_8064CD88)(void);

extern void fn_800B18F8(void);
extern void fn_80144680(void *);

void fn_8011BB48(void)
{
    fn_800B18F8();
    if (lbl_8064CDC0 != 0) {
        fn_80144680(lbl_8064CDC0);
        lbl_8064CDC0 = 0;
    }
    lbl_8064CD88 = 0;
}

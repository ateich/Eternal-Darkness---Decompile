extern int lbl_8064CD88;
extern int lbl_8064CDC0;
extern int lbl_8064CE6C;

extern void fn_8011C830(int);
extern void fn_80144680(int);
extern void fn_801E8AC4(int);

void fn_8011CD98(void)
{
    fn_8011C830(0);
    fn_801E8AC4(lbl_8064CE6C);
    fn_80144680(lbl_8064CDC0);
    lbl_8064CD88 = 0;
}

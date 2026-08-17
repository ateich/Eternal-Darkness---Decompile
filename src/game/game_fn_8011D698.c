extern int lbl_8064CD88;
extern int lbl_8064CE80;
extern int lbl_8064CE7C;
extern int lbl_8064CDC0;

extern void fn_80144680(int);
extern void fn_801E8AC4(int);

void fn_8011D698(void)
{
    lbl_8064CD88 = 0;
    fn_801E8AC4(lbl_8064CE80);
    fn_801E8AC4(lbl_8064CE7C);
    fn_80144680(lbl_8064CDC0);
    lbl_8064CDC0 = 0;
}

extern int lbl_8064CD8C;
extern int lbl_8064CD88;
extern int lbl_8064CE84;
extern int lbl_8064CDC0;
extern int lbl_8064CE80;
extern int lbl_8064CE7C;
extern int lbl_8064CBA0;
extern int lbl_8024ECC0[];

extern void fn_80118080(void);
extern void fn_8011D698(void);
extern void fn_8011D8D0(void);
extern int fn_80144628(int, void*, int);
extern int fn_801E8A8C(void);
extern void fn_801E8AEC(int, int, int, int);
extern void fn_801E8B10(int, int, int, int, void (*)(void));
extern void fn_801E8B24(int, int, int);

void fn_8011D470(void)
{
    lbl_8064CE84 = 0;
    lbl_8064CD8C = (int)fn_8011D8D0;
    lbl_8064CD88 = (int)fn_8011D698;
    lbl_8064CDC0 = fn_80144628(6, lbl_8024ECC0, 0);
    lbl_8024ECC0[21] = 0;
    lbl_8024ECC0[22] = 0;
    lbl_8064CE80 = fn_801E8A8C();
    lbl_8064CE7C = fn_801E8A8C();
    fn_801E8AEC(lbl_8064CE80, 0, 51, 51);
    fn_801E8B24(lbl_8064CE80, lbl_8064CBA0, 0);
    fn_801E8AEC(lbl_8064CE7C, 0, 3, 3);
    fn_801E8B10(lbl_8064CE80, 1, 0, 0, fn_80118080);
    fn_801E8B10(lbl_8064CE7C, 1, 0, 0, fn_80118080);
}

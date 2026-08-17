extern unsigned char lbl_8024EC08[0xA0];
extern int lbl_8064CD88;
extern int lbl_8064CD8C;
extern int lbl_8064CDC0;
extern int lbl_8064CE58;
extern int lbl_8064CE68;
extern int lbl_8064CE6C;
extern int lbl_8064CE70;

extern void fn_8011CD98(void);
extern void fn_8011D048(void);
extern void fn_80118080(void);
extern int fn_80144628(int, void *, int);
extern int fn_801E8A8C(void);
extern void fn_801E8AEC(int, int, int, int);
extern void fn_801E8B10(int, int, int, int, void *);

void fn_8011CD00(void)
{
    lbl_8064CE58 = 1;
    lbl_8064CE68 = 0;
    lbl_8064CD8C = (int)fn_8011D048;
    lbl_8064CD88 = (int)fn_8011CD98;
    lbl_8064CDC0 = fn_80144628(5, lbl_8024EC08, 0);
    lbl_8064CE6C = fn_801E8A8C();
    fn_801E8AEC(lbl_8064CE6C, 0, 2, 2);
    fn_801E8B10(lbl_8064CE6C, 1, 0, 0, fn_80118080);
    lbl_8064CE70 = 0;
}

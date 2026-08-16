extern int lbl_80331A08[];
extern int lbl_8024DE38[];
extern int lbl_8064CD34;
extern int lbl_8064CD58;
extern int lbl_8064CDC0;
extern int lbl_8064CD88;
extern int lbl_8064CDB4;
extern int lbl_8064CDB0;

extern int fn_801E8D34(int);
extern void fn_80111F2C(int, int);
extern void fn_80117EF0(void);
extern void fn_801E8AC4(int);
extern void fn_801E5FB0(int);
extern void fn_80144680(int);

void fn_801139D4(void)
{
    int i;

    lbl_8064CD34 = fn_801E8D34(lbl_80331A08[5]) * 3 +
                     fn_801E8D34(lbl_80331A08[4]);
    fn_80111F2C(0, 0);
    fn_80117EF0();
    for (i = 0; i < 13; i++) {
        fn_801E8AC4(lbl_80331A08[i]);
    }
    fn_801E5FB0(lbl_8024DE38[11]);
    lbl_8024DE38[11] = 0;
    fn_801E5FB0(lbl_8064CD58);
    lbl_8064CD58 = 0;
    fn_80144680(lbl_8064CDC0);
    lbl_8064CD88 = 0;
    fn_801E5FB0(lbl_8064CDB4);
    lbl_8064CDB4 = 0;
    fn_801E5FB0(lbl_8064CDB0);
    lbl_8064CDB0 = 0;
}

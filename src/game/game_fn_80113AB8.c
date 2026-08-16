extern unsigned char lbl_80331748[];
extern unsigned int lbl_8024E388[];
extern int lbl_8064CD34;
extern int lbl_8064CD38;
extern int lbl_8064CD3C;

extern void *memset(void *, int, unsigned int);
extern int fn_801E78DC(int);
extern void fn_801E7974(int, int);

void fn_80113AB8(void)
{
    memset(lbl_80331748, 0, 0xB0);
    if (lbl_8024E388[0] == 0) {
        lbl_8024E388[0] = fn_801E78DC(54);
        lbl_8024E388[1] = fn_801E78DC(54);
        lbl_8024E388[2] = fn_801E78DC(54);
        fn_801E7974(lbl_8024E388[0], 0);
    }
    lbl_8064CD34 = 0;
    lbl_8064CD38 = 0;
    lbl_8064CD3C = -1;
}

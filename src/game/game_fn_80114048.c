extern int lbl_80331A08[];
extern int lbl_8064CD38;
extern int lbl_8064CD3C;
extern int lbl_8064CD44;

extern void fn_80144C40(void);
extern void fn_801E8B6C(int, unsigned int);
extern int fn_801E8D34(int);
extern int fn_801E8D3C(int);
extern void fn_801E8B24(int, int, int);
extern void fn_80112278(int);

void fn_80114048(unsigned int value)
{
    int old_primary;
    int old_secondary;
    int primary;
    int secondary;

    fn_80144C40();
    switch (lbl_8064CD44) {
    case 0:
        fn_801E8B6C(lbl_80331A08[0], value);
        break;
    case 5:
        old_primary = fn_801E8D34(lbl_80331A08[5]);
        old_secondary = fn_801E8D3C(lbl_80331A08[5]);
        fn_801E8B6C(lbl_80331A08[5], value);
        if (old_primary != fn_801E8D34(lbl_80331A08[5])) {
            lbl_8064CD38 = 0;
            lbl_8064CD3C = -1;
        }
        if (old_secondary != fn_801E8D3C(lbl_80331A08[5])) {
            fn_80112278(fn_801E8D3C(lbl_80331A08[5]) * 3);
        }
        break;
    case 15:
    case 16:
        fn_801E8B6C(lbl_80331A08[8], value);
        primary = fn_801E8D34(lbl_80331A08[8]);
        secondary = fn_801E8D34(lbl_80331A08[7]);
        if (primary == 0 && secondary > 2) {
            fn_801E8B24(lbl_80331A08[7], 2, 0);
        } else if (primary == 1 && secondary > 3) {
            fn_801E8B24(lbl_80331A08[7], 3, 0);
        }
        break;
    }
}

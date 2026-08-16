extern int lbl_80331A08[];
extern int lbl_8064CD38;
extern int lbl_8064CD3C;
extern unsigned int lbl_8064CD44;

extern void fn_80144C40(void);
extern void fn_801E8B6C(int, unsigned int);
extern int fn_801E8D34(int);
extern void fn_801E8B24(int, int, int);

void fn_801141B8(unsigned int value)
{
    int old_primary;
    int primary;
    int secondary;

    fn_80144C40();
    switch (lbl_8064CD44) {
    case 1:
    case 10:
    case 12:
        fn_801E8B6C(lbl_80331A08[1], value);
        break;
    case 2:
    case 11:
    case 13:
    case 26:
        fn_801E8B6C(lbl_80331A08[2], value);
        break;
    case 6:
        fn_801E8B6C(lbl_80331A08[6], value);
        break;
    case 3:
        fn_801E8B6C(lbl_80331A08[3], value);
        break;
    case 5:
        old_primary = fn_801E8D34(lbl_80331A08[4]);
        fn_801E8B6C(lbl_80331A08[4], value);
        if (old_primary != fn_801E8D34(lbl_80331A08[4])) {
            lbl_8064CD38 = 0;
            lbl_8064CD3C = -1;
        }
        break;
    case 15:
    case 16:
        fn_801E8B6C(lbl_80331A08[7], value);
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

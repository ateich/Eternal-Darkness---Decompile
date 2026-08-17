extern int lbl_8064CE84;
extern int lbl_8064CE7C;
extern int lbl_8024ECC0[];
extern int lbl_803003C8[];
extern unsigned char lbl_8064B9B8;

extern int fn_800B193C(void);
extern void fn_800B2AE8(void);
extern void fn_80144C40(void);
extern void fn_801A98F4(int, int);
extern int fn_801E8D34(int);

void fn_8011D804(void)
{
    if (fn_800B193C() != 0) {
        fn_800B2AE8();
    } else {
        switch (lbl_8064CE84) {
        case 0:
            switch (fn_801E8D34(lbl_8064CE7C)) {
            case 0:
                fn_801A98F4(546, 100);
                lbl_8064CE84 = 1;
                lbl_8024ECC0[21] = 20;
                lbl_8024ECC0[22] = 5;
                break;
            case 1:
                lbl_803003C8[4] ^= 1;
                break;
            case 2:
                (&lbl_8064B9B8)[3] = 5;
                lbl_8064CE84 = 2;
                break;
            }
            break;
        }
    }
    fn_80144C40();
}

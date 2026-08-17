extern int lbl_8064CE6C;
extern int lbl_8064CE70;
extern int lbl_8064D294;

extern int fn_800B193C(void);
extern void fn_800B2AE8(void);
extern void fn_8011C6BC(int, int, unsigned char);
extern void fn_8011C830(int);
extern void fn_80144C40(void);
extern void fn_801A96A8(int, int, int);
extern int fn_801A98F4(int, int);
extern int fn_801E8D34(int);

void fn_8011CEF4(void)
{
    if (fn_800B193C() != 0) {
        fn_800B2AE8();
    } else {
        fn_801A98F4(546, 100);
        switch (lbl_8064CE70) {
        case 0:
            switch (fn_801E8D34(lbl_8064CE6C)) {
            case 1:
                lbl_8064CE70 = 1;
                fn_8011C6BC(140, 154, 254);
                break;
            case 0:
                switch (lbl_8064D294) {
                case 0: lbl_8064D294 = 1; break;
                case 1: lbl_8064D294 = 2; break;
                case 2: lbl_8064D294 = 0; break;
                }
                fn_801A96A8(lbl_8064D294, 1, 1);
                break;
            }
            break;
        case 1:
            fn_8011C830(1);
            lbl_8064CE70 = 0;
            break;
        }
    }
    fn_80144C40();
}

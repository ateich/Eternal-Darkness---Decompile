extern unsigned char lbl_80332158[];
extern int lbl_8064CCA0;
extern int lbl_8064CE70;

extern int fn_800AFCD0(void *);
extern void fn_800B177C(int, void *);
extern int fn_800B193C(void);
extern void fn_800B2548(int, int);
extern void fn_800B283C(void);
extern void fn_800B689C(int, int);
extern void fn_80109B94(void);
extern void fn_8011C830(int);
extern void fn_8011CD98(void);
extern void fn_8011CDD4(void);
extern void fn_80144C40(void);
extern int fn_801A98F4(int, int);
extern void fn_801E8B24(int, int, int);

void fn_8011CE1C(void)
{
    if (fn_800B193C() != 0) {
        fn_800B283C();
    } else {
        switch (lbl_8064CE70) {
        case 0:
            if (fn_800AFCD0(lbl_80332158 + 8) != 0) {
                fn_800B177C(1, fn_8011CDD4);
                fn_800B689C(0, 1);
                fn_800B2548(11, 0);
            } else {
                fn_801A98F4(611, 50);
                fn_8011CD98();
                fn_80109B94();
                fn_801E8B24(lbl_8064CCA0, 1, 0);
            }
            break;
        case 1:
            fn_801A98F4(611, 50);
            fn_8011C830(0);
            lbl_8064CE70 = 0;
            break;
        }
    }
    fn_80144C40();
}

extern unsigned char lbl_80332158[];
extern int lbl_8064CDC8;
extern int lbl_8064CE70;

extern int fn_800AFCD0(void *);
extern int fn_800B193C(void);
extern void fn_800B177C(int, void *);
extern void fn_800B2548(int, int);
extern void fn_800B689C(int, int);
extern void fn_80109B94(void);
extern void fn_8010AD7C(void);
extern void fn_8010F418(void);
extern void fn_8011CD98(void);
extern unsigned int fn_80144710(unsigned int, int, int);
extern void fn_80144C40(void);
extern int fn_801A98F4(int, int);
extern void fn_8011CDD4(void);

void fn_8011CC20(void)
{
    if (lbl_8064CE70 != 1 && fn_800B193C() == 0) {
        if (fn_800AFCD0(lbl_80332158 + 8) != 0) {
            fn_800B177C(1, fn_8011CDD4);
            fn_800B689C(0, 1);
            fn_800B2548(11, 0);
        } else {
            fn_8011CD98();
            if (fn_80144710(0x1000, 0, 0) != 0) {
                lbl_8064CDC8 = 2;
            } else if (fn_80144710(0x1000000, 0, 0) != 0) {
                fn_8010F418();
                fn_801A98F4(495, 50);
            } else {
                fn_8010AD7C();
                fn_801A98F4(495, 50);
            }
        }
    }
    fn_80144C40();
}

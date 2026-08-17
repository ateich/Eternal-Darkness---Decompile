extern int lbl_8064CE84;
extern int lbl_8064CDC8;
extern int lbl_8024ECC0[];
extern char lbl_80332158[];

extern int fn_800AFCD0(void*);
extern int fn_800B193C(void);
extern void fn_800B177C(int, void (*)(void));
extern void fn_800B2548(int, int);
extern void fn_800B689C(int, int);
extern void fn_80109B94(void);
extern void fn_8010AD7C(void);
extern void fn_8010F418(void);
extern void fn_8011D698(void);
extern void fn_8011D6DC(void);
extern void fn_80144628(int, void*, int);
extern void* fn_80144710(int, int, int);
extern void fn_80144C40(void);
extern int fn_801A98F4(int, int);

void fn_8011D36C(void)
{
    if (lbl_8064CE84 >= 5 || lbl_8064CE84 < 1) {
        if (fn_800B193C() == 0) {
            lbl_8024ECC0[21] = 0;
            lbl_8024ECC0[22] = 0;
            if (fn_800AFCD0(lbl_80332158 + 8) != 0) {
                fn_800B177C(1, fn_8011D6DC);
                fn_800B689C(0, 1);
                fn_800B2548(11, 0);
            } else {
                fn_80144C40();
                if (fn_80144710(0x1000, 0, 0) != 0) {
                    lbl_8064CDC8 = 2;
                } else if (fn_80144710(0x1000000, 0, 0) != 0) {
                    fn_8011D698();
                    fn_8010F418();
                    fn_801A98F4(0x1ef, 50);
                } else {
                    fn_8011D698();
                    fn_8010AD7C();
                    fn_801A98F4(0x1ef, 50);
                }
            }
        }
        fn_80144C40();
    }
}

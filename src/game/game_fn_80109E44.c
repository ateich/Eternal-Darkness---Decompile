extern volatile int lbl_8064CDA8;
extern volatile int lbl_8064CDAC;
extern volatile int lbl_8064CDA0;
extern int lbl_8064CDC8;
extern void fn_80109C5C(void);
extern void fn_80144C40(void);
extern unsigned int fn_80144710(int, int, int);
extern void fn_801A98F4(int, int);
extern void fn_8010F418(void);
extern void fn_8010AD7C(void);

void fn_80109E44(void)
{
    while (lbl_8064CDA8 == 0 || lbl_8064CDAC == 0 || lbl_8064CDA0 == 0) {}
    fn_80109C5C();
    fn_80144C40();
    if (fn_80144710(0x1000, 0, 0) != 0) {
        lbl_8064CDC8 = 2;
    } else if (fn_80144710(0x1000000, 0, 0) != 0) {
        fn_801A98F4(0x1EF, 50);
        fn_8010F418();
    } else {
        fn_801A98F4(0x1EF, 50);
        fn_8010AD7C();
    }
}

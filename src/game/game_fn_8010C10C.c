extern unsigned char lbl_80332140[];
extern volatile int lbl_8064CDA8;
extern volatile int lbl_8064CDAC;
extern int lbl_8064CDC8;

extern void fn_80144C40(void);
extern unsigned int fn_80144710(unsigned int, int, int);
extern int fn_801A98F4(int, int);
extern void fn_8010BFF0(void);
extern void fn_80109B94(void);
extern void fn_80119568(void);

void fn_8010C10C(void)
{
    if ((*(unsigned int *)(lbl_80332140 + 0x10) & 3) == 0) {
        fn_80144C40();
        while (lbl_8064CDA8 == 0) {}
        if (fn_80144710(0x1000, 0, 0) != 0) {
            lbl_8064CDC8 = 2;
        } else if (fn_80144710(0x1000000, 0, 0) != 0) {
            fn_801A98F4(0x1EF, 50);
            fn_8010BFF0();
            fn_80109B94();
        } else {
            fn_801A98F4(0x1EF, 50);
            while (lbl_8064CDA8 == 0 || lbl_8064CDAC == 0) {}
            fn_8010BFF0();
            fn_80119568();
        }
    }
}

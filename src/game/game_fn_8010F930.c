extern unsigned int lbl_80331738[];
extern unsigned int lbl_8064CDC0;
extern unsigned int lbl_8064CCF0;
extern unsigned int lbl_8064CCEC;
extern unsigned int lbl_8064CDB4;
extern unsigned int lbl_8064CDB0;
extern unsigned int lbl_8064CD88;

extern void fn_80144680(unsigned int);
extern void fn_80237C28(void);
extern void fn_80008CA0(void);
extern void fn_801ACC94(int);
extern void fn_801B2380(int);
extern void fn_801E8AC4(unsigned int);
extern void fn_801E5FB0(unsigned int);

void fn_8010F930(void)
{
    int i;

    fn_80144680(lbl_8064CDC0);
    fn_80237C28();
    fn_80008CA0();
    fn_801ACC94(1);
    fn_801B2380(1);

    for (i = 0; i < 3; i++) {
        fn_801E8AC4(lbl_80331738[i]);
    }
    fn_801E8AC4(lbl_8064CCF0);
    fn_801E5FB0(lbl_8064CCEC);
    lbl_8064CD88 = 0;
    fn_801E5FB0(lbl_8064CDB4);
    lbl_8064CDB4 = 0;
    fn_801E5FB0(lbl_8064CDB0);
    lbl_8064CDB0 = 0;
}

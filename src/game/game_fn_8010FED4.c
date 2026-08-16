extern int lbl_8064CD20;
extern int lbl_8064CDC8;

extern void fn_801A98F4(int, int);
extern void fn_80144C40(void);
extern void fn_80237C28(void);
extern void fn_80008CA0(void);
extern void fn_801ACC94(int);
extern void fn_801B2380(int);

void fn_8010FED4(void)
{
    switch (lbl_8064CD20) {
    case 1:
    case 2:
        fn_801A98F4(0x263, 50);
        lbl_8064CD20 = 0;
        break;
    case 0:
        fn_80144C40();
        lbl_8064CDC8 = 2;
        break;
    case 4:
        fn_801A98F4(0x263, 50);
        lbl_8064CD20 = 1;
        fn_80237C28();
        fn_80008CA0();
        fn_801ACC94(1);
        fn_801B2380(1);
        break;
    case 3:
        break;
    }
}

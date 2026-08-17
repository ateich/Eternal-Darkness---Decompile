extern int lbl_8064CD80;
extern int lbl_8064CDC8;
extern unsigned char lbl_8064CE1C;
extern unsigned short lbl_8064CE1E;
extern int lbl_8064CE10;
extern int lbl_8064CE24;
extern int lbl_8064CE28;
extern int lbl_8064CE30;
extern unsigned char lbl_8024EA90[];

extern int fn_8015AA0C(void);
extern void fn_80118AC4(void);
extern int fn_8015AA14(void);
extern void fn_8015D458(void *, int, int);
extern void fn_8015DAB0(int);
extern void fn_80119550(void);
extern void fn_801ACD8C(void);
extern int fn_801AD5FC(int, int);
extern void fn_801AD404(int, int, int);
extern void fn_801AD490(void);

void fn_8011A79C(void)
{
    int value = fn_8015AA0C();

    fn_80118AC4();
    lbl_8064CD80 = value;
    lbl_8064CDC8 = 2;
    fn_8015D458(lbl_8024EA90, lbl_8064CD80, fn_8015AA14());
    fn_8015DAB0(lbl_8064CD80);
    lbl_8064CE1C = 150;
    lbl_8064CE1E = 7;
    lbl_8064CE24 = 0;
    lbl_8064CE30 = 2;
    lbl_8064CE28 = 255;
    lbl_8064CE10 = 0;
    fn_80119550();
    fn_801ACD8C();
    if (fn_801AD5FC(1, 0) != 0) {
        lbl_8064CE10 = 1;
        fn_801AD404(0, 0, 16);
        fn_801AD490();
        fn_801AD404(100, 100, 1);
    }
}

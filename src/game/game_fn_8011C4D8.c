extern int lbl_8064C2A8;
extern int lbl_8064C2B0;
extern void *lbl_8064CD80;
extern char lbl_802515D0[];

extern int fn_800B193C(void);
extern void fn_800B2EC0(unsigned char);
extern void fn_80119224(int, unsigned char);
extern void *fn_80144470(int);
extern void fn_801A852C(int *, int, int, unsigned int);
extern void fn_801A8EDC(void *);
extern void fn_801A8F08(int, int, int, int, int, int, int);
extern void fn_801ED3F4(void *);

void fn_8011C4D8(unsigned char value)
{
    int color0 = lbl_8064C2B0;
    int color1;
    int color2;
    int color3;
    int color4;
    int color5;
    int color6;

    ((unsigned char *)&color0)[3] = value;
    fn_801ED3F4(lbl_8064CD80);
    fn_801A8EDC(lbl_802515D0);

    color1 = lbl_8064C2A8;
    fn_801A852C(&color1, 0, 31, 0x80000000);
    fn_801A8F08(144, 0, 575, 479, -1, 0, 5);

    if (fn_80144470(-1) == 0) {
        color2 = lbl_8064C2A8;
        fn_801A852C(&color2, 0, 28, 0x80000000);
        fn_801A8F08(393, 392, 433, 425, -1, 0, 5);
        color3 = color0;
        fn_801A852C(&color3, 5, 41, 0x80000000);
        fn_801A8F08(393, 392, 433, 425, -1, 0, 5);
    } else {
        color4 = lbl_8064C2A8;
        fn_801A852C(&color4, 0, 29, 0x80000000);
        fn_801A8F08(395, 384, 442, 432, -1, 0, 5);
        color5 = color0;
        fn_801A852C(&color5, 5, 42, 0x80000000);
        fn_801A8F08(395, 384, 442, 432, -1, 0, 5);
    }

    color6 = color0;
    fn_801A852C(&color6, 5, 43, 0x80000000);
    fn_801A8F08(250, 392, 388, 424, -1, 0, 5);
    fn_80119224(0, value);
    if (fn_800B193C() != 0) {
        fn_800B2EC0(value);
    }
}

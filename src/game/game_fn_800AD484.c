extern int lbl_8064C960;
extern int lbl_8064C968;
extern int fn_801ED3F4(int);
extern void fn_801A8D38(int);
extern void fn_801A9250(int, int, int);
extern void fn_801F03B8(void);

void fn_800AD484(void)
{
    if (lbl_8064C960 != 0) {
        int value = fn_801ED3F4(lbl_8064C968);
        fn_801A8D38(5);
        fn_801A9250(0, 255, 1);
        fn_801F03B8();
        fn_801ED3F4(value);
    }
}

typedef unsigned long u32;

extern const u32 lbl_80650E2C;
extern const u32 lbl_80650E30;
extern const u32 lbl_80650E34;
extern const u32 lbl_80650E38;

extern void fn_801A8D38(int);
extern void fn_801A8660(int, int, int, int, int, const u32*);

void fn_801A92D0(void)
{
    fn_801A8D38(6);
    {
        u32 color = lbl_80650E2C;
        fn_801A8660(0, 0, 639, 40, -1, &color);
    }
    {
        u32 color = lbl_80650E30;
        fn_801A8660(0, 439, 639, 40, -1, &color);
    }
    {
        u32 color = lbl_80650E34;
        fn_801A8660(0, 40, 10, 399, -1, &color);
    }
    {
        u32 color = lbl_80650E38;
        fn_801A8660(629, 40, 10, 399, -1, &color);
    }
}

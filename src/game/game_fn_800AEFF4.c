typedef unsigned int u32;
typedef signed short s16;

extern void fn_801A8D38(int);
extern void fn_801E3AA4(int);
extern void fn_801E5430(s16, s16);
extern u32 fn_801E3A34(u32*);
extern void fn_801E56AC(float, const char*, ...);
extern void fn_801A8660(int, int, int, int, int, const u32*);

extern char lbl_8064B6B0;
extern int lbl_8064C9D8;
extern const float lbl_8064EFFC;
extern const u32 lbl_8064F000;
extern u32 lbl_8064F004;

void fn_800AEFF4(void)
{
    u32 textColor;
    u32 barColor;
    int x;
    int i;

    fn_801A8D38(5);
    fn_801E3AA4(0);
    fn_801E5430(0x40, 0x164);
    textColor = lbl_8064F000;
    fn_801E3A34(&textColor);
    fn_801E56AC(lbl_8064EFFC, &lbl_8064B6B0);

    i = 0;
    x = 0x40;
    do {
        int last = lbl_8064C9D8;
        s16 drawX = x;
        int y = 0x198;
        int height = 0x1C;
        if (i > last) {
            height = 0xE;
            y = 0x19F;
        }
        barColor = lbl_8064F004;
        fn_801A8660(drawX, y, 4, height, -1, &barColor);
        i++;
        x += 8;
    } while (i < 0x40);
}

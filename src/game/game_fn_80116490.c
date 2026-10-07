typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Color { u8 r, g, b, a; } Color;

extern unsigned int lbl_80331748[];
extern int lbl_80331A08[];
extern char *lbl_8024DCF0[];
extern char lbl_8024E254[];
extern char lbl_8064B964[8];
extern char lbl_8064B96C[8];
extern char lbl_8064B974[8];
extern Color lbl_8064C2A8;
extern Color lbl_8064C2B0;
extern Color lbl_8064C2BC;
extern const Color lbl_8064FF84;
extern const Color lbl_8064FF88;
extern const float lbl_8064FF7C;
extern const float lbl_8064FF8C;

extern int fn_801E8D3C(int);
extern int fn_801E8D34(int);
extern void fn_801A852C(Color, int, int, u32);
extern void fn_801A9118(int, u16, int);
extern void fn_801A8974(int, int, int, int, int, int);
extern void fn_801A872C(int, int, int, int, int, int, Color);
extern void fn_801E3AA4(int);
extern void fn_801E5AD0(u8);
extern void fn_801E3A34(Color);
extern void fn_801E5430(short, short);
extern void fn_801E56AC(float, const char *, ...);
extern void fn_801E76E0(unsigned int);
extern int fn_80201B44();
extern void *fn_80201814();
extern unsigned int fn_8020216C(void);

static inline Color WithAlpha(Color color, u8 alpha)
{
    color.a = alpha;
    return color;
}

void fn_80116490(int compact, int showLabel, u8 alpha)
{
    int limit;
    int i;
    unsigned int *flags;
    int base;
    int index;

    base = fn_801E8D3C(lbl_80331A08[5]) * 3;
    index = fn_801E8D34(lbl_80331A08[5]) * 3 + fn_801E8D34(lbl_80331A08[4]);

    fn_801A852C(lbl_8064C2A8, 0, 5, 0x80000000);
    fn_801A9118(0, 0x68, 5);
    fn_801A852C(lbl_8064C2A8, 0, 2, 0x80000000);

    flags = &lbl_80331748[index];
    if ((*(flags += 2) & 0x04000000) || (fn_80201B44(), fn_80201814(), fn_8020216C() & 0x4000)) {
        fn_801A9118(0x3C, 0x6C, 5);
        fn_801A9118(0x40, 0x70, 5);
    }
    if ((*flags & 0x0C000000) || (fn_80201B44(), fn_80201814(), fn_8020216C() & 0x4000)) {
        fn_801A9118(0x44, 0x74, 5);
    }
    fn_801A852C(lbl_8064FF84, 5, 3, 0x80000000);

    limit = 12 - base;
    for (i = 0; i < (limit > 9 ? 9 : limit); i++) {
        fn_801A9118(0, (i + 0x3D) * 4, 5);
    }

    if (compact) {
        fn_801A8974((short)((index - base) % 3 * 75 + 0x130), (short)((index - base) / 3 * 75 + 0x8C), 0x40, 0x40, -0x7698, 2);
    } else {
        fn_801A872C((short)((index - base) % 3 * 75 + 0x130), (short)((index - base) / 3 * 75 + 0x8C), 0x40, 0x40, -0x7698, 2, lbl_8064C2BC);
        fn_801E3AA4(0);
        fn_801E5AD0(0x63);
    }
    fn_801E3AA4(0);
    fn_801E5AD0(0x63);

    fn_801E3A34(WithAlpha(lbl_8064FF88, alpha));

    if (fn_801E8D3C(lbl_80331A08[5]) != 0) {
        fn_801E5430(0x225, 0xD7);
        fn_801E56AC(lbl_8064FF7C, lbl_8064B964);
    }
    if (fn_801E8D3C(lbl_80331A08[5]) * 3 + 9 < 12) {
        fn_801E5430(0x225, 0x100);
        fn_801E56AC(lbl_8064FF7C, lbl_8064B96C);
    }

    if (showLabel) {
        fn_801E76E0(*flags & 0x70000);
        fn_801E3A34(lbl_8064C2B0);
        fn_801E5430((short)((index - base) % 3 * 75 + 0x150), (short)((index - base) / 3 * 75 + 0x64));
        if (*flags == 0) {
            fn_80201B44();
            fn_80201814();
            if ((fn_8020216C() & 0x4000) == 0) {
                return;
            }
        }
        if ((*flags & 0x08000000) || (fn_80201B44(), fn_80201814(), fn_8020216C() & 0x4000)) {
            fn_801E56AC(lbl_8064FF8C, lbl_8064B974, lbl_8024DCF0[index]);
        } else {
            fn_801E56AC(lbl_8064FF8C, lbl_8024E254, index + 1);
        }
    }
}

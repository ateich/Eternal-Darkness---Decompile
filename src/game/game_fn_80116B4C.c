typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Color { u8 r, g, b, a; } Color;
typedef struct Pos { short x, y; } Pos;
typedef struct PosList { Pos p[5]; } PosList;
typedef struct Glyphs { signed char c[4]; } Glyphs;

extern unsigned int lbl_80331748[];
extern const PosList lbl_8023A63C;
extern char *lbl_8024DCF0[];
extern char lbl_8024E260[];
extern char lbl_8064B978[8];
extern char lbl_8064B980[8];
extern Color lbl_8064C2A8;
extern Color lbl_8064C2B0;
extern const Glyphs lbl_8064FF94;
extern const float lbl_8064FF7C;
extern const float lbl_8064FF8C;
extern const float lbl_8064FF98;

extern void fn_801A852C(Color, int, int, u32);
extern void fn_801A9118(int, u16, int);
extern void fn_801E3AA4(int);
extern void fn_801E5AD0(u8);
extern void fn_801E3A34(Color);
extern void fn_801E5430(short, short);
extern void fn_801E56AC(float, const char *, ...);
extern int fn_801E75A4(unsigned int, int);
extern void fn_801ED5F4(int, int, int, int, int, float);
extern int fn_80113E48(unsigned int);
extern int fn_80201B44();
extern void *fn_80201814();
extern unsigned int fn_8020216C(void);

void fn_80116B4C(void)
{
    PosList pos;
    Glyphs glyphs;
    unsigned int *slot;
    Pos *p;
    int i;
    int index;
    char *name;
    int type;
    int flags;

    pos = lbl_8023A63C;

    fn_801A852C(lbl_8064C2A8, 0, 0xD, 0x80000000);
    fn_801A9118(0, 0x13C, 5);
    fn_801A852C(lbl_8064C2A8, 0, 0x37, 0x80000000);
    fn_801A9118(0, 0x1A0, 5);
    fn_801A852C(lbl_8064C2A8, 0, 0x38, 0x80000000);
    fn_801A9118(0, 0x1A4, 5);
    fn_801A852C(lbl_8064C2A8, 0, 0x36, 0x80000000);
    fn_801A9118(0, 0x1A8, 5);
    fn_801A9118(0, 0x1AC, 5);
    fn_801A9118(0, 0x1B0, 5);
    fn_801A9118(0, 0x1B4, 5);
    fn_801A9118(0, 0x1B8, 5);
    fn_801E3AA4(0);
    fn_801E5AD0(0x63);

    for (i = 0; i < 5; i++) {
        slot = &lbl_80331748[i];
        p = &pos.p[i];
        fn_801E3A34(lbl_8064C2B0);
        if (slot[0x26] != 0) {
            index = fn_80113E48(slot[0x26]);
            if (index != -1) {
                glyphs = lbl_8064FF94;
                name = (char *)fn_801E75A4(slot[0x26] & 0x70000, 0) + 0x2C;
                type = fn_801E75A4(slot[0x26] & 0xF, 0);
                flags = 0x40;
                fn_801E5430(p->x, p->y);
                if ((lbl_80331748[index + 2] & 0x08000000) || (fn_80201B44(), fn_80201814(), fn_8020216C() & 0x4000)) {
                    fn_801E56AC(lbl_8064FF8C, lbl_8024DCF0[index]);
                } else {
                    fn_801E56AC(lbl_8064FF8C, lbl_8024E260, index + 1);
                }
                fn_801E5430(p->x, p->y + 0x28);
                switch (type) {
                case 0:
                    flags = 0x20;
                    break;
                case 1:
                    flags = 8;
                    break;
                case 2:
                    flags = 0x10;
                    break;
                }
                fn_801ED5F4(1, flags | 0x402, 1, 0, 0, lbl_8064FF7C);
                fn_801E56AC(lbl_8064FF98, lbl_8064B978, glyphs.c[type], name);
                fn_801ED5F4(0, 2, 1, 0, 0, lbl_8064FF7C);
            } else {
                fn_801E5430(p->x, p->y + 0x28);
                fn_801E56AC(lbl_8064FF8C, lbl_8064B980);
            }
        } else {
            fn_801E5430(p->x, p->y + 0x28);
            fn_801E56AC(lbl_8064FF8C, lbl_8064B980);
        }
    }
}

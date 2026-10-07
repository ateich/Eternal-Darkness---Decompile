typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Color { u8 r, g, b, a; } Color;
typedef struct Block52 { u32 word[13]; } Block52;

/* Menu data block at 0x8024CE40 (texture lists, name tables, format strings). */
typedef struct MenuData {
    u8 textures[0x310];        /* 0x000 */
    u8 textureList[0xAF8];     /* 0x310 */
    char *bitNames[3];         /* 0xE08: indexed by bit number - 16 */
    u8 padE14[0x9C];           /* 0xE14 */
    char *bookNames[12];       /* 0xEB0 */
    u8 padEE0[0x54C];          /* 0xEE0 */
    char bookNameFmt[0x28];    /* 0x142C */
    char bitFmt[0x18];         /* 0x1454 */
    char runeFmt[0x14];        /* 0x146C */
    char pageFmt[0xC];         /* 0x1480 */
    char bookIndexFmt[0x24];   /* 0x148C */
    char exitFmt[4];           /* 0x14B0 */
} MenuData;

extern MenuData lbl_8024CE40;
/* Journal state block at 0x80331748. */
typedef struct JournalState {
    unsigned int header[2];          /* 0x00 */
    unsigned int chapterFlags[24];   /* 0x08 */
    unsigned int bookFlags[12];      /* 0x68 */
} JournalState;

extern JournalState lbl_80331748;
extern int lbl_80331A08[];
extern const volatile unsigned int lbl_8023A414[12];
extern char lbl_8064B988[3];
extern char lbl_8064B98C[3];
extern Color lbl_8064C2A8;
extern Color lbl_8064C2B0;
extern Color lbl_8064C2BC;
extern void *lbl_8064C508;
extern unsigned char lbl_8064CD28;
extern int lbl_8064CD44;
extern unsigned int lbl_8064CD48;
extern unsigned int lbl_8064CD4C;
extern unsigned int lbl_8064CD50;
extern unsigned int lbl_8064CD54;
extern unsigned int lbl_8064CD60;
extern int lbl_8064CD68;
extern int lbl_8064CD6C;
extern void *lbl_8064CD80;
extern void *lbl_8064CDB0;
extern void *lbl_8064CDB4;
extern unsigned int lbl_8064CCD8;
extern const float lbl_8064FF78;
extern const float lbl_8064FF7C;

extern int fn_801E8D34(int);
extern int fn_801E8D3C(int);
extern int fn_801E8D44(int);
extern int fn_801E8D24(int);
extern int fn_801E75A4(unsigned int, int);
extern unsigned int fn_801E7578(unsigned int);
extern void fn_80119224(int, u8);
extern void fn_801F683C(Block52 *);
extern void fn_801F03F0(Block52 *, int);
extern void fn_80156C04(void);
extern void fn_801882C4(void);
extern void fn_80156CBC(void);
extern void fn_801882D0(void);
extern void fn_801ED3F4(void *);
extern void fn_801A8D38(int);
extern void fn_801A90BC(void *, void *);
extern void fn_801A872C(int, int, int, int, int, int, Color);
extern void fn_801A8974(int, int, int, int, int, int);
extern void fn_801A852C(Color, int, int, u32);
extern void fn_801A9118(int, u16, int);
extern void *fn_801E6CA0(void *, int, int, int, int);
extern void fn_80115D8C(unsigned int, unsigned int, int);
extern void fn_801E3AA4(int);
extern void fn_801E5AD0(u8);
extern void fn_801E3A34(Color);
extern void fn_801E5430(short, short);
extern void fn_801E56AC(float, const char *, ...);
extern void fn_801156D0(int);
extern void fn_801157B4(void);
extern void fn_80116490(int, int, u8);
extern void fn_80116838(int, int);
extern void fn_801168EC(int, int, int);
extern void fn_80116B4C(void);
extern unsigned int fn_80113CF8(unsigned int);
extern int fn_80113E48(unsigned int);
extern int fn_80201B44();
extern void *fn_80201814();
extern unsigned int fn_8020216C(void);

void fn_80116E88(u8 alpha)
{
    Block52 copy;
    Block52 source;
    int runeCount;
    int symbolMask;
    unsigned int i;
    int count;
    int sel;
    int max;
    int page;
    int total;
    int idx;
    unsigned int mask;
    MenuData *data = &lbl_8024CE40;

    runeCount = fn_801E75A4(lbl_8064CD4C & 0xF, fn_801E8D34(lbl_80331A08[2]));
    symbolMask = fn_801E75A4(lbl_8064CD4C & 0x3FF0, fn_801E8D34(lbl_80331A08[3]));
    fn_80119224(3, alpha);
    fn_801F683C(&source);
    copy = source;
    fn_801F03F0(&copy, 0);
    fn_80156C04();
    fn_801882C4();
    fn_80156CBC();
    fn_801882D0();
    fn_801ED3F4(lbl_8064CD80);
    fn_801A8D38(5);
    fn_801A90BC(data->textures, data->textureList);

    if (lbl_8064CD44 != 0) {
        switch (fn_801E8D34(lbl_80331A08[0])) {
        case 0:
            fn_801A872C(0xAE, 0xB4, 0x50, 0x2C, -0x7698, 2, lbl_8064C2BC);
            break;
        case 1:
            fn_801A872C(0xA7, 0xF8, 0x50, 0x2C, -0x7698, 2, lbl_8064C2BC);
            break;
        case 2:
            fn_801A872C(0xAD, 0x13B, 0x50, 0x2C, -0x7698, 2, lbl_8064C2BC);
            break;
        case 3:
            fn_801A872C(0xA7, 0x17F, 0x50, 0x2C, -0x7698, 2, lbl_8064C2BC);
            break;
        }
    }

    switch (lbl_8064CD44) {
    case 17:
        max = ((lbl_80331748.bookFlags[lbl_8064CD6C] & 0xF) << 1) + 3;
        fn_80115D8C(lbl_80331748.bookFlags[lbl_8064CD6C],
                    (lbl_8064CD68 < max ? lbl_8064CD68 : max) > 0 ? (lbl_8064CD68 < max ? lbl_8064CD68 : max) : 0,
                    0xFF);
        fn_801E3AA4(0);
        fn_801E5AD0(0x63);
        fn_801E3A34(lbl_8064C2B0);
        switch (max) {
        case 3:
            fn_801E5430(0x19D, 0x50);
            break;
        case 5:
            fn_801E5430(0x1A2, 0x32);
            break;
        case 7:
            fn_801E5430(0x1A2, 0x32);
            break;
        }
        fn_801E56AC(lbl_8064FF78, data->bookNameFmt, data->bookNames[lbl_8064CD6C]);
        break;
    case 0:
        sel = fn_801E8D34(lbl_80331A08[0]);
        if (lbl_8064CCD8 != 0) {
            sel = fn_801E75A4(lbl_8064CCD8, 0);
        }
        switch (sel) {
        case 0:
            fn_801A8974(0xAE, 0xB4, 0x50, 0x2C, -0x7698, 2);
            break;
        case 1:
            fn_801A8974(0xA7, 0xF8, 0x50, 0x2C, -0x7698, 2);
            break;
        case 2:
            fn_801A8974(0xAD, 0x13B, 0x50, 0x2C, -0x7698, 2);
            break;
        case 3:
            fn_801A8974(0xA7, 0x17F, 0x50, 0x2C, -0x7698, 2);
            break;
        }
        if (lbl_8064CCD8 == 0) {
            if (lbl_8064CDB4 == 0) {
                lbl_8064CDB4 = fn_801E6CA0(lbl_8064C508, 1, 8, 0, 1);
            }
            if (lbl_8064CDB0 == 0) {
                lbl_8064CDB0 = fn_801E6CA0(lbl_8064C508, 1, 5, 0, 1);
            }
        }
        break;
    case 1:
        lbl_8064CD60 = lbl_8064CD48;
    case 10:
    case 12:
    case 25:
        count = 0;
        idx = fn_801E8D34(lbl_80331A08[1]);
        if (lbl_8064CD44 == 10) {
            fn_80116490(0, 1, 100);
            fn_80116838(0, 0);
        } else if (lbl_8064CD44 == 12 || lbl_8064CD44 == 25) {
            fn_80116490(0, 1, 100);
            fn_80116838(1, 0);
        }
        fn_801ED3F4(lbl_8064CD80);
        fn_801A90BC(data->textures, data->textureList);
        for (i = 0; i <= 3; i++) {
            if (lbl_8064CD60 & (0x10000 << i)) {
                fn_801A852C(lbl_8064C2A8, 0, i + 0x58, 0x80000000);
                fn_801A9118(0, (count + 0x6F) * 4, 5);
                count++;
            }
        }
        fn_801156D0(idx);
        fn_801E3AA4(0);
        fn_801E3A34(lbl_8064C2B0);
        fn_801E5430(0xA8, 0x7A);
        fn_801E56AC(lbl_8064FF78, data->bitFmt, (data->bitNames - 16)[fn_801E75A4(lbl_8064CD60, idx)]);
        break;
    case 2:
        fn_80115D8C(lbl_8064CD50 | (runeCount << 4), lbl_8064CD54, 0x4B);
    case 11:
    case 13:
    case 26:
        if (lbl_8064CD44 == 13 || lbl_8064CD44 == 26) {
            fn_80116490(0, 1, 100);
            fn_80116838(1, 0);
        } else if (lbl_8064CD44 == 11) {
            fn_80116490(0, 1, 100);
            fn_80116838(0, 0);
        }
        fn_801ED3F4(lbl_8064CD80);
        fn_801A90BC(data->textures, data->textureList);
        fn_801168EC(0, 0, fn_801E7578(lbl_8064CD4C & 0xF));
        fn_801156D0(fn_801E8D34(lbl_80331A08[2]));
        fn_801E3AA4(0);
        fn_801E3A34(lbl_8064C2B0);
        fn_801E5430(0xA8, 0x7A);
        fn_801E56AC(lbl_8064FF78, data->runeFmt);
        break;
    case 3:
        page = fn_801E8D3C(lbl_80331A08[3]);
        total = fn_801E8D44(lbl_80331A08[3]) + 1;
        fn_80115D8C(lbl_8064CD50 | (symbolMask << (lbl_8064CD54 << 2)), lbl_8064CD54, lbl_8064CD28);
        fn_801168EC(0xF, page, page + 5 < total ? page + 5 : total);
        fn_801156D0(fn_801E8D24(lbl_80331A08[3]));
        fn_801E3AA4(0);
        fn_801E3A34(lbl_8064C2B0);
        if (page != 0) {
            fn_801E5430(0x9B, 0x46);
            fn_801E56AC(lbl_8064FF7C, lbl_8064B988);
        }
        if (page + 5 < total) {
            fn_801E5430(0x23F, 0x46);
            fn_801E56AC(lbl_8064FF7C, lbl_8064B98C);
        }
        fn_801E5430(0xA8, 0x7A);
        fn_801E56AC(lbl_8064FF78, data->pageFmt);
        break;
    case 4:
        idx = fn_80113E48(fn_80113CF8(lbl_8064CD50));
        max = ((lbl_8064CD50 & 0xF) << 1) + 3;
        fn_80115D8C(lbl_8064CD50, lbl_8064CD54, 0xFF);
        if (idx == -1) {
            break;
        }
        fn_801E3AA4(0);
        fn_801E5AD0(0x63);
        fn_801E3A34(lbl_8064C2B0);
        switch (max) {
        case 3:
            fn_801E5430(0x19D, 0x50);
            break;
        case 5:
            fn_801E5430(0x1A2, 0x32);
            break;
        case 7:
            fn_801E5430(0x1A2, 0x32);
            break;
        }
        if ((lbl_80331748.chapterFlags[idx] & 0x08000000) || (fn_80201B44(), fn_80201814(), fn_8020216C() & 0x4000)) {
            fn_801E56AC(lbl_8064FF78, data->bookNameFmt, data->bookNames[idx]);
        } else {
            fn_801E56AC(lbl_8064FF78, data->bookIndexFmt, idx + 1);
        }
        break;
    case 5:
        sel = 0;
        i = fn_801E8D34(lbl_80331A08[5]) * 3 + fn_801E8D34(lbl_80331A08[4]);
        fn_80201B44();
        fn_80201814();
        if (fn_8020216C() & 0x4000) {
            i = lbl_8023A414[i] & 0x70000;
        } else {
            i = lbl_80331748.chapterFlags[i] & 0x70000 & lbl_8064CD48;
        }
        for (mask = 0; mask <= 3; mask++) {
            if (i & (0x10000 << mask)) {
                fn_801A852C(lbl_8064C2A8, 0, mask + 0x58, 0x80000000);
                fn_801A9118(0, (sel + 0x6F) * 4, 5);
                sel++;
            }
        }
        fn_80116490(1, 1, alpha);
        break;
    case 18:
    case 19:
        sel = 0;
        i = fn_801E8D34(lbl_80331A08[5]) * 3 + fn_801E8D34(lbl_80331A08[4]);
        fn_80201B44();
        fn_80201814();
        if (fn_8020216C() & 0x4000) {
            i = lbl_8023A414[i] & 0x70000;
        } else {
            i = lbl_80331748.chapterFlags[i] & 0x70000 & lbl_8064CD48;
        }
        for (mask = 0; mask <= 3; mask++) {
            if (i & (0x10000 << mask)) {
                fn_801A852C(lbl_8064C2A8, 0, mask + 0x58, 0x80000000);
                fn_801A9118(0, (sel + 0x6F) * 4, 5);
                sel++;
            }
        }
        fn_80116490(0, 1, 100);
        fn_80116838(2, 1);
        break;
    case 23:
        fn_80116490(0, 1, 100);
        fn_80116838(1, 1);
        break;
    case 6:
        sel = 0;
        i = fn_801E8D34(lbl_80331A08[5]) * 3 + fn_801E8D34(lbl_80331A08[4]);
        fn_80201B44();
        fn_80201814();
        if (fn_8020216C() & 0x4000) {
            i = lbl_8023A414[i] & 0x70000;
        } else {
            i = lbl_80331748.chapterFlags[i] & 0x70000 & lbl_8064CD48;
        }
        for (mask = 0; mask <= 3; mask++) {
            if (i & (0x10000 << mask)) {
                fn_801A852C(lbl_8064C2A8, 0, mask + 0x58, 0x80000000);
                fn_801A9118(0, (sel + 0x6F) * 4, 5);
                sel++;
            }
        }
        fn_80116490(0, 1, 100);
        fn_80116838(fn_801E8D24(lbl_80331A08[6]), 1);
        break;
    case 20:
    case 21:
    case 22:
        fn_80116490(0, 0, 100);
        fn_80116838(2, 1);
        break;
    case 7:
    case 8:
    case 9:
        fn_80116490(0, 0, 100);
        fn_80116838(fn_801E8D24(lbl_80331A08[6]), 1);
        break;
    case 27:
        fn_801E3AA4(0);
        fn_801E3A34(lbl_8064C2B0);
        fn_801E5430(0xA8, 0x7A);
        fn_801E56AC(lbl_8064FF78, data->exitFmt);
        fn_801ED3F4(lbl_8064CD80);
        fn_801A90BC(data->textures, data->textureList);
    case 14:
    case 24:
    case 28:
        fn_80116B4C();
        break;
    case 15:
    case 16:
        fn_801157B4();
        break;
    }
}

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct Entry801B1A1C {
    u8 active;
    u8 pad;
    u16 id;
} Entry801B1A1C;

extern Entry801B1A1C lbl_80251858[];
extern s32 lbl_8064D370;
extern s32 lbl_8064D36C;
extern s32 lbl_8064D368;
extern s32 lbl_8064D354;
extern s32 lbl_8064D378;
extern s32 lbl_8064D374;
extern s32 lbl_8064D364;
extern s32 lbl_8064D360;
extern s32 lbl_8064D35C;
extern void fn_801AD404(s32, s32, s32);
extern void fn_801AD490(void);

void fn_801B1A1C(s32 id, s32 mode)
{
    Entry801B1A1C* entry = lbl_80251858;
    s32 i;

    if (mode != 0) {
        fn_801AD404(0, 0, mode);
        fn_801AD490();
    }

    lbl_8064D370 = -1;
    lbl_8064D354 = 1;
    lbl_8064D378 = 1;
    lbl_8064D374 = 1;
    lbl_8064D36C = id;
    lbl_8064D368 = 0;
    lbl_8064D364 = -2;
    lbl_8064D360 = -1;
    lbl_8064D35C = 255;

    for (i = 0; i < 538; i++, entry++) {
        if (entry->active == 0 && entry->id == id) {
            lbl_8064D370 = i;
            break;
        }
    }
}

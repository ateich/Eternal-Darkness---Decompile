typedef unsigned char u8;
typedef unsigned int u32;

extern void* lbl_8064D4BC;
extern void* lbl_8064D4C0;
extern void* lbl_8064D4C4;
extern void* lbl_8064D4C8;
extern void* lbl_8064D4CC;
extern u8 lbl_8064D4D0;
extern u8 lbl_8064D4D1;
extern u8 lbl_8064D4B8;
extern u8 lbl_8064D4D2;

void fn_801CA240(u32 flags)
{
    lbl_8064D4BC = 0;
    lbl_8064D4C0 = 0;
    lbl_8064D4C4 = 0;
    lbl_8064D4C8 = 0;
    lbl_8064D4CC = 0;
    lbl_8064D4D0 = 1;
    lbl_8064D4D1 = 3;
    lbl_8064D4B8 = 0;
    lbl_8064D4D2 = (flags & 2) != 0;
}

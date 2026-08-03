typedef int s32;
typedef unsigned int u32;

typedef struct GlobalState {
    char pad_0[0x10];
    u32 flags;
    char pad_14[0x1908];
    s32 field_191C;
} GlobalState;

extern s32 lbl_8064C62C;
extern s32 lbl_8064C630;
extern s32 lbl_8064C634;
extern s32 lbl_8064C638;
extern s32 lbl_8064C63C;
extern s32 lbl_8064C640;
extern s32 lbl_8064CBA0;
extern GlobalState lbl_803003C8;
extern void fn_801A96A8(s32, s32, s32);
extern void fn_801A9A40(s32, s32, s32);
extern void fn_80144430(s32, s32);

void fn_8001D5A8(void)
{
    fn_801A96A8(lbl_8064C638, 0, 0);
    if (lbl_8064C63C != 0) {
        lbl_803003C8.flags |= 1;
    } else {
        lbl_803003C8.flags &= 0xFFFFFFFEU;
    }

    lbl_8064CBA0 = lbl_8064C634;
    fn_801A9A40(2, lbl_8064C630, lbl_8064C630);
    fn_80144430(lbl_8064C640, 1);
    lbl_803003C8.field_191C = lbl_8064C62C;
}

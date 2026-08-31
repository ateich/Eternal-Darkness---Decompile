typedef signed long s32;
typedef unsigned long u32;

extern const float lbl_80650DFC;
extern const float lbl_80650E00;
extern const u32 lbl_80650DF8;

extern void fn_801ED5F4(s32, s32, s32, s32, s32, float);
extern void fn_801A872C(s32, s32, s32, s32, s32, s32, const u32*);
extern void fn_801A8D38(s32);

void fn_801A88D0(s32 x, s32 y, s32 width, s32 height, s32 depth, s32 inset)
{
    u32 color;

    fn_801ED5F4(1, 0x422, 1, 0, 0, lbl_80650DFC);
    color = lbl_80650DF8;
    fn_801A872C(x, y, width, height, depth, inset, &color);
    fn_801ED5F4(0, 2, 1, 0, 0, lbl_80650E00);
    fn_801A8D38(5);
}

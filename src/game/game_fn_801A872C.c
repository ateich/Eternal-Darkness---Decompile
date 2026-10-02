typedef signed short s16;
typedef signed long s32;
typedef unsigned long u32;

extern void fn_801A852C(u32*, s32, s32, u32);
extern void fn_801ECF50(u32);
extern void fn_80226AB4(u32, u32, u32);
extern void fn_801A9454(s32, s32, s32);
extern void fn_801A9450(void);

void fn_801A872C(s32 x, s32 y, s32 width, s32 height, s32 depth,
                 s32 inset, const u32* color)
{
    s16 left = x;
    s16 top = y;
    s16 right = left + width;
    s16 bottom = top + height;
    s32 topInset;
    s32 rightInset;
    s32 bottomInset;
    s32 leftInset;
    u32 copy = *color;

    fn_801A852C(&copy, 0, -1, 0x80000000);
    fn_801ECF50(4);
    fn_80226AB4(0x80, 5, 0x10);
    fn_801A9454((s16)x, (s16)y, (s16)depth);
    fn_801A9454(right, (s16)y, (s16)depth);
    inset = (s16)inset;
    topInset = top + inset;
    fn_801A9454(right, (s16)topInset, (s16)depth);
    fn_801A9454(left, (s16)topInset, (s16)depth);
    rightInset = right - inset;
    fn_801A9454((s16)rightInset, (s16)topInset, (s16)depth);
    fn_801A9454(right, (s16)topInset, (s16)depth);
    bottomInset = bottom - inset;
    fn_801A9454(right, (s16)bottomInset, (s16)depth);
    fn_801A9454((s16)rightInset, (s16)bottomInset, (s16)depth);
    fn_801A9454((s16)x, (s16)bottomInset, (s16)depth);
    fn_801A9454(right, (s16)bottomInset, (s16)depth);
    fn_801A9454(right, bottom, (s16)depth);
    fn_801A9454((s16)x, bottom, (s16)depth);
    fn_801A9454((s16)x, (s16)topInset, (s16)depth);
    leftInset = left + inset;
    fn_801A9454((s16)leftInset, (s16)topInset, (s16)depth);
    fn_801A9454((s16)leftInset, (s16)bottomInset, (s16)depth);
    fn_801A9454((s16)x, (s16)bottomInset, (s16)depth);
    fn_801A9450();
}

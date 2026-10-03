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
    s16 right = (s16)x + width;
    s16 bottom = (s16)y + height;
    s16 shortInset;
    s16 left = x;
    s16 top = y;
    s32 rightInset;
    s32 bottomInset;
    u32 copy = *color;

    fn_801A852C(&copy, 0, -1, 0x80000000);
    fn_801ECF50(4);
    fn_80226AB4(0x80, 5, 0x10);
    fn_801A9454((s16)x, (s16)y, (s16)depth);
    fn_801A9454(right, (s16)y, (s16)depth);
    shortInset = inset;
    top += shortInset;
    fn_801A9454(right, top, (s16)depth);
    fn_801A9454((s16)x, top, (s16)depth);
    rightInset = right - shortInset;
    fn_801A9454((s16)rightInset, top, (s16)depth);
    fn_801A9454(right, top, (s16)depth);
    bottomInset = bottom - shortInset;
    fn_801A9454(right, (s16)bottomInset, (s16)depth);
    fn_801A9454((s16)rightInset, (s16)bottomInset, (s16)depth);
    fn_801A9454((s16)x, (s16)bottomInset, (s16)depth);
    fn_801A9454(right, (s16)bottomInset, (s16)depth);
    fn_801A9454(right, bottom, (s16)depth);
    fn_801A9454((s16)x, bottom, (s16)depth);
    fn_801A9454((s16)x, top, (s16)depth);
    left += shortInset;
    fn_801A9454(left, top, (s16)depth);
    fn_801A9454(left, (s16)bottomInset, (s16)depth);
    fn_801A9454((s16)x, (s16)bottomInset, (s16)depth);
    fn_801A9450();
}

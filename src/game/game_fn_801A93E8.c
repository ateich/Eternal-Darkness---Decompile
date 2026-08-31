typedef signed long s32;

extern s32 lbl_8064CBA4;
extern const float lbl_80650E3C;

s32 fn_801A93E8(s32 value, s32 shift)
{
    if (lbl_8064CBA4 == 1) {
        s32 offset = 320 << shift;
        value = (s32)(lbl_80650E3C * (value - offset) + offset);
    }
    return value;
}

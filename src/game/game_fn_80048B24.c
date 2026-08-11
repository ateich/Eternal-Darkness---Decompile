typedef signed short s16;

extern float lbl_8064B4C0;
extern const float lbl_8064E398;
extern const float lbl_8064E3A8;

void fn_80048B24(s16 value)
{
    lbl_8064B4C0 = lbl_8064E3A8 * ((value + 100) / lbl_8064E398);
}

typedef unsigned char u8;
typedef unsigned int u32;

extern const volatile float lbl_806509F8;
extern const volatile float lbl_806509FC;
extern const double lbl_80650A00;

void fn_801859FC(u8* self, u8 value)
{
    float step = lbl_806509F8;
    u32 count = value;

    if (count > 2)
        step = lbl_806509FC / count;
    self[0] = value + 1;
    *(float*)(self + 0x2C) = step;
}

typedef unsigned int u32;
typedef signed int s32;

extern s32 lbl_8064CF10;

void fn_801252D8(s32 value)
{
    register u32 hid2;

    if (value == lbl_8064CF10)
        return;

    lbl_8064CF10 = value;
    hid2 = (value << 8) | 7;
    hid2 |= hid2 << 16;
    asm { mtspr 918, hid2 }
}

typedef unsigned char u8;

extern u8 lbl_803283E0[512];

void fn_800EEC0C(u8 *output, int value0, int value1, int value2)
{
    output[0] = lbl_803283E0[3];
    output[1] = lbl_803283E0[value0 >> 6];
    output[0x20] = lbl_803283E0[value1 >> 6];
    output[0x21] = lbl_803283E0[value2 >> 6];
}

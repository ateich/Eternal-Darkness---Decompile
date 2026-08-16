typedef unsigned char u8;

extern u8 lbl_803283E0[512];

void fn_800EEB44(void)
{
    int i;
    int value;
    int output;

    i = 0;
    value = -128;
    for (; i < 512; i++, value++) {
        if (value < 0) {
            output = 0;
        } else {
            output = 255;
            if (value <= 255) {
                output = value;
            }
        }
        lbl_803283E0[i] = output;
    }
}

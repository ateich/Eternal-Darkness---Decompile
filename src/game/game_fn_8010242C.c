typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

extern u8 lbl_8032CC08[];

void fn_8010242C(void)
{
    s32 i;
    s32 value;
    u8* clamp;
    s32* quantized;
    s32* reciprocal;

    clamp = lbl_8032CC08;
    for (i = -128; i < 384; i++) {
        if (i < 0) {
            value = 0;
        } else {
            if (i <= 255) {
                value = i;
            } else {
                value = 255;
            }
        }
        *clamp++ = value;
    }

    quantized = (s32*)(lbl_8032CC08 + 0x200);
    for (i = 0; i < 16; i++) {
        if (i == 0) {
            quantized[i] = 0;
        } else {
            quantized[i] = (4096 / (i << 4)) << 4;
        }
    }

    reciprocal = (s32*)(lbl_8032CC08 + 0x240);
    reciprocal[0] = 0;
    for (i = 1; i < 512; i++) {
        reciprocal[i] = 4096 / i;
    }
}

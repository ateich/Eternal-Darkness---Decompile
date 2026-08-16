typedef unsigned char u8;

extern u8 lbl_803281E0[];
extern void fn_800EEC0C(u8 *, int, int, int);

void fn_800EEC44(u8 *input, u8 *output, int width, int height)
{
    int rows = height >> 1;
    int y;
    u8 *middle = input + width * height;
    u8 *lower = middle + (width >> 1) * rows;

    for (y = 0; y < rows; y++) {
        u8 *top0 = input;
        u8 *top1 = input + width;
        int x;
        u8 *dst = output + ((y >> 1) * width * 16) + ((y & 1) ? 16 : 0);

        for (x = 0; x < (width >> 1); x++) {
            int cb = *lower++ - 128;
            int cr = *middle++ - 128;
            int blue = -52 * cb - 25 * cr + 0x2020;
            int green = 102 * cb + 129 * cr + 0x2020;
            int red = -25 * cb - 52 * cr + 0x2020;
            int lum = ((int)lbl_803281E0[*top0++] - 16) * 74;
            u8 *block = dst + ((x >> 1) * 64) + ((x & 1) ? 4 : 0);

            fn_800EEC0C(block, lum + green, lum + blue, lum + red);
            lum = ((int)lbl_803281E0[*top0++] - 16) * 74;
            fn_800EEC0C(block + 2, lum + green, lum + blue, lum + red);
            lum = ((int)lbl_803281E0[*top1++] - 16) * 74;
            fn_800EEC0C(block + 8, lum + green, lum + blue, lum + red);
            lum = ((int)lbl_803281E0[*top1++] - 16) * 74;
            fn_800EEC0C(block + 10, lum + green, lum + blue, lum + red);
        }
        input += width * 2;
    }
}

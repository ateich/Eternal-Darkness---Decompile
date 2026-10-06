typedef unsigned char u8;

extern u8 lbl_803281E0[];
extern void fn_800EEC0C(u8 *, int, int, int);

void fn_800EEC44(u8 *input, u8 *output, int width, int height)
{
    u8 *luma;
    u8 *u_plane;
    u8 *v_plane;
    int remaining;
    int row_count;
    int x;
    int y;
    u8 *row0;
    u8 *row1;
    u8 *dst;
    int red;
    int green;
    int blue;
    u8 *block;
    u8 *block2;
    int columns;
    int rows;
    int v;
    int u;
    int lum;

    columns = width >> 1;
    rows = height >> 1;
    luma = input;
    input += width * height;
    u_plane = input;
    input += columns * rows;
    v_plane = input;
    y = 0;
    row_count = rows;

    while (row_count > 0) {
        row0 = luma;
        luma += width;
        row1 = luma;
        dst = output + (y >> 1) * width * 16;
        dst += (y & 1) ? 16 : 0;
        remaining = columns;
        x = 0;
        while (remaining > 0) {
            v = *v_plane++ - 128;
            u = *u_plane++ - 128;
            red = 102 * v + 0x2020;
            green = (-25 * u) + (-52 * v) + 0x2020;
            block = dst + (x >> 1) * 64;
            block += (x & 1) ? 4 : 0;
            block2 = block + 8;
            blue = 129 * u + 0x2020;
            lum = ((int)lbl_803281E0[row0[0]] - 16) * 74;

            fn_800EEC0C(block, lum + red, lum + green, lum + blue);
            lum = ((int)lbl_803281E0[row0[1]] - 16) * 74;
            row0 += 2;
            fn_800EEC0C(block + 2, lum + red, lum + green, lum + blue);
            lum = ((int)lbl_803281E0[row1[0]] - 16) * 74;
            fn_800EEC0C(block2, lum + red, lum + green, lum + blue);
            lum = ((int)lbl_803281E0[row1[1]] - 16) * 74;
            row1 += 2;
            fn_800EEC0C(block2 + 2, lum + red, lum + green, lum + blue);
            x++;
            remaining--;
        }
        luma += width;
        row_count--;
        y++;
    }
}

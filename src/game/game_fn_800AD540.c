typedef unsigned char u8;
typedef unsigned short u16;

extern u8 lbl_8031D858[];
extern u16* lbl_8064D71C[2];
extern void fn_8015CBB0(void*, int, u8*);
extern void fn_8020B774(void*, int);

static int clamp_index(int value, int limit)
{
    if (value < 0) {
        return 0;
    }
    if (value > limit) {
        return limit;
    }
    return value;
}

static int mask_pixel(const u8* mask, int stride, int width, int height,
                      int x, int y)
{
    int cx = clamp_index(x, width - 1);
    int cy = clamp_index(y, height - 1);
    return (mask[cy * stride + (cx >> 3)] & (1 << (cx & 7))) != 0;
}

void fn_800AD540(void* source, int width, int height, int source_stride)
{
    int buffer_index;
    int y;
    int x;
    int mask_stride;
    int row_offset;
    int column_offset;

    fn_8015CBB0(source, source_stride, lbl_8031D858);

    for (buffer_index = 0; buffer_index < 2; buffer_index++) {
        u16* pixels = lbl_8064D71C[buffer_index] + 0x21E80;
        for (y = 0; y < 46; y++) {
            for (x = 0; x < 640; x++) {
                if (x == 0 || y == 0 || x == 639 || y == 45) {
                    pixels[x] = 0x2880;
                } else {
                    pixels[x] = 0x1080;
                }
            }
            pixels += 640;
        }
    }

    row_offset = ((480 - height) >> 1) * 640;
    column_offset = (((640 - width) >> 1) +
                     (unsigned int)((640 - width) >> 1) / 0x80000000U) >> 1;
    column_offset *= 2;
    mask_stride = width >> 3;

    for (buffer_index = 0; buffer_index < 2; buffer_index++) {
        u16* output = lbl_8064D71C[buffer_index] + row_offset + column_offset;
        for (y = 0; y < height; y++) {
            for (x = 0; x < width; x++) {
                int source_y = height - y - 1;
                int intensity = 0;
                int dx;
                int dy;

                if (mask_pixel(lbl_8031D858, mask_stride, width, height,
                               x, source_y)) {
                    intensity = 150;
                } else {
                    for (dy = -1; dy <= 1; dy++) {
                        for (dx = -1; dx <= 1; dx++) {
                            if ((dx != 0 || dy != 0) &&
                                mask_pixel(lbl_8031D858, mask_stride, width,
                                           height, x + dx, source_y + dy)) {
                                intensity += 20;
                            }
                        }
                    }
                    if (intensity > 150) {
                        intensity = 150;
                    }
                }
                output[x] = (u16)((intensity << 8) | 0x80);
            }
            output += 640;
        }
        fn_8020B774(lbl_8064D71C[buffer_index], 0x96000);
    }
}

typedef unsigned char u8;
typedef unsigned short u16;

extern u8 lbl_8031D858[];
extern u16* lbl_8064D71C[2];
extern void fn_8015CBB0(void*, int, u8*);
extern void fn_8020B774(void*, int);

#define POSITIVE_PART(v) ((v) & (((-(v) & ~(v))) >> 31))
#define CLAMP_INDEX(v, limit) \
    (POSITIVE_PART(v) > (limit) ? (limit) : POSITIVE_PART(v))
#define MASK_PIXEL(mask, stride, xmax, ymax, x, y) \
    ((mask)[CLAMP_INDEX((y), (ymax)) * (stride) + \
            (CLAMP_INDEX((x), (xmax)) >> 3)] & \
     (1 << (CLAMP_INDEX((x), (xmax)) & 7)))

void fn_800AD540(void* source, int width, int height, int source_stride)
{
    int buffer_index;
    u16 x;
    u16 y;
    int mask_stride;
    int row_offset;
    int column_offset;
    u8* mask = lbl_8031D858;

    fn_8015CBB0(source, source_stride, mask);

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
    column_offset = ((640 - width) >> 1) / 2;
    column_offset *= 2;
    mask_stride = width >> 3;

    for (buffer_index = 0; buffer_index < 2; buffer_index++) {
        u16* output = lbl_8064D71C[buffer_index] + row_offset + column_offset;
        for (y = 0; y < height; y++) {
            for (x = 1; x < width; x++) {
                int source_y = height - y - 1;
                int intensity = 0;
                if (MASK_PIXEL(mask, mask_stride, width - 1,
                               height - 1, x, source_y + 1)) {
                    intensity += 20;
                }
                if (MASK_PIXEL(mask, mask_stride, width - 1,
                               height - 1, x, source_y - 1)) {
                    intensity += 20;
                }
                if (MASK_PIXEL(mask, mask_stride, width - 1,
                               height - 1, x + 1, source_y + 1)) {
                    intensity += 20;
                }
                if (MASK_PIXEL(mask, mask_stride, width - 1,
                               height - 1, x + 1, source_y)) {
                    intensity += 20;
                }
                if (MASK_PIXEL(mask, mask_stride, width - 1,
                               height - 1, x + 1, source_y - 1)) {
                    intensity += 20;
                }
                if (MASK_PIXEL(mask, mask_stride, width - 1,
                               height - 1, x - 1, source_y + 1)) {
                    intensity += 20;
                }
                if (MASK_PIXEL(mask, mask_stride, width - 1,
                               height - 1, x - 1, source_y)) {
                    intensity += 20;
                }
                if (MASK_PIXEL(mask, mask_stride, width - 1,
                               height - 1, x - 1, source_y - 1)) {
                    intensity += 20;
                }
                if (MASK_PIXEL(mask, mask_stride, width - 1,
                               height - 1, x, source_y)) {
                    intensity = 150;
                }
                if (intensity > 150) {
                    intensity = 150;
                }
                output[x] = (u16)((intensity << 8) | 0x80);
            }
            output += 640;
        }
        fn_8020B774(lbl_8064D71C[buffer_index], 0x96000);
    }
}

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct ImageHeader {
    void* data;
    u16 width;
    u16 height;
    u8 horizontal_sampling;
    u8 vertical_sampling;
} ImageHeader;

int fn_80106AC0(ImageHeader* header)
{
    int raw_width = header->width;
    int width = raw_width / 4;
    int raw_height;
    int height;
    int sampled_width;
    int sampled_height;
    int sampled_area;
    int full_area;

    if (header->horizontal_sampling == 2) {
        sampled_width = width >> 1;
    } else {
        sampled_width = width;
    }
    raw_height = header->height;
    height = raw_height / 4;
    if (header->vertical_sampling == 2) {
        sampled_height = height >> 1;
    } else {
        sampled_height = height;
    }

    sampled_area = (sampled_width + 2) * (sampled_height + 2);
    full_area = (width + 2) * (height + 2);
    return 0x3CD0 + 2 * (full_area + 2 * sampled_area);
}

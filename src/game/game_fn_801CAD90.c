typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void fn_801CA7C0(int, int, int, int);

void fn_801CAD90(int control, int channel, int layer, u16 value)
{
    if ((u8)channel != 0xFF) {
        if ((u8)control < 0x40) {
            fn_801CA7C0((u8)control & 0x1F, channel, layer, (value >> 7) & 0xFF);
            fn_801CA7C0(((u8)control & 0x1F) + 0x20, channel, layer, value & 0x7F);
        } else if ((u8)(control - 0x80) <= 1) {
            fn_801CA7C0((u8)control & 0xFE, channel, layer, (value >> 7) & 0xFF);
            fn_801CA7C0(((u8)control & 0xFE) + 1, channel, layer, value & 0x7F);
        } else if ((u8)(control - 0x84) <= 1) {
            fn_801CA7C0((u8)control & 0xFE, channel, layer, (value >> 7) & 0xFF);
            fn_801CA7C0(((u8)control & 0xFE) + 1, channel, layer, value & 0x7F);
        } else {
            fn_801CA7C0(control, channel, layer, (value >> 7) & 0xFF);
        }
    }
}

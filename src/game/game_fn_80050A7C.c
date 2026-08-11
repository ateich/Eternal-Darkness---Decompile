typedef unsigned char u8;
typedef unsigned short u16;

extern int fn_800C9660(int value);
extern int lbl_8064D5A8;
extern int lbl_8064B4CC;

u16 fn_80050A7C(int value, u8* out_level)
{
    u16 results[5] = {0x181, 0x215, 0x216, 0x181, 0x22C};
    int index = fn_800C9660(value);

    if (out_level != 0) {
        int frame = lbl_8064D5A8;

        if (frame - 30 < lbl_8064B4CC) {
            *out_level = 50;
        } else {
            *out_level = 100;
        }
        lbl_8064B4CC = frame;
    }

    return results[index];
}

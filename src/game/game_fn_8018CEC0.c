typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 lbl_8023B078[4];
extern u16 lbl_80607120[];
extern u32 fn_800FBFB0(void);

void fn_8018CEC0(u32* dest, u8 count)
{
    u32 values[4];
    u32* second;
    int i;

    values[0] = lbl_8023B078[0];
    values[1] = lbl_8023B078[1];
    values[2] = lbl_8023B078[2];
    values[3] = lbl_8023B078[3];
    second = dest + lbl_80607120[1];

    for (i = 0; i < count; i++) {
        u32 random = fn_800FBFB0();
        dest[0] = values[random & 3];
        second[0] = dest[0];
        dest[1] = values[(random + 1) & 3];
        second[1] = dest[1];
        dest[2] = values[(random + 2) & 3];
        second[2] = dest[2];
        dest[3] = values[(random + 3) & 3];
        second[3] = dest[3];
        dest += 4;
        second += 4;
    }
}

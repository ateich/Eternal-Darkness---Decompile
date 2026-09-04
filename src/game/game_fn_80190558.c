typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;

extern u8 lbl_802FC5BC[];
extern const float lbl_80650B10;

void fn_80190558(u8* data)
{
    float value;

    data[1] = 0x40;
    *(u16*)(data + 4) = 0x24;
    value = lbl_80650B10;
    *(u16*)(data + 6) = 0x78;
    data[2] = 0xFF;
    ((s8*)data)[3] = -17;
    *(u32*)(data + 0x10) = *(u32*)(lbl_802FC5BC + 0xC);
    *(float*)(data + 0x14) = value;
    data[0x18] = 0xFF;
    data[0x19] = 0x9B;
    data[0x1A] = 0x11;
    data[0x1B] = 0xFF;
    ((s8*)data)[0x1D] = -5;
    *(u32*)(data + 0x20) = 0;
    *(u32*)(data + 0x24) = 0;
    *(float*)(data + 0x38) = value;
}

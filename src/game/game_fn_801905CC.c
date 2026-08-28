typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 lbl_802FC5BC[];
extern float lbl_80650B10;

void fn_801905CC(u8* data)
{
    float value;

    data[1] = 0x40;
    *(u16*)(data + 4) = 0x24;
    *(u16*)(data + 6) = 0x78;
    value = lbl_80650B10;
    data[2] = 0xFF;
    ((s8*)data)[3] = -5;
    *(u32*)(data + 0x10) = *(u32*)(lbl_802FC5BC + 0xC);
    data[0x14] = 0xFF;
    data[0x15] = 0x9B;
    data[0x16] = 0x11;
    data[0x17] = 0xFF;
    ((s8*)data)[0x19] = -5;
    *(u32*)(data + 0x1C) = 0;
    *(u32*)(data + 0x20) = 0;
    *(float*)(data + 0x34) = value;
}

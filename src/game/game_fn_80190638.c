typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 lbl_802FC5BC[];

void fn_80190638(u8* data)
{
    data[1] = 0x40;
    *(u16*)(data + 4) = 0x24;
    *(u16*)(data + 6) = 0;
    data[2] = 0xFF;
    ((s8*)data)[3] = -5;
    *(u32*)(data + 0x10) = *(u32*)(lbl_802FC5BC + 0xC);
    data[0x14] = 0x11;
    data[0x15] = 0xFF;
}

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 lbl_802FC5BC[];

void fn_8017ED64(u8* value)
{
    value[0] = 4;
    value[1] = 1;
    *(u16*)(value + 4) = 40;
    *(u16*)(value + 8) = 10;
    *(u16*)(value + 0x14) = 2;
    value[0x16] = 2;
    *(u16*)(value + 0x18) = 400;
    *(u32*)(value + 0x1C) = *(u32*)(lbl_802FC5BC + 0x18);
    *(u32*)(value + 0x20) = *(u32*)(lbl_802FC5BC + 0x14);
}

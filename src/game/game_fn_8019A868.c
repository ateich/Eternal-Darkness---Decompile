typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 lbl_802FC5BC[];

void fn_8019A868(u8* object)
{
    object[0] = 0x20;
    object[1] = 4;
    *(u16*)(object + 4) = 0x41;
    *(signed char*)(object + 3) = -17;
    *(u16*)(object + 8) = 40;
    *(u16*)(object + 6) = 300;
    *(u32*)(object + 0x10) = *(u32*)(lbl_802FC5BC + 0xc);
    *(u32*)(object + 0x14) = 0x40;
    object[0x18] = 1;
    object[0x19] = 7;
}

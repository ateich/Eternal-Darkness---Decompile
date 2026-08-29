typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned int u32;

extern u32 lbl_802FC5BC[];
void fn_8019CFC4(u8* object)
{
    object[0] = 7;
    object[1] = 4;
    *(u16*)(object + 4) = 0x41;
    object[2] = 0xFF;
    *(s8*)(object + 3) = -5;
    *(u32*)(object + 0xC) = 0;
    *(u32*)(object + 0x10) = lbl_802FC5BC[8];
    object[0x14] = 5;
    object[0x15] = 0xFF;
    *(u16*)(object + 0x16) = 30;
    *(float*)(object + 0x24) = 0.0873f;
    *(u16*)(object + 0x18) = 30;
    *(u16*)(object + 0x1A) = 30;
    *(u16*)(object + 0x1C) = 30;
}

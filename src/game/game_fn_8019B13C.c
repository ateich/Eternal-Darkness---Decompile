typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern const float lbl_80650BE8;

void fn_8019B13C(u8* object)
{
    object[0] = 1;
    object[1] = 12;
    *(u16*)(object + 4) = 0x35;
    *(u16*)(object + 6) = 0x78;
    object[2] = 0xAA;
    *(s8*)(object + 3) = -2;
    object[0x14] = 0xAA;
    object[0x15] = 100;
    object[0x16] = 2;
    object[0x17] = 0xAA;
    *(s8*)(object + 0x19) = -2;
    *(u32*)(object + 0x1C) = 1;
    *(u32*)(object + 0x20) = 1;
    *(u32*)(object + 0x24) = 0;
    *(u32*)(object + 0x28) = 0;
    object[0x18] = 0;
    *(float*)(object + 0x34) = lbl_80650BE8;
    *(u32*)(object + 0x38) = 0;
    object[0x3C] = 0;
    object[0x3D] = 0;
    object[0x3E] = 0;
}

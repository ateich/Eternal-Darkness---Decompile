typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 lbl_8064D18C;
static const float lbl_80650B20 = 0.0f;

void fn_80191360(u8* object)
{
    object[0] = 3;
    object[1] = 8;
    *(u16*)(object + 4) = 0x35;
    *(u16*)(object + 6) = 0x78;
    object[2] = 0xFF;
    *(signed char*)(object + 3) = -15;
    *(u32*)(object + 0xC) = 0;
    object[0x14] = 1;
    object[0x15] = 1;
    object[0x16] = 15;
    object[0x17] = 15;
    object[0x18] = 3;
    object[0x19] = 0;
    object[0x1A] = 0;
    object[0x1B] = 0;
    *(u16*)(object + 0x28) = 300;
    *(float*)(object + 0x34) = lbl_80650B20;
    *(float*)(object + 0x38) = lbl_80650B20;
    *(float*)(object + 0x3C) = lbl_80650B20;
    *(u32*)(object + 0x24) = 0;
    *(u32*)(object + 0x20) = 0;
    *(u32*)(object + 0x1C) = 0;
    *(u32*)(object + 0x2C) = 0;
    *(u32*)(object + 0x30) = lbl_8064D18C;
}

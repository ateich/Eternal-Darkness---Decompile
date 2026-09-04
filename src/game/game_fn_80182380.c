typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;

extern u8 lbl_802FC5BC[];
extern const float lbl_806509B8;

void fn_80182380(u8* descriptor)
{
    descriptor[0] = 0x20;
    descriptor[1] = 0x10;
    *(u16*)(descriptor + 4) = 0x3A;
    descriptor[2] = 0xF0;
    ((s8*)descriptor)[3] = -0x3C;
    *(u16*)(descriptor + 6) = 0x1F4;
    *(u16*)(descriptor + 8) = 0x32;
    *(u32*)(descriptor + 0x10) = *(u32*)(lbl_802FC5BC + 0xC);
    *(u16*)(descriptor + 0x14) = 0;
    *(u16*)(descriptor + 0x16) = 0;
    *(s16*)(descriptor + 0x18) = -1;
    descriptor[0x1E] = 0;
    *(u16*)(descriptor + 0x1A) = 4;
    *(u16*)(descriptor + 0x1C) = 4;
    descriptor[0x1F] = 4;
    descriptor[0x20] = 7;
    descriptor[0x21] = 0xFF;
    descriptor[0x22] = 0xFF;
    *(float*)(descriptor + 0x28) = lbl_806509B8;
    descriptor[0x24] = 0;
    descriptor[0x23] = 0;
    descriptor[0x25] = 0;
    descriptor[0x26] = 3;
    descriptor[0x27] = 0;
}

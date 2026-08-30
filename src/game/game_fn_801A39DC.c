typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

extern const float lbl_80650D40;
extern const float lbl_80650D44;
extern u32 lbl_8064D18C;

void fn_801A39DC(u8* descriptor)
{
    descriptor[0] = 3;
    descriptor[1] = 4;
    *(u16*)(descriptor + 4) = 0x31;
    descriptor[2] = 0xFF;
    *(signed char*)(descriptor + 3) = -5;
    *(u32*)(descriptor + 0xC) = 0;
    *(u16*)(descriptor + 0x36) = 30;
    *(float*)(descriptor + 0x30) = lbl_80650D40;
    descriptor[0x38] = 1;
    descriptor[0x39] = 1;
    descriptor[0x3A] = 12;
    descriptor[0x3B] = 12;
    descriptor[0x3C] = 3;
    descriptor[0x3D] = 0;
    *(u16*)(descriptor + 0x34) = 300;
    *(u32*)(descriptor + 0x20) = lbl_8064D18C;
    *(float*)(descriptor + 0x24) = lbl_80650D44;
    *(float*)(descriptor + 0x28) = lbl_80650D44;
    *(float*)(descriptor + 0x2C) = lbl_80650D44;
    descriptor[0x3E] = 200;
    descriptor[0x3F] = 3;
    *(u32*)(descriptor + 0x18) = 0;
    *(u32*)(descriptor + 0x14) = 0;
    descriptor[0x41] = 0;
}

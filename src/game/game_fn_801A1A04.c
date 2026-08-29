typedef unsigned char u8;
typedef unsigned short u16;

extern float lbl_80650D10;

void fn_801A1A04(void* descriptor_)
{
    u8* descriptor = descriptor_;
    float value;

    descriptor[0] = 1;
    descriptor[1] = 0x28;
    value = lbl_80650D10;
    descriptor[2] = 0xFF;
    *(signed char*)(descriptor + 3) = -5;
    *(u16*)(descriptor + 4) = 3;
    *(u16*)(descriptor + 8) = 0;
    *(u16*)(descriptor + 6) = 0;
    descriptor[0x19] = 0;
    *(float*)(descriptor + 0x14) = value;
    descriptor[0x18] = 1;
}

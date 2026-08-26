typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

void fn_8017F794(u8* value)
{
    value[0] = 4;
    value[1] = 4;
    *(u16*)(value + 4) = 38;
    value[2] = 250;
    *(signed char*)(value + 3) = -25;
    *(u16*)(value + 6) = 0;
    *(u16*)(value + 8) = 1;
    *(u16*)(value + 0x14) = 16;
    *(u32*)(value + 0x18) = 1;
}

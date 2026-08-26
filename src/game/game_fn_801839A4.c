typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

void fn_801839A4(u8* desc)
{
    desc[0] = 0x20;
    desc[1] = 6;
    desc[2] = 0xFC;
    *(s8*)(desc + 3) = -6;
    *(u16*)(desc + 4) = 7;
    desc[0x14] = 0;
}

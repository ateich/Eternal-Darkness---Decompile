typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned long u32;

void fn_8019A3A4(u8* object)
{
    object[0] = 8;
    object[1] = 4;
    *(u16*)(object + 4) = 0x57;
    object[2] = 0xff;
    *(s8*)(object + 3) = -15;
    *(u16*)(object + 6) = 300;
    *(u32*)(object + 0x18) = 0;
}

typedef unsigned char u8;
typedef unsigned short u16;

void fn_80182B84(u8* descriptor)
{
    descriptor[0] = 1;
    descriptor[1] = 8;
    descriptor[2] = 0xFA;
    *(signed char*)(descriptor + 3) = -10;
    *(u16*)(descriptor + 4) = 7;
    descriptor[0x14] = 1;
    descriptor[0x15] = 10;
    descriptor[0x16] = 0;
    descriptor[0x17] = 0x80;
}

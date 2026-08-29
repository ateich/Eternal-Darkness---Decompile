typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

void fn_80199EBC(u8* object)
{
    object[0] = 0x20;
    object[1] = 4;
    *(u16*)(object + 4) = 0x57;
    object[3] = 0x33;
    *(u16*)(object + 6) = 0x5a;
    *(u16*)(object + 0x1e) = 0x80;
    *(u16*)(object + 0x26) = 1;
    *(u16*)(object + 0x28) = 4;
    *(u32*)(object + 0x2c) = 0;
    *(u32*)(object + 0x14) = 0;
    *(u16*)(object + 0x1c) = 10;
}

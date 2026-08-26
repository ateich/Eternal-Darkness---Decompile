typedef unsigned char u8;
typedef unsigned short u16;

void fn_8017ED50(u8* object, u8* config)
{
    object[0x8C] = *(u16*)(config + 6);
    object[0x8D] = 0x2D;
}

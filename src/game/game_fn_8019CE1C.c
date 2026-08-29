typedef unsigned char u8;

void fn_8019CE1C(u8* object, u8 index, int mask)
{
    object[index + 0xAC] &= ~mask;
}

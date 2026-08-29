typedef unsigned char u8;

int fn_8019CE08(u8* object, u8 index, int mask)
{
    return mask & object[index + 0xAC];
}

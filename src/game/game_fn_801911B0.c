typedef unsigned char u8;

u8 fn_801911B0(u8* data, int index)
{
    return data[0x95] & (1 << index);
}

typedef unsigned char u8;
typedef unsigned int u32;

u32 fn_80180430(u32* bits, u32 index)
{
    return (1 << ((u8)index - (index & 0xE0))) & bits[(u8)index >> 5];
}

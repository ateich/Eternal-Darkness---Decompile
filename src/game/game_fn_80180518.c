typedef unsigned char u8;
typedef unsigned int u32;

void fn_80180518(u32* bits, u32 index, int value)
{
    u32* word = bits + ((u8)index >> 5);
    u32 mask;

    index = (u8)index - (index & 0xE0);
    mask = 1 << index;

    *word |= mask;
    if (value == 0) {
        *word &= ~mask;
    }
}

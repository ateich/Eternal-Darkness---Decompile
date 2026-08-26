typedef unsigned char u8;
typedef unsigned int u32;

void fn_801806D4(u8* data, u32* source, int index)
{
    index *= 4;
    data += index;
    *(u32*)(data + 8) = *source;
}

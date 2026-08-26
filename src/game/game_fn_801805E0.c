typedef unsigned char u8;
typedef unsigned int u32;

void fn_801805E0(u8* data, int count, u8 value, u32 unused, u32* source,
                 float scale)
{
    int i;

    data[0] = count;
    data[1] = value;
    data[3] = value;
    data[2] = value * scale;
    data[4] = 0;

    for (i = 0; i < (u8)count; i++) {
        ((u32*)data)[i + 2] = *source;
    }
}

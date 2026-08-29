typedef unsigned char u8;
typedef unsigned int u32;

void fn_8019A5C8(u8* object, u8* config)
{
    *(u32*)(object + 0x9C) = *(u32*)(config + 0x14);
    *(u32*)(object + 0x8C) = 1;
}

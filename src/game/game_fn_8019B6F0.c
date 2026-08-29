typedef unsigned char u8;
typedef unsigned int u32;

void fn_8019B6F0(u8* object, u8* config)
{
    object[0x8C] = config[0x14];
    object[0x8D] = config[0x15];
    object[0x8F] = config[0x19];
    *(u32*)(object + 0x90) = *(u32*)(config + 0x1C);
    *(u32*)(object + 0x98) = *(u32*)(config + 0x20);
    object[0x8E] = config[0x18];
    *(u32*)(object + 0x94) = 1;
    *(u32*)(object + 0xA0) = *(u32*)(config + 0x3C);
    *(u32*)(object + 0x9C) = 0;
}

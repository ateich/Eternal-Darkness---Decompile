typedef unsigned char u8;
typedef unsigned long u32;

void fn_801997E8(u8* object, u8* config)
{
    object[0x8c] = config[0x14];
    object[0x8d] = config[0x15];
    object[0x8e] = config[0x16];
    object[0x8f] = config[0x17];
    object[0x90] = config[0x18];
    object[0x91] = 0;
    object[0x92] = 7;
    *(u32*)(object + 0x94) = 0;
    *(u32*)(object + 0x98) = 1;
    *(u32*)(object + 0x9c) = 0;
    *(u32*)(object + 0xa0) = 0;
    *(u32*)(object + 0xa4) = *(u32*)(config + 0x1c);
    *(u32*)(object + 0xa8) = *(u32*)(config + 0x24);
    *(u32*)(object + 0xac) = *(u32*)(config + 0x28);
    *(u32*)(object + 0xb0) = *(u32*)(config + 0x2c);
    *(u32*)(object + 0xb4) = *(u32*)(config + 0x30);
    *(u32*)(object + 0xb8) = *(u32*)(config + 0x34);
}

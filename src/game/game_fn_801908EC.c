typedef unsigned char u8;
typedef unsigned int u32;

void fn_801908EC(u8* data, u8* config)
{
    *(float*)(data + 0x8C) = *(float*)(config + 0x14);
    data[0x90] = config[0x18];
    data[0x91] = config[0x19];
    data[0x93] = config[0x1D];
    *(u32*)(data + 0x94) = *(u32*)(config + 0x20);
    *(u32*)(data + 0x9C) = *(u32*)(config + 0x24);
    data[0x92] = config[0x1C];
    *(u32*)(data + 0x98) = 1;
}

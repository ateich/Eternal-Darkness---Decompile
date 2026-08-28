typedef unsigned char u8;
typedef unsigned int u32;

extern void* memset(void*, int, u32);

void fn_80191BA8(u8* object, u8* config)
{
    object[0x8D] = config[0x14];
    object[0x8E] = config[0x15];
    object[0x8F] = config[0x16];
    object[0x90] = config[0x17];
    object[0x91] = config[0x19];
    object[0x92] = config[0x1A];
    if (config[0x1A] == 0) {
        object[0x94] = config[0];
    } else {
        object[0x94] = 0;
    }
    object[0x93] = 0;
    object[0x8C] = 1;
    if (*(int*)(config + 0x24) != 0) {
        object[0x8C] |= 2;
    }
    if (*(int*)(config + 0x20) != 0) {
        object[0x8C] |= 8;
        object[0x8C] |= 0x10;
    }
    *(u32*)(object + 0x98) = *(u32*)(config + 0x2C);
    memset(object + 0x9C, 0, 0x1C);
    object[0x95] = 0;
}

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

void fn_8019AAB4(u8* object, u8* config)
{
    *(u32*)(object + 0x8C) = *(u32*)(config + 0x14);
    *(u32*)(object + 0x90) = *(u32*)(config + 0x14) * 2 - 1;
    *(u16*)(object + 0x94) = *(u16*)(config + 8);
    object[0x96] = 0;
    object[0x97] = config[0x18];
    object[0x98] = config[0x19];
}

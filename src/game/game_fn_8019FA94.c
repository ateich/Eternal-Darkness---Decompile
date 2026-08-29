typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

void fn_8019FA94(u8* obj, u8* config)
{
    obj[0x92] = config[0x1A];
    *(u16*)(obj + 0x90) = *(u16*)(config + 0x18);
    *(u32*)(obj + 0x8C) = *(u32*)(config + 0x14);
    *(u32*)(obj + 0x94) = 0;
}

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void* memcpy(void*, const void*, unsigned long);

void fn_801A4880(u8* object, u8* config)
{
    *(u16*)(object + 0x9a) = *(u16*)(config + 0x22);
    memcpy(object + 0x9c, config + 0x2a, 6);
    *(u32*)(object + 0x8c) = *(u32*)(config + 0x14);
    object[0x98] = config[0x20];
    *(u32*)(object + 0x90) = 1;
    *(u32*)(object + 0xa4) = *(u32*)(config + 0x34);
}

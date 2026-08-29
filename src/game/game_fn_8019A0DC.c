typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned long u32;

extern void* memcpy(void*, const void*, unsigned long);

void fn_8019A0DC(u8* object, u8* config)
{
    *(u16*)(object + 0x96) = *(u16*)(config + 0x1e);
    memcpy(object + 0x98, config + 0x20, 6);
    *(s16*)(object + 0x9e) = *(s16*)(config + 0x26);
    *(s16*)(object + 0xa0) = *(s16*)(config + 0x28);
    *(u32*)(object + 0x8c) = *(u32*)(config + 0x14);
    *(u32*)(object + 0x90) = 1;
    *(u16*)(object + 0x94) = *(u16*)(config + 0x1c);
}

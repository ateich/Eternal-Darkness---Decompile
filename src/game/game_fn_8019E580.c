typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

void fn_8019E580(u8* obj, u8* config)
{
    u16 halfHeight = *(u16*)(config + 0x16) >> 1;
    u16 halfWidth = *(u16*)(config + 0x14) >> 1;

    *(s16*)(obj + 0x94) = *(s16*)(obj + 0x10) + halfWidth;
    *(s16*)(obj + 0x96) = *(s16*)(obj + 0x10) - halfWidth;
    *(s16*)(obj + 0x98) = *(s16*)(obj + 0x12) + halfHeight;
    *(s16*)(obj + 0x9A) = *(s16*)(obj + 0x12) - halfHeight;
    *(u32*)(obj + 0x8C) = *(u32*)(config + 0x18);
    *(s16*)(obj + 0x92) = -10;
    *(u8*)(obj + 0x90) = 1;
}

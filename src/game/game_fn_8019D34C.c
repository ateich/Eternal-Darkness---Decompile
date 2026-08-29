typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;

extern const float lbl_80650C3C;

void fn_8019D34C(u8* object, u8* config)
{
    *(u32*)(object + 0x9C) = *(u32*)(config + 0x20);
    *(u32*)(object + 0x8C) = 1;
    *(s16*)(object + 0x94) = *(s16*)(config + 0x16);
    *(float*)(object + 0xA0) = lbl_80650C3C;
    *(float*)(object + 0xA4) = *(float*)(config + 0x24);
    *(s16*)(object + 0x96) = *(s16*)(config + 0x18);
    *(s16*)(object + 0x98) = *(s16*)(config + 0x1A);
    *(s16*)(object + 0x9A) = *(s16*)(config + 0x1C);
}

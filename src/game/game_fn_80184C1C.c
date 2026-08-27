typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

void fn_80184C1C(u8* self, u8* desc)
{
    *(u32*)(self + 0x8C) = *(u32*)(desc + 0x18);
    self[0x90] = desc[0];
    self[0x91] = 8;
    self[0x92] = 0;
    *(u32*)(self + 0x94) = *(u32*)(desc + 8);
    *(s16*)(self + 0x98) = *(s16*)(self + 0x10);
    *(s16*)(self + 0x9A) = *(s16*)(self + 0x12);
    *(s16*)(self + 0x9C) = *(s16*)(self + 0x14);
    *(s16*)(self + 0x9E) = *(s16*)(self + 0x10);
    *(s16*)(self + 0xA0) = *(s16*)(self + 0x12);
    *(s16*)(self + 0xA2) = *(s16*)(self + 0x14);
    *(u16*)(self + 0xA4) = 0;
}

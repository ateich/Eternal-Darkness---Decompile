typedef unsigned char u8;
typedef signed short s16;

void fn_80182E64(u8* self, const u8* desc)
{
    self[0x8E] = desc[0x16];
    *(s16*)(self + 0x8C) = *(s16*)(self + 0x14) + desc[0x15];
    self[0x8F] = desc[0x14];
    self[0x90] = 1;
}

typedef signed short s16;
typedef unsigned char u8;

void fn_80184C7C(u8* self, s16* value)
{
    *(s16*)(self + 0x98) = value[0];
    *(s16*)(self + 0x9A) = value[1];
    *(s16*)(self + 0x9C) = value[2];
}

typedef unsigned char u8;

void fn_80186A80(u8* self, u8 mode)
{
    self[0x8D] = mode;
}

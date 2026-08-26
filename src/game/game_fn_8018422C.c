typedef unsigned char u8;

void fn_8018422C(u8* self, u8* desc)
{
    self[0x8C] = desc[0x14];
    self[0x8D] = desc[0x15];
    self[0x8E] = 0;
    self[0x8F] = 0;
}

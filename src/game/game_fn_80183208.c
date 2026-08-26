typedef unsigned char u8;

void fn_80183208(u8* self, const u8* descriptor)
{
    self[0x8C] = 0;
    self[0x8D] = 4;
    self[0x8E] = 0x24;
    self[0x8F] = descriptor[1];
}

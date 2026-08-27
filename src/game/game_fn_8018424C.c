typedef unsigned char u8;
typedef unsigned short u16;

void fn_8018424C(u8* self, u8* desc)
{
    int i;
    u8 shift = desc[0x17];

    self[0x8C] = desc[0x14];
    self[0x8D] = desc[0x15];
    self[0x8E] = desc[0x18];
    self[0x8F] = desc[0x19];
    self[0x90] = desc[0x16];
    *(u16*)(self + 0x92) = *(u16*)(desc + 0x1A);

    for (i = 0; i < desc[0]; i++) {
        *(u16*)(self + 0x94 + i * 2) = i << shift;
    }
}

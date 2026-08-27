typedef unsigned char u8;
typedef unsigned short u16;

void fn_801869E4(u8* self, u16 first, u16 second, u8 mode)
{
    *(u16*)(self + 0x92) = first;
    *(u16*)(self + 0x94) = second;
    self[0x8D] = mode;
    *(u16*)(self + 0x9A) = first;
}

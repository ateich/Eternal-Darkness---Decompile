typedef unsigned short u16;

void fn_801850E4(unsigned char* self)
{
    u16 flags = *(u16*)(self + 0xA4);

    if (!(flags & 0x10)) {
        *(u16*)(self + 0xA4) = flags | 8;
    }
}

typedef unsigned char u8;
typedef unsigned short u16;

void fn_8012C370(u8* state)
{
    *(u16*)(state + 0xA) &= ~0x12;
    *(u16*)(state + 0x5A) = 0;
    *(u16*)(state + 0x5C) = 0;
    *(u16*)(state + 0x5E) = 0;
    *(u16*)(state + 0x54) = 0;
    *(u16*)(state + 0x56) = 0;
    *(u16*)(state + 0x58) = 0;
    *(u16*)(state + 0x60) = 0;
    *(u16*)(state + 0x62) = 0;
    *(u16*)(state + 0x64) = 0;
    *(u16*)(state + 0x66) = 0;
    *(u16*)(state + 0x68) = 0;
    *(u16*)(state + 0x6A) = 0;
}

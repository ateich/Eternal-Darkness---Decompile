typedef unsigned char u8;
typedef unsigned short u16;

void fn_8012C328(u8* state)
{
    *(u16*)(state + 0xA) &= ~0x24;
    *(u16*)(state + 0x42) = 0;
    *(u16*)(state + 0x44) = 0;
    *(u16*)(state + 0x46) = 0;
    *(u16*)(state + 0x3C) = 0;
    *(u16*)(state + 0x3E) = 0;
    *(u16*)(state + 0x40) = 0;
    *(u16*)(state + 0x48) = 0;
    *(u16*)(state + 0x4A) = 0;
    *(u16*)(state + 0x4C) = 0;
    *(u16*)(state + 0x4E) = 0;
    *(u16*)(state + 0x50) = 0;
    *(u16*)(state + 0x52) = 0;
}

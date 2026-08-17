typedef unsigned char u8;
typedef unsigned short u16;
void fn_8012C444(u8* state)
{
    *(unsigned int*)(state + 0x3C) = *(unsigned int*)(state + 0x42);
    *(u16*)(state + 0x40) = *(u16*)(state + 0x46);
}

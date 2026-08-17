typedef unsigned char u8;
typedef unsigned short u16;
void fn_8012C458(u8* state)
{
    *(unsigned int*)(state + 0x54) = *(unsigned int*)(state + 0x5A);
    *(u16*)(state + 0x58) = *(u16*)(state + 0x5E);
}

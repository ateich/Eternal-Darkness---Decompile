typedef unsigned char u8;
typedef unsigned short u16;

void fn_801978F8(u8* object, u16 value)
{
    *(u16*)(object + 8) = value;
}

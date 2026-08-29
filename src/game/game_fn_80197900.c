typedef unsigned char u8;
typedef unsigned short u16;

void fn_80197900(u8* object, u16 value)
{
    if (object != 0)
        *(u16*)(object + 0x94) = value;
}

typedef unsigned char u8;
typedef unsigned short u16;

extern u8* fn_8015C28C(int);

u16 fn_8015AB68(int index)
{
    return *(u16*)(fn_8015C28C(index) + 0x80);
}

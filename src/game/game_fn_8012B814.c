typedef unsigned char u8;
typedef unsigned short u16;

u16 fn_8012B814(u8* owner)
{
    return *(u16*)(*(u8**)(owner + 0x3C) + 0xC);
}

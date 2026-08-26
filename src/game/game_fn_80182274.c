typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

void fn_80182274(u8* object, u8* descriptor)
{
    object[0x8C] = *(u16*)(descriptor + 6);
    object[0x8D] = 5;
    *(u32*)(object + 0x90) = *(u32*)(descriptor + 0x18);
}

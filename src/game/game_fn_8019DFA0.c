typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;

void fn_8019DFA0(u8* object)
{
    object[0] = 8;
    *(u16*)(object + 8) = 0x800;
    object[1] = 20;
    *(u16*)(object + 4) = 0;
    object[2] = 250;
    ((s8*)object)[3] = -5;
    *(u16*)(object + 6) = 500;
    *(u16*)(object + 0x14) = 640;
    *(u16*)(object + 0x16) = 480;
    *(u32*)(object + 0x18) = 1;
    *(u32*)(object + 0x1C) = 1;
}

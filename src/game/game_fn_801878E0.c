typedef unsigned char u8;
typedef unsigned short u16;

void fn_801878E0(void* object)
{
    u8* p = (u8*)object;
    *(float*)(p + 0xB8) = p[0xE2];
    *(float*)(p + 0xBC) = p[0xE3];
    *(float*)(p + 0xC0) = p[0xE4];
    *(u16*)(p + 0xE0) = 0;
    *(float*)(p + 0xC8) = p[0x8D] >> 1;
}

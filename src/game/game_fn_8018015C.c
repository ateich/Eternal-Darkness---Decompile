typedef unsigned char u8;
typedef unsigned int u32;

u8 fn_8018015C(void* object, u32 index)
{
    u8* entries = *(u8**)((char*)object + 0x4C);
    return entries[(u8)index * 0x38];
}

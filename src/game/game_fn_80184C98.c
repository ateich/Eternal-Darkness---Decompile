typedef unsigned char u8;
typedef unsigned int u32;

extern void* memcpy(void*, const void*, u32);

void fn_80184C98(u8* self, void* value)
{
    memcpy(*(u8**)(self + 0x4C) + 0xA, value, 6);
}

typedef unsigned int u32;

extern void* memcpy(void*, const void*, u32);

void fn_80184884(void* object, const void* value)
{
    memcpy((char*)object + 0x2C, value, 4);
}

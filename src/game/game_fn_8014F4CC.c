typedef unsigned char u8;
typedef unsigned int u32;

extern void fn_8014F53C(void);
extern void fn_8019AF2C(void);
extern void fn_80149B60(void);
extern void* memset(void*, int, unsigned int);

void fn_8014F4CC(u8* first, u8* second)
{
    *(void**)(first + 0x90) = fn_8019AF2C;
    *(u32*)(first + 0x94) = 0;
    *(void**)(first + 0x98) = fn_8014F53C;
    *(u32*)(first + 0x9C) = 0;
    *(void**)(first + 0xA0) = fn_80149B60;
    *(u32*)(first + 0xA4) = 0;
    first[0xBC] = 4;
    second[0] = 1;
    memset(second + 0x88, 0, 0x40);
}

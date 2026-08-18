typedef unsigned char u8;
typedef unsigned int u32;

extern void fn_80149748(void);
extern void fn_8019CEF8(void);
extern void fn_80149B60(void);
extern void* memset(void*, int, unsigned int);

void fn_801540EC(u8* object, u8* resource)
{
    *(void**)(object + 0x90) = fn_8019CEF8;
    *(u32*)(object + 0x94) = 0;
    *(void**)(object + 0x98) = fn_80149748;
    *(u32*)(object + 0x9C) = 0;
    *(void**)(object + 0xA0) = fn_80149B60;
    *(u32*)(object + 0xA4) = 0;
    object[0xBC] = 1;
    resource[0] = 1;
    memset(resource + 0x88, 0, 0x40);
}

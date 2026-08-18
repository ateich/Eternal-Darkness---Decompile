typedef unsigned char u8;
typedef unsigned int u32;

extern void fn_801A1BD0(void);
extern void fn_801A19BC(void);
extern void fn_801A1AB0(void);
extern void fn_80154428(void);
extern void fn_80149B60(void);
extern void* memset(void*, int, unsigned int);

void fn_801541BC(u8* object, u8* resource, u8 alternate, u8 kind)
{
    *(void**)(object + 0x90) = fn_801A1BD0;
    if (alternate)
        *(void**)(object + 0x94) = fn_801A19BC;
    else
        *(void**)(object + 0x94) = fn_801A1AB0;
    *(void**)(object + 0x98) = fn_80154428;
    *(u32*)(object + 0x9C) = 0;
    *(void**)(object + 0xA0) = fn_80149B60;
    *(u32*)(object + 0xA4) = 0;
    object[0xBC] = 1;
    object[0xBE] = kind;
    resource[0] = 1;
    memset(resource + 0x88, 0, 0x40);
}

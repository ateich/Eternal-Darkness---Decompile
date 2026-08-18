typedef unsigned char u8;
typedef unsigned int u32;

extern void fn_801A42A0(void);
extern void fn_80155644(void);
extern void fn_80149B60(void);
extern void* memset(void*, int, unsigned int);

void fn_801555D4(u8* work, u8* object)
{
    *(u32*)(work + 0x90) = (u32)fn_801A42A0;
    *(u32*)(work + 0x94) = 0;
    *(u32*)(work + 0x98) = (u32)fn_80155644;
    *(u32*)(work + 0x9c) = 0;
    *(u32*)(work + 0xa0) = (u32)fn_80149B60;
    *(u32*)(work + 0xa4) = 0;
    work[0xbc] = 4;
    object[0] = 1;
    memset(object + 0x88, 0, 0x40);
}

typedef unsigned char u8;
typedef unsigned int u32;

extern void fn_801A1B34(void);
extern void fn_801A1A04(void);
extern void fn_80148874(void);
extern void fn_80154428(void);
extern void fn_80149B60(void);
extern void* memset(void*, int, u32);

void fn_80154A14(void* object, void* data, u8 alternate)
{
    *(void**)((char*)object + 0x90) = fn_801A1B34;
    *(void**)((char*)object + 0x94) = fn_801A1A04;
    *(void**)((char*)object + 0x98) = alternate ? fn_80154428 : fn_80148874;
    *(u32*)((char*)object + 0x9C) = 0;
    *(void**)((char*)object + 0xA0) = fn_80149B60;
    *(u32*)((char*)object + 0xA4) = 0;
    *(u8*)((char*)object + 0xBC) = 1;
    *(u8*)data = 1;
    memset((char*)data + 0x88, 0, 0x40);
}

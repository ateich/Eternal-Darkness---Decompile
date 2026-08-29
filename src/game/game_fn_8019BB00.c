typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void fn_8019F1D8(void*, void*, int, u8, s8, int);
extern int fn_8019BAA8(void*);

int fn_8019BB00(u8* object)
{
    if (*(u16*)(object + 0xA) >= *(u16*)(object + 0xC)) {
        u8* entry = *(u8**)(object + 0x4C) + 0x21;
        fn_8019F1D8(object + 0xA0, entry, 1, *entry, -object[0xA2], 0);
        *(u32*)(object + 0x14C) = (u32)fn_8019BAA8;
    }
    (*(u16*)(object + 0xA))++;
    return 0;
}

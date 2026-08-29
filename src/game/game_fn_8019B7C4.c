typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void fn_8018E24C(void*, u8, int);
extern void fn_8018E230(void*, void*, int, u8, u8, int);
extern u8 fn_8018E26C(void*, void*);
extern void fn_8018E1C4(void*, u8, u8, u8);
extern int fn_8019B8B4(void*);

int fn_8019B7C4(u8* object)
{
    u8* entry = *(u8**)(object + 0x4C);

    if ((*(int*)(object + 0x90) == 0 &&
         *(u16*)(object + 0xA) >= *(u16*)(object + 0xC)) ||
        *(int*)(object + 0x94) == 0) {
        if (*(int*)(object + 0x98) != 0) {
            fn_8018E24C(entry, object[4], 0);
        } else {
            fn_8018E230(entry, entry + 0x2B, 1, object[2], object[4], 0);
        }
        *(u32*)(object + 0x14C) = (u32)fn_8019B8B4;
    } else if (entry[0] == 4) {
        fn_8018E26C(entry, entry + 0x2B);
    } else if (*(int*)(object + 0x98) != 0 &&
               *(u16*)(object + 0xA) >= object[0x8E]) {
        fn_8018E1C4(object, object[0x8C], object[0x8F], object[0x8D]);
    }
    (*(u16*)(object + 0xA))++;
    return 0;
}

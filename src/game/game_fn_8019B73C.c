typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 fn_8018E26C(void*, void*);
extern void fn_8018E1C4(void*, u8, u8, u8);
extern int fn_8019B7C4(void*);

int fn_8019B73C(u8* object)
{
    u8* entry = *(u8**)(object + 0x4C);

    if (fn_8018E26C(entry, entry + 0x2B) == 0) {
        if (*(int*)(object + 0x98) != 0 &&
            *(u16*)(object + 0xA) >= object[0x8E]) {
            fn_8018E1C4(object, object[0x8C], object[0x8F], object[0x8D]);
        }
        *(u32*)(object + 0x14C) = (u32)fn_8019B7C4;
    }
    (*(u16*)(object + 0xA))++;
    return 0;
}

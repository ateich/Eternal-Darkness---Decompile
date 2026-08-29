typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 fn_8019F1EC(void*, void*);
extern int fn_8019BB00(void*);

int fn_8019B914(u8* object)
{
    u8* entry = *(u8**)(object + 0x4C);

    if (fn_8019F1EC(object + 0xA0, entry + 0x21) == 0) {
        *(u32*)(object + 0x14C) = (u32)fn_8019BB00;
    }
    (*(u16*)(object + 0xA))++;
    return 0;
}

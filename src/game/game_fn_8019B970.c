typedef unsigned char u8;
typedef unsigned short u16;

extern u8 fn_8019F1EC(void*, void*);
extern u8 fn_8018E26C(void*, void*);

int fn_8019B970(u8* object)
{
    u8* entry = *(u8**)(object + 0x4C);

    if (*(u8*)(object + 0xA0) != 0) {
        fn_8019F1EC(object + 0xA0, entry + 0x21);
    }
    if (fn_8018E26C(entry, entry + 0x2B) == 0 || *(u16*)(object + 0xA) > 300) {
        *(u16*)(object + 0x22) = 8;
    } else {
        (*(u16*)(object + 0xA))++;
    }
    return 0;
}

typedef unsigned char u8;
typedef unsigned short u16;

extern u8 fn_8018E26C(void*, void*);

int fn_8019B8B4(u8* object)
{
    u8* entry = *(u8**)(object + 0x4C);

    if (entry[0] != 0 && fn_8018E26C(entry, entry + 0x2B) == 0) {
        *(u16*)(object + 0x22) = 8;
    }
    (*(u16*)(object + 0xA))++;
    return 0;
}

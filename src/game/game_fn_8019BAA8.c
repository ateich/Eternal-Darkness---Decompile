typedef unsigned char u8;
typedef unsigned short u16;

extern u8 fn_8019F1EC(void*, void*);

int fn_8019BAA8(u8* object)
{
    u8* entry = *(u8**)(object + 0x4C);

    if (fn_8019F1EC(object + 0xA0, entry + 0x21) == 0) {
        *(u16*)(object + 0x22) = 8;
    }
    (*(u16*)(object + 0xA))++;
    return 0;
}

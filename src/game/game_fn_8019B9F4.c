typedef unsigned char u8;
typedef unsigned short u16;

extern u8 fn_8019F1EC(void*, void*);
extern u8 fn_8018E26C(void*, void*);

int fn_8019B9F4(u8* object)
{
    u8 count = object[1];
    u8 result = 0;
    u8* entry;
    int i;

    if (object[0xA0] != 0) {
        entry = *(u8**)(object + 0x4C);
        for (i = 0; i < count; i++) {
            fn_8019F1EC(object + 0xA0, entry + 0x21);
            entry += 0x38;
        }
    }

    entry = *(u8**)(object + 0x4C);
    for (i = 0; i < count; i++) {
        result = fn_8018E26C(entry, entry + 0x2B);
        entry += 0x38;
    }

    if (result == 0) {
        *(u16*)(object + 0x22) = 8;
    } else {
        (*(u16*)(object + 0xA))++;
    }
    return 0;
}

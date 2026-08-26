typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern void fn_80179904(void*, s16);
extern void fn_8018E230(void*, void*, int, int, int, int);
extern void fn_8017F3B4(void);

int fn_8017F120(u8* object)
{
    int i;
    int count;
    u8* entry;

    count = object[1];
    entry = *(u8**)(object + 0x4C);
    for (i = 0; i < count; i++, entry += 0x38) {
        *(s16*)(entry + 0x0A) += *(s16*)(entry + 0x10);
        *(s16*)(entry + 0x0C) += *(s16*)(entry + 0x12);
    }

    entry = *(u8**)(object + 0x4C);
    if (*(u16*)(object + 0x0A) == *(u16*)(entry + 8)) {
        for (i = 0; i < count; i++, entry += 0x38) {
            s16 x;
            s16 y;

            *(u16*)(entry + 8) += *(u16*)(object + 0xEC);
            *(s16*)(entry + 0x14) = 0;
            fn_80179904(entry + 0x10, 1);
            *(s16*)(entry + 0x16) = 0;
            *(s16*)(entry + 0x18) = 0;
            *(s16*)(entry + 0x1A) = -1;

            x = *(s16*)(entry + 0x10);
            if (x != 0) {
                *(s16*)(entry + 0x16) = x > 0 ? -1 : 1;
            }
            y = *(s16*)(entry + 0x12);
            if (y != 0) {
                *(s16*)(entry + 0x18) = y > 0 ? -1 : 1;
            }
            fn_8018E230(entry, entry + 0x2B, 1, 0, 5, 250);
        }
        *(void (**)(void))(object + 0x14C) = fn_8017F3B4;
    }
    (*(u16*)(object + 0x0A))++;
    return 0;
}

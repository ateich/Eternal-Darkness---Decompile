typedef unsigned char u8;
typedef unsigned short u16;

extern void fn_8018183C(void*, int, short);
extern void fn_8018E504(void*, void*);
extern void fn_801865EC(void*, void*, int);
extern void fn_8018E230(void*, void*, int, u8, u8, int);
extern void fn_8018E8B8(void*, u8, int);

int fn_8018FB74(u8* object)
{
    u8* channel;
    u8 count;
    int old_tick;
    int i;
    u8* entry;
    int j;

    old_tick = *(u16*)(object + 0xA);
    entry = *(u8**)(object + 0x4C);
    count = object[1];
    *(u16*)(object + 0xA) = old_tick + 1;
    fn_8018183C(object + 0xA0, 0, *(u16*)(object + 0xA6));

    for (i = 0; i < count; entry += 0x38, i++) {
        if (entry[0] != 0) {
            fn_8018E504(entry, entry + 0x20);
        }
        fn_801865EC(object, object + 0x10, i);
        if (old_tick == *(u16*)(entry + 8)) {
            fn_8018E230(entry, entry + 0x2B, 1, entry[0x2B], object[4], 0);
            j = 0;
            channel = entry;
            while (j < 4) {
                fn_8018E8B8(entry + 0x20, channel[0x2B], j);
                j++;
                channel += 4;
            }
        }
    }

    if (old_tick >= *(u16*)(object + 0xC)) {
        *(u16*)(object + 0x22) = 8;
    }
    return 0;
}

typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed long s32;
typedef unsigned long u32;

extern s32 fn_80180430(void*, u8);
extern s32 fn_80180454(void*);
extern void fn_80180518(void*, u8, s32);
extern void fn_80180554(void*, void*, void*, void*, s32, s32);
extern void fn_8017D318(void*, void*, s32, void*, s16, s16);
extern s32 fn_8017D1E0(void*, void*, s32, u16, s32, s32);
extern void fn_8018E26C(void*, void*);
extern void fn_8018E230(void*, void*, s32, s32, u8, s32);
extern void fn_8018F014(void*, u16);
extern void* memcpy(void*, const void*, unsigned long);

s32 fn_8019A150(u8* object)
{
    u8 packet[6];
    u8* entry;
    s32 index;
    u8 count;

    index = 0;
    entry = *(u8**)(object + 0x4c);
    count = object[1];
    while (index < count) {
        if (fn_80180430(object + 0x24, (u8)index) != 0) {
            if (entry[0] != 0) {
                fn_8018E26C(entry, entry + 0x2b);
            } else {
                fn_8017D318(entry + 0xa, object + 0x10, 0, entry + 0x10,
                            *(s16*)(object + 0x9e),
                            *(s16*)(object + 0xa0));
                if (fn_8017D1E0(entry + 0xa, object + 0x10, 10,
                                *(u16*)(object + 0x94), 0, 0) != 0) {
                    if (*(s32*)(object + 0x90) == 0 ||
                        (*(s32*)(object + 0x8c) == 0 &&
                         *(u16*)(object + 0xa) >= *(u16*)(object + 0xc))) {
                        entry[0x2b] = 0;
                        fn_80180518(object + 0x24, (u8)index, 0);
                    } else {
                        memcpy(packet, object + 0x98, 6);
                        fn_8018F014(packet, *(u16*)(object + 0x96));
                        fn_80180554(entry, packet, object + 0x16,
                                    object + 0x1c, 0, 0);
                        fn_8018E230(entry, entry + 0x2b, 1, 0,
                                    object[4], 0xcc);
                    }
                }
            }
        }
        entry += 0x38;
        index++;
    }
    if (fn_80180454(object + 0x24) != 0 ||
        (*(s32*)(object + 0x8c) == 0 &&
         (s32)*(u16*)(object + 0xa) >= (s32)*(u16*)(object + 0xc) + 100)) {
        *(u16*)(object + 0x22) = 8;
    }
    (*(u16*)(object + 0xa))++;
    return 0;
}

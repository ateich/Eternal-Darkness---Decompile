typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;

extern s32 fn_80179064(s16, s16, s16, s16);
extern void fn_8017D700(s16*, s16*, s16, s16*, u8, u8, u8, u8);
extern u8 fn_8018E26C(u8*, u8*);
extern void fn_8018E230(u8*, u8*, s32, u8, u8, s32);
extern void* fn_80201814(void*);

s32 fn_80191568(u8* object)
{
    u8* element = *(u8**)(object + 0x4C);
    u8 count = object[1];
    u8 arg5;
    u8 arg7 = object[0x8E];
    u8 arg6;
    u8 arg8 = object[0x90];
    s32 distance = fn_80179064(*(s16*)(element + 0xA), *(s16*)(element + 0xC),
                              *(s16*)(object + 0x10), *(s16*)(object + 0x12));
    s32 i;

    if (distance > 300) {
        arg5 = 20;
        arg6 = 60;
    } else if ((*(u16*)(object + 0xA) > 17 ||
                (*(u16*)(object + 0xA) > 12 && distance > 100))) {
        arg5 = 6;
        arg6 = 20;
    } else {
        arg5 = object[0x8D];
        arg6 = object[0x8F];
    }

    i = 0;
    while (i < count) {
        fn_8017D700((s16*)(element + 0xA), (s16*)(object + 0x10),
                    *(s16*)(element + 0x1C), (s16*)(element + 0x10),
                    arg5, arg6, arg7, arg8);
        element[0x21] += object[0x91];
        i++;
        element += 0x38;
    }

    if (object[0x60] != 0) {
        if (fn_8018E26C(object + 0x60, object + 0x5F) == 0) {
            *(u16*)(object + 0x22) = 8;
        }
    } else if (((object[0x8C] & 2) == 0 &&
                *(u16*)(object + 0xA) == *(u16*)(object + 0xC)) ||
               (object[0x8C] & 1) == 0 ||
               fn_80201814(*(void**)(object + 0x98)) == 0) {
        fn_8018E230(object + 0x60, object + 0x5F, 1,
                    object[2], object[4], 0);
    }

    (*(u16*)(object + 0xA))++;
    return 1;
}

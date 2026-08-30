typedef signed short s16;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

extern u32 lbl_80651E90;
extern u16 lbl_80651E94;
extern u32 lbl_8064D224;
extern u32 lbl_8064D18C;
extern float lbl_80650D98;
extern u8 lbl_80607130[];
extern u8 lbl_80606328[];
extern u8 lbl_80606318[];

extern void fn_801804AC(void*, void*, void*, void*);
extern void* memset(void*, int, unsigned long);
extern void fn_80180554(void*, void*, void*, void*, u16, int);
extern void fn_801805E0(void*, int, u8, u32, void*, float);
extern void fn_80180518(void*, int, int);
extern void fn_8018E230(void*, void*, int, int, s8, u8);
extern void fn_801A53C4(void*, u8, float);
extern void fn_8018C540(void*, void*, u8, int, u16);
extern void fn_801F5A04(void*, s16, void*, void*);

void fn_801A5068(u8* object, void* first, void* second, u8* config)
{
    struct {
        u32 word;
        u16 half;
    } setup;
    u8 count;
    u8* entry;
    int i;

    setup.word = lbl_80651E90;
    setup.half = lbl_80651E94;
    count = config[0];
    entry = *(u8**)(object + 0x4c);
    fn_801804AC(object, first, second, &setup);

    object[0] = 0x80;
    object[1] = config[0];
    object[2] = config[2];
    object[4] = config[3];
    *(u16*)(object + 0xc) = *(u16*)(config + 6);
    *(s16*)(object + 0xe) = *(s16*)(config + 4);
    *(u16*)(object + 0xa) = 0;
    *(u32*)(object + 0x44) = 0;
    *(u32*)(object + 0x68) = lbl_8064D224;
    *(u32*)(object + 0x38) = lbl_8064D18C;
    memset(object + 0x24, 0, 0x10);

    *(u16*)second = 0;
    *(u16*)((u8*)second + 2) = 0;
    *(u16*)((u8*)second + 4) = 0;
    *(u16*)first = 0;
    *(u16*)((u8*)first + 2) = 0;
    *(u16*)((u8*)first + 4) = 0;

    for (i = 0; (u8)i < count; i++) {
        fn_80180554(entry, first, second, &setup, *(u16*)(config + 8), 0);
        fn_801805E0(entry + 0x20, 4, config[1], (i & 0x3f) << 2,
                    config + 0x10, lbl_80650D98);
        fn_80180518(object + 0x24, i, 1);
        if (config[0x49] != 0)
            fn_8018E230(entry, entry + 0x2b, 1, 0,
                        -object[4], entry[0x2b]);
        entry += 0x38;
    }

    fn_801A53C4(*(void**)(object + 0x54), count, *(float*)(config + 0x44));
    fn_8018C540(*(void**)(object + 0x58), config + 0x10, count, 4,
                *(u16*)(lbl_80607130 + 2));
    *(u16*)(object + 0x22) = 4;
    if (*(s16*)(config + 4) >= 0)
        fn_801F5A04(object + 0x6c, *(s16*)(config + 4), lbl_80606328,
                    lbl_80606318);
}

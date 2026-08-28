typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct ShortCoord3 {
    s16 x;
    s16 y;
    s16 z;
} ShortCoord3;

extern const ShortCoord3 lbl_80651D80;
extern const float lbl_80650B00;
extern void* lbl_8064D224;
extern u8 lbl_80606318[];
extern u8 lbl_80606328[];

extern void* memset(void*, int, unsigned int);
extern void* memcpy(void*, const void*, unsigned int);
extern void fn_801804AC(void*, void*, void*, ShortCoord3*);
extern void fn_80180518(void*, u32, int);
extern void fn_80180554(void*, void*, void*, ShortCoord3*, u16, int);
extern void fn_801805E0(void*, int, u8, u32, u32*, float);
extern void fn_801806D4(void*, u32*, int);
extern void fn_8018C118(void*, u8);
extern void fn_8018FFBC(void*, u32*, u32*, u8);
extern void fn_801F5A04(void*, s16, void*, void*);

void fn_8018F948(u8* object, void* first, void* second, u8* config)
{
    u8 i;
    u8* cfg;
    void* fst;
    void* snd;
    u8* obj;
    ShortCoord3 fixed;
    u32 first_value;
    u32 second_value;
    u8 count;
    u8* entry;
    u8* values;

    cfg = config;
    fst = first;
    snd = second;
    obj = object;
    values = cfg + 0x14;
    fixed = lbl_80651D80;
    entry = *(u8**)(obj + 0x4C);
    count = cfg[0];
    fn_801804AC(obj, fst, snd, &fixed);

    obj[0] = 0x80;
    obj[1] = count;
    *(u16*)(obj + 0xC) = *(u16*)(cfg + 6);
    *(s16*)(obj + 0xE) = *(s16*)(cfg + 4);
    *(u16*)(obj + 0xA) = 0;
    *(u32*)(obj + 0x44) = 0;
    obj[2] = cfg[2];
    obj[4] = cfg[3];
    *(void**)(obj + 0x68) = lbl_8064D224;
    memset(obj + 0x24, 0, 0x10);

    memcpy(&first_value, values, sizeof(first_value));
    memcpy(&second_value, values + 4, sizeof(second_value));

    for (i = 0; (u8)i < count; i++) {
        fn_80180554(entry, fst, snd, &fixed, *(u16*)(cfg + 8), 0);
        fn_801805E0(entry + 0x20, 2, cfg[1], i * 2,
                    &first_value, lbl_80650B00);
        fn_801806D4(entry + 0x20, &second_value, 1);
        fn_80180518(obj + 0x24, i, 1);
        entry += 0x38;
    }

    fn_8018C118(*(void**)(obj + 0x54), count);
    fn_8018FFBC(*(void**)(obj + 0x58), &first_value, &second_value, count);
    if (*(s16*)(cfg + 4) >= 0) {
        fn_801F5A04(obj + 0x6C, *(s16*)(cfg + 4), lbl_80606328,
                    lbl_80606318);
    }
}

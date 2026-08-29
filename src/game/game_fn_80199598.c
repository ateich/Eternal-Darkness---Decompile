typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned long u32;

extern u32 lbl_80651DC8;
extern u16 lbl_80651DCC;
extern u32 lbl_80650BD0;
extern const float lbl_80650BC4;
extern const float lbl_80650BC8;
extern const float lbl_80650BCC;
extern void* lbl_8064D224;
extern u8 lbl_80607120[];
extern u8 lbl_80606328[];
extern u8 lbl_80606318[];

extern void fn_801804AC(void*, void*, void*, void*);
extern void* memset(void*, int, unsigned long);
extern void* memcpy(void*, const void*, unsigned long);
extern void fn_80180554(void*, void*, void*, void*, int, s16);
extern void fn_801805E0(void*, int, u8, u8, float, void*);
extern void fn_80180518(void*, int, int);
extern void fn_8018F014(void*, int);
extern void fn_8018E230(void*, void*, int, u8, u8, u8);
extern void fn_8018E260(void*, u8, u8);
extern void fn_8018CEC0(void*, u8);
extern void fn_8018C540(void*, void*, u8, int, u16);
extern void fn_801F5A04(void*, s16, void*, void*);

void fn_80199598(u8* object, void* first, void* second, u8* config)
{
    u8 count;
    int groups;
    u8* entry;
    int group;
    int within;
    int index;
    struct {
        u32 word;
        u16 half;
    } setup;
    u8 transformed[6];
    u32 value;

    setup.word = lbl_80651DC8;
    setup.half = lbl_80651DCC;
    value = lbl_80650BD0;
    count = config[0];
    groups = count / config[0x15];
    fn_801804AC(object, first, second, &setup);

    object[0] = 0x80;
    object[1] = count;
    object[4] = config[3];
    *(u16*)(object + 0xc) = config[0x16] + (groups - 1) * config[0x14];
    *(s16*)(object + 0xe) = *(s16*)(config + 4);
    *(u16*)(object + 0xa) = 0;
    *(u32*)(object + 0x44) = 0;
    *(float*)(object + 0x3c) = lbl_80650BC4;
    *(float*)(object + 0x40) = lbl_80650BC8;
    *(void**)(object + 0x68) = lbl_8064D224;
    memset(object + 0x24, 0, 0x10);

    entry = *(u8**)(object + 0x4c);
    if (groups > 1) {
        index = 0;
        group = 0;
        for (; (u8)group < groups; group++) {
            within = 0;
            for (; (u8)within < config[0x15]; within++) {
                fn_80180554(entry, first, second, &setup, 0,
                            *(s16*)(config + 0x20));
                fn_801805E0(entry + 0x20, 4, config[1],
                            (u32)((u8)index << 2), lbl_80650BCC, &value);
                entry += 0x38;
                index++;
            }
        }
    } else {
        index = 0;
        for (; (u8)index < config[0x15]; index++) {
            memcpy(transformed, first, 6);
            fn_8018F014(transformed, 0x10);
            fn_80180554(entry, transformed, second, &setup, 0,
                        *(s16*)(config + 0x20));
            fn_801805E0(entry + 0x20, 4, config[1],
                        (u32)((u8)index << 2), lbl_80650BCC, &value);
            fn_8018E230(entry, entry + 0x2b, 2, config[0x17],
                        object[4], config[0x18]);
            fn_8018E260(entry, config[0x17], config[0x18]);
            fn_80180518(object + 0x24, index, 1);
            entry += 0x38;
        }
    }

    fn_8018CEC0(*(void**)(object + 0x54), count);
    fn_8018C540(*(void**)(object + 0x58), config + 0x10, count, 4,
                *(u16*)(lbl_80607120 + 2));
    if (*(s16*)(config + 4) >= 0) {
        fn_801F5A04(object + 0x6c, *(s16*)(config + 4),
                    lbl_80606328, lbl_80606318);
    }
}

typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 lbl_80607120[];
extern u32 lbl_8064A80C;
extern u32 lbl_8064A8A4;
extern const u8 lbl_8064C1C0[];
extern const float lbl_8064B000;
extern u8 lbl_80606318[];
extern u8 lbl_80606328[];

extern void* memset(void*, int, unsigned int);
extern void* memcpy(void*, const void*, unsigned int);

extern void fn_801804AC(u8*, void*, void*, void*);
extern int fn_8018F0A0(void);
extern void fn_80180518(u8*, int, int);
extern void fn_80179904(void*, u8);
extern void fn_80180554(u8*, u8*, void*, u8*, u16, int);
extern void fn_801805E0(u8*, int, u8, u32, u8*, float);
extern void fn_8018CB70(void*, u8, u16);
extern void fn_8018C540(void*, u8*, u8, int, u16);
extern void fn_801F5A04(u8*, s16, u8*, u8*);

void fn_8019F320(u8* object, u8* source, u8* value, u8* config)
{
    u8 channel[4];
    u8 key[6];
    u8 count;
    u8* entry;
    u32 i;

    entry = *(u8**)(object + 0x4C);
    count = config[0];
    *(u32*)&key[0] = *(const u32*)&lbl_8064C1C0[0];
    *(u16*)&key[4] = *(const u16*)&lbl_8064C1C0[4];
    fn_801804AC(object, source, value, key);
    object[0] = 0x80;
    object[1] = config[0];
    object[2] = config[2];
    object[4] = config[3];
    *(u16*)(object + 0xC) = *(u16*)(config + 6);
    *(s16*)(object + 0xE) = *(s16*)(config + 4);
    *(u16*)(object + 0xA) = 0;
    *(u32*)(object + 0x44) = 0;
    *(u32*)(object + 0x38) = lbl_8064A80C;
    *(u32*)(object + 0x68) = lbl_8064A8A4;
    object[3] |= 0x81;
    object[6] = 5;
    object[7] = 5;
    if (fn_8018F0A0()) {
        *(s16*)(object + 0x1A) = -*(s16*)(object + 0x1A);
        *(s16*)(value + 4) = -*(s16*)(value + 4);
    }
    memset(object + 0x24, 0, 0x10);
    channel[0] = config[0x10];
    channel[1] = config[0x11];
    channel[2] = config[0x12];
    channel[3] = config[0x13];
    fn_80180518(object + 0x24, 0, 1);
    for (i = 0; (u8)i < count; i++) {
        memcpy(key, source, 6);
        fn_80179904(value, config[0x18]);
        fn_80180554(entry, key, value, object + 0x14, *(u16*)(config + 8), 0);
        fn_801805E0(entry + 0x20, 4, config[1], i * 4, channel, lbl_8064B000);
        entry += 0x38;
    }
    fn_8018CB70(*(void**)(object + 0x54), count, *(u16*)(lbl_80607120 + 2));
    fn_8018C540(*(void**)(object + 0x58), channel, count, 4, *(u16*)(lbl_80607120 + 2));
    *(u16*)(object + 0x22) = 4;
    if (*(s16*)(config + 4) >= 0) {
        fn_801F5A04(object + 0x6C, *(s16*)(config + 4), lbl_80606328, lbl_80606318);
    }
}

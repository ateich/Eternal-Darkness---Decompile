typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct ShortCoord3 {
    s16 x;
    s16 y;
    s16 z;
} ShortCoord3;

extern u32 lbl_80651DA0;
extern u16 lbl_80651DA4;
extern u32 lbl_80650B28;
extern float lbl_80650B20;
extern float lbl_80650B2C;
extern void* lbl_8064D224;
extern float lbl_80650B30;
extern double lbl_80650B38;
extern double lbl_80650B18;
extern float lbl_80650B34;
extern u8 lbl_802FC5BC[];
extern u8 lbl_80607120[];
extern u8 lbl_80606318[];
extern u8 lbl_80606328[];

extern void* memset(void*, int, u32);
extern float fn_80048C2C(float);
extern float fn_80048C50(float);
extern void fn_801804AC(void*, ShortCoord3*, ShortCoord3*, ShortCoord3*);
extern void fn_80180518(void*, u32, int);
extern void fn_80180554(void*, ShortCoord3*, ShortCoord3*, ShortCoord3*, int,
                        int);
extern void fn_801805E0(void*, int, u8, int, void*, float);
extern void fn_8018CEC0(void*, u8);
extern void fn_8018C540(void*, void*, u8, int, u16);
extern void fn_801F5A04(void*, s16, void*, void*);

void fn_801916D0(u8* object, ShortCoord3* first, ShortCoord3* second,
                 u8* config)
{
    ShortCoord3 zero;
    u32 effect = lbl_80650B28;
    u8* entry;
    u8 count;
    u32 i;
    ShortCoord3 position;
    void* source;

    *(u32*)&zero = lbl_80651DA0;
    *(u16*)((u8*)&zero + 4) = lbl_80651DA4;
    entry = *(u8**)(object + 0x4C);
    count = config[0];
    fn_801804AC(object, first, second, &zero);

    object[0] = 0x80;
    object[1] = count;
    object[2] = config[2];
    object[4] = config[3];
    *(s16*)(object + 0xE) = *(s16*)(config + 4);
    *(u16*)(object + 0xC) = *(u16*)(config + 6);
    *(u16*)(object + 0xA) = 0;
    *(void**)(object + 0x68) = lbl_8064D224;
    *(u32*)(object + 0x38) = *(u32*)(config + 0x30);
    *(u32*)(object + 0x44) = 0;
    *(float*)(object + 0x3C) = lbl_80650B20;
    *(float*)(object + 0x40) = lbl_80650B2C;
    if (*(s32*)(config + 0x1C) != 0) {
        *(u32*)(object + 0x5C) = effect;
    }
    memset(object + 0x24, 0, 0x10);

    for (i = 0; (u8)i < count; i++) {
        float angle = lbl_80650B30 * (float)(u8)i / (float)count;
        position.x = (s16)((float)*(s16*)(config + 0x28) *
                           fn_80048C2C(angle) + *(float*)(config + 0x34));
        position.y = (s16)((float)*(s16*)(config + 0x28) *
                           fn_80048C50(angle) + *(float*)(config + 0x38));
        position.z = (s16)*(float*)(config + 0x3C);
        fn_80180554(entry, &position, second, &zero, 0,
                    (signed char)config[0x1B]);
        if (config[0x1A] == 0) {
            fn_80180518(object + 0x24, i, 1);
            source = lbl_802FC5BC + 0xC;
        } else {
            source = &effect;
        }
        fn_801805E0(entry + 0x20, 4, config[1], 0, source, lbl_80650B34);
        entry += 0x38;
    }

    fn_8018CEC0(*(void**)(object + 0x54), count);
    fn_8018C540(*(void**)(object + 0x58), lbl_802FC5BC + 0xC, count, 4,
                *(u16*)(lbl_80607120 + 2));
    if (*(s16*)(config + 4) >= 0) {
        fn_801F5A04(object + 0x6C, *(s16*)(config + 4), lbl_80606328,
                    lbl_80606318);
    }
}

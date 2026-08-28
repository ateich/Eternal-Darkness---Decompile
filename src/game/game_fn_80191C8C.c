typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct ShortCoord3 {
    s16 x;
    s16 y;
    s16 z;
} ShortCoord3;

typedef struct FloatCoord3 {
    u32 pad[2];
    float x;
    float y;
    float z;
    u32 tail[5];
} FloatCoord3;

extern void* memcpy(void*, const void*, u32);
extern void* fn_80201814(void*);
extern void* fn_80201BC8(void);
extern void fn_8011F6A4(void*, u32, u32, s32, FloatCoord3*, s32);
extern void fn_801795D8(void*, void*, ShortCoord3*);
extern void fn_80179904(ShortCoord3*, u8);

void fn_80191C8C(u8* object, u8* config)
{
    ShortCoord3 delta;
    FloatCoord3 position;
    u8* entry;
    s32 i;
    u8 value;

    entry = object + 0x8C;
    for (i = 0; i < config[0]; i++, entry++) {
        *entry = config[0x14];
    }

    object[0xAC] = config[0x16];
    object[0xAD] = config[0x15];
    object[0xB1] = config[0x17];
    object[0xB2] = config[0x18];
    object[0xB3] = config[0x19];
    object[0xB4] = config[0x1A];
    object[0xB5] = config[0x1B];
    *(u32*)(object + 0xB8) = 0;
    *(u32*)(object + 0xBC) = 0;
    *(u32*)(object + 0xC8) = *(u32*)(config + 0x28);
    *(u32*)(object + 0xCC) = *(u32*)(config + 0x2C);
    *(u32*)(object + 0xD8) = *(u32*)(config + 0x38);
    memcpy(object + 0xC0, config + 0x1E, 6);
    *(u32*)(object + 0xDC) = *(u32*)(config + 0x3C);

    if (fn_80201814(*(void**)(object + 0xCC)) != 0) {
        fn_8011F6A4(fn_80201BC8(), *(u32*)(object + 0xD0),
                    *(u32*)(object + 0xD4), -1, &position, 1);
        *(s16*)(object + 0xC0) = (s16)position.x;
        *(s16*)(object + 0xC2) = (s16)position.y;
        *(s16*)(object + 0xC4) = (s16)position.z;
        fn_801795D8(object + 0xC0, object + 0x10, &delta);
        fn_80179904(&delta, config[0x16]);

        object[0xAE] = delta.x < 0 ? -delta.x : delta.x;
        object[0xAF] = delta.y < 0 ? -delta.y : delta.y;
        object[0xB0] = delta.z < 0 ? -delta.z : delta.z;

        value = config[0x15];
        if (object[0xAE] > value) {
            value = object[0xAE];
        }
        object[0xAE] = value;
        value = config[0x15];
        if (object[0xAF] > value) {
            value = object[0xAF];
        }
        object[0xAF] = value;
        value = config[0x15];
        if (object[0xB0] > value) {
            value = object[0xB0];
        }
        object[0xB0] = value;
    }

    object[0xB7] = 1;
    if (config[0x24] != 0) {
        object[0xB7] |= 2;
    }
}

typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;

extern void* memset(void*, int, u32);
extern void fn_8018E230(void*, void*, int, int, s8, u8);

void fn_8019D92C(u8* object, u8* config)
{
    u8* entry;
    u8* counters;
    int i;

    entry = *(u8**)(object + 0x4C);
    memset(object + 0x98, 0, object[1] * 2);
    object[0xFC] = config[0x1E];
    object[0xFB] = config[0x1D];
    *(s16*)(object + 0x90) = *(s16*)(object + 0x14) + *(u16*)(config + 0x14);
    *(u16*)(object + 0x92) = *(u16*)(config + 0x14);
    object[0xFF] = config[0x1C];
    object[0x100] = config[0x22];
    object[0x101] = config[0x21];
    object[0x102] = 0;
    object[0xFD] = config[0x20];
    *(u16*)(object + 0x98) = 0;
    *(u16*)(object + 0x94) = 0;
    object[0xDA] = config[0x23];

    counters = object + 0x8C;
    for (i = 1; i < config[0]; i++) {
        *(s16*)(counters + 2 + i * 2 + 0xA) =
            *(s16*)(counters + 2 + i * 2 + 8) - config[0x20];
        counters[i + 0x4F] = 0;
    }

    fn_8018E230(entry, entry + 0x2B, 1, 0, (s8)counters[0x6F], object[2]);
}

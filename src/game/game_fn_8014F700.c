typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

typedef struct Vec3Words {
    u32 x, y, z;
} Vec3Words;

extern u32 lbl_80651BF8;
extern u16 lbl_80651BFC;

extern void fn_801501DC(void);
extern u8* fn_80149D98(void*);
extern void fn_80149D64(void*);
extern void fn_801858E0(void*);
extern void fn_80185AE8(void);
extern int fn_801E8328();
extern void* memcpy(void*, const void*, unsigned int);

void fn_8014F700(Vec3Words* position, u16 value, u32* source)
{
    u8* instance = fn_80149D98(fn_801501DC);
    struct {
        u32 word;
        u16 half;
    } config;

    if (instance != 0) {
        u8* embedded;

        config.word = lbl_80651BF8;
        config.half = lbl_80651BFC;
        instance[0x1328] = 4;
        fn_80149D64(instance);
        *(u16*)(instance + 8) = 0;
        embedded = instance + 0x10;
        *(u16*)(instance + 0x0A) = 0;
        *(s16*)(instance + 0x0C) = -3;
        fn_801858E0(embedded);
        *(u32*)(embedded + 0x78) = *source;
        embedded[0x7B] = 0xFF;
        *(u16*)(embedded + 4) = value;
        embedded[1] = 0x20;
        *(u16*)(embedded + 8) = 0;
        *(u16*)(embedded + 6) = 0x19;
        *(s8*)(embedded + 3) = -10;
        embedded[0x14] = 3;
        *(u16*)(embedded + 0x1C) = embedded[1];
        embedded[0x19] = 8;
        embedded[0x18] |= 2;
        *(s8*)(embedded + 0x18) &= (s8)~0x10;
        *(void**)(embedded + 0x90) = fn_80185AE8;
        *(Vec3Words*)(embedded + 0x98) = *position;
        memcpy(embedded + 0xA4, &config, 6);
        *(u32*)(embedded + 0x94) = 0;
        embedded[0xAA] = 4;
        fn_801E8328(0x10, embedded);
    }
}

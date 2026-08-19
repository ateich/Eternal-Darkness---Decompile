typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Vec3Words {
    u32 x, y, z;
} Vec3Words;

typedef struct Entry {
    u8 bytes[0xB0];
} Entry;

extern u32 lbl_8065056C;
extern u16 lbl_80650570;
extern u32 lbl_802FC5BC[];

extern void fn_8014F320(void*, u8, u16);
extern void fn_80181924(void);
extern void* fn_80149E04(void);
extern void fn_80147E88(void*);
extern void fn_801489B4(void*, void*);
extern void fn_80184740(void*);
extern void fn_80149B38(void*);
extern int fn_801E8328();
extern void* memcpy(void*, const void*, unsigned int);

void fn_8014F3A4(Vec3Words* position, u8 object_id, u16 value,
                 u16 type, u8* output)
{
    Entry entry;
    struct {
        u32 word;
        u16 half;
    } config;
    void* instance;

    config.word = lbl_8065056C;
    config.half = lbl_80650570;
    fn_8014F320(&entry, object_id, value);
    *(void**)(entry.bytes + 0x90) = fn_80181924;
    memcpy(entry.bytes + 0xA4, &config, 6);
    entry.bytes[0xAA] = 4;
    *(Entry*)output = entry;
    *(Vec3Words*)(output + 0x98) = *position;

    instance = fn_80149E04();
    if (instance != 0) {
        u8* embedded = output + 0xB0;
        *(void**)(output + 0x170) = instance;
        fn_80147E88(embedded);
        fn_801489B4(embedded, instance);
        embedded[0xBC] = 4;
        *(u32*)(embedded + 0x94) = 0;
        fn_80184740(embedded);
        embedded[1] = 3;
        *(u16*)(embedded + 4) = type;
        *(u32*)(embedded + 0x2C) = lbl_802FC5BC[3];
        embedded[0x2F] = 0xE0;
        *(u8*)instance = object_id;
        fn_80149B38(instance);
        fn_801E8328(0x19, output);
    }
}

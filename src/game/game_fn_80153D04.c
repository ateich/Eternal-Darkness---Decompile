typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Vec3f {
    float x, y, z;
} Vec3f;

extern u32 lbl_806505D8;
extern u16 lbl_806505DC;
extern void fn_8014B738(void);
extern u8* fn_80149D98(void (*)(void));
extern void fn_80149D64(void*);
extern void fn_80182380(void*);
extern void fn_80182448(void);
extern void* memcpy(void*, const void*, u32);
extern int fn_801E8328();

void fn_80153D04(Vec3f* position, u8 kind, u8 style, u16 value,
                 u8 flag, u16 count, u16 second, u16 third, u8 mode)
{
    u8 key[8];
    u8* instance;
    u8* work;

    *(u32*)key = lbl_806505D8;
    *(u16*)(key + 4) = lbl_806505DC;
    instance = fn_80149D98(fn_8014B738);
    if (instance != 0) {
        fn_80149D64(instance);
        work = instance + 8;
        instance[0x1328] = mode;
        fn_80182380(work);
        work[0] = kind;
        work[1] = style;
        *(u16*)(work + 4) = value;
        *(u16*)(work + 8) = second;
        *(u16*)(work + 6) = third;
        work[0x1F] = flag;
        *(u16*)(work + 0x1C) = count;
        *(void (**)(void))(work + 0x90) = fn_80182448;
        *(Vec3f*)(work + 0x98) = *position;
        memcpy(work + 0xA4, key, 6);
        *(u32*)(work + 0x94) = 0;
        work[0xAA] = mode;
        fn_801E8328(16, work);
    }
}

typedef signed short s16;
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Vec3f {
    float x, y, z;
} Vec3f;

extern void fn_8014B738(void);
extern void* fn_80149D98(void (*)(void));
extern void fn_80149D64(void*);
extern void fn_801858E0(void*);
extern void fn_80185AE8(void);
extern void* memcpy(void*, const void*, u32);
extern int fn_801E8328();
extern u32 lbl_80651C50;
extern u16 lbl_80651C54;

void fn_80152404(Vec3f* position, s16 kind, u16 duration, u8 mode, u32* packed)
{
    u8 key[8];
    u8* instance;
    u8* work;

    instance = fn_80149D98(fn_8014B738);
    if (instance != 0) {
        *(u32*)key = lbl_80651C50;
        *(u16*)(key + 4) = lbl_80651C54;
        fn_80149D64(instance);
        work = instance + 8;
        instance[0x1328] = mode;
        fn_801858E0(work);
        *(u32*)(work + 0x78) = *packed;
        *(u16*)(work + 4) = kind;
        work[1] = 60;
        work[0x14] = 16;
        *(u16*)(work + 8) = (duration - work[1]) / (signed char)work[0x14];
        *(u16*)(work + 6) = *(u16*)(work + 8) + 17;
        work[2] = 255;
        *(signed char*)(work + 3) = -15;
        *(u16*)(work + 0x1C) = work[1];
        work[0x18] |= 2;
        work[0x19] = 8;
        *(void (**)(void))(work + 0x90) = fn_80185AE8;
        *(Vec3f*)(work + 0x98) = *position;
        memcpy(work + 0xA4, key, 6);
        *(u32*)(work + 0x94) = 0;
        work[0xAA] = mode;
        fn_801E8328(0x10, work);
    }
}

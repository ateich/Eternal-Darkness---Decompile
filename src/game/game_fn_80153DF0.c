typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Vec3f {
    float x, y, z;
} Vec3f;

extern u32 lbl_80651C70;
extern u16 lbl_80651C74;
extern void fn_8014B738(void);
extern u8* fn_80149D98(void (*)(void));
extern void fn_80149D64(void*);
extern void fn_8019A868(void*);
extern void fn_8019A7C4(void);
extern void* memcpy(void*, const void*, u32);
extern void fn_801E8328(int, void*);

void fn_80153DF0(Vec3f* position, u8 kind, u8 style, u16 value,
                 u32* optional, u16 key_value, void* resource, u8 first,
                 u8 second, u16 count, u16 third, u8 mode)
{
    u8 key[8];
    u8* instance;
    u8* work;

    *(u32*)key = lbl_80651C70;
    *(u16*)(key + 4) = lbl_80651C74;
    instance = fn_80149D98(fn_8014B738);
    if (instance != 0) {
        fn_80149D64(instance);
        work = instance + 8;
        instance[0x1328] = mode;
        fn_8019A868(work);
        work[0] = kind;
        work[1] = style;
        *(u16*)(work + 4) = value;
        *(u16*)(work + 8) = count;
        *(u16*)(work + 6) = third;
        if (optional != 0)
            *(u32*)(work + 0x10) = *optional;
        *(void**)(work + 0x14) = resource;
        work[0x18] = first;
        work[0x19] = second;
        *(void (**)(void))(work + 0x90) = fn_8019A7C4;
        *(Vec3f*)(work + 0x98) = *position;
        *(u16*)(key + 4) = key_value;
        memcpy(work + 0xA4, key, 6);
        *(u32*)(work + 0x94) = 0;
        work[0xAA] = mode;
        fn_801E8328(16, work);
    }
}

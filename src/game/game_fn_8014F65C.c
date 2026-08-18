typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Vec3Words {
    u32 x, y, z;
} Vec3Words;

extern void fn_8014FFE0(void);
extern u8* fn_80149D98(void*);
extern void fn_80149D64(void*);
extern int fn_801A98F4(int, int);

void fn_8014F65C(Vec3Words* position, u16 first, u16 second,
                 u32 value, u32* source, float scale)
{
    u8* instance = fn_80149D98(fn_8014FFE0);

    if (instance != 0) {
        instance[0x1328] = 4;
        fn_80149D64(instance);
        *(u16*)(instance + 0x0C) = first;
        *(u16*)(instance + 0x0E) = second;
        *(Vec3Words*)(instance + 0x10) = *position;
        *(float*)(instance + 0x1C) = scale;
        *(u32*)(instance + 8) = value;
        *(u32*)(instance + 0x20) = *source;
        fn_801A98F4(0xDB, 0x64);
    }
}

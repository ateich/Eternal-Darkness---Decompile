typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct Vec3f {
    float x;
    float y;
    float z;
} Vec3f;

extern void fn_80150A24(void);
extern u8* fn_80149D98(void (*callback)(void));
extern void fn_80149D64(void*);

void fn_80150950(s32 owner, Vec3f* position, u16 duration, u16 field_132E,
                 s32 mode, u32 field_1C, u32 field_20, u32 field_24)
{
    u8* instance;

    instance = fn_80149D98(fn_80150A24);
    if (instance != 0) {
        instance[0x1328] = 2;
        fn_80149D64(instance);
        *(s32*)(instance + 0x1324) = owner;
        *(u16*)(instance + 0x132E) = field_132E;
        *(u16*)(instance + 0x08) = position->x;
        *(u16*)(instance + 0x0A) = position->y;
        *(u16*)(instance + 0x0C) = position->z;
        *(u16*)(instance + 0x0E) = 0;
        *(u16*)(instance + 0x10) = 0;
        *(u16*)(instance + 0x12) = 3;
        *(s32*)(instance + 0x28) = mode;
        *(u16*)(instance + 0x14) = duration;
        *(u16*)(instance + 0x16) = duration;
        *(u32*)(instance + 0x1C) = field_1C;
        *(u32*)(instance + 0x20) = field_20;
        *(u32*)(instance + 0x24) = field_24;
    }
}

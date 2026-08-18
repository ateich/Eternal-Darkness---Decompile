typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct Vec3Words {
    u32 x;
    u32 y;
    u32 z;
} Vec3Words;

extern void fn_80150400(void);
extern void fn_80151D00(void);
extern u8* fn_80149D98(void (*callback)(void));
extern void fn_80149D64(void*);

void fn_801502C0(Vec3Words* position, Vec3Words* target, u32 value,
                 u16 kind, u16 field_16, u16 field_18, u16 field_24,
                 u16 field_1A, u16 duration, u16 delay, u32 field_30,
                 u32* field_260, s32 mode, u16 field_12)
{
    u8* instance;

    switch (mode) {
    case 2:
    case 3:
        instance = fn_80149D98(fn_80151D00);
        break;
    default:
        instance = fn_80149D98(fn_80150400);
        break;
    }

    if (instance != 0) {
        if (duration == 0)
            duration = 30000;

        instance[0x1328] = 2;
        fn_80149D64(instance);

        *(Vec3Words*)(instance + 0x34) = *position;
        *(Vec3Words*)(instance + 0x40) = *target;
        *(u16*)(instance + 0x14) = kind;
        *(u16*)(instance + 0x16) = field_16;
        *(u16*)(instance + 0x18) = field_18;
        *(u16*)(instance + 0x1A) = field_1A;
        *(u16*)(instance + 0x1C) = duration;
        *(u16*)(instance + 0x1E) = delay;
        *(u16*)(instance + 0x20) = field_1A + duration + delay;
        *(u16*)(instance + 0x22) = field_1A;
        *(u16*)(instance + 0x24) = field_24;
        *(u32*)(instance + 0x2C) = value;
        *(u32*)(instance + 0x30) = field_30;
        *(u32*)(instance + 0x08) = 0;
        *(u32*)(instance + 0x0C) = 0;
        *(u16*)(instance + 0x26) = 0;
        *(u32*)(instance + 0x25C) = 0;
        *(u32*)(instance + 0x260) = *field_260;
        *(s32*)(instance + 0x28) = mode;
        *(u16*)(instance + 0x12) = field_12;
    }
}

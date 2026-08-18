typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

#pragma use_lmw_stmw on

typedef struct Vec3 { u32 x, y, z; } Vec3;

extern void fn_80154B6C(void*);
extern void* fn_80149D98(void (*)(void*));
extern void fn_80149D64(void*);

void fn_80154A98(Vec3* position, s16* rotation, u8 kind, u16* limits,
                 float scale)
{
    void* work = fn_80149D98(fn_80154B6C);

    if (work != 0) {
        *(u8*)((char*)work + 0x1328) = 0x84;
        fn_80149D64(work);
        *(u8*)((char*)work + 0x25) = kind;
        *(float*)((char*)work + 8) = scale;
        *(Vec3*)((char*)work + 0xC) = *position;
        *(u8*)((char*)work + 0x26) = 0;
        if (limits != 0) {
            *(u8*)((char*)work + 0x24) = 1;
            *(u16*)((char*)work + 0x20) = limits[0];
            *(u16*)((char*)work + 0x22) = limits[1];
        } else {
            *(u8*)((char*)work + 0x24) = 0;
            *(u16*)((char*)work + 0x20) = 0;
            *(u16*)((char*)work + 0x22) = 0;
        }
        *(s16*)((char*)work + 0x18) = rotation[0];
        *(s16*)((char*)work + 0x1A) = rotation[1];
        *(s16*)((char*)work + 0x1C) = rotation[2];
    }
}

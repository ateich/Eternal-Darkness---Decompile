typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef float f32;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

typedef struct {
    u8 bytes[40];
} SpawnHeader;

typedef struct {
    u8 bytes[172];
} SpawnInfo;

extern const char lbl_8023CBC8[];
extern s32 lbl_8064D18C;

extern double fn_8016A694(void*, int);
extern s32 fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern unsigned int fn_800F5C54();
extern void fn_80196578(void*);
extern void fn_8018F81C(void*, u8);
extern s32 fn_801D3974(s32);
extern void* fn_8015C4A4(s32, s32);
extern Vec3s* fn_80158ABC(void*, s32, s32);
extern void* fn_80147EC4(void*);
extern void fn_801964E8(void*, s32, s32);
extern s32 fn_80142A70(s32, Vec3s*, s32, s32, s32, s32, s32, s32);
extern s32 fn_8014B8D0(void*, s32);
extern void fn_801966E0(void);

s32 fn_80018708(void* script)
{
    SpawnInfo info;
    SpawnHeader header;
    Vec3s first;
    Vec3s last;
    Vec3s points[24];
    s32 arg1;
    s32 arg2;
    s32 count;
    s32 kind;
    s32 flags;
    s32 i;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 min_z;
    f32 max_z;
    f32 best_low;
    f32 best_high;

    arg1 = (s32)fn_8016A694(script, 1);
    arg2 = (s32)fn_8016A694(script, 2);
    count = (s32)fn_8016A694(script, 3);
    if (fn_8016A598(script) != count + 4) {
        fn_80163BB4(script, lbl_8023CBC8, count + 2, fn_8016A598(script));
        return 0;
    }

    kind = (s32)fn_8016A694(script, 4);
    fn_80196578(&header);
    *(s16*)&header.bytes[4] = -1;
    fn_8018F81C(&header, (u8)count);

    *(u16*)&info.bytes[8] = 15;
    info.bytes[1] = 8;
    info.bytes[2] = (u8)count;

    flags = 0;
    switch (kind) {
    case 0:
        flags = 0x100;
        break;
    case 1:
        flags = 0x20;
        break;
    case 2:
        flags = 0x08;
        break;
    case 3:
        flags = 0x10;
        break;
    case 4:
        flags = 0x40;
        break;
    }

    *(s32*)&header.bytes[20] = fn_801D3974(kind);
    *(s32*)&header.bytes[24] = *(s32*)&header.bytes[20];
    header.bytes[27] = (u8)arg2;
    header.bytes[23] = (u8)arg1;
    *(s32*)&info.bytes[12] = *(s32*)&header.bytes[24];
    *(s32*)&info.bytes[16] = *(s32*)&header.bytes[20];
    info.bytes[25] = 9;
    info.bytes[28] = 3;
    *(u16*)&info.bytes[22] = (u16)flags;
    info.bytes[4] |= 0x81;
    info.bytes[3] = 0;

    first = *fn_80158ABC(
        fn_8015C4A4(fn_800F5C54(fn_8016A694(script, 5)), 2), 2, 0);
    last = *fn_80158ABC(
        fn_8015C4A4(fn_800F5C54(fn_8016A694(script, 7)), 2), 2, 0);
    dx = (f32)(last.x - first.x);
    dy = (f32)(last.y - first.y);
    dz = (f32)(last.z - first.z);
    min_z = (f32)first.z;
    max_z = (f32)first.z;
    best_low = 1000000.0f;
    best_high = -1000000.0f;

    for (i = 0; i < count; i++) {
        Vec3s* point;
        f32 distance;

        point = fn_80158ABC(
            fn_8015C4A4(fn_800F5C54(fn_8016A694(script, i + 5)), 2),
            2, 0);
        distance = dx * point->x + dy * point->y + dz * point->z;
        if ((f32)point->z < min_z) {
            min_z = point->z;
        }
        if ((f32)point->z > max_z) {
            max_z = point->z;
        }
        if (distance > best_high) {
            best_high = distance;
            last = *point;
        }
        if (distance < best_low) {
            best_low = distance;
            first = *point;
        }
        points[i] = *point;
    }

    info.bytes[170] = 2;
    *(s32*)&info.bytes[144] = (s32)fn_801966E0;
    fn_80147EC4(&info);
    if (*(void**)&info.bytes[148] != 0) {
        fn_801964E8(*(void**)&info.bytes[148], 1, 0);
    }

    first.y = (s16)min_z;
    last.y = (s16)max_z;
    fn_8014B8D0(
        *(void**)&info.bytes[148],
        fn_80142A70(2, &first, (s16)(max_z - min_z), lbl_8064D18C,
                    0, 0, 0, 0));
    return 0;
}

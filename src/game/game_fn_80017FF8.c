typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
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
    u8 bytes[144];
} SpawnInfo;

typedef struct {
    char invalid_count[52];
    f32 colour[3];
    f32 origin[3];
    char missing_marker[25];
} MarkerDiagnostics;

MarkerDiagnostics lbl_8023CBC8 = {
    "\nInvalid Num of Markers! Expecting %i, and got %i",
    { 0.2f, 0.2f, 0.2f },
    { 0.0f, 0.0f, 0.0f },
    "Could not find marker %u"
};
extern double lbl_8064DE68;
extern s32 lbl_8064D1BC;
extern s32 lbl_8064D18C;

extern double fn_8016A694(void*, int);
extern int fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_8016A830(void*, double);
extern unsigned int fn_800F5C54(double);
extern void fn_80196578(void*);
extern void fn_8018F81C(void*, u8);
extern int fn_801D3974(s32);
extern int fn_8015C4A4(int, int);
extern Vec3s* fn_80158ABC(int, int, void*);
extern void fn_80211AAC(f32*, f32*);
extern void* fn_80147EC4(void*);
extern void fn_801964E8(void*, s32, s32);
extern void fn_801978F8(void*, u16);
extern s32 fn_80142A70(s32, Vec3s*, s32, s32, s32, s32, s32, s32);
extern s32 fn_8014B8D0(void*, s32);
extern void fn_801966E0(void);
extern void fn_8014BA14(void);

s32 fn_80017FF8(void* script)
{
    SpawnInfo info;
    SpawnHeader header;
    Vec3s first;
    Vec3s last;
    Vec3s points[24];
    f32 direction[3];
    s32 count;
    s32 kind;
    s32 mode;
    s32 user_value;
    s32 flags;
    s32 handle;
    s32 i;
    f32 min_z;
    f32 max_z;
    f32 best_low;
    f32 best_high;

    handle = -1;
    count = (s32)fn_8016A694(script, 1);
    if (fn_8016A598(script) != count + 4) {
        fn_80163BB4(script, lbl_8023CBC8.invalid_count, count + 4,
                    fn_8016A598(script));
        fn_8016A830(script, lbl_8064DE68);
        return 1;
    }

    kind = (s32)fn_8016A694(script, 2);
    mode = (s32)fn_8016A694(script, 3);
    user_value = (s32)fn_8016A694(script, 4);

    fn_80196578(&header);
    *(s16*)&header.bytes[4] = -1;
    fn_8018F81C(&header, (u8)count);

    *(u16*)&info.bytes[8] = 15;
    info.bytes[1] = 9;
    info.bytes[2] = (u8)count;
    info.bytes[0] = 0;
    if (lbl_8064D1BC == 0x89C || lbl_8064D1BC == 0xADE ||
        lbl_8064D1BC == 0x33D || lbl_8064D1BC == 0x395) {
        *(u16*)&header.bytes[28] = 100;
    }

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
    header.bytes[27] = 60;
    header.bytes[23] = 150;
    *(s32*)&info.bytes[12] = *(s32*)&header.bytes[24];
    *(s32*)&info.bytes[16] = *(s32*)&header.bytes[20];
    info.bytes[25] = 9;
    info.bytes[28] = 3;
    *(u16*)&info.bytes[22] = (u16)flags;
    info.bytes[4] |= 0x81;
    info.bytes[3] = 0;

    first = *fn_80158ABC(fn_8015C4A4(fn_800F5C54(fn_8016A694(script, 5)), 2), 2, 0);
    last = *fn_80158ABC(fn_8015C4A4(fn_800F5C54(fn_8016A694(script, 7)), 2), 2, 0);
    direction[0] = (f32)(last.x - first.x);
    direction[1] = (f32)(last.y - first.y);
    direction[2] = 0.0f;
    fn_80211AAC(direction, direction);

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
        distance = direction[0] * point->x + direction[1] * point->y +
                   direction[2] * point->z;
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

    if (fn_80147EC4(&info) != 0) {
        void* object = *(void**)&info.bytes[92];
        s16 width = (s16)(max_z - min_z);

        fn_801964E8(object, 1, 0);
        fn_801978F8(object, 0);
        first.y = (s16)min_z;
        last.y = (s16)max_z;
        if (mode != 0) {
            handle = fn_80142A70(2, &first, width, lbl_8064D18C, 0,
                                 (s32)fn_8014BA14, (s32)object, user_value);
        } else {
            handle = fn_80142A70(2, &first, width, lbl_8064D18C, 0,
                                 0, 0, user_value);
        }
        handle = fn_8014B8D0(object, handle);
    }

    fn_8016A830(script, (double)handle);
    return 1;
}

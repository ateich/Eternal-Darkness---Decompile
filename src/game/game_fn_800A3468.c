typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Vec3_800A3468 {
    float x;
    float y;
    float z;
} Vec3_800A3468;

typedef struct Result800A3468 {
    u8 pad0[8];
    Vec3_800A3468 position;
    u8 pad14[0x14];
} Result800A3468;

typedef struct Info800A3468 {
    u8 pad0[0x264];
    struct {
        u8 pad0[0x12];
        u16 owner;
    }* data;
} Info800A3468;

extern float lbl_8064EEA4;
extern int fn_801A7468(void*);
extern int fn_8011F6A4(u32, int, int, int, Result800A3468*, int);
extern void* fn_801A7498(void*);
extern void *fn_80201814();
extern Info800A3468* fn_800A1D28(void*);
extern void fn_800A33A8(Vec3_800A3468*);
extern void fn_800A32B8(Vec3_800A3468*);
extern void fn_801AC9F4(u16, int, Vec3_800A3468*, int);

int fn_800A3468(u32 handle, void* resource)
{
    Result800A3468 result;
    Vec3_800A3468 position;
    int type = fn_801A7468(resource);
    int effect = -1;

    if (type == 4 || type == 6 || type == 8) {
        effect = 7;
    } else if (type == 5 || type == 7 || type == 9) {
        effect = 6;
    }

    if (fn_8011F6A4(handle, 28, effect, -1, &result, 1) != -1) {
        Info800A3468* info;

        fn_801A7498(resource);
        info = fn_800A1D28(fn_80201814());
        handle = info->data->owner;
        position = result.position;
        position.z = lbl_8064EEA4;
        fn_800A33A8(&position);
        fn_800A32B8(&position);
        fn_801AC9F4((u16)handle, 127, &position, 5);
    }
    return 1;
}

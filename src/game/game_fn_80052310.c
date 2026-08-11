typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern u16 fn_80050730(int type, int mode, u8* out_level, u8* out_flags,
                       u16* out_time, u32* out_value);
extern int fn_801AC9F4(u16 sound, u8 level, Vec3* position, u8 flags);
extern void fn_800EB458(const char* format, ...);
extern const char lbl_8024178C[];

int fn_80052310(int type, const s16* position)
{
    u8 level = 0;
    u8 flags = 0;
    u16 time = 0;
    u32 value = 0;
    int handle = 0;
    u16 sound = fn_80050730(type, 0, &level, &flags, &time, &value);

    if (sound != 0) {
        Vec3 converted;

        converted.x = position[0];
        converted.y = position[1];
        converted.z = position[2];
        handle = fn_801AC9F4(sound, level, &converted, flags);
        fn_800EB458(lbl_8024178C, type, sound, level);
    }

    return handle;
}

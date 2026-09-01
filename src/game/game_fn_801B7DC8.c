typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct SequenceInfo {
    u8 pad0[2];
    u16 flags;
    u8 arg2;
    u8 pitch;
    u8 key;
    u8 velocity;
    u8 arg3;
    u8 arg11;
} SequenceInfo;

extern SequenceInfo* fn_801BD1EC(u32);
extern s32 fn_801B64D0(u32, s32, u32, u32, u32, u32, u8, u8, u8, u16,
                       u16, u8, short, u8, u32);

s32 fn_801B7DC8(u32 sequence, u32 key, u32 velocity, u8 arg13, u32 arg14)
{
    s32 result = -1;
    SequenceInfo* info = fn_801BD1EC(sequence);

    if (info != 0) {
        if ((u8)key == 0xFF) {
            key = info->key;
        }
        if ((u8)velocity == 0xFF) {
            velocity = info->velocity;
        }
        result = fn_801B64D0(info->flags, info->pitch, info->arg2,
                             info->arg3 | 0x80, key, velocity, 0xFF, 0xFF,
                             0, 0, 0xFF, info->arg11, 0, arg13, arg14);
    }
    return result;
}

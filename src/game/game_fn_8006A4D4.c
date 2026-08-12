typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct ObjectInfo {
    void *unused;
    u8 *state;
} ObjectInfo;

extern ObjectInfo *fn_80201B8C(s32 object);

s32 fn_8006A4D4(s32 object)
{
    ObjectInfo *info;
    u8 *state;
    u32 flags;

    info = fn_80201B8C(object);
    if (info != 0) {
        state = info->state;
    } else {
        state = 0;
    }
    flags = state[9];
    flags &= 4;
    return !flags;
}

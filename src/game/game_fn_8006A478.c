typedef signed int s32;
typedef unsigned char u8;

typedef struct ObjectInfo {
    void *unused;
    u8 *state;
} ObjectInfo;

extern ObjectInfo *fn_80201B8C(s32 object);
extern s32 fn_80201B54(s32 object);

void fn_8006A478(s32 object)
{
    ObjectInfo *info;
    u8 *state;

    info = fn_80201B8C(object);
    if (info != 0) {
        state = info->state;
    } else {
        state = 0;
    }
    fn_80201B54(object);
    state[9] |= 4;
}

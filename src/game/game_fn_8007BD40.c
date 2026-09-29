typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef int s32;
typedef unsigned int u32;

typedef struct Vec3 { float x, y, z; } Vec3;
typedef struct EffectState {
    void *resource;
    u32 owner;
    u32 packed_velocity;
    u8 pad0C[0x10];
    s16 finished;
    u8 pad1E[4];
    s16 status;
    u8 pad24[2];
    u16 timer;
    u8 pad28[4];
    s8 retry;
    u8 pad2D[3];
    u32 flags;
} EffectState;

__declspec(section ".sdata") extern u8 lbl_8064C8DC[];
extern u8 lbl_8064B588[4];
extern u8 lbl_8064B58C[4];
extern unsigned int fn_800FBFB0(void);
#define fn_800FBFB0() ((int)fn_800FBFB0())
extern EffectState *fn_801FD6F4(void *);
extern void *fn_80201814(u32);
extern void *fn_80201BC8(void *);
extern void fn_8011F114(Vec3 *, void *);
extern s32 fn_801AC908(u32, Vec3 *, s32);
extern u32 fn_801AC8AC(u16, u8, s32, Vec3 *);
extern void fn_801FD880(void *, u8 *);
extern s32 fn_801FD8BC(void *);
extern u32 fn_80155DB4(void);
extern void fn_801FDEB4(void *, Vec3 *);
extern void fn_801FD80C(void *, u8 *);
extern void fn_801FDF74(void *, s32);
extern s32 fn_801FE05C(void *);
extern void fn_8007BCD4(void);

/* NonMatching: honest reconstruction of the effect update and fade state. */
s32 fn_8007BD40(void *input)
{
    struct Effect *arg = input;
    void *resource;
    void *transform;
    EffectState *state = fn_801FD6F4(arg);
    Vec3 position;
    u8 color[4];
    s8 x, y, z;
    s32 y_value, z_value;
    s32 lifetime;
    s32 random;
    u32 red;

    if (state != 0 && state->finished == 0) {
        resource = (void *)fn_80201814(state->owner);
        if (resource != 0) {
            if (fn_80155DB4() != 0) {
                transform = fn_80201BC8(resource);
                fn_8011F114(&position, transform);
                if (*(u16 *)(lbl_8064C8DC + 4) != 0 &&
                    fn_801AC908(*(u32 *)lbl_8064C8DC, &position, 255) == 0) {
                    *(u32 *)lbl_8064C8DC = fn_801AC8AC(
                        *(u16 *)(lbl_8064C8DC + 4), lbl_8064C8DC[6], 200,
                        &position);
                }
                fn_801FD880(arg, color);
                lifetime = fn_801FD8BC(arg);
                red = color[0];
                x = (s8)(state->packed_velocity >> 24);
                y_value = (s8)((state->packed_velocity >> 16) & 0xFF);
                y = y_value;
                z_value = (s8)((state->packed_velocity >> 8) & 0xFF);
                z = z_value;
                if (red == lbl_8064B58C[0] &&
                    color[1] == lbl_8064B58C[1] &&
                    color[2] == lbl_8064B58C[2]) {
                    random = fn_800FBFB0() & 63;
                    color[0] = lbl_8064B58C[0] +
                        (((lbl_8064B588[0] - lbl_8064B58C[0]) * random) >> 6);
                    color[1] = lbl_8064B58C[1] +
                        (((lbl_8064B588[1] - lbl_8064B58C[1]) * random) >> 6);
                    color[2] = lbl_8064B58C[2] +
                        (((lbl_8064B588[2] - lbl_8064B58C[2]) * random) >> 6);
                    color[0] = color[0] < 255 ? color[0] : 255;
                    color[1] = color[1] < 255 ? color[1] : 255;
                    color[2] = color[2] < 255 ? color[2] : 255;
                    lifetime = ((random * -200) >> 6) + 1300;
                    x = (s8)((fn_800FBFB0() & 31) - 16);
                    y_value = (s8)((fn_800FBFB0() & 31) - 16);
                    y = y_value;
                    z_value = (s8)((fn_800FBFB0() & 31) - 16);
                    z = z_value;
                } else {
                    s32 value;
                    value = red - 2;
                    color[0] = value > lbl_8064B58C[0] ? value : lbl_8064B58C[0];
                    color[1] = color[1] - 2 > lbl_8064B58C[1] ?
                        color[1] - 2 : lbl_8064B58C[1];
                    value = color[2] - 2;
                    color[2] = value > lbl_8064B58C[2] ? value : lbl_8064B58C[2];
                    lifetime = lifetime - 50 > 1300 ? lifetime - 50 : 1300;
                    if ((s8)x > 0) x = (s8)(x - 1);
                    else if (x < 0) x = (s8)(x + 1);
                    if ((s8)y > 0) y = (s8)(y - 1);
                    else if (y < 0) y = (s8)(y + 1);
                    if ((s8)z > 0) z = (s8)(z - 1);
                    else if (z < 0) z = (s8)(z + 1);
                }
                state->packed_velocity = ((u8)x << 24) | ((u8)y << 16) |
                                         ((u8)z << 8);
                position.x += x;
                position.y += y;
                position.z += z;
                fn_801FDEB4(arg, &position);
                fn_801FD80C(arg, color);
                fn_801FDF74(arg, lifetime);
                state->flags = 0x10000;
                state->timer = 0;
                state->retry = 5;
            } else if (state->retry > 0) {
                state->retry--;
            } else {
                state->finished = 1;
            }
        } else {
            state->finished = 1;
        }
    } else if (fn_801FE05C(arg) != 0) {
        state->status = 2;
        fn_8007BCD4();
    }
    return 0;
}

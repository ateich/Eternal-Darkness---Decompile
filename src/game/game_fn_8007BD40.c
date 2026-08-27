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

extern u32 lbl_8064D954;
extern u8 lbl_8064C604[];
extern unsigned int fn_800FBFB0(void);
#define fn_800FBFB0() ((int)fn_800FBFB0())
extern EffectState *fn_801FD6F4(void *);
extern void *fn_80201814();
extern void *fn_80201BC8();
extern void fn_8011F114();
extern s32 fn_801AC908(u32, Vec3 *, s32);
extern u32 fn_801AC8AC(u16, u8, s32, Vec3 *);
extern void fn_801FD880(void *, u8 *);
extern s32 fn_801FD8BC(void *);
extern s32 fn_80155DB4(void);
extern void fn_801FDEB4(void *, Vec3 *);
extern void fn_801FD80C(void *, u8 *);
extern void fn_801FDF74(void *, s32);
extern s32 fn_801FE05C(void *);
extern void fn_8007BCD4(void);

/* NonMatching: honest reconstruction of the effect update and fade state. */
s32 fn_8007BD40(void *arg)
{
    EffectState *state = fn_801FD6F4(arg);
    Vec3 position;
    u8 color[4];
    s32 x, y, z;
    s32 lifetime;
    s32 random;

    if (state != 0 && state->finished == 0) {
        void *resource = (void *)fn_80201814(state->owner);
        if (resource != 0) {
            if (fn_80155DB4() != 0) {
                fn_8011F114(&position, fn_80201BC8(resource));
                if (*(u16 *)((u8 *)&lbl_8064D954 + 4) != 0 &&
                    fn_801AC908(lbl_8064D954, &position, 255) == 0) {
                    lbl_8064D954 = fn_801AC8AC(
                        *(u16 *)((u8 *)&lbl_8064D954 + 4),
                        *((u8 *)&lbl_8064D954 + 6), 200, &position);
                }
                fn_801FD880(arg, color);
                lifetime = fn_801FD8BC(arg);
                x = (s8)(state->packed_velocity >> 24);
                y = (s8)(state->packed_velocity >> 16);
                z = (s8)(state->packed_velocity >> 8);
                if (color[0] == lbl_8064C604[0] &&
                    color[1] == lbl_8064C604[1] &&
                    color[2] == lbl_8064C604[2]) {
                    random = fn_800FBFB0() & 63;
                    color[0] += (lbl_8064C604[-4] - color[0]) * random / 64;
                    color[1] += (lbl_8064C604[-3] - color[1]) * random / 64;
                    color[2] += (lbl_8064C604[-2] - color[2]) * random / 64;
                    if (color[0] > 255) color[0] = 255;
                    if (color[1] > 255) color[1] = 255;
                    if (color[2] > 255) color[2] = 255;
                    lifetime = 1300 - (200 * random) / 64;
                    x = (s8)((fn_800FBFB0() & 31) - 16);
                    y = (s8)((fn_800FBFB0() & 31) - 16);
                    z = (s8)((fn_800FBFB0() & 31) - 16);
                } else {
                    s32 value;
                    value = color[0] - 2;
                    if (value > lbl_8064C604[0]) color[0] = value;
                    else color[0] = lbl_8064C604[0];
                    value = color[1] - 2;
                    if (value > lbl_8064C604[1]) color[1] = value;
                    else color[1] = lbl_8064C604[1];
                    value = color[2] - 2;
                    if (value > lbl_8064C604[2]) color[2] = value;
                    else color[2] = lbl_8064C604[2];
                    if (lifetime - 50 > 1300) lifetime -= 50;
                    else lifetime = 1300;
                    if (x > 0) x--; else if (x < 0) x++;
                    if (y > 0) y--; else if (y < 0) y++;
                    if (z > 0) z--; else if (z < 0) z++;
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

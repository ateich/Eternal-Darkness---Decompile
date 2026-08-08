typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

#pragma use_lmw_stmw on

typedef struct EffectState {
    u8 pad_00[4];
    f32 x;
    f32 y;
    f32 scale;
    u8 pad_10[4];
    s32 mode;
    u8 pad_18[4];
    s32 variant;
    s16 left;
    s16 top;
    u8 pad_24[6];
    u8 alpha;
} EffectState;

typedef struct ParticlePoint {
    s16 x;
    s16 y;
} ParticlePoint;

typedef struct EffectData {
    char resource[0x50];
    ParticlePoint point[3][5];
    s16 delay[3][5];
    u8 pad_AA[2];
    s16 age[3][5];
    u8 pad_CA[2];
    u32 color[3];
} EffectData;

extern const u32 lbl_80238C28[6];
extern const u32 lbl_80238C40[3];
extern EffectData lbl_8023DEB0;
extern u32 lbl_8064C2A8;
extern void* lbl_8064CD7C;
extern s32 lbl_8064D5A8;
extern u8 lbl_8064C6E8;
extern const u32 lbl_8064DF88;
extern const u32 lbl_8064DF8C;
extern const f32 lbl_8064DF90;
extern const f32 lbl_8064DF94;
extern const f32 lbl_8064DF98;
extern const f32 lbl_8064DF9C;

extern void fn_801F1034(void);
extern void fn_801A852C(u32*, s32, s32, u32);
extern void fn_801A85D4(u32*, s32, s32, u32);
extern void fn_801ECF50(s32);
extern void fn_801A8D38(s32);
extern void fn_80226AB4(s32, s32, s32);
extern void fn_80225F4C(s32, void*, s32);
extern void fn_80026740(void);
extern void fn_80026754(s32, s32, s32);
extern void fn_80026DAC(s32, s32);
extern void fn_80026DBC(u32);
extern u32 fn_800FBFB0(void);
extern s32 fn_801ED3F4(void*);
extern void fn_801A8F08(s16, s16, s16, s16, s32, s32, s32, s32, s32);

void fn_80026768(EffectState* state)
{
    u32 colors[6];
    u32 texcoords[3];
    u32 packed[6];
    s16 edge[5];
    s32 alpha;
    s32 x0;
    s32 x1;
    s32 y0;
    s32 y1;
    s32 bottom;
    s32 texture;
    s32 depth;
    s32 variant;
    s32 i;
    u32 draw_color;

    if (state == 0 || state->alpha == 0) {
        return;
    }

    alpha = state->alpha;
    if (state->mode != 0) {
        alpha = (u8)(lbl_8064DF90 * alpha);
    }

    for (i = 0; i < 6; i++) {
        colors[i] = lbl_80238C28[i];
    }
    for (i = 0; i < 3; i++) {
        texcoords[i] = lbl_80238C40[i];
    }

    variant = state->variant;
    texture = state->mode != 0 ? -1 : -30360;
    depth = state->mode != 0 ? -1 : (alpha | 0xFFFF0A00);
    draw_color = (alpha | 0x0A0A0A00);
    for (i = 0; i < 2; i++) {
        packed[i] = draw_color;
    }
    for (; i < 4; i++) {
        packed[i] = depth;
    }
    packed[4] = colors[variant * 2] | alpha;
    packed[5] = colors[variant * 2 + 1] | alpha;

    x0 = (s32)(lbl_8064DF98 * state->x);
    x1 = (s32)(lbl_8064DF98 * state->y);
    if (x0 > x1) {
        s32 swap = x0;
        x0 = x1;
        x1 = swap;
    }
    y0 = (s32)(lbl_8064DF9C + (61 - x0) * state->scale);
    y1 = (s32)(lbl_8064DF9C + (61 - x1) * state->scale);
    bottom = (s32)(lbl_8064DF94 + lbl_8064DF98 * state->scale);
    edge[0] = y0;
    edge[1] = y0;
    edge[2] = y1;
    edge[3] = y1;
    edge[4] = bottom;

    fn_801F1034();
    draw_color = lbl_8064C2A8;
    fn_801A852C(&draw_color, -1, 0, 0);
    fn_801ECF50(9);

    x0 = state->left + 6;
    x1 = x0 + 19;
    for (i = 0; i < 3; i++) {
        s32 top = state->top + edge[i * 2];
        s32 bot = state->top + edge[i * 2 + 1];
        fn_80226AB4(0x80, 5, 4);
        fn_80026754(x0, top, texture);
        fn_80026DBC(packed[i * 2]);
        fn_80026DAC(0, 0);
        fn_80026754(x1, top, texture);
        fn_80026DBC(packed[i * 2]);
        fn_80026DAC(0, 0);
        fn_80026754(x1, bot, texture);
        fn_80026DBC(packed[i * 2 + 1]);
        fn_80026DAC(0, 0);
        fn_80026754(x0, bot, texture);
        fn_80026DBC(packed[i * 2 + 1]);
        fn_80026DAC(0, 0);
        fn_80026740();
    }

    fn_80225F4C(13, lbl_8023DEB0.resource, 4);
    ((u8*)&lbl_8023DEB0.color[variant])[3] = state->alpha;
    draw_color = lbl_8023DEB0.color[variant];
    fn_801A852C(&draw_color, 0, 9, 0x80000000);

    for (i = 0; i < 5; i++) {
        ParticlePoint* point = &lbl_8023DEB0.point[variant][i];
        s16* age = &lbl_8023DEB0.age[variant][i];
        s16* delay = &lbl_8023DEB0.delay[variant][i];
        s32 limit = edge[4] - state->top;

        if (*age == 1) {
            lbl_8064C6E8++;
            if (lbl_8064C6E8 >= 20) {
                lbl_8064C6E8 = 0;
            }
        }
        if (*age >= 24) {
            point->y = limit + (fn_800FBFB0() & 0x1F);
            point->x = (fn_800FBFB0() & 7) + 2;
            *delay = (fn_800FBFB0() & 3) + 5;
            *age = 0;
        }
        if (point->y <= limit) {
            fn_801A8F08(state->left + 6 + point->x,
                        state->top + point->y,
                        state->left + 6 + point->x + *delay,
                        state->top + point->y + *delay,
                        texture, *age >> 3, 5, 0, 5);
        }
        if (point->y <= -3) {
            (*age)++;
        } else if (lbl_8064D5A8 % (10 - *delay) == 0) {
            point->y--;
        }
    }

    fn_80225F4C(13, lbl_8023DEB0.resource, 4);
    if (state->mode != 0) {
        draw_color = lbl_8064DF88;
        ((u8*)&draw_color)[3] = state->alpha;
        fn_801A852C(&draw_color, 0, 0, 0x80000000);
        fn_801A8F08(state->left, state->top, state->left + 31,
                    state->top + 30, -1, 0, 5, 0, 5);
        fn_801A8F08(state->left, state->top + edge[4], state->left + 31,
                    state->top + edge[4] + 30, -1, 4, 5, 0, 5);
    } else {
        fn_801ED3F4(lbl_8064CD7C);
        draw_color = lbl_8064DF8C;
        ((u8*)&draw_color)[3] = state->alpha;
        fn_801A85D4(&draw_color, 14, 15, 0x80000000);
        fn_801A8F08(state->left, state->top, state->left + 31,
                    state->top + 30, -30360, 0, 5, 0, 5);
        fn_801A8F08(state->left, state->top + edge[4], state->left + 31,
                    state->top + edge[4] + 30, -30360, 4, 5, 0, 5);
    }
}

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct Color {
    u32 value;
} Color;

typedef struct UiState {
    u8 pad_00[0x1C];
    s32 texture;
    s16 x;
    s16 y;
    s16 number;
    u8 pad_26[4];
    u8 alpha;
} UiState;

extern const Color lbl_8064DFB0;
extern const f32 lbl_8064DFB4;
extern const u16 lbl_8023DF88[][2];
extern const u16 lbl_8023DFAC[][2];
extern u8 lbl_802515D0[];
extern char lbl_8064B2F0;
extern void* lbl_8064C4E8;

extern void fn_801A852C(Color, s32, s32, u32);
extern void fn_801A8DE8(void*, s16, s16, s16, s16, s32, s32, s32);
extern void fn_801E3AA4(s32);
extern void fn_801E5430(s16, s16);
extern void fn_801E3A34(Color);
extern void fn_801E56AC(const char*, ...);
extern void fn_801ED3F4(void*);

void fn_80027030(UiState* state)
{
    Color color;
    s32 texture;

    if (state == 0) {
        return;
    }
    if (state->alpha == 0) {
        return;
    }

    color = lbl_8064DFB0;
    ((u8*)&color)[3] = state->alpha;
    fn_801A852C(color, 0, state->texture, 0x80000000);

    texture = state->texture;
    fn_801A8DE8(lbl_802515D0,
                state->x + lbl_8023DF88[texture][0],
                state->y + lbl_8023DF88[texture][1],
                state->x + lbl_8023DFAC[texture][0],
                state->y + lbl_8023DFAC[texture][1],
                -1, 0, 5);

    fn_801E3AA4(0);
    fn_801E5430(state->x + 0x20, state->y + 0x2E);
    fn_801E3A34(color);
    fn_801E56AC(&lbl_8064B2F0, lbl_8064DFB4, state->number);
    fn_801ED3F4(lbl_8064C4E8);
}

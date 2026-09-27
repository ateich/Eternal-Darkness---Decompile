typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Color {
    u8 r, g, b, a;
} Color;

typedef struct ColorDelta {
    s8 r, g, b, a;
} ColorDelta;

typedef struct ActorState {
    char pad_000[0x197];
    s8 active;
    int handle;
} ActorState;

extern Color lbl_8064F380;
extern ColorDelta lbl_8064F384;
extern ColorDelta lbl_8064F388;
extern Color lbl_8064F38C;

extern u16 fn_8012DBE8(u8* owner, u32 index, u8* color);
extern void fn_800A1AF0(void* object, int index, int active, int copy_values,
                        Color first, ColorDelta second, Color third, u16 mode);
extern void fn_800A3C84(void *, int, int, int);
extern void fn_800CFFFC(void *, ActorState *);
extern void fn_800A4C98(ActorState *, void *);
extern void fn_800A4670(ActorState *, void *, int);
extern void fn_800A2D78(ActorState *);
extern void fn_800A4D04(ActorState *);
extern void fn_800A4634(ActorState *, void *);

void fn_800D322C(ActorState *state, void *object, int enabled, int value)
{
    u16 flags = 0x80;
    Color disabled_color;
    ColorDelta delta;
    ColorDelta disabled_delta;
    ColorDelta enabled_delta;
    Color color;
    Color enabled_color;

    disabled_color = lbl_8064F380;
    disabled_delta = lbl_8064F384;
    enabled_delta = lbl_8064F388;
    enabled_color = lbl_8064F38C;

    if (enabled != 0) {
        flags |= 0x32;
        color = enabled_color;
        delta = enabled_delta;
    } else {
        flags |= 0x12;
        color = disabled_color;
        delta = disabled_delta;
    }

    if (state->handle != -1) {
        fn_8012DBE8(object, 15, (u8*)&color);
        fn_800A1AF0(object, state->handle, enabled, value, color, delta, color, flags);
    }
    if (state->active != 0) {
        fn_800A3C84(object, state->handle, enabled, value);
    }
    if (enabled != 0) {
        fn_800CFFFC(object, state);
        fn_800A4C98(state, object);
        fn_800A4670(state, object, 32);
    } else {
        fn_800A2D78(state);
        fn_800A4D04(state);
        fn_800A4634(state, object);
    }
}

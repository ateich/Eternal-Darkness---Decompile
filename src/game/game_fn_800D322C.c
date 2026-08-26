typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Vec3 {
    u32 x;
    u32 y;
    u32 z;
} Vec3;

typedef struct ActorState {
    char pad_000[0x197];
    s8 active;
    int handle;
} ActorState;

extern u32 lbl_8064F380;
extern u32 lbl_8064F384;
extern u32 lbl_8064F388;
extern u32 lbl_8064F38C;

extern unsigned short fn_8012DBE8(void *, int, u32 *);
extern void fn_800A1AF0(void *, int, int, int, Vec3 *, u32 *, u32 *, u16);
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
    volatile Vec3 first;
    volatile Vec3 second;
    Vec3 position;
    u32 upper;
    u32 lower;
    u32 a = lbl_8064F380;
    u32 b = lbl_8064F384;
    u32 c = lbl_8064F388;
    u32 d = lbl_8064F38C;

    first.x = d;
    first.z = c;
    second.x = b;
    second.z = a;

    if (enabled != 0) {
        flags |= 0x32;
        first.y = d;
        second.y = c;
    } else {
        flags |= 0x12;
        first.y = a;
        second.y = b;
    }

    if (state->handle != -1) {
        fn_8012DBE8(object, 15, (u32 *)&first.y);
        position.x = first.y;
        lower = second.y;
        upper = first.y;
        fn_800A1AF0(object, state->handle, enabled, value,
                    &position, &lower, &upper, flags);
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

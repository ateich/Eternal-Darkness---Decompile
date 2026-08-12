typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct TransitionState {
    u8 pad_00[0x1C];
    u16 active;
    u8 pad_1E[0x41];
    u8 requested;
} TransitionState;

extern s32 fn_800AD354(void *object);
extern void fn_80201D2C(void *, s32);
extern void fn_80201D14(void *, s32);

s32 fn_80054C14(void *object, TransitionState *state)
{
    s32 result = 0;

    if (state->requested == 0 && state->active == 0 && fn_800AD354(object) != 0) {
        state->requested = 1;
        result = 1;
        fn_80201D2C(object, 0x7D);
        fn_80201D14(object, 1);
    }

    return result;
}

typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;

extern void* fn_8011FCE4(void* object);
extern void fn_80008710(void* object, void* value);
extern void fn_80045A24(s32 value, s32 flags);
extern void fn_8001DA0C(void);
extern void fn_8001D9FC(int mode);
extern void fn_801EFE84(int value);

typedef struct GameState {
    void* object;
    u8 pad[8];
} GameState;

typedef struct TransitionState {
    u8 pad0[0x1D0];
    s16 timer;
    u8 pad1[8];
    u8 value;
    u8 pad2;
    s8 option_flag;
    u8 pad3[4];
    s8 type;
    u8 flag;
    u8 active;
} TransitionState;

extern GameState lbl_803003C8;
extern u8 lbl_8030F540[];
extern void* lbl_8064C4E4;
extern s32 lbl_8064C6D4;

void fn_80052580(s32 type, s32 value, s32 flag, s32 timer, s32 options)
{
    lbl_8064C6D4 = 0;

    if (lbl_8064C4E4 != 0) {
        fn_80008710(lbl_803003C8.object, fn_8011FCE4(lbl_8064C4E4));
    }

    if (type != 0) {
        if ((s8)lbl_8030F540[0x1DC] != 0) {
            options |= 1;
        }
        fn_80045A24(1, options);
    }

    {
        TransitionState* state = (TransitionState*)lbl_8030F540;

        state->active = 1;
        state->type = type;
        state->flag = flag;
        state->timer = timer;
        state->value = value;

        fn_8001DA0C();
        fn_8001D9FC(4);

        if (state->value != 0x25 && state->value != 0x26 && state->value != 0x27 &&
            state->type != 0) {
            fn_801EFE84(1);
        }
    }
}

typedef signed int s32;
typedef unsigned char u8;

typedef struct RuntimeObject {
    unsigned char data[0xC0];
    void *sound;
    void *effect;
    unsigned char tail[0x42];
    u8 state;
    u8 unused_10B;
    u8 flags;
} RuntimeObject;

typedef struct RuntimeState {
    RuntimeObject *runtime;
} RuntimeState;

typedef struct EventState {
    unsigned char data[0x9E];
    u8 mode;
} EventState;

extern s32 fn_80201B54(void *object);
extern void fn_8006845C(void *object);
extern void fn_80068074(void *object);
extern void fn_80187A34(void *sound, s32 fade);
extern void fn_80067DA4(RuntimeState *state);
extern void fn_80067E24(RuntimeState *state);
extern void *fn_8014C7B8(void *effect);
extern signed char fn_801FEA10(void);
extern void fn_801FE934(void *context, s32 value);
extern void fn_80149E28(void *effect);
extern void fn_8012B344(s32 event);
extern void fn_80067D30(void *object);
extern void fn_80068FE0(void *object, s32 event);
extern void fn_80067B6C(void);
extern void fn_8011E174(s32 value, s32 unused);
extern void fn_80201D34(void *object, s32 state);
extern void fn_80201D1C(void *object, s32 value);

void fn_8006872C(void *object, EventState *event_state, s32 unused,
                 RuntimeState *state, s32 event)
{
    void *context;

    fn_80201B54(object);
    fn_8006845C(object);
    fn_80068074(object);
    if (state->runtime->sound != 0 && *(void **)((unsigned char *)state->runtime->sound + 0x88) != 0) {
        fn_80187A34(*(void **)((unsigned char *)state->runtime->sound + 0x88), 1);
        state->runtime->sound = 0;
    } else {
        fn_80067DA4(state);
    }
    fn_80067E24(state);
    if (state->runtime->effect != 0) {
        context = fn_8014C7B8(state->runtime->effect);
        if (context != 0 && fn_801FEA10() == -1) {
            fn_801FE934(context, 0);
        }
        fn_80149E28(state->runtime->effect);
        state->runtime->effect = 0;
    }
    fn_8012B344(event);
    fn_80067D30(object);
    fn_80068FE0(object, event);
    fn_80067B6C();
    state->runtime->state = 5;
    state->runtime->flags = 0;
    if (event_state->mode == 1) {
        fn_8011E174(0x40, 0);
    }
    fn_80201D34(object, 4);
    fn_80201D1C(object, 1);
}

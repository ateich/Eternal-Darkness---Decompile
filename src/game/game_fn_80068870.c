typedef signed int s32;
typedef signed short s16;

typedef struct Vec3 { float x, y, z; } Vec3;
typedef struct RuntimeObject {
    unsigned char data[0xC0];
    void *sound;
    void *effect;
} RuntimeObject;
typedef struct RuntimeState { RuntimeObject *runtime; } RuntimeState;

const float lbl_8064E710 = 150.0f;
extern void fn_8011F114();
extern int fn_801AC9F4(s32 kind, s32 value, Vec3 *position, s32 count);
extern void fn_801D38BC(s32 kind, s32 *word, s16 *half);
extern void fn_80152404(Vec3 *position, s16 value, s32 owner, s32 kind, s32 *word);
extern void fn_80187A34(void *sound, s32 fade);
extern void fn_80067DA4(RuntimeState *state);
extern void fn_80067E24(RuntimeState *state);
extern void *fn_8014C7B8(void *effect);
extern signed char fn_801FEA10(void);
extern void fn_801FE934(void *context, s32 value);
extern void fn_80149E28(void *effect);

void fn_80068870(s32 unused1, s32 state_value, RuntimeState *state, s32 owner)
{
    Vec3 position;
    s32 result_word;
    s32 word;
    s16 half;
    void *context;

    fn_8011F114(&position, (void *)state_value);
    fn_801AC9F4(0x3B, 0x64, &position, 5);
    position.z += lbl_8064E710;
    fn_801D38BC(2, &result_word, &half);
    word = result_word;
    fn_80152404(&position, half, owner, 0xC, &word);
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
}

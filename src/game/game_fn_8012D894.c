typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Vec4 {
    float x;
    float y;
    float z;
    float w;
} Vec4;

typedef struct RotationState {
    u8 padding[0x26];
    u16 previous_frame;
    u16 frame;
    u8 padding_2a[0x42];
    short current[4];
    short target[4];
    short alternate_target[4];
    float amount;
    float step;
    int turns;
} RotationState;

extern const float lbl_806501D8;
extern const float lbl_806501DC;

extern void fn_8012BE64(const short*, Vec4*);
extern void fn_8012BE78(const Vec4*, short*);
extern int fn_8012D9D4(float*, const float*, float);
extern void fn_8017A7D4(const Vec4*, const Vec4*, float, Vec4*);
extern void fn_8017A9B8(const Vec4*, const Vec4*, float, Vec4*, int);

int fn_8012D894(RotationState* state)
{
    Vec4 target;
    Vec4 alternate_target;
    Vec4 current;
    float sampled_step;
    float* interpolated_amount;
    const float* interpolation_step;
    int complete;

    fn_8012BE64(state->target, &target);
    fn_8012BE64(state->alternate_target, &alternate_target);
    fn_8012BE64(state->current, &current);

    interpolated_amount = &state->amount;
    interpolation_step = &state->step;
    sampled_step = state->step;
    complete = fn_8012D9D4(interpolated_amount, interpolation_step,
                           sampled_step > lbl_806501D8
                               ? lbl_806501DC
                               : lbl_806501D8);

    if (state->turns != 0) {
        fn_8017A9B8(&target, &alternate_target, state->amount, &current,
                    state->turns);
    } else {
        fn_8017A7D4(&target, &alternate_target, state->amount, &current);
    }

    if (state->frame != 0) {
        state->previous_frame = state->frame;
    }
    fn_8012BE78(&current, state->current);
    return complete;
}

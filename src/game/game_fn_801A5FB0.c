typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

typedef struct Sample {
    int state;
    float angle;
    float value;
    int magnitude;
} Sample;

typedef struct Bucket {
    int unused;
    int count;
} Bucket;

typedef struct State {
    char pad0[8];
    u32 flags;
    int magnitude;
    int state;
    float angle;
    char pad18[4];
    float value;
    float base_angle;
    float target_angle;
    u32 mode;
    char pad2c[4];
    int maximum;
    s16 field34;
    s16 x;
    s16 y;
    char pad3a[4];
    u16 field3e;
} State;

extern double lbl_80650DB0;
extern volatile float lbl_80650DA0;
extern float lbl_80650DA4;
extern float lbl_80650DA8;
extern int lbl_8064C288;
extern int lbl_8064C28C;
extern int lbl_8064D260;
extern Sample lbl_8025120C[];
extern Bucket lbl_8025127C[];

extern float fn_800490E8(float, float);
extern void fn_8017A12C(float*, float, float);
extern float fn_801A657C(int);
extern int fn_801A65C0(int);
extern int fn_801A6EC4(void);
extern float fn_801A65E0(int);
extern int fn_801A6350(int);
extern int fn_801A63A0(Bucket*);
extern void fn_801A6410(int, Sample*, float*, float*, int*);

void fn_801A5FB0(State* state)
{
    int magnitude;
    Bucket* counts;
    Sample* samples;
    int i;
    Bucket* bucket;
    s16 x;
    s16 y;
    float absolute;
    float result[2];
    int next_state;

    if (state->flags & 8) {
        x = state->x;
        y = state->y;
        state->field34 = 2;
        magnitude = x * x + y * y;
        state->angle = state->base_angle + fn_800490E8((float)*(volatile s16*)&state->y, (float)*(volatile s16*)&state->x);
        fn_8017A12C(result, state->target_angle, state->angle);
        absolute = result[0] < lbl_80650DA0 ? -result[0] : result[0];
        if (absolute > lbl_80650DA4 && magnitude <= 100 && !(state->mode & 0xf)) {
            if ((result[0] < lbl_80650DA0 ? -result[0] : result[0]) > lbl_80650DA8) {
                state->state = 0x16;
            } else {
                state->state = 0xf;
            }
            state->value = fn_801A657C(magnitude);
            state->flags |= 0x80;
            goto record;
        }
        if (magnitude > 100) {
            if (state->flags & 0x20) {
                state->state = 1;
                if (magnitude < 1600) {
                    state->magnitude = (magnitude << 16) / 1600;
                }
                state->flags |= 0x80;
            } else if (state->flags & 0x10) {
                if (state->field3e != 0) {
                    state->state = 3;
                } else {
                    state->state = 2;
                    if (magnitude < 1600) {
                        state->magnitude = (magnitude << 16) / 1600;
                    }
                    if (state->field3e != 0 && state->magnitude > state->maximum) {
                        state->magnitude = state->maximum;
                    }
                }
                state->flags |= 0x80;
            } else {
                if (magnitude <= 2116) {
                    state->state = lbl_8064C288;
                    if (magnitude < 1024) {
                        state->magnitude = (magnitude << 16) / 1024;
                    }
                } else {
                    state->state = lbl_8064C28C;
                    state->magnitude = fn_801A65C0(magnitude);
                }
                state->flags |= 0x80;
            }
            if (fn_801A6EC4()) {
                state->value = fn_801A65E0(magnitude);
            } else {
                state->value = fn_801A657C(magnitude);
            }
        }
    }

record:
    lbl_8025120C[lbl_8064D260].state = state->state;
    lbl_8025120C[lbl_8064D260].angle = state->angle;
    lbl_8025120C[lbl_8064D260].value = state->value;
    lbl_8025120C[lbl_8064D260].magnitude = state->magnitude;
    lbl_8064D260++;
    if (lbl_8064D260 >= 7) {
        lbl_8064D260 = 0;
    }

    counts = lbl_8025127C;
    samples = lbl_8025120C;
    counts[0].count = 0;
    counts[1].count = 0;
    counts[2].count = 0;
    counts[3].count = 0;
    counts[4].count = 0;
    for (i = 0; i < 7; i++) {
        bucket = &counts[fn_801A6350(samples[i].state)];
        bucket->count++;
    }
    next_state = fn_801A63A0(lbl_8025127C);
    if (next_state == state->state) {
        return;
    }
    state->state = fn_801A63A0(lbl_8025127C);
    fn_801A6410(state->state, lbl_8025120C, &state->angle, &state->value, &state->magnitude);
    if (state->state != -1) {
        state->flags |= 0x80;
    } else {
        state->flags &= 0xFFFFFF7F;
    }
}

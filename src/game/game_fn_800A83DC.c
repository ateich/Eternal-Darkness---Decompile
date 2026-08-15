typedef struct UpdateState {
    unsigned char pad0[8];
    int timer8;
    unsigned char padC[4];
    int timer10;
    unsigned char pad14[0x18];
    int timer2C;
    int timer30;
    int target;
    int timer38;
} UpdateState;

extern int fn_800AD3A4(void*);
extern void fn_800A80CC(int, void*, void*, UpdateState*);
extern int fn_800A82C8(void);
extern void* fn_80201814(void*);
extern int fn_80036E50(void*);
extern int fn_80201B64(void*);
extern void fn_800A821C(int, void*, void*, void*, UpdateState*, void*);

int fn_800A83DC(void* object, void* source, void* extra, int index,
                UpdateState* state)
{
    int result = 1;

    if (fn_800AD3A4(object) != 0) {
        return 0;
    }

    if (state->timer10 > 0) {
        state->timer10--;
    }
    if (state->timer8 > 0) {
        state->timer8--;
    }
    if (state->timer38 > 0) {
        state->timer38--;
    }

    if (state->timer2C > 0) {
        state->timer2C--;
        if (state->timer2C == 0) {
            if (state->timer8 != 0) {
                state->timer2C = 1;
            } else {
                fn_800A80CC(index, object, source, state);
                result = 0;
            }
        }
    } else if (fn_800A82C8() != 0) {
        state->timer2C = 300;
    }

    if (state->timer30 > 0) {
        state->timer30--;
        if (state->timer30 == 0) {
            if (state->timer8 != 0 || result == 0) {
                state->timer30 = 1;
            } else {
                void* target = fn_80201814((void*)state->target);
                if (target != 0) {
                    if (fn_80036E50(target) == 6 &&
                        (fn_80201B64(target) == 6 ||
                         fn_80201B64(target) == 8)) {
                        state->target = 0;
                    } else {
                        fn_800A821C(0x810, (void*)state->target, object, source,
                                    state, extra);
                        result = 0;
                    }
                }
            }
        }
    }
    return result;
}

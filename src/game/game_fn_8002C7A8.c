typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef int s32;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct ScreenEffectState {
    void* draw_callback;
    float current_x;
    float target_x;
    float current_y;
    float target_y;
    s32 enabled;
    s32 unk18;
    s32 type;
    char unk20[6];
    s16 timer;
    char unk28[2];
    u8 value;
    u8 limit;
} ScreenEffectState;

extern s32 lbl_8064D6EC;
extern void* lbl_8064C4E0;
extern const double lbl_8064E098;
extern const double lbl_8064E0A0;
extern const float lbl_8064E0A8;
extern const float lbl_8064E0AC;

extern s32 fn_80200C10(void*);
extern int fn_80200C38();
extern void fn_80200C20(void*);
extern s32 fn_800460EC(s32);
extern void *fn_80201B8C();
extern int fn_80201B54();
extern void fn_80201D2C(void *, s32);
extern void fn_80201D14(void *, s32);
extern int fn_801E8328();
extern void fn_80201D34(void *, s32);
extern void fn_80201D1C(void *, s32);
extern int fn_801E79FC(void*, int);
extern void fn_80026070(ScreenEffectState*);
extern void fn_80026768(void);

s32 fn_8002C7A8(void* callback, s32 phase, void* event)
{
    s32 event_id = fn_80200C10(event);
    s32 busy = fn_800460EC(event_id);
    ScreenEffectState* state = *(ScreenEffectState**)((char*)fn_80201B8C(callback) + 0x14);
    fn_80201B54(callback);

    if (event_id == 3) {
        state->enabled = 1;
        state->draw_callback = fn_80026768;
        if (busy == 0 && lbl_8064D6EC == 0) {
            if (state->type != 2 || fn_801E79FC(lbl_8064C4E0, 0x257) != 0) {
                fn_80026070(state);
            }
        }
    }

    if (phase == 0) {
        if (event_id == 1) {
            fn_80201D2C(callback, 1);
            fn_80201D14(callback, 1);
            return 1;
        }
        if (event_id == 0x10) {
            Vec3* values = (Vec3*)fn_80200C38(event);
            float scale;
            float normalized_y;
            float normalized_x;
            fn_80200C20(event);
            scale = values->z;
            normalized_y = values->y / scale;
            normalized_x = values->x / scale;
            state->target_x = normalized_y;
            state->current_x = normalized_x;
            fn_80201D2C(callback, 0xA);
            fn_80201D14(callback, 1);
            return 1;
        }
        if (event_id == 0x11) {
            state->limit = 0;
            state->value = 0;
            fn_80201D2C(callback, 1);
            fn_80201D14(callback, 1);
            return 1;
        }
        if (event_id == 0x39) {
            fn_801E8328(2, callback);
            fn_80201D34(callback, 0);
            fn_80201D1C(callback, 1);
            return 1;
        }
        goto unhandled;
    }

    if (phase == 1) {
        goto unhandled;
    }

    if (phase == 0x26) {
        if (event_id == 1) {
            state->timer = 60;
            return 1;
        }
        if (event_id == 3) {
            if (busy == 0) {
                s32 timer = state->timer - 1;
                state->timer = timer;
                if ((s16)timer <= 1) {
                    fn_80201D2C(callback, 0xB);
                    fn_80201D14(callback, 1);
                }
            }
            return 1;
        }
        goto unhandled;
    }

    if (phase == 0xC) {
        if (event_id != 3) {
            goto unhandled;
        }
        if (busy == 0) {
            if (state->current_y <= state->target_y) {
                state->current_y = (float)((double)state->current_y + lbl_8064E098);
            } else if (state->current_y >= state->target_y) {
                state->current_y = (float)((double)state->current_y - lbl_8064E098);
            }

            if (state->current_x <= state->target_x) {
                state->current_x = (float)((double)state->current_x + lbl_8064E0A0);
                if (state->current_x >= state->target_x &&
                    state->current_y < lbl_8064E0A8 + state->target_y &&
                    state->current_y > state->target_y - lbl_8064E0A8) {
                    state->current_y = state->target_y;
                    fn_80201D2C(callback, 0x26);
                    fn_80201D14(callback, 1);
                }
            } else if (state->current_x >= state->target_x) {
                state->current_x -= lbl_8064E0AC;
                if (state->current_x <= state->target_x &&
                    state->current_y < lbl_8064E0A8 + state->target_y &&
                    state->current_y > state->target_y - lbl_8064E0A8) {
                    state->current_y = state->target_y;
                    fn_80201D2C(callback, 0x26);
                    fn_80201D14(callback, 1);
                }
            }
        }
        return 1;
    }

    if (phase == 0xA) {
        if (event_id == 1) {
            state->limit = 0xFF;
            return 1;
        }
        if (event_id == 3) {
            if (busy == 0) {
                if (state->value < state->limit - 7) {
                    state->value += 6;
                } else {
                    state->value = state->limit;
                    fn_80201D2C(callback, 0xC);
                    fn_80201D14(callback, 1);
                }
            }
            return 1;
        }
        goto unhandled;
    }

    if (phase == 0xB) {
        if (event_id == 1) {
            state->limit = 0;
            return 1;
        }
        if (event_id == 3) {
            if (busy == 0) {
                if (state->value > state->limit + 5) {
                    state->value -= 4;
                } else {
                    state->value = state->limit;
                    fn_80201D2C(callback, 1);
                    fn_80201D14(callback, 1);
                }
            }
            return 1;
        }
        goto unhandled;
    }

    return 0;

unhandled:
    return 0;
}

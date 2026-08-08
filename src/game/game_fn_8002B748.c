typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct S16Vec3 {
    s16 x;
    s16 y;
    s16 z;
} S16Vec3;

typedef struct EffectState {
    u8 pad[0xC];
    u32 sound;
    s32 value;
    S16Vec3 position;
    u16 count;
    u16 kind;
    u16 delay;
    s16 period;
    u8 flag;
} EffectState;

#pragma use_lmw_stmw on

extern void* lbl_8064C4E0;
extern volatile s32 lbl_8064D18C;
extern volatile float lbl_8064E034;
extern double lbl_8064E038;

extern s32 fn_80200C10(void*);
extern void* fn_80201B8C(void*);
extern s32 fn_80201B54(void*);
extern void fn_801E7974(void*, u32);
extern void fn_80201D2C(void*, s32);
extern void fn_80201D14(void*, s32);
extern void fn_801E8328(s32, void*);
extern void fn_80201D34(void*, s32);
extern void fn_80201D1C(void*, s32);
extern s32 fn_801E79FC(void*, u32);
extern void fn_8020123C(s32, s32, s32, s32);
extern void fn_80179DB0(S16Vec3*, S16Vec3*);
extern void* fn_80153904(EffectState*, S16Vec3*, float, u16);
extern void* fn_80156938(void*);
extern void fn_8017FF1C(void*, s32);
extern s32 fn_80050730(s32, s32, u8*, u8*, s32, s32);
extern void fn_801AAE68(float, s32, u8, s32, EffectState*, s32, s32, s32,
                        u16, s32);

s32 fn_8002B748(void* callback, s32 phase, void* event)
{
    s32 event_id = fn_80200C10(event);
    EffectState* state = *(EffectState**)((u8*)fn_80201B8C(callback) + 0x74);
    s32 object_id = fn_80201B54(callback);

    if (phase == 0) {
        if (event_id == 1) {
            if (state->sound != 0 && state->sound != (u32)-1) {
                fn_801E7974(lbl_8064C4E0, state->sound);
            }
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
        if (event_id == 0x3D) {
            fn_801E8328(2, callback);
            return 1;
        }
        if (event_id != 2) {
            goto event_unhandled;
        }
        return 1;
    }

    if (phase == 1) {
        if (event_id == 1) {
            return 1;
        }
        if (event_id == 3) {
            if (state->sound != 0 && state->sound != (u32)-1 &&
                fn_801E79FC(lbl_8064C4E0, state->sound) == 0) {
                fn_801E8328(2, callback);
                return 0;
            }

            if (state->delay != 0) {
                if (state->delay == 30) {
                    extern void fn_8002B6B0(EffectState*);
                    fn_8002B6B0(state);
                }
                state->delay--;
                if (state->delay == 0) {
                    fn_8020123C(0xE7, object_id, object_id, 0);
                    state->count++;
                }
            } else {
                state->count++;
                if (state->period != 0 &&
                    state->period - state->count == 30) {
                    extern void fn_8002B6B0(EffectState*);
                    fn_8002B6B0(state);
                }
                if ((state->period != 0 &&
                     state->count % state->period == 0) ||
                    state->period == 0) {
                    fn_8020123C(0xE7, object_id, object_id, 0);
                    state->count = 0;
                }
            }
            return 1;
        }
        if (event_id == 0xE7) {
            S16Vec3 position;
            void* effect;
            s32 effect_type;
            float intensity;
            u8 type;
            u8 unused;

            fn_80179DB0(&position, &state->position);
            effect = fn_80153904(state, &position, (float)state->value,
                                 state->kind);
            if (fn_801E79FC(lbl_8064C4E0, 0x2EA) == 0 && effect != 0) {
                fn_8017FF1C(fn_80156938(effect), 4);
            }
            effect_type = fn_80050730(0x41, 0, &type, &unused, 0, 0);
            intensity = lbl_8064E034;
            fn_801AAE68(intensity, effect_type, type, 0, state, 2, 2, 0,
                        (u16)lbl_8064D18C, 0);
            if (state->flag == 0) {
                fn_8020123C(0x39, object_id, object_id, 0);
            }
            return 1;
        }
        if (event_id != 2) {
            goto event_unhandled;
        }
        return 1;
    }
    goto phase_unhandled;

phase_unhandled:
    return 0;
event_unhandled:
    return 0;
}

typedef signed short s16;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int s32;

typedef struct EffectState {
    void* draw_callback;
    float current;
    float target;
    float unk0C;
    float scale;
    s32 enabled;
    s32 unk18;
    s32 type;
    char unk20[4];
    s16 value;
    char unk26[4];
    u8 alpha;
    u8 target_alpha;
} EffectState;

typedef struct EventData {
    char unk00[0x14];
    s32 fallback;
    s32 primary;
} EventData;

extern const float lbl_8064E064;
extern const float lbl_8064E0B0;

extern s32 fn_80200C10(void*);
extern EventData* fn_80200C38(void*);
extern void* fn_80201B8C();
extern int fn_80201B54();
extern s32 fn_800460EC(void);
extern void fn_80026070(EffectState*);
extern void fn_80027030(void);
extern void fn_80201D2C(void*, s32);
extern void fn_80201D14(void*, s32);
extern u16 fn_80158234(EventData*);
extern u16 fn_80157994(void*);
extern void* fn_80201814();
extern void* fn_80201C24();
extern void fn_801E8328();
extern void fn_80201D34(void*, s32);
extern void fn_80201D1C(void*, s32);

s32 fn_8002CBF8(void* callback, s32 phase, void* event)
{
    s32 event_id = fn_80200C10(event);
    EffectState* state = *(EffectState**)((char*)fn_80201B8C(callback) + 0x14);
    fn_80201B54(callback);

    if (event_id == 3) {
        state->enabled = 1;
        state->scale = lbl_8064E064;
        state->draw_callback = fn_80027030;
        if (fn_800460EC() == 0) {
            fn_80026070(state);
        }
    }

    if (phase == 0) {
        if (event_id == 1) {
            fn_80201D2C(callback, 1);
            fn_80201D14(callback, 1);
            return 1;
        }
        if (event_id == 0x87) {
            state->target_alpha = 0;
            state->alpha = 0;
            fn_80201D2C(callback, 1);
            fn_80201D14(callback, 1);
            return 1;
        }
        if (event_id == 0x11) {
            state->target_alpha = 0;
            state->alpha = 0;
            fn_80201D2C(callback, 1);
            fn_80201D14(callback, 1);
            return 1;
        }
        if (event_id == 0x10) {
            EventData* data = fn_80200C38(event);
            s32 linked = 0;
            u16 kind;

            if (data->primary != 0) {
                linked = data->primary;
            } else if (data->fallback != 0) {
                linked = data->fallback;
            }

            kind = fn_80158234(data);
            switch (kind) {
            case 1:
                state->type = 7;
                break;
            case 2:
            case 8:
            case 0x10:
            case 0x40:
                state->type = 5;
                break;
            case 0x20:
            case 0x80:
            case 0x100:
                state->type = 6;
                break;
            case 0x200:
                state->type = 2;
                break;
            case 0x800:
                state->type = 3;
                break;
            case 0x400:
                state->type = 4;
                break;
            case 4:
                state->type = 1;
                break;
            case 0x2000:
                state->type = 8;
                break;
            default:
                state->type = -1;
                break;
            }

            if (state->type != -1) {
                fn_80201D2C(callback, 0xA);
                fn_80201D14(callback, 1);
                state->target = lbl_8064E064;
                state->value = fn_80157994(data);
                if (linked != 0) {
                state->value += (s16)fn_80157994(fn_80201C24(fn_80201814(linked)));
                }
            }
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

    if (phase == 0xC) {
        if (event_id != 3) {
            goto unhandled;
        }
        if (state->current <= state->target) {
            state->current += lbl_8064E0B0;
            if (state->current >= state->target) {
                fn_80201D2C(callback, 0xB);
                fn_80201D14(callback, 1);
            }
        } else if (state->current >= state->target) {
            state->current -= lbl_8064E0B0;
            if (state->current <= state->target) {
                fn_80201D2C(callback, 0xB);
                fn_80201D14(callback, 1);
            }
        }
        return 1;
    }

    if (phase == 0xA) {
        if (event_id == 1) {
            state->target_alpha = 0xFF;
            return 1;
        }
        if (event_id == 3) {
            if (state->alpha < state->target_alpha) {
                state->alpha += 1;
            } else {
                state->alpha = state->target_alpha;
                fn_80201D2C(callback, 0xC);
                fn_80201D14(callback, 1);
            }
            return 1;
        }
        goto unhandled;
    }

    if (phase == 0xB) {
        if (event_id == 1) {
            state->target_alpha = 0;
            return 1;
        }
        if (event_id == 3) {
            if (state->alpha > state->target_alpha) {
                state->alpha -= 1;
            } else {
                state->alpha = state->target_alpha;
                fn_80201D2C(callback, 1);
                fn_80201D14(callback, 1);
            }
            return 1;
        }
        goto unhandled;
    }

    return 0;

unhandled:
    return 0;
}

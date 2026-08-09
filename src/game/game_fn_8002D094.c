typedef int s32;

typedef struct EventFloat {
    float value;
} EventFloat;

typedef struct EffectState {
    char unk00[8];
    float target;
} EffectState;

extern s32 fn_80200C10(void*);
extern EventFloat* fn_80200C38(void*);
extern void* fn_80201B8C(void*);
extern s32 fn_80201B54(void*);
extern void fn_80201D2C(void*, s32);
extern void fn_80201D14(void*, s32);
extern void fn_801E8328(s32, void*);
extern void fn_80201D34(void*, s32);
extern void fn_80201D1C(void*, s32);

s32 fn_8002D094(void* callback, s32 phase, void* event)
{
    s32 event_id = fn_80200C10(event);
    EffectState* state = *(EffectState**)((char*)fn_80201B8C(callback) + 0x18);
    fn_80201B54(callback);

    if (phase == 0) {
        if (event_id == 1) {
            fn_80201D2C(callback, 1);
            fn_80201D14(callback, 1);
            return 1;
        }
        if (event_id == 0x27) {
            state->target = fn_80200C38(event)->value;
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

    return 0;

unhandled:
    return 0;
}

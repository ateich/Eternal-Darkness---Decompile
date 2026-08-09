typedef int s32;
typedef unsigned int u32;

typedef struct CallbackState {
    char unk00[0x1C];
    void* inner;
} CallbackState;

typedef struct InnerState {
    char unk00[0xE8];
    s32 object_id;
} InnerState;

typedef struct ObjectState {
    char unk00[0x40];
    void* value40;
} ObjectState;

extern void* lbl_8064C4E0;

extern s32 fn_80200C10(void*);
extern CallbackState* fn_80201B8C(void*);
extern s32 fn_80201B54(void*);
extern void fn_80201D2C(void*, s32);
extern void fn_80201D14(void*, s32);
extern void* fn_80201814(s32);
extern ObjectState* fn_80036D38(void*);
extern void fn_801EF38C(s32);
extern void fn_801E8328(s32, void*);
extern void fn_80201D34(void*, s32);
extern void fn_80201D1C(void*, s32);
extern s32 fn_801E79FC(void*, s32);
extern void fn_800CE524(void*);

s32 fn_8002D3B0(void* callback, s32 phase, void* event)
{
    s32 event_id = fn_80200C10(event);
    InnerState* state = (InnerState*)fn_80201B8C(callback)->inner;
    void* object;
    ObjectState* object_state;
    fn_80201B54(callback);

    if (phase == 0) {
        if (event_id == 1) {
            fn_80201D2C(callback, 1);
            fn_80201D14(callback, 1);
            return 1;
        }
        if (event_id == 0x39) {
            object = fn_80201814(state->object_id);

            if ((u32)object != 0) {
                object_state = fn_80036D38(object);
                object_state->value40 = 0;
            }
            fn_801EF38C(0);
            fn_801E8328(2, callback);
            fn_80201D34(callback, 0);
            fn_80201D1C(callback, 1);
            return 1;
        }
        goto unhandled;
    }

    if (phase == 1) {
        if (event_id != 3) {
            goto unhandled;
        }
        if (fn_801E79FC(lbl_8064C4E0, 0x2ED) != 0) {
            fn_800CE524(callback);
        }
        return 1;
    }

    return 0;

unhandled:
    return 0;
}

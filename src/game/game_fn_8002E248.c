typedef int s32;

typedef struct CallbackState {
    char unk00[0x28];
    void* inner;
} CallbackState;

typedef struct InnerState {
    s32 active;
    char unk04[0x4];
    s32 linked_id;
    char unk0C[0x8];
    s32* result;
} InnerState;

typedef struct LinkedCallbackState {
    char unk00[0x8C];
    void* inner;
} LinkedCallbackState;

typedef struct LinkedInnerState {
    char unk00[0x28];
    s32 active;
} LinkedInnerState;

extern s32 fn_80200C10(void*);
extern s32 fn_80200C38(void*);
extern CallbackState* fn_80201B8C(void*);
extern s32 fn_80201B54(void*);
extern void fn_802020B4(void*, s32);
extern void fn_80201D2C(void*, s32);
extern void fn_80201D14(void*, s32);
extern void fn_8020123C(s32, s32, s32, s32);
extern void* fn_80201814(s32);
extern s32 fn_80201B64(void*);
extern s32 fn_80201B5C(void*);
extern void* fn_80201BC8(void*);
extern s32 fn_8011F130(void*);
extern void fn_801E32F8(InnerState*);
extern void fn_801E8328(s32, void*);
extern void fn_80201D34(void*, s32);
extern void fn_80201D1C(void*, s32);

s32 fn_8002E248(void* callback, s32 phase, void* event)
{
    s32 event_id = fn_80200C10(event);
    InnerState* state = (InnerState*)fn_80201B8C(callback)->inner;
    s32 object_id = fn_80201B54(callback);

    if (phase == 0) {
        if (event_id == 1) {
            fn_802020B4(callback, 1);
            fn_80201D2C(callback, 1);
            fn_80201D14(callback, 1);
            return 1;
        }

        if (event_id == 0xC4) {
            s32 result = fn_80200C38(event);

            if (state->result != 0) {
                if ((unsigned int)result != 0) {
                    *state->result = result;
                } else {
                    void* linked = fn_80201814(state->linked_id);
                    if (linked != 0 && fn_80201B64(linked) != 8 &&
                        fn_80201B5C(linked) != 0x15) {
                        *state->result = fn_8011F130(fn_80201BC8(linked));
                    }
                }
            }

            fn_8020123C(0x39, object_id, object_id, 0);
            return 1;
        }

        if (event_id == 0x39) {
            void* linked;

            if (state->active != 0) {
                fn_8020123C(0xEB, 0, state->linked_id, 0);
            }

            linked = fn_80201814(state->linked_id);
            if (linked != 0) {
                LinkedCallbackState* linked_callback =
                    (LinkedCallbackState*)fn_80201B8C(linked);
                ((LinkedInnerState*)linked_callback->inner)->active = 0;
            }

            fn_801E32F8(state);
            fn_801E8328(2, callback);
            fn_80201D34(callback, 0);
            fn_80201D1C(callback, 1);
            return 1;
        }
    } else if (phase != 1) {
        return 0;
    }

    return 0;
}

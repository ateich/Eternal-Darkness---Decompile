typedef unsigned char u8;
typedef int s32;

typedef struct CallbackState {
    char unk00[0x2C];
    void* inner;
} CallbackState;

typedef struct SlotArray {
    char unk00[0x2C];
    s32 ids[3];
} SlotArray;

typedef struct OtherState {
    char unk00[0x8C];
    SlotArray* slots;
} OtherState;

typedef struct InnerState {
    char unk00[0x8];
    s32 other_id;
    char unk0C[0x4];
    s32 kind;
    char unk14[0x4];
    s32 handle;
    char unk1C[0x4];
    s32* result;
    u8 position[0xC];
} InnerState;

extern s32 lbl_8064D18C;

extern s32 fn_80200C10(void*);
extern int fn_80200C38(void*);
extern void* fn_80201B8C();
extern int fn_80201B54();
extern void fn_802020B4(void*, int);
extern void fn_80201D2C(void*, s32);
extern void fn_80201D14(void*, s32);
extern unsigned long long fn_8020123C();
extern s32 fn_801AC9C0(s32);
extern void fn_801AC980(s32, s32);
extern void* fn_80201814();
extern void fn_801D7F04(InnerState*, s32);
extern void fn_801E8328();
extern void fn_80201D34(void*, s32);
extern void fn_80201D1C(void*, s32);
extern s32 fn_801AC908(s32, void*, s32);
extern s32 fn_801AC8AC(s32, s32, s32, void*);

s32 fn_8002D69C(void* callback, s32 phase, void* event)
{
    s32 event_id = fn_80200C10(event);
    InnerState* state = (InnerState*)((CallbackState*)fn_80201B8C(callback))->inner;
    s32 object_id = fn_80201B54(callback);

    if (phase == 0) {
        if (event_id == 1) {
            fn_802020B4(callback, 1);
            fn_80201D2C(callback, 1);
            fn_80201D14(callback, 1);
            return 1;
        }
        if (event_id == 0xC4) {
            if (state->result != 0) {
                *state->result = fn_80200C38(event);
            }
            fn_8020123C(0x39, object_id, object_id, 0);
            return 1;
        }
        if (event_id == 0x39) {
            s32 valid = -fn_80200C38(event) == 0;
            void* other;

            if (fn_801AC9C0(state->handle) != 0) {
                fn_801AC980(state->handle, 0xF);
            }

            other = fn_80201814(state->other_id);
            if (other != 0) {
                OtherState* other_state = (OtherState*)fn_80201B8C(other);
                s32 i;

                for (i = 0; i < 3; i++) {
                    if (other_state->slots->ids[i] == object_id) {
                        other_state->slots->ids[i] = 0;
                        break;
                    }
                }
            }

            fn_801D7F04(state, valid);
            fn_801E8328(2, callback);
            fn_80201D34(callback, 0);
            fn_80201D1C(callback, 1);
            return 1;
        }
        if (event_id == 0xB) {
            return 1;
        }
        goto unhandled;
    }

    if (phase == 1) {
        if (event_id == 1) {
            return 1;
        }
        if (event_id == 3) {
            if (state->kind == lbl_8064D18C &&
                fn_801AC908(state->handle, state->position, 0xFF) == 0) {
                state->handle = fn_801AC8AC(0x1F5, 0x64, 0x2710,
                                            state->position);
            }
            return 1;
        }
        if (event_id == 2) {
            return 1;
        }
        goto unhandled;
    }

    return 0;

unhandled:
    return 0;
}

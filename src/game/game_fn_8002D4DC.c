typedef signed short s16;
typedef int s32;

typedef struct CallbackState {
    char unk00[0x20];
    void* inner;
} CallbackState;

typedef struct InnerState {
    char unk00[0xF2];
    s16 flags;
} InnerState;

extern s32 fn_80200C10(void*);
extern void* fn_80201B8C();
extern int fn_80201B54();
extern void fn_80201D2C(void*, s32);
extern void fn_80201D14(void*, s32);
extern void fn_801E8328(s32, void*);
extern void fn_80201D34(void*, s32);
extern void fn_80201D1C(void*, s32);
extern void fn_800CE8E8(void*);
extern void fn_800CE698(void*);
extern s32 fn_800CE6EC(void*);
extern void fn_800CE8B8(void*);
extern s32 fn_800CE7D0(void*);
extern unsigned long long fn_8020123C();

s32 fn_8002D4DC(void* callback, s32 phase, void* event)
{
    s32 event_id = fn_80200C10(event);
    InnerState* state = (InnerState*)((CallbackState*)fn_80201B8C(callback))->inner;
    s32 object_id = fn_80201B54(callback);

    if (phase == 0) {
        if (event_id == 1) {
            fn_80201D2C(callback, 0xA);
            fn_80201D14(callback, 1);
            return 1;
        }
        if (event_id == 0x39) {
            fn_801E8328(2, callback);
            fn_80201D34(callback, 0);
            fn_80201D1C(callback, 1);
            return 1;
        }
        if (event_id == 0x11) {
            state->flags &= ~1;
            fn_80201D2C(callback, 0xB);
            fn_80201D14(callback, 1);
            return 1;
        }
        goto unhandled;
    }

    if (phase == 1) {
        if (event_id == 1) {
            fn_800CE8E8(callback);
            return 1;
        }
        if (event_id == 3) {
            fn_800CE698(callback);
            return 1;
        }
        goto unhandled;
    }

    if (phase == 0xA) {
        if (event_id != 3) {
            goto unhandled;
        }
        if ((fn_800CE6EC(callback) & 1) != 0) {
            fn_80201D2C(callback, 1);
            fn_80201D14(callback, 1);
        }
        return 1;
    }

    if (phase == 0xB) {
        if (event_id == 1) {
            fn_800CE8B8(callback);
            return 1;
        }
        if (event_id == 3) {
            if ((fn_800CE7D0(callback) & 2) != 0) {
                fn_8020123C(0x39, object_id, object_id, 0);
            }
            return 1;
        }
        goto unhandled;
    }

    return 0;

unhandled:
    return 0;
}

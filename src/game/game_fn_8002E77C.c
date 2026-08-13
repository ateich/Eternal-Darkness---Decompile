typedef int s32;
typedef unsigned char u8;

typedef struct CallbackState {
    char unk00[0x34];
    void* inner;
} CallbackState;

typedef struct InnerState {
    s32 linked_id;
    s32 type;
    void* spawned;
} InnerState;

typedef struct LinkedCallbackState {
    char unk00[0x8C];
    void* inner;
} LinkedCallbackState;

typedef struct LinkedInnerState {
    char unk00[0x3C];
    s32 active;
} LinkedInnerState;

typedef struct TableState {
    char unk00[0xC];
    s32 index;
} TableState;

typedef struct TableEntry {
    char unk00[0x8];
    s32 type;
} TableEntry;

extern s32 lbl_8064D18C;
extern TableState lbl_803003C8;
extern TableEntry lbl_8023BA64[];

extern int fn_80200C10(void *);
extern void *fn_80201B8C();
extern int fn_80201B54();
extern void fn_8011FF18(s32);
extern s32 fn_801D3944(s32);
extern s32 fn_8002EA18(s32);
extern void* fn_800CE9A4(void*, s32, s32);
extern int fn_801E8328();
extern s32 fn_801D38E8(s32);
extern int fn_80201AE4(void);
extern unsigned long long fn_8020123C();
extern void fn_802020B4(void*, int);
extern s32 fn_800DE354(void);
extern s32 fn_802066E0(s32, s32);
extern void fn_8011DD8C(s32, s32);
extern void fn_802006D4(s32, s32, s32, s32, s32);
extern void *fn_80201814();
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);
extern void fn_80201D34(void *, s32);
extern void fn_80201D1C(void *, s32);

s32 fn_8002E77C(void* callback, s32 phase, void* event)
{
    s32 event_id = fn_80200C10(event);
    InnerState* state = (InnerState*)((CallbackState*)fn_80201B8C(callback))->inner;
    s32 object_id = fn_80201B54(callback);

    if (phase == 0) {
        if (event_id == 1) {
            union {
                s32 value;
                u8 bytes[4];
            } descriptor;

            fn_8011FF18(0x50);
            descriptor.value = fn_801D3944(state->type);
            descriptor.bytes[3] = fn_8002EA18(state->type);
            state->spawned = fn_800CE9A4(&descriptor, 5, 0x40);
            if (state->spawned != 0) {
                fn_801E8328(0xD, state->spawned);
            }
            if (fn_801D38E8(state->type) == 4) {
                fn_8020123C(0x8A, object_id, fn_80201AE4(), 0);
            }
            fn_802020B4(callback, 1);
            fn_8020123C(0x1B, object_id, fn_800DE354(), 1);
            fn_80201D2C(callback, 1);
            fn_80201D14(callback, 1);
            return 1;
        }

        if (event_id == 0x39) {
            fn_8020123C(0x1B, object_id, fn_800DE354(), 0);
            if (lbl_8064D18C == 0xC4) {
                if (fn_802066E0(fn_80201AE4(), 0xE98A39BB) != 0) {
                    s32 type = fn_801D38E8(state->type);
                    if (type == lbl_8023BA64[lbl_803003C8.index].type) {
                        fn_8011DD8C(4, 0);
                    }
                }
            }
            if (state->spawned != 0) {
                s32 spawned_id = fn_80201B54(state->spawned);
                fn_8020123C(0x11, spawned_id, spawned_id, 0);
            }
            if (fn_801D38E8(state->type) == 4) {
                s32 first_id = fn_80201AE4();
                fn_802006D4(fn_80201AE4(), first_id, -1, 0x8B, 0);
                fn_8020123C(0x8C, object_id, fn_80201AE4(), 0);
            }
            {
                void* linked = fn_80201814(state->linked_id);
                if (linked != 0) {
                    LinkedCallbackState* linked_callback =
                        (LinkedCallbackState*)fn_80201B8C(linked);
                    ((LinkedInnerState*)linked_callback->inner)->active = 0;
                }
            }
            fn_8011FF18(0x96);
            fn_80201D34(callback, 0);
            fn_80201D1C(callback, 1);
            fn_801E8328(2, callback);
            return 1;
        }
    } else if (phase == 1) {
        if (event_id == 1) return 1;
        if (event_id == 3) return 1;
        if (event_id == 2) return 1;
    } else {
        return 0;
    }
    return 0;
}

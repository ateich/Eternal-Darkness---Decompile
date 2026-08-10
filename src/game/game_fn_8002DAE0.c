typedef signed short s16;
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;
typedef unsigned long long u64;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct CallbackState {
    char unk00[0x24];
    void* inner;
} CallbackState;

typedef struct OtherState {
    char unk00[0x0C];
    void* timer_object;
    char unk10[0x7C];
    void* status;
    char unk90[0x0F];
    u8 kind;
} OtherState;

typedef struct StatusObject {
    char unk00[0x150];
    u16 timer;
} StatusObject;

typedef struct TimerObject {
    char unk00[0x3E];
    u16 timer;
} TimerObject;

typedef struct InnerState {
    s16 value;
    char unk02[0x9A];
    Vec3 position;
    char unkA8[0x0C];
    s32 linked_id;
    void* stats;
    u8* flags;
    u8* counter;
    s32* result;
    Vec3 last_position;
} InnerState;

extern const double lbl_8064E038;
extern const float lbl_8064E064;
extern const float lbl_8064E0AC;
extern const float lbl_8064E0B0;

extern s32 fn_80200C10(void*);
extern s32 fn_80200C38(void*);
extern s32 fn_80200C28(void*);
extern s32 fn_80200C20(void*);
extern void* fn_80201B8C();
extern int fn_80201B54();
extern void fn_802020B4(void*, int);
extern void fn_80201D2C(void*, s32);
extern void fn_80201D14(void*, s32);
extern unsigned long long fn_8020123C();
extern void* fn_80201814();
extern s32 fn_80201B5C(void*);
extern s32 fn_80201B64(void*);
extern void* fn_80201BC8();
extern int fn_80201B44();
extern void fn_801E8328(s32, void*);
extern void fn_80201D34(void*, s32);
extern void fn_80201D1C(void*, s32);
extern void fn_801DABFC(InnerState*);
extern void fn_801DACA4(s32, s32);
extern void fn_801A7228(s32);
extern u16 fn_801A7530(s32);
extern void fn_801A7744(Vec3*, s32);
extern s32 fn_801A7498(s32);
extern s32 fn_801A7570(s32);
extern s16 fn_801A74F8(s32);
extern s32 fn_801A74C0(s32);
extern s32 fn_801A717C(void);
extern void fn_801A74A0(s32, s32);
extern void fn_801A74A8(s32, s32);
extern void fn_801A7538(s32, u16);
extern void fn_801A7518(s32, s16);
extern void fn_801A764C(s32, Vec3*);
extern void fn_801A7470(s32, s32);
extern void* fn_8004910C(s32);
extern s32 fn_801D38E8(void*);
extern void fn_801DA8CC(s32, Vec3*, s32, InnerState*);
extern s32 fn_80071DD8(void);
extern s32 fn_8006749C(s32);
extern s16 fn_801CEB2C(void*);
extern void fn_80120AD0(void*, s32, s32, u16, float, float);
extern s32 fn_801D9FE4();
extern void fn_801D16E4(s32, s32);
extern void fn_8002D8C8(s32, u16*, u16*, s32*);

s32 fn_8002DAE0(void* callback, s32 phase_arg, void* event_arg, s32* output)
{
    void* event = event_arg;
    s32 phase = phase_arg;
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
            void* linked = fn_80201814(state->linked_id);
            if (linked != 0) {
                void* linked_state = *(void**)((char*)fn_80201B8C(linked) + 0x8C);
                *(s32*)((char*)linked_state + 0x24) = 0;
            }
            fn_801DABFC(state);
            fn_801DACA4(state->linked_id, 0);
            fn_801E8328(2, callback);
            fn_80201D34(callback, 0);
            fn_80201D1C(callback, 1);
            return 1;
        }
        if (event_id == 0xED) {
            fn_8020123C(0xB, fn_80200C20(event),
                        fn_80200C28(event), fn_80200C38(event));
            fn_801A7228(fn_80200C38(event));
            return 1;
        }
        if (event_id == 0x3A) {
            fn_8020123C(0x27, fn_80200C20(event),
                        fn_80200C28(event), fn_80200C38(event));
            fn_801A7228(fn_80200C38(event));
            return 1;
        }
        if (event_id == 0xB) {
            s32 can_chain = 1;
            s32 is_type_8 = 0;
            u16 transferred_flags;
            u16 item_flags;
            s32 transfer_count;
            s32 source = fn_80200C20(event);
            s32 item = fn_80200C38(event);
            Vec3 position;
            s32 target_id;
            s32 item_bits;
            void* target;
            OtherState* target_state;
            s32 is_type_24;
            s32 mode;
            s16 amount;

            item_flags = 0;
            transfer_count = 0;
            transferred_flags = fn_801A7530(item);
            fn_801A7744(&position, item);
            target_id = fn_801A7498(item);
            item_bits = fn_801A7570(item);
            target = fn_80201814(target_id);
            target_state = target != 0 ? (OtherState*)fn_80201B8C(target) : 0;

            if (target_state != 0 && target_state->kind == 0x28) {
                goto item_done;
            }

            if (target != 0) {
                void* source_object = fn_8004910C(item);
                s32 target_type = fn_80201B5C(target);
                OtherState* source_state = source_object != 0
                    ? (OtherState*)fn_80201B8C(source_object) : 0;
                is_type_24 = target_type == 0x18;
                is_type_8 = target_type == 8;
                if (source_state != 0 && source_state->kind == 0x12) {
                    can_chain = 0;
                }
            } else {
                is_type_24 = 0;
            }

            mode = fn_801D38E8(state->stats);
            fn_8002D8C8(mode, &transferred_flags, &item_flags,
                        &transfer_count);
            if (transfer_count <= 0) {
                goto item_done;
            }

            {
                s32 ignore_item = 0;
                amount = fn_801A74F8(item);
                if (amount == 0) {
                void* linked = fn_80201814(state->linked_id);
                if (linked != 0 && fn_80201B5C(linked) == 0x1C) {
                        ignore_item = 1;
                    }
                }
                if (ignore_item != 0) {
                    goto item_done;
                }
            }

            if ((fn_801A74C0(item) & 0x00400000) != 0) {
                fn_801DA8CC(target_id, &position, source, state);
            }

            if (mode == 4 && !is_type_24 && target_id != 0) {
                s32 created = fn_801A717C();
                fn_801A74A0(created, object_id);
                fn_801A74A8(created, target_id);
                fn_801A7538(created, item_flags);
                {
                    s16 applied_amount;
                    if (target_id == fn_80201B44() && fn_80071DD8() != 0) {
                        applied_amount = 1;
                    } else {
                        applied_amount = amount;
                    }
                    fn_801A7518(created, applied_amount);
                }
                fn_801A764C(created, &state->position);
                if ((item_flags & 1) != 0) {
                    fn_801A7470(created, 0xB);
                }
                {
                    u32 message_result = fn_8020123C(
                        0xDC, object_id, target_id, created) & 0xFFFFFFFFULL;
                if (message_result == 0) {
                    fn_8020123C(0x27, object_id, target_id, created);
                    if (target != 0 && fn_80201B64(target) != 8 &&
                        fn_80201B5C(target) != 0x15) {
                        void* effect = fn_80201BC8(target);
                        if (effect != 0) {
                            s32 mask = fn_8006749C(4);
                            s16 rank = fn_801CEB2C(state->stats);
                            u8 level = (u8)((rank >> 1) + 1);
                            float scale;
                            scale = lbl_8064E0B0 - lbl_8064E0AC *
                                (float)(level - 2);
                            fn_80120AD0(effect, 0, 100,
                                        (u16)(mask | 2),
                                        lbl_8064E064, scale);
                        }
                    }
                }
                }
                fn_801A7228(created);
                if (target_state != 0 && target_state->status != 0) {
                    ((StatusObject*)target_state->status)->timer = 300;
                }
            } else if ((item_flags & 1) != 0 && !is_type_24 &&
                       target_id != 0 && source != target_id && can_chain &&
                       (item_bits & 0x20) == 0) {
                s32 created = fn_801A717C();
                fn_801A7470(created, 0xB);
                fn_801A74A0(created, 0);
                fn_801A74A8(created, target_id);
                {
                    u32 message_result = fn_8020123C(
                        0xDC, object_id, target_id, created) & 0xFFFFFFFFULL;
                if (message_result == 0) {
                    fn_8020123C(0x35, object_id, target_id, created);
                }
                }
                fn_801A7228(created);
                if (target_state != 0 && target_state->status != 0) {
                    ((StatusObject*)target_state->status)->timer = 300;
                    if (target_state->timer_object != 0) {
                        ((TimerObject*)target_state->timer_object)->timer = 60;
                    }
                }
            }

            if ((*state->flags & 8) == 0) {
                s16 delta = (s16)(amount * transfer_count);
                if ((item_flags & 8) != 0) {
                    delta = (s16)(delta / 100);
                }
                if (delta >= state->value || (is_type_8 && (item_flags & 1))) {
                    state->value = 0;
                    if (target != 0 && fn_80201B64(target) != 8 &&
                        fn_80201B5C(target) != 0x15) {
                        fn_8020123C(0xC4, object_id, object_id,
                                    (s32)&position);
                    } else {
                        fn_8020123C(0x39, object_id, object_id, 0);
                    }
                } else {
                    s32 before = fn_801D9FE4(state->stats) & 0xFF;
                    state->value -= delta;
                    {
                        s32 after = fn_801D9FE4(state->stats, state->value) & 0xFF;
                        if (after <= before) {
                            *state->counter += before - after;
                        }
                    }
                    state->last_position = position;
                }
            }

item_done:
            if (output != 0) {
                *output = transferred_flags;
            }
            return 1;
        }
        if (event_id == 0x5C) {
            fn_801D16E4(state->linked_id, 0);
            return 1;
        }
        goto unhandled;
    }

    if (phase == 1) {
        if (event_id == 1) {
            return 1;
        }
        if (event_id == 3) {
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

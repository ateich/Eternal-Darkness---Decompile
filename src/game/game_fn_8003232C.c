typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

typedef struct ObjectInfo {
    u8 pad00[0x4C];
    void* state4C;
    u8 pad50[0x3C];
    void* object8C;
} ObjectInfo;

typedef struct OwnerState {
    u8 pad00[0x4C];
    s32 owner4C;
    s32 owner50;
} OwnerState;

typedef struct EntryTable {
    u8 pad00[0x88];
    void* entries88[10];
} EntryTable;

typedef struct EffectState {
    u8 index;
    u8 pad01[3];
    s32 value04;
    s32 value08;
    u8 pad0C[8];
    s32 value14;
    s32 value18;
    s32 value1C;
    s32 value20;
    s32 object24;
    s32 object28;
    u8 vector2C[0xC];
    u8 descriptor38[0xC0];
    EntryTable* entriesF8;
    u8 valueFC;
    u8 valueFD;
    u16 flagsFE;
} EffectState;

extern volatile s32 lbl_8064D18C;
extern const f32 lbl_8064E064;
extern const u32 lbl_8064E180;
extern const f32 lbl_8064E184;
extern const double lbl_8064E188;

extern s32 fn_80200C10(void*);
extern void *fn_80201B8C();
extern int fn_80201B54();
extern void *fn_80201814();
extern int fn_80201B4C(void*);
extern void fn_80201D2C(void *, s32);
extern void fn_80201D14(void *, s32);
extern void fn_80201D34(void *, s32);
extern void fn_80201D1C(void *, s32);
extern int fn_80035628(void*);
extern int fn_801D3974(s32);
extern s32 fn_801D3A24(s32, s32);
extern void fn_8014CFF4(void*, void*, s32, s32, void*, void*, s32);
extern void fn_8014CE98(void*, void*, s32, s32, void*, s32, s32, s32, s32,
                       void*, void*, s32, s32, s32);
extern void fn_8020104C(int, void *, void *, int, float);
#define fn_8020104C(a, b, c, d, e) fn_8020104C((a), (void *)(b), (void *)(c), (int)(d), (e))
extern void fn_80191204(void*, s32);
extern void fn_801911FC(void*, s32);
extern u8 fn_80180130(void*);
extern int fn_801E8328();

s32 fn_8003232C(void* object, s32 action, void* event, s32* completed)
{
    u32 color;
    volatile u32 color2;
    EffectState* state;
    register s32 object_id;
    register s32 event_id;
    register s32 selection;
    register void* linked;

    event_id = fn_80200C10(event);
    state = ((ObjectInfo*)fn_80201B8C(object))->state4C;
    object_id = fn_80201B54(object);

    if (action == 0) {
        if (event_id == 1) {
            if (lbl_8064D18C == 0xEF) {
                asm { nop }
            }

            linked = fn_80201814(state->object24);
            state->value04 = 0;
            state->index = 0;

            if (state->object28 == 0) {
                fn_8014CFF4(state->descriptor38, linked, state->value14,
                            state->value18, state->vector2C, &state->value04,
                            state->value08);
            } else {
                s32 kind;
                s32 mode = 0;
                fn_80201814(state->object28);
                asm { mr selection, r3 }
                if (state->flagsFE & 1) {
                    fn_80201814(state->object24);
                    asm { mr selection, r3 }
                    kind = fn_80035628((void*)selection);
                } else {
                    kind = fn_80035628((void*)selection);
                }

                if (fn_80201B4C(linked) == 2) {
                    switch (kind) {
                    case 1: mode = 1; break;
                    case 2: mode = 3; break;
                    case 3: mode = 2; break;
                    }
                    color = fn_801D3974(kind);
                    kind = fn_801D3A24(kind, 0x31);
                } else {
                    color2 = lbl_8064E180;
                    color = lbl_8064E180;
                    mode = 1;
                    kind = 0x27;
                }

                {
                    void* primary;
                    register void* secondary;
                    fn_80201814(state->object28);
                    asm { mr secondary, r3 }
                    primary = fn_80201814(state->object24);
                    fn_8014CE98(state->descriptor38, primary,
                            state->value14, state->value18, secondary,
                            state->value1C, state->value20, kind, mode, &color,
                            &state->value04, state->value08, state->valueFC,
                            state->valueFD);
                }
            }

            fn_8020104C(0x79, object_id, object_id, 0, lbl_8064E064);
            fn_80201D2C(object, 1);
            fn_80201D14(object, 1);
            return 1;
        }

        if (event_id == 0x79) {
            if (state->entriesF8 != 0) {
                void* entry = state->entriesF8->entries88[state->index];
                if (entry != 0) {
                    fn_80191204(entry, 1);
                    state->index++;
                    if (state->index == 1) {
                        fn_801911FC(entry, 1);
                    }
                    if (state->index < 10) {
                        fn_8020104C(0x79, object_id, object_id, 0,
                                   (f32)fn_80180130(entry));
                    }
                }
            }
            return 1;
        }

        if (event_id == 0x7A) {
            state->value04 = 1;
            fn_8020104C(0x39, object_id, object_id, 0, lbl_8064E184);
            return 1;
        }

        if (event_id == 0x39) {
            void* parent = fn_80201814(state->object24);
            if (parent != 0) {
                OwnerState* owner = ((ObjectInfo*)fn_80201B8C(parent))->object8C;
                if (owner->owner4C == object_id) {
                    owner->owner4C = 0;
                } else if (owner->owner50 == object_id) {
                    owner->owner50 = 0;
                }
            }
            fn_801E8328(2, object);
            fn_80201D34(object, 0);
            fn_80201D1C(object, 1);
            return 1;
        }
    } else if (action == 1) {
        if (event_id == 1) {
            asm { }
            return 1;
        }
        if (event_id == 3) {
            asm { }
            return 1;
        }
        if (event_id == 2) {
            return 1;
        }
    } else {
        return 0;
    }
    return 0;
}

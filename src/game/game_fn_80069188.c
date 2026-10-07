typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef struct Color { u8 r, g, b, a; } Color;
typedef struct Vec3 { float x, y, z; } Vec3;

typedef struct SoundLink {
    u8 pad00[0x88];
    void *sound;
} SoundLink;
typedef struct Runtime {
    u8 pad00[0xC0];
    SoundLink *sound;
    void *effect;
    u8 padC8[0x40];
    s16 timer;
    u8 pad10A[2];
    u8 flags;
} Runtime;
typedef struct State {
    Runtime *runtime;
    u8 pad04[5];
    u8 flags;
} State;
typedef struct Owner {
    u8 pad00[0x6C];
    s32 id;
} Owner;
typedef struct Actor {
    u8 pad00[4];
    State *state;
    u8 pad08[0x84];
    Owner *owner;
    u8 pad90[4];
    s32 kind;
    u8 pad98[6];
    u8 mode;
    u8 variant;
} Actor;

extern s32 lbl_8064D5A8, lbl_8064D18C, lbl_8064C5AC;
extern u8 *lbl_8064C4E0;
extern float lbl_8064C898;
extern const float lbl_8064E728;
extern const float lbl_8064E780, lbl_8064E784, lbl_8064E788, lbl_8064E78C;
extern Color lbl_8064E75C, lbl_8064E760, lbl_8064E764;
extern u32 lbl_8064E768, lbl_8064E76C, lbl_8064E770, lbl_8064E774;
extern u32 lbl_8064E778, lbl_8064E77C;
extern u32 lbl_8065196C, lbl_80651970, lbl_80651974;
extern Vec3 lbl_80239078, lbl_80239084;

extern s32 fn_80200C10(void *), fn_80200C20(void *), fn_80200C28(void *);
extern void *fn_80200C38(void *);
extern void *fn_80201BC8(void *), *fn_80201814(s32);
extern void *fn_80201B8C(void *);
extern s32 fn_80201B54(void *), fn_80201EB8(void *);
extern void *fn_80201B9C(void), *fn_80201BC0(void *);
extern u32 fn_80202160(void *);
extern void fn_8011F114(Vec3 *, void *);
extern void fn_801441C0(s32, s32, s32);
extern void fn_8011E1C4(void), fn_8011E174(u32, s32);
extern void *fn_80068668(State *);
extern s32 fn_80066D04(s32, s32);
extern void fn_80201D2C(void *, s32), fn_80201D14(void *, u8);
extern void fn_80201D34(void *, s32), fn_80201D1C(void *, u8);
extern void *fn_800E0708(void *, u16, u32);
extern void *fn_8012C62C(void *, s32, void *, void *, void *, s32);
extern void fn_801A5910(s32), fn_801E7974(u8 *, u32), fn_801E79A0(u8 *, u32);
extern void fn_8016B400(s32, void *, void *);
extern s32 *fn_800681C8();
extern void fn_8012B324(void *), fn_8012B344(void *);
extern s32 fn_800CA2C8(void *);
extern void fn_8003D7B4(s32);
extern u32 fn_8011FA8C(void *, u32, u32);
extern u64 fn_8020123C(s32, s32, s32, s32);
extern void fn_8020104C(s32, s32, s32, s32, float);
extern void fn_80067D30(void *), fn_80067B6C(void), fn_8006845C(void *);
/* These legacy calls retain the context argument supplied by retail. */
extern void fn_80068074();
extern void fn_80187A34(void *, void *), fn_80067DA4(State *), fn_80067E24(State *);
extern void *fn_8014C7B8(void *);
extern s32 fn_801FEA10(u32);
extern void fn_801FE934(u32, u8), fn_80149E28(void *);
extern void fn_80067A18(s32);
extern s32 fn_801E8328(u32, u32);
extern void fn_80064B38(s32, void *, s32 *), fn_80067C20(void *), fn_801D14CC(s32);
extern void fn_80068FE0(void *, void *), fn_801A7228(void *);
extern s16 fn_801A74F8(void *);
extern u32 fn_801A7590(void *);
extern s32 fn_800654F8(s32);
extern void fn_801A7518(void *, s16), fn_800674E4(s32, s32);
/* Retail supplies the event to this legacy entry point as an unused argument. */
extern void fn_80067650();
extern void fn_80068AAC(s32, s32, void *, Runtime **, Actor *, s32);
extern void *fn_801294DC(void *, s32, s32, s32);
extern s32 fn_800683E4(void *, s32);
extern void fn_80128C28(void *, u32, u32);
extern void fn_80067EB8(void *), fn_80067BAC(void *);
extern void fn_8006872C(void *, Actor *, s32, State *, s32);
extern s32 fn_801AC908(u32, void *, u8);
extern s32 fn_801AAE68(u16, u8, u8, float, Vec3 *, s8, u8, u8, u16, u32);
extern s32 fn_802006D4(s32, s32, s32, s32, void (*)(s32));
extern void fn_801878E0(void *), fn_801FDF74(u32, s32), fn_801878D8(void *, void *);
extern u16 fn_801878D0(void *);
extern s32 fn_80068674(void *, s32);
extern s32 fn_801AC9F4(u16, u8, Vec3 *, u8);
extern void *fn_801D551C(Vec3 *, Vec3 *, s32, s32, s32, u8, u8, u8, s32, s32, u8, u8, u8);
extern void *fn_80156938(void *);
extern u32 fn_80193860(void *);
extern void fn_801938D8(void *, u32);
extern u32 fn_80178E94(const float *, const float *);
extern s32 fn_80068230();
extern void fn_800073D8(s32), fn_80067848(void);
extern s32 fn_800681A0(void *, s32);

/* Dispatch object events, propagating state changes through the twelve links. */
s32 fn_80069188(void *object, s32 state_id, void *event, s32 *result)
{
    Vec3 position;
    Vec3 linked_position;
    Vec3 candidate_position;
    Vec3 linked_temp;
    Vec3 candidate_temp;
    s32 kind = fn_80200C10(event);
    void *model = fn_80201BC8(object);
    Actor *actor = fn_80201B8C(object);
    Owner *owner = actor->owner;
    State *state = actor->state;
    s32 id = fn_80201B54(object);

    fn_8011F114(&position, model);
    if (kind == 3 && state->runtime != 0 && state->runtime->timer != 0) {
        if (--state->runtime->timer > 130) {
            if (!(lbl_8064D5A8 & 15))
                fn_801441C0(14, 2, 14);
        } else {
            switch (state->runtime->timer) {
            case 118: fn_801441C0(1, 1, 15); break;
            case 102: fn_801441C0(1, 2, 15); break;
            case 88: fn_801441C0(1, 3, 15); break;
            case 72: fn_801441C0(1, 4, 15); break;
            case 58: fn_801441C0(1, 5, 15); break;
            case 32: fn_801441C0(1, 6, 15); break;
            case 13: fn_801441C0(1, 7, 15); break;
            }
        }
    }

    if (state_id == 0) {
        if (kind == 1) {
            Color colors[3];
            Color slot_colors[3];
            u32 a2[2], b2[2], c2[2];
            u32 a3[2], b3[2], c3[2];
            u32 a0[2], b0[2], c0[2];
            colors[2] = lbl_8064E75C;
            colors[1] = lbl_8064E760;
            colors[0] = lbl_8064E764;
            if (actor->mode == 1) {
                fn_8011E1C4();
                fn_8011E174(0x40, 1);
            }
            state->flags |= 1;
            if ((s32)fn_80068668(state)) {
                fn_80201D2C(object, 0x2E);
                fn_80201D14(object, 1);
            } else {
                fn_80201D2C(object, 0x22);
                fn_80201D14(object, 1);
            }
            if (owner != 0 && fn_80201814(actor->owner->id) != 0)
                state->flags |= 2;
            fn_800E0708(object, 1, 2);
            fn_8012C62C(model, 1, (slot_colors[2] = colors[1], &slot_colors[2]),
                (slot_colors[1] = colors[2], &slot_colors[1]),
                (slot_colors[0] = colors[0], &slot_colors[0]), 4);
            if (fn_80066D04((s32)object, 2)) {
                fn_8012C62C(model, 2,
                    (a2[1] = a2[0] = lbl_8064E768, &a2[1]),
                    (b2[1] = b2[0] = lbl_8065196C, &b2[1]),
                    (c2[1] = c2[0] = lbl_8064E76C, &c2[1]), 4);
            }
            if (fn_80066D04((s32)object, 3)) {
                fn_8012C62C(model, 3,
                    (a3[1] = a3[0] = lbl_8064E770, &a3[1]),
                    (b3[1] = b3[0] = lbl_80651970, &b3[1]),
                    (c3[1] = c3[0] = lbl_8064E774, &c3[1]), 4);
            }
            fn_8012C62C(model, 0,
                (a0[1] = a0[0] = lbl_8064E778, &a0[1]),
                (b0[1] = b0[0] = lbl_80651974, &b0[1]),
                (c0[1] = c0[0] = lbl_8064E77C, &c0[1]), 4);
            return 1;
        } else if (kind == 0x86) {
            fn_801A5910((s32)fn_80200C38(event));
            return 1;
        } else if (kind == 0xBB) {
            s32 value = (s32)fn_80200C38(event);
            if (value) fn_801E7974(lbl_8064C4E0, value);
            return 1;
        } else if (kind == 0xBC) {
            s32 value = (s32)fn_80200C38(event);
            if (value) fn_801E79A0(lbl_8064C4E0, value);
            return 1;
        } else if (kind == 0xBE) {
            s32 value = (s32)fn_80200C38(event);
            if (value) fn_8016B400(value, (void *)id, 0);
            return 1;
        } else if (kind == 0x39) {
            s32 *links = fn_800681C8(object);
            s32 i;
            fn_8012B324(model);
            fn_800CA2C8(object);
            fn_8003D7B4(id);
            fn_8011FA8C(model, 0xC0, 0);
            fn_80201D34(object, 0);
            fn_80201D1C(object, 1);
            for (i = 0; i < 12; i++) {
                if (links[i]) fn_8020123C(0x41, id, links[i], 0);
            }
            fn_80067D30(object);
            fn_80067B6C();
            fn_8006845C(object);
            fn_80068074(object);
            if (state->runtime->sound != 0 && state->runtime->sound->sound != 0) {
                fn_80187A34(state->runtime->sound->sound, (void *)1);
                state->runtime->sound = 0;
            } else {
                fn_80067DA4(state);
            }
            fn_80067E24(state);
            if (state->runtime->effect != 0) {
                void *context = fn_8014C7B8(state->runtime->effect);
                if (context != 0 && (s8)fn_801FEA10((u32)context) == -1)
                    fn_801FE934((u32)context, 0);
                fn_80149E28(state->runtime->effect);
                state->runtime->effect = 0;
            }
            fn_80067A18(id);
            fn_801E8328(2, (u32)object);
            return 1;
        } else if (kind == 0x27) {
            fn_80064B38((s32)object, event, result);
            return 1;
        } else if (kind == 0x3E) {
            fn_80067B6C();
            fn_80067C20(object);
            fn_801D14CC(id);
            return 1;
        } else if (kind == 0x1C) {
            if ((s32)fn_80200C38(event)) {
                fn_80067D30(object);
                fn_80067B6C();
            } else {
                fn_80067C20(object);
            }
            return 1;
        } else if (kind == 0x3D) {
            fn_80068FE0(object, model);
            fn_8003D7B4(id);
            fn_8020123C(0x39, id, id, 0);
            fn_80067A18(id);
            return 1;
        } else if (kind == 0xED) {
            fn_8020123C(0xB, fn_80200C20(event), fn_80200C28(event), (s32)fn_80200C38(event));
            fn_801A7228(fn_80200C38(event));
            return 1;
        } else if (kind == 0x3A) {
            fn_8020123C(0x27, fn_80200C20(event), fn_80200C28(event), (s32)fn_80200C38(event));
            fn_801A7228(fn_80200C38(event));
            return 1;
        } else if (kind == 0xB) {
            s32 value = (s32)fn_80200C38(event);
            s16 saved = fn_801A74F8((void *)value);
            s32 answer;
            if (!(fn_801A7590((void *)value) & 1)) fn_801A7518((void *)value, 0);
            answer = fn_800654F8(value);
            fn_801A7518((void *)value, saved);
            if (result) *result = answer;
            return 1;
        } else if (kind == 0xEA) {
            fn_800674E4((s32)object, (s32)event);
            return 1;
        } else if (kind == 0xEB) {
            fn_80067650(object, event);
            return 1;
        } else if (kind == 0x20) {
            if (result) *result = 0;
            return 1;
        } else if (kind == 0x3B) {
            if (result) *result = 1;
            return 1;
        } else if (kind == 0x3F) {
            if (result) *result = 0;
            return 1;
        } else if (kind == 0x44) {
            s32 sender = fn_80200C20(event);
            s32 propagate = (s32)fn_80200C38(event);
            s32 *links = fn_800681C8(object);
            s32 i;
            fn_80201D2C(object, 0x16);
            fn_80201D14(object, 1);
            if (propagate) {
                if (state->runtime->flags & 4) {
                    /* ASM: nop preserves the retail recursion-guard marker; an empty C block is removed. */
                    asm { nop }
                } else {
                    state->runtime->flags |= 4;
                    for (i = 0; i < 12; i++) {
                        if (links[i] && sender != links[i]) {
                            fn_8020123C(0x44, id, links[i], 1);
                            fn_8020104C(0x43, id, links[i], 0, lbl_8064C898);
                            lbl_8064C898 += lbl_8064E728;
                        }
                    }
                    state->runtime->flags &= ~4;
                }
            }
            return 1;
        } else if (kind == 0x43) {
            fn_80068AAC(id, (s32)object, model, &state->runtime, actor, (s32)event);
            return 1;
        } else if (kind == 8) {
            if (!fn_80066D04((s32)object, 0)) {
                s32 *links = fn_800681C8(object);
                s32 i;
                if (state->runtime->sound == 0 || state->runtime->sound->sound == 0) {
                    /* ASM: nop preserves the retail missing-sound marker; C has no observable operation here. */
                    asm { nop }
                }
                for (i = 0; i < 12; i++) {
                    if (links[i]) fn_8020123C(0x41, id, links[i], 0);
                }
                fn_8006845C(object);
                fn_80068074(object);
                if (state->runtime->sound != 0 && state->runtime->sound->sound != 0) {
                    fn_80187A34(state->runtime->sound->sound, (void *)1);
                    state->runtime->sound = 0;
                } else {
                    fn_80067DA4(state);
                }
                fn_80067E24(state);
                if (state->runtime->effect != 0) {
                    void *context = fn_8014C7B8(state->runtime->effect);
                    if (context != 0 && (s8)fn_801FEA10((u32)context) == -1)
                        fn_801FE934((u32)context, 0);
                    fn_80149E28(state->runtime->effect);
                    state->runtime->effect = 0;
                }
                fn_80068FE0(object, model);
                fn_80067B6C();
                fn_800CA2C8(object);
                fn_8020104C(8, id, id, 0, lbl_8064E780);
                fn_8012B344(model);
                fn_80067D30(object);
                if (actor->mode == 1) fn_8011E174(0x40, 0);
                fn_80201D34(object, 4);
                fn_80201D1C(object, 1);
            }
            return 1;
        }
    } else if (state_id == 0x16) {
        if (kind == 0x44) return 1;
        else if (kind == 0x3B) return 1;
        else if (kind == 0xB) return 1;
        else if (kind == 8) return 1;
    } else if (state_id == 0x22) {
        if (kind == 0x42) {
            s32 *links = fn_800681C8(object);
            s32 sender = fn_80200C20(event);
            s32 propagate = (s32)fn_80200C38(event);
            s32 i;
            fn_8012B344(model);
            fn_80128C28(fn_801294DC(model, 0x2B, 0x24, 10), (u32)fn_800683E4, id);
            fn_80067EB8(object);
            fn_80067BAC(object);
            if (propagate) {
                if (state->runtime->flags & 8) {
                    /* ASM: nop preserves the retail recursion-guard marker; an empty C block is removed. */
                    asm { nop }
                } else {
                    state->runtime->flags |= 8;
                    for (i = 0; i < 12; i++) {
                        if (links[i] && sender != links[i]) fn_8020123C(0x42, id, links[i], 1);
                    }
                    state->runtime->flags &= ~8;
                }
            }
            fn_80201D2C(object, 0x2E);
            fn_80201D14(object, 1);
            if (result) *result = 1;
            return 1;
        } else if (kind == 8) {
            return 1;
        } else if (kind == 0x41) {
            fn_8006872C(object, actor, (s32)event, state, (s32)model);
            return 1;
        } else if (kind == 3) {
            if (!fn_80066D04((s32)object, 0)) {
                fn_8006872C(object, actor, (s32)event, state, (s32)model);
                fn_80067B6C();
            }
            return 1;
        }
    } else if (state_id == 0x2E) {
        if (kind == 0x1C) {
            if ((s32)fn_80200C38(event)) {
                fn_80067D30(object);
                fn_80067B6C();
            } else {
                fn_80067C20(object);
                if (!fn_801AC908(lbl_8064C5AC, 0, 100)) {
                    lbl_8064C5AC = fn_801AAE68(0x4B, 100, 0, lbl_8064E784, &position,
                                             1, 2, 0, (u16)lbl_8064D18C, 0);
                }
            }
            return 1;
        } else if (kind == 0x40) {
            s32 *links = fn_800681C8(object);
            s32 sender = fn_80200C20(event);
            s32 propagate = (s32)fn_80200C38(event);
            void *animation;
            s32 i;
            fn_8012B344(model);
            animation = fn_801294DC(model, 0x2B, 0x24, 10);
            fn_802006D4(id, id, 0x2E, 0x43, 0);
            fn_80128C28(animation, (u32)fn_800683E4, id);
            if (state->runtime->sound != 0 && state->runtime->sound->sound != 0)
                fn_801878E0(state->runtime->sound->sound);
            if (state->runtime->effect != 0) {
                void *context = fn_8014C7B8(state->runtime->effect);
                if (context != 0) fn_801FDF74((u32)context, 1000);
            }
            fn_80067C20(object);
            if (propagate) {
                if (state->runtime->flags & 1) {
                    /* ASM: nop preserves the retail recursion-guard marker; an empty C block is removed. */
                    asm { nop }
                } else {
                    state->runtime->flags |= 1;
                    for (i = 0; i < 12; i++) {
                        if (links[i] && sender != links[i]) fn_8020123C(0x40, id, links[i], 1);
                    }
                    state->runtime->flags &= 0xFE;
                }
            }
            return 1;
        } else if (kind == 3) {
            s32 active = fn_80066D04((s32)object, 0);
            if (state->runtime->sound != 0 && state->runtime->sound->sound != 0) {
                u8 mode = fn_80202160(object);
                fn_801878D8(state->runtime->sound->sound, (void *)(u32)mode);
            }
            if (!active) {
                s32 *links = fn_800681C8(object);
                s32 i;
                for (i = 0; i < 12; i++) {
                    if (links[i]) fn_8020123C(0x41, id, links[i], 0);
                }
                fn_8006872C(object, actor, (s32)event, state, (s32)model);
                fn_80067B6C();
            } else if (state->runtime->sound != 0 && state->runtime->sound->sound != 0 &&
                       fn_801878D0(state->runtime->sound->sound) >= 300) {
                s32 count = fn_80068674(object, id);
                s32 *links = fn_800681C8(object);
                if (count) {
                    s32 i;
                    for (i = 0; i < 12; i++) {
                        if (links[i] && (u32)(fn_8020123C(0x42, id, links[i], 1) & 0xFFFFFFFF)) {
                            void *linked = fn_80201814(links[i]);
                            void *linked_model;
                            Vec3 *chosen;
                            void *effect;
                            void *context;
                            linked_position = lbl_80239078;
                            linked_model = fn_80201BC8(linked);
                            if (linked_model) {
                                fn_8011F114(&linked_temp, linked_model);
                                chosen = &linked_temp;
                            } else {
                                chosen = &linked_position;
                            }
                            {
                                float elevation = lbl_8064E788;
                                float raised_z, linked_z;
                                linked_position = *chosen;
                                raised_z = position.z + elevation;
                                linked_z = linked_position.z;
                                position.z = raised_z;
                                linked_position.z = linked_z + elevation;
                            }
                            fn_801AC9F4(0x4A, 100, &position, 2);
                            effect = fn_801D551C(&position, &linked_position, 2, 0, 0, 3, 10, 4,
                                                1, 0, 17, 10, 12);
                            context = fn_80156938(effect);
                            fn_801938D8(context, fn_80193860(context) | 0x410);
                            linked_position.z -= lbl_8064E788;
                            position.z -= lbl_8064E788;
                        }
                    }
                    fn_8020123C(0x40, id, id, 0);
                } else {
                    fn_8020123C(0x43, id, id, 1);
                }
            } else {
                void *candidate = fn_80201B9C();
                s32 room = fn_80201EB8(object);
                position.z += lbl_8064E788;
                while (candidate != 0) {
                    Actor *candidate_actor = fn_80201B8C(candidate);
                    s32 candidate_room;
                    s32 candidate_id;
                    void *candidate_model;
                    Vec3 *chosen;
                    candidate_position = lbl_80239084;
                    candidate_room = fn_80201EB8(candidate);
                    candidate_id = fn_80201B54(candidate);
                    candidate_model = fn_80201BC8(candidate);
                    if (candidate_model != 0) {
                        fn_8011F114(&candidate_temp, candidate_model);
                        chosen = &candidate_temp;
                    } else {
                        chosen = &candidate_position;
                    }
                    candidate_position = *chosen;
                    if (candidate_room == room && candidate_actor != 0 &&
                        candidate_actor->kind == 2 && candidate_actor->variant == 3 &&
                        (float)fn_80178E94(&candidate_position.x, &position.x) < lbl_8064E78C &&
                        (u32)(fn_8020123C(0x3B, id, candidate_id, 0) & 0xFFFFFFFF) == 1) {
                        u64 answer = fn_8020123C(0x3F, id, candidate_id, 0);
                        s32 slot = fn_80068230(object);
                        s32 candidate_slot = fn_80068230(candidate);
                        if (slot != -1 && candidate_slot != -1 && (u32)(answer & 0xFFFFFFFF) == 1) {
                            s32 *links = fn_800681C8(object);
                            s32 *candidate_links = fn_800681C8(candidate);
                            if (links == candidate_links) {
                                fn_800073D8(lbl_8064D18C);
                                fn_80067848();
                            }
                            links[slot] = candidate_id;
                            candidate_links[candidate_slot] = id;
                            fn_800681A0(object, 0);
                            candidate_position.z += lbl_8064E788;
                        }
                    }
                    candidate = fn_80201BC0(candidate);
                }
                position.z -= lbl_8064E788;
            }
            return 1;
        }
    } else {
        return 0;
    }
    return 0;
}

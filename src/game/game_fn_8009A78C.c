/* Event/state dispatcher for actor transitions, damage and fading.
 * The remaining retail differences are the compiler-generated GPR save/restore
 * helpers in place of stmw/lmw; no compiler settings are overridden here. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef int s32;
typedef float f32;
#define NULL ((void*)0)

typedef struct Vec3 { float x, y, z; } Vec3;
typedef union Color { u32 word; struct { u8 r, g, b, a; } channel; } Color;

/* Per-object event state, referenced by the owner at offset 0x54. */
typedef struct EventState {
    u8 pad00[0xC0];
    u32 unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC;
    u32 unkE0;
    s32 delay, timer;
    u32 unkEC;
    void* effect;
    void* target;
    u32 unkF8;
    void* action;
    u16 flags;
    u8 limit, count, active, alpha;
} EventState;
typedef struct ActorData {
    u8 pad00[0x54];
    EventState* state;
    u8 pad58[0x34];
    u8* actor;
} ActorData;
typedef struct ActionEvent { u8 pad00[0x20]; s32 value; } ActionEvent;
typedef struct GameState { u8 pad00[8]; s32 mode; } GameState;

/* Retail supplies diagnostic strings; the release callee reads only object. */
extern s32 fn_80035FB8();
extern s32 fn_80036E50(void*);
extern void fn_8003C114(void*, void*, s32);
extern void fn_80048708(void*);
extern void fn_80064B38(s32, void*, s32*);
extern s32 fn_800654F8(s32);
extern void fn_80068994(void*, s32);
extern void fn_8009BD50(void*, void*, EventState*, void*);
extern void fn_8009C300(void*, u32, u32);
extern void fn_8009C424(void*, EventState*, void*, u32*);
extern void fn_8009C550(void*);
extern s32 fn_8009C90C(EventState*);
extern s32 fn_8009C980(EventState*, s32);
extern void fn_8009C9D4(void*, void*, void*, void*, s32, s32, f32);
extern s32 fn_800AD3A4(void);
extern void** fn_800BC100(s32, s32, s32*, s32, s32, s32, s32);
extern void fn_800BCCC4(void*, Vec3*);
extern void fn_800BD194(void*, void*);
extern void fn_800BD2DC(void*, void*);
extern void fn_800BDEE4(void*, void*);
extern void fn_800BE010(void*, void*);
extern s32 fn_800BE0F4(void*, void*);
extern void fn_800BE8D4(s32);
extern s32 fn_800C9BA8(void*, ActorData*);
extern s32 fn_800CA2C8(void*);
extern void fn_800CA890(void*, void*, Vec3*, s32, s32);
extern void fn_800CC4DC(void*);
extern void fn_800CC860(void*, s32, s32);
extern void fn_800CD094(void*, void*, s32);
extern void fn_800CF598(void*);
extern void fn_8011F0E8(void*, Vec3*);
extern void fn_8011F114(Vec3*, void*);
extern u32 fn_8011FA8C(void*, u32, u32);
extern u32 fn_8011FABC(void*, u32, u32);
extern u32 fn_8011FADC(void*, u32);
extern u32 fn_8011FAEC(void*);
extern u32 fn_8011FAF4(void*);
extern void fn_8011FEDC(void*, u8);
extern void fn_8011FEE4(void*, u8);
extern void fn_8011FEEC(void*, f32);
extern void fn_8011FEF4(void*, f32);
extern s32 fn_8011FF38(void);
extern void fn_80120AD0(void*, Vec3*, u16, u32, f32, f32);
extern void fn_801261F4(void*);
extern void fn_80128A84(void*, u16, u32);
extern void* fn_80128E30(void*);
extern s32 fn_80128EAC(void*);
extern void* fn_80128F40(void*);
extern void fn_80128F74(void*, u32);
extern u16 fn_801290D0(void*);
extern void fn_80129BA4(void*, f32, f32);
extern s32 fn_8012A1BC(void*, s32);
extern void fn_8012B324(void*);
extern void fn_8012B344(void*);
extern f32 fn_8012B750(void*);
extern f32 fn_8012B7D0(void*, Vec3*);
extern void* fn_8012C62C(void*, s32, Color*, Color*, Color*, s32);
extern u16 fn_8012DBE8(void*, s32, Color*);
extern s32 fn_8012DCBC(void*, s32, s32, Color*, s32*, s32);
extern s32 fn_80152360(s32, s32);
extern void fn_8017A12C(f32*, f32, f32);
extern void* fn_8018095C(void*);
extern u32 fn_8019BBB4(void*);
extern void fn_8019BBCC(void*, u32, u32);
extern void fn_801A7228(void*);
extern u32 fn_801A7498(void*);
extern u32 fn_801A74C0(void*);
extern void fn_801A7588(void*, u32);
extern void fn_801A977C(void*, s32);
extern s32 fn_801AAE68(u16, u8, u8, f32, Vec3*, signed char, u8, u8, u16, u32);
extern void fn_801D0CF0(void*);
extern void fn_801D13D8(s32, s32);
extern s32 fn_801D16A0(void*, s32);
extern u32 fn_801DA0EC(u32);
extern s32 fn_801DAC18(void*, s32);
extern s32 fn_801E8328(s32, void*);
extern void fn_801FE4FC(u32);
extern s32 fn_802006D4(s32, s32, s32, s32, void (*)(s32));
extern s32 fn_80200C10(void*);
extern s32 fn_80200C20(void*);
extern s32 fn_80200C28(void*);
extern void* fn_80200C38(void*);
extern void fn_8020104C(s32, s32, s32, s32, f32);
extern void fn_802011D4(void*);
extern u64 fn_8020123C(s32, s32, s32, s32);
extern void* fn_80201814(s32);
extern s32 fn_80201B44(void);
extern s32 fn_80201B54(void*);
extern s32 fn_80201B5C(void*);
extern ActorData* fn_80201B8C(void*);
extern void* fn_80201B94(void*);
extern void* fn_80201BC8(void*);
extern void* fn_80201C48(void*);
extern void fn_80201D14(void*, u8);
extern void fn_80201D1C(void*, u8);
extern void fn_80201D2C(void*, s32);
extern void fn_80201D34(void*, s32);
extern void fn_80201DD8(void*, void*);
extern void fn_80201F44(void*, Vec3*);
extern void fn_80204FDC(void*);
extern char lbl_80245368[];
extern GameState lbl_803003C8;
extern char lbl_8064B620[8], lbl_8064B628[8], lbl_8064B630[8];
extern s32 lbl_8064D18C;
extern u32 lbl_8064D5A8;
extern const Color lbl_8064ED28, lbl_8064ED2C, lbl_8064ED30;
extern const Color lbl_8064ED34, lbl_8064ED38, lbl_8064ED3C, lbl_8064ED40;
extern const Color lbl_806519F0, lbl_806519F4;
extern const f32 lbl_8064ED44, lbl_8064ED48, lbl_8064ED4C, lbl_8064ED50;
extern const f32 lbl_8064ED54, lbl_8064ED58, lbl_8064ED5C, lbl_8064ED60;
extern const f32 lbl_8064ED64, lbl_8064ED68;

s32 fn_8009A78C(register void* object, register s32 phase,
                  register void* event, register u32* result)
{
    Vec3 position, otherPosition, spawnPosition, warpPosition;
    Vec3 spawnCopy, otherCopy, facingCopy, warpCopy;
    s32 spawnId;
    f32 angleDelta;
    Color savedColor, transitionColor;
    s32 transitioning;
    Color currentColor;
    f32 facingDelta;
    s32 warpId;
    Color tickColor;
    Color fadeEnd, fadeRate, fadeStart;
    Color restoreEnd, restoreEndTemp, restoreRate, restoreStart, restoreStartTemp;
    Color visibleEnd, visibleRate, visibleStart;
    register s32 targetId;
    register char* strings;
    register EventState* state;
    register ActorData* data;
    register u8* actor;
    register s32 actorId;
    register s32 kind;
    register void* context;
    register void* room;
    register void* payload;
    register void* sourceObject;
    register void* foundObject;
    register void** spawned;
    register s32 senderId, sourceId, mappedId;
    register s32 accepted, special, animation;
    register s32 hitResult, flags, currentTarget;
    f32 heading, magnitude;
    register char* debugName;
    register void* debugObject;
    register u32 renderFlags;
    register u32 forwarded, mask;

    strings = lbl_80245368;
    kind = fn_80200C10(event);
    room = fn_80201BC8(object);
    data = fn_80201B8C(object);
    actor = data->actor;
    state = data->state;
    context = fn_80201B94(object);
    actorId = fn_80201B54(object);
    fn_8011F114(&position, room);
    targetId = (s32)fn_80201C48(context);
    if (kind == 3) {
        fn_800CC4DC(object);
        fn_8009C90C(state);
        mappedId = state->timer;
        if (mappedId > 0) {
            state->timer = (s32) (mappedId - 1);
        }
    }

    if (phase == 0) {
        if (kind == 0x1) {
            fn_80201D2C(object, 1);
            fn_80201D14(object, 1);
            state->effect = NULL;
            state->unkC0 = 0;
            state->unkC4 = 0;
            state->unkC8 = 0;
            state->unkCC = 0;
            state->unkD0 = 0;
            state->unkD4 = 0;
            state->unkD8 = 0;
            state->unkDC = 0;
            state->active = 0;
            fn_800BD194(object, actor);
            state->target = 0U;
            return 1;
        }
        if (kind == 0xEF) {
            if (result != NULL) {
                *result = 1;
            }
            return 1;
        }
        if (kind == 0x8) {
            fn_800CD094(object, event, 0x320);
            if ((void *) state->effect != NULL) {
                fn_801FE4FC((u32)state->effect);
                state->effect = NULL;
            }
            return 1;
        }
        if (kind == 0xED) {
            fn_8020123C(0xB, fn_80200C20(event), fn_80200C28(event), (s32)fn_80200C38(event));
            fn_801A7228(fn_80200C38(event));
            return 1;
        }
        if (kind == 0xB) {
            payload = fn_80200C38(event);
            special = fn_801DA0EC(actorId);
            fn_801A7588(payload, 0x8000);
            hitResult = fn_800654F8((s32)payload);
            if (result != NULL) {
                *result = hitResult;
            }
            if (special != 0) {
                sourceId = fn_801A7498(payload);
                if ((foundObject = fn_80201814(sourceId)) != NULL) {
                    register int isSpecial = fn_80201B5C(foundObject) == 0x19;
                    if (isSpecial) fn_8020123C(0xBD, sourceId, actorId, 0);
                }
            }
            return 1;
        }
        if (kind == 0xC9) {
            if (fn_8011FF38() != 0) {
                fn_8011FEDC(room, 0x4B);
                fn_8011FEE4(room, 0x78);
                fn_8011FEEC(room, lbl_8064ED44);
                fn_8011FEF4(room, lbl_8064ED44);
                fn_8011FA8C(room, 0, 0x20000000);
                fn_801AAE68(0x1F1, 0x64, 0, lbl_8064ED48, &position, 2, 2, 0, (u16) lbl_8064D18C, 0);
            }
            return 1;
        }
        if (kind == 0xE) {
            fn_80068994(object, (s32)event);
            return 1;
        }
        if (kind == 0x27) {
            fn_80064B38((s32)object, event, (s32*)result);
            return 1;
        }
        if (kind == 0x20) {
            if (result != NULL) {
                *result = 0;
            }
            return 1;
        }
        if (kind == 0x6B) {
            if (result != NULL) {
                *result = 0;
            }
            return 1;
        }
        if (kind == 0x3B) {
            accepted = 0;
            senderId = fn_80200C20(event);
            sourceObject = fn_80201814(senderId);
            if ((sourceObject != NULL) && ((senderId == fn_80201B44()) || (fn_80201B5C(sourceObject) == 0x19)) && (fn_80036E50(sourceObject) != 6)) {
                accepted = 1;
            }
            if (result != NULL) {
                *result = accepted;
            }
            return 1;
        }
        if (kind == 0x82) {
            if (result != NULL) {
                *result = 0;
            }
            return 1;
        }
        if (kind == 0xE6) {
            fn_8009C424(object, state, event, result);
            return 1;
        }
        if (kind == 0x35) {
            fn_8009C424(object, state, event, result);
            return 1;
        }
        if (kind == 0xBD) {
            if (((u32) state->action != 0U) && (fn_801D16A0(state->action, 0x1040U) != 0)) {
                fn_801D0CF0(state->action);
                state->action = 0U;
            }
            fn_8020123C(0x69, actorId, actorId, 0);
            return 1;
        }
        if (kind == 0x69) {
            spawned = fn_800BC100(0, 0, &spawnId, 8, 0, 0, 0);
            if (spawned != NULL) {
                fn_800BD194(object, actor);
                mappedId = fn_80152360(lbl_8064D18C, spawnId);
                if (mappedId != spawnId) {
                    spawnId = mappedId;
                    spawned = fn_800BC100(0, 0, &spawnId, 0x10, 0, 0, 0);
                }
                fn_800BCCC4(*spawned, &spawnPosition);
                fn_80201DD8(context, (void*)-1);
                spawnCopy = spawnPosition;
                fn_80201F44(object, &spawnCopy);
                fn_800BDEE4(object, data->actor);
                fn_800CA890(object, event, &spawnPosition, 2, 0x8A);
                state->target = 0U;
            }
            return 1;
        }
        if (kind == 0x3E) {
            fn_8020104C(0xFF, actorId, actorId, 0, lbl_8064ED44);
            fn_800BD194(object, actor);
            state->target = 0U;
            return 1;
        }
        if (kind == 0xFF) {
            if ((void *) state->effect == NULL) {
                fn_8009C300(object, 0, 1);
                state->effect = NULL;
            }
            return 1;
        }
        if (kind == 0x3D) {
            if ((void *) state->effect != NULL) {
                fn_801FE4FC((u32)state->effect);
                state->effect = NULL;
            }
            fn_800BD2DC(object, actor);
            state->target = 0U;
            return 1;
        }
        if (kind == 0x39) {
            fn_800BD2DC(object, actor);
            fn_8012B324(room);
            fn_80201D34(object, 0);
            fn_80201D1C(object, 1);
            fn_801E8328(2, object);
            return 1;
        }
        if (kind == 0xCD) {
            if ((void *) state->effect == NULL) {
                state->effect = fn_80200C38(event);
            }
            return 1;
        }
        if (kind == 0x78) {
            if (fn_801D16A0(state->action, 0x820) != 0) {
                fn_8009C980(state, ((ActionEvent*)fn_80200C38(event))->value);
            }
            state->action = 0U;
            state->timer = (s32) state->delay;
            return 1;
        }
        if (kind == 0x37) {
            return 1;
        }
        if (kind == 0x32) {
            return 1;
        }
        if (kind == 0x1E) {
            return 1;
        }
        goto unhandled;
    } else if (phase == 0x1) {
        if (kind == 3) {
            if (targetId != 0) {
                fn_8009BD50(object, room, state, event);
            }
            if (!(lbl_8064D5A8 & 7)) {
                fn_80201DD8(context, (void*)fn_80201B44());
            }
            return 1;
        }
        goto unhandled;
    } else if (phase == 0x6) {
        if (kind == 12) {
            fn_80201D2C(object, 1);
            fn_80201D14(object, 1);
            return 1;
        }
        if (kind == 7) {
            /* ASM: mr/addi preserve the argument setup and zero-offset table
             * address; MWCC folds the C address expression into mr. */
            asm { mr debugObject, object; addi debugName, strings, 0 }
            if (fn_80035FB8(debugObject, debugName, lbl_8064B620,
                            strings + 0x14, lbl_8064B628, strings + 0x20) == 0) {
                fn_80201D2C(object, 1);
                fn_80201D14(object, 1);
            }
            return 1;
        }
        if (kind == 13) {
            fn_80201D2C(object, 1);
            fn_80201D14(object, 1);
            fn_8012B344(room);
            return 1;
        }
        goto unhandled;
    } else if (phase == 0x7) {
        if (kind == 0x1) {
            if (state->flags & 1) {
                if (((u32) state->action != 0U) && (fn_801D16A0(state->action, 0x1040U) != 0)) {
                    fn_801D0CF0(state->action);
                    state->action = 0U;
                }
                fn_8020123C(0x69, actorId, actorId, 0);
                state->flags = (u16) (state->flags & 0xFFFE);
            }
            return 1;
        }
        if (kind == 0x36) {
            fn_80201D2C(object, 1);
            fn_80201D14(object, 1);
            return 1;
        }
        if (kind == 0x7) {
            /* ASM: mr/addi preserve the argument setup and zero-offset table
             * address; MWCC folds the C address expression into mr. */
            asm { mr debugObject, object; addi debugName, strings, 0 }
            if (fn_80035FB8(debugObject, debugName, lbl_8064B630,
                            strings + 0x14, lbl_8064B628, strings + 0x20) == 0) {
                fn_80201D2C(object, 1);
                fn_80201D14(object, 1);
            }
            return 1;
        }
        if (kind == 0x3D) {
            if ((u32) state->action != 0U) {
                fn_801D0CF0(state->action);
                if (result != NULL) {
                    fn_802011D4(event);
                    mask = ~0U;
                    /* ASM: and preserves the retail caller's use of r4 after this
                     * void event-forwarding call; C cannot name that ABI register. */
                    asm { and forwarded, r4, mask }
                    *result = forwarded;
                }
            }
            return 1;
        }
        if (kind == 0xBD) {
            return 1;
        }
        goto unhandled;
    } else if (phase == 0x30) {
        if (kind == 0x1) {
            fn_800BE8D4(actorId);
            fn_8011FABC(room, 0, 0x80);
            return 1;
        }
        if (kind == 0x2) {
            return 1;
        }
        if (kind == 0xE2) {
            fn_8011FABC(room, 0x80, 0);
            fn_8011F0E8(room, (Vec3*)(actor + 0xA0));
            fn_8011FA8C(room, 0, 0xC0);
            fn_80048708(room);
            fadeStart = lbl_8064ED30;
            fadeRate = lbl_8064ED2C;
            fadeEnd = lbl_8064ED28;
            fn_8012C62C(room, 0xF, &fadeEnd, &fadeRate, &fadeStart, 4);
            if (fn_801DAC18((void*)actorId, 1) != 0) {
                fn_801D13D8(actorId, 0);
            }
            fn_80201DD8(context, (void*)fn_80201B44());
            if ((currentTarget = (s32)fn_80201C48(context)) != 0 && (foundObject = fn_80201814(currentTarget)) != NULL) {
                register void* targetRoom = fn_80201BC8(foundObject);
                fn_8011F114(&otherPosition, targetRoom);
                fn_801290D0(room);
                /* ASM: mr uses the accessor's already zero-extended r3 value;
                 * MWCC otherwise adds a redundant clrlwi for its u16 return. */
                asm { mr renderFlags, r3 }
                fn_80128F74(room, renderFlags | 0x100);
                otherCopy = otherPosition;
                heading = fn_8012B7D0(room, &otherCopy);
                fn_8017A12C(&angleDelta, fn_8012B750(room), heading);
                magnitude = angleDelta;
                if (magnitude < lbl_8064ED4C) {
                    magnitude = -magnitude;
                }
                if (magnitude > lbl_8064ED50) {
                    fn_80129BA4(fn_80128E30(room), heading, lbl_8064ED54);
                }
            }
            state->target = 0U;
            return 1;
        }
        if (kind == 0x3D) {
            if ((u32) state->action != 0U) {
                fn_801D0CF0(state->action);
            }
            fn_8012DBE8(room, 0xF, &savedColor);
            state->alpha = savedColor.channel.a;
            if (fn_8012DCBC(room, 0xF, 0, &transitionColor, &transitioning, 4) != 0) {
                if (transitioning != 0) {
                    state->alpha = 0xFFU;
                } else {
                    state->alpha = 0U;
                }
            }
            if (result != NULL) {
                fn_802011D4(event);
                mask = ~0U;
                /* ASM: and preserves the retail caller's use of r4 after this
                 * void event-forwarding call; C cannot name that ABI register. */
                asm { and forwarded, r4, mask }
                *result = forwarded;
            }
            return 1;
        }
        if (kind == 0x3E) {
            fn_801261F4(room);
            restoreStartTemp = lbl_8064ED38;
            restoreStartTemp.channel.a = state->alpha;
            restoreStart = restoreStartTemp;
            restoreRate = lbl_806519F0;
            restoreEndTemp = lbl_8064ED34;
            restoreEndTemp.channel.a = state->alpha;
            restoreEnd = restoreEndTemp;
            fn_8012C62C(room, 0xF, &restoreEnd, &restoreRate, &restoreStart, 4);
            flags = fn_8011FAF4(room);
            fn_8012DBE8(room, 0xF, &currentColor);
            if (!(flags & 0x80) && (currentColor.channel.a == 0)) {
                fn_80201DD8(context, (void*)fn_80201B44());
                currentTarget = (s32)fn_80201C48(context);
                visibleStart = lbl_8064ED40;
                visibleRate = lbl_806519F4;
                visibleEnd = lbl_8064ED3C;
                fn_8012C62C(room, 0xF, &visibleEnd, &visibleRate, &visibleStart, 4);
                if (currentTarget != 0) {
                    fn_8011F114(&otherPosition, fn_80201BC8(fn_80201814(currentTarget)));
                    fn_801290D0(room);
                    /* ASM: mr uses the accessor's already zero-extended r3 value;
                     * MWCC otherwise adds a redundant clrlwi for its u16 return. */
                    asm { mr renderFlags, r3 }
                    fn_80128F74(room, renderFlags | 0x100);
                    facingCopy = otherPosition;
                    heading = fn_8012B7D0(room, &facingCopy);
                    fn_8017A12C(&facingDelta, fn_8012B750(room), heading);
                    magnitude = facingDelta;
                    if (magnitude < lbl_8064ED4C) {
                        magnitude = -magnitude;
                    }
                    if (magnitude > lbl_8064ED50) {
                        fn_80129BA4(fn_80128E30(room), heading, lbl_8064ED54);
                    }
                }
            }
            if (result != NULL) {
                fn_802011D4(event);
                mask = ~0U;
                /* ASM: and preserves the retail caller's use of r4 after this
                 * void event-forwarding call; C cannot name that ABI register. */
                asm { and forwarded, r4, mask }
                *result = forwarded;
            }
            return 1;
        }
        if (kind == 0x9D) {
            register s32 warpSuccess;
            register void* warpController;
            register void** warpEntry;
            warpSuccess = 0;
            warpId = (s32)fn_80200C38(event);
            if ((u32) state->target != 0U) {
                warpController = fn_8018095C(state->target);
                if ((warpController != NULL) && (fn_8019BBB4(warpController) & 8)) {
                    fn_8019BBCC(warpController, 0, 8);
                    fn_8011F0E8(room, (Vec3*)(actor + 0xA0));
                }
            }
            warpId = fn_80152360(lbl_8064D18C, (s32) warpId);
            warpEntry = fn_800BC100(0, 0, &warpId, 0x10, 0, 0, 0);
            if (warpEntry != NULL) {
                fn_800BD194(object, actor);
                fn_800BCCC4(*warpEntry, &warpPosition);
                fn_80201DD8(context, (void*)-1);
                warpCopy = warpPosition;
                fn_80201F44(object, &warpCopy);
                fn_800BDEE4(object, data->actor);
                warpSuccess = 1;
            }
            if (result != NULL) {
                *result = warpSuccess;
            }
            return 1;
        }
        if (kind == 0x3) {
            if (!(lbl_8064D5A8 & 0x1F) && ((u32) state->target != 0U) && (fn_800BE0F4(object, data->actor) == 0)) {
                fn_800BDEE4(object, data->actor);
            }
            fn_8012DBE8(room, 0xF, &tickColor);
            if (tickColor.channel.a >= 0xFBU) {
                if ((s32) state->timer < 0x78) {
                    state->timer = 0x78;
                }
                fn_80201D2C(object, 1);
                fn_80201D14(object, 1);
            }
            if ((u32) state->target != 0U) {
                fn_800BE010(object, actor);
                fn_8009C9D4(object, room, state->target, actor, 0x50, 0, lbl_8064ED58);
            }
            return 1;
        }
        if (kind == 0x35) {
            return 1;
        }
        if (kind == 0xB) {
            return 1;
        }
        if (kind == 0x1E) {
            return 1;
        }
        if (kind == 0x8) {
            return 1;
        }
        if (kind == 0x29) {
            return 1;
        }
        if (kind == 0x2A) {
            return 1;
        }
        if (kind == 0x2B) {
            return 1;
        }
        if (kind == 0x2D) {
            return 1;
        }
        if (kind == 0x2C) {
            return 1;
        }
        if (kind == 0x28) {
            return 1;
        }
        if (kind == 0x69) {
            return 1;
        }
        if (kind == 0xBD) {
            return 1;
        }
        if (kind == 0x3B) {
            return 1;
        }
        goto unhandled;
    } else if (phase == 0x40) {
        if (kind == 0x3) {
            return 1;
        }
        if (kind == 0x78) {
            fn_80201D2C(object, 1);
            fn_80201D14(object, 1);
            if (result != NULL) {
                fn_802011D4(event);
                mask = ~0U;
                /* ASM: and preserves the retail caller's use of r4 after this
                 * void event-forwarding call; C cannot name that ABI register. */
                asm { and forwarded, r4, mask }
                *result = forwarded;
            }
            return 1;
        }
        if (kind == 0x7) {
            /* ASM: mr/addi preserve the argument setup and zero-offset table
             * address; MWCC folds the C address expression into mr. */
            asm { mr debugObject, object; addi debugName, strings, 0 }
            if (fn_80035FB8(debugObject, debugName, lbl_8064B630,
                            strings + 0x14, lbl_8064B628, strings + 0x20) == 0) {
                fn_80201D2C(object, 1);
                fn_80201D14(object, 1);
            }
            return 1;
        }
        if (kind == 0x3D) {
            fn_801D0CF0(state->action);
            if (result != NULL) {
                fn_802011D4(event);
                mask = ~0U;
                /* ASM: and preserves the retail caller's use of r4 after this
                 * void event-forwarding call; C cannot name that ABI register. */
                asm { and forwarded, r4, mask }
                *result = forwarded;
            }
            return 1;
        }
        goto unhandled;
    } else if (phase == 0x1F) {
        if (kind == 0x1) {
            register s32 animationIndex = fn_80128EAC(room);
            animation = fn_8012A1BC(room, animationIndex);
            fn_80128F40(room);
            fn_800CC860(object, 2, 3);
            fn_800BE8D4(actorId);
            fn_801A977C(room, 0x33);
            fn_800CA2C8(object);
            fn_80204FDC(object);
            fn_8020104C(0x11, actorId, actorId, 0, lbl_8064ED5C);
            fn_80128A84(fn_80128E30(room), 0, animation);
            return 1;
        }
        if (kind == 0x30) {
            hitResult = fn_800654F8((s32)fn_80200C38(event));
            if (result != NULL) {
                *result = hitResult;
            }
            return 1;
        }
        if (kind == 0x3D) {
            fn_8020123C(0x39, actorId, actorId, 0);
            return 1;
        }
        if (kind == 0x11) {
            fn_800CF598(object);
            fn_80120AD0(room, 0, 0, 0x101, lbl_8064ED60, lbl_8064ED4C);
            fn_80201D34(object, 0x15);
            fn_80201D1C(object, 1);
            return 1;
        }
        if (kind == 0x31) {
            fn_8003C114(object, room, actorId);
            return 1;
        }
        if (kind == 0x7) {
            fn_80035FB8(object, strings + 0x38, strings + 0x4C, strings + 0x14, strings + 0x60, strings + 0x60);
            return 1;
        }
        if (kind == 0x20) {
            return 1;
        }
        if (kind == 0x3B) {
            return 1;
        }
        if (kind == 0x6B) {
            return 1;
        }
        if (kind == 0x3F) {
            return 1;
        }
        if (kind == 0x1E) {
            return 1;
        }
        if (kind == 0x35) {
            return 1;
        }
        if (kind == 0x37) {
            return 1;
        }
        if (kind == 0x8) {
            return 1;
        }
        if (kind == 0xB) {
            return 1;
        }
        if (kind == 0x27) {
            return 1;
        }
        if (kind == 0x69) {
            return 1;
        }
        if (kind == 0x3E) {
            return 1;
        }
        if (kind == 0x67) {
            return 1;
        }
        goto unhandled;
    } else if (phase == 0x8) {
        if (kind == 0x1) {
            if (room != NULL) {
                flags = fn_8011FAEC(room);
                fn_8011FADC(room, flags & 0xFFFFFF3F);
            }
            fn_8009C550(object);
            fn_800CC860(object, 1, 0);
            fn_800BE8D4(actorId);
            fn_80204FDC(object);
            return 1;
        }
        if (kind == 0xF9) {
            if (fn_800AD3A4() == 0) {
                fn_800CA2C8(object);
            }
            return 1;
        }
        if (kind == 0x11) {
            fn_800CF598(object);
            fn_80120AD0(room, 0, 0, 0x101, lbl_8064ED64, lbl_8064ED4C);
            fn_80201D34(object, 0x15);
            fn_80201D1C(object, 1);
            return 1;
        }
        if (kind == 0x2) {
            fn_802006D4(actorId, actorId, 8, 0x11, 0);
            return 1;
        }
        if (kind == 0x3B) {
            if (result != NULL) {
                *result = 0;
            }
            return 1;
        }
        if (kind == 0xC1) {
            if (((s32) lbl_803003C8.mode != 5) && (result != NULL)) {
                *result = fn_800C9BA8(room, data);
            }
            return 1;
        }
        if (kind == 0x2F) {
            fn_80201D2C(object, 0x1F);
            fn_80201D14(object, 1);
            return 1;
        }
        if (kind == 0xB) {
            register void* hitPayload;
            register s32 damageResult;
            hitPayload = fn_80200C38(event);
            if (fn_801A74C0(hitPayload) & 0x20) {
                damageResult = fn_800654F8((s32)hitPayload);
                fn_8020123C(0x2F, actorId, actorId, 0);
                fn_8020104C(0x31, actorId, actorId, 0, lbl_8064ED68);
                if (result != NULL) {
                    *result = damageResult;
                }
            }
            return 1;
        }
        if (kind == 0x1E) {
            return 1;
        }
        if (kind == 0x35) {
            return 1;
        }
        if (kind == 0x37) {
            return 1;
        }
        if (kind == 0x32) {
            return 1;
        }
        if (kind == 0x8) {
            return 1;
        }
        if (kind == 0x27) {
            return 1;
        }
        if (kind == 0x69) {
            return 1;
        }
        if (kind == 0xBD) {
            return 1;
        }
        if (kind == 0x3E) {
            return 1;
        }
        if (kind == 0xE6) {
            return 1;
        }
        if (kind == 0xFF) {
            return 1;
        }
        goto unhandled;
    }
    return 0;
unhandled:
    return 0;
}

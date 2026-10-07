/* Event/state dispatcher for a fading, warping actor variant.
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

extern void fn_80048708(void*);
extern void fn_8009C300(void*, u32, u32);
extern void fn_8009C550(void*);
extern void fn_8009C9D4(void*, void*, void*, void*, s32, s32, f32);
extern void** fn_800BC100(s32, s32, s32*, s32, s32, s32, s32);
extern void fn_800BCCC4(void*, Vec3*);
extern void fn_800BD194(void*, void*);
extern void fn_800BD2DC(void*, void*);
extern void fn_800BDEE4(void*, void*);
extern void fn_800BE010(void*, void*);
extern void fn_800BE8D4(s32);
extern s32 fn_800CA2C8(void*);
extern void fn_800CA890(void*, void*, Vec3*, s32, s32);
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
extern void* fn_80128E30(void*);
extern void fn_80128F74(void*, u32);
extern s32 fn_801290D0(void*);
extern void fn_80129BA4(void*, f32, f32);
extern void fn_8012B324(void*);
extern f32 fn_8012B750(void*);
extern f32 fn_8012B7D0(void*, Vec3*);
extern void* fn_8012C62C(void*, s32, Color*, Color*, Color*, s32);
extern u16 fn_8012DBE8(void*, s32, Color*);
extern s32 fn_80152360(s32, s32);
extern void fn_8017A12C(f32*, f32, f32);
extern s32 fn_801AAE68(u16, u8, u8, f32, Vec3*, signed char, u8, u8, u16, u32);
extern void fn_801D13D8(s32, s32);
extern s32 fn_801DAC18(void*, s32);
extern s32 fn_801E8328(s32, void*);
extern void fn_801FE4FC(u32);
extern s32 fn_802006D4(s32, s32, s32, s32, void (*)(s32));
extern s32 fn_80200C10(void*);
extern void* fn_80200C38(void*);
extern u64 fn_802011D4(void*);
extern void* fn_80201814(s32);
extern s32 fn_80201B44(void);
extern s32 fn_80201B54(void*);
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
extern s32 lbl_8064D18C;
extern const Color lbl_8064ED90, lbl_8064ED94, lbl_8064ED98;
extern const Color lbl_8064ED9C, lbl_8064EDA0, lbl_806519F8;
extern const f32 lbl_8064ED44, lbl_8064ED48, lbl_8064ED4C, lbl_8064ED50;
extern const f32 lbl_8064ED54, lbl_8064ED58, lbl_8064ED64;

s32 fn_8009CC30(register void* object, register s32 phase,
                  register void* event, register u32* result)
{
    Vec3 position, otherPosition, spawnPosition;
    Vec3 spawnCopy, otherCopy, facingCopy;
    s32 spawnId;
    f32 angleDelta;
    Color currentColor;
    f32 facingDelta;
    Color tickColor;
    Color fadeEnd, fadeRate, fadeStart;
    Color visibleEnd, visibleRate, visibleStart;
    register u8* actor;
    register EventState* state;
    register void* context;
    register void* room;
    register ActorData* data;
    register s32 kind;
    register s32 actorId;
    register void** spawned;
    register u32 flags;
    register s32 currentTarget;
    register void* foundObject;
    register u32 renderFlags;
    f32 heading, magnitude;

    kind = fn_80200C10(event);
    room = fn_80201BC8(object);
    data = fn_80201B8C(object);
    actor = data->actor;
    state = data->state;
    context = fn_80201B94(object);
    actorId = fn_80201B54(object);
    fn_8011F114(&position, room);
    fn_80201C48(context);

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
        if (kind == 0x8) {
            fn_800CD094(object, event, 0x320);
            if ((void *) state->effect != NULL) {
                fn_801FE4FC((u32)state->effect);
                state->effect = NULL;
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
        if (kind == 0x69) {
            spawnId = (s32)fn_80200C38(event);
            spawnId = fn_80152360(lbl_8064D18C, spawnId);
            spawned = fn_800BC100(0, 0, &spawnId, 0x10, 0, 0, 0);
            if (spawned != NULL) {
                fn_800BD194(object, actor);
                fn_800BCCC4(*spawned, &spawnPosition);
                fn_80201DD8(context, (void*)-1);
                spawnCopy = spawnPosition;
                fn_80201F44(object, &spawnCopy);
                fn_800BDEE4(object, data->actor);
                fn_800CA890(object, event, &spawnPosition, 3, 0x8A);
                state->target = 0U;
            }
            return 1;
        }
        if (kind == 0x3E) {
            if ((void *) state->effect == NULL) {
                fn_8009C300(object, 0, 1);
                state->effect = NULL;
            }
            fn_800BD194(object, actor);
            state->target = 0U;
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
            fn_80200C38(event);
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
            return 1;
        }
        goto unhandled;
    } else if (phase == 0x30) {
        if (kind == 0x1) {
            fn_800BE8D4(actorId);
            fn_8011FABC(room, 0, 0x80);
            return 1;
        }
        if (kind == 0xE2) {
            fn_8011FABC(room, 0x80, 0);
            fn_8011F0E8(room, (Vec3*)(actor + 0xA0));
            fn_8011FA8C(room, 0, 0xC0);
            fn_80048708(room);
            fadeStart = lbl_8064ED98;
            fadeRate = lbl_8064ED94;
            fadeEnd = lbl_8064ED90;
            fn_8012C62C(room, 0xF, &fadeEnd, &fadeRate, &fadeStart, 4);
            fn_80201DD8(context, (void*)fn_80201B44());
            currentTarget = (s32)fn_80201C48(context);
            if (fn_801DAC18((void*)actorId, 1) != 0) {
                fn_801D13D8(actorId, 0);
            }
            if (currentTarget != 0 && (foundObject = fn_80201814(currentTarget)) != NULL) {
                register void* targetRoom = fn_80201BC8(foundObject);
                fn_8011F114(&otherPosition, targetRoom);
                renderFlags = fn_801290D0(room);
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
        if (kind == 0x3E) {
            fn_801261F4(room);
            flags = fn_8011FAF4(room);
            fn_8012DBE8(room, 0xF, &currentColor);
            if (!(flags & 0x80) && (currentColor.channel.a == 0)) {
                visibleStart = lbl_8064EDA0;
                visibleRate = lbl_806519F8;
                visibleEnd = lbl_8064ED9C;
                fn_8012C62C(room, 0xF, &visibleEnd, &visibleRate, &visibleStart, 4);
                fn_80201DD8(context, (void*)fn_80201B44());
                if ((currentTarget = (s32)fn_80201C48(context)) != 0) {
                    fn_8011F114(&otherPosition, fn_80201BC8(fn_80201814(currentTarget)));
                    renderFlags = fn_801290D0(room);
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
                *result = fn_802011D4(event) & 0xFFFFFFFF;
            }
            return 1;
        }
        if (kind == 0x3) {
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
        if (kind == 0x27) {
            return 1;
        }
        if (kind == 0x69) {
            return 1;
        }
        if (kind == 0x3B) {
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
            fn_800CA2C8(object);
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
            return 1;
        }
        if (kind == 0x2F) {
            return 1;
        }
        if (kind == 0xB) {
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
        goto unhandled;
    }
    return 0;
unhandled:
    return 0;
}

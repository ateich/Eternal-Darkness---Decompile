typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;
#define NULL 0

typedef struct Vec3 { float x, y, z; } Vec3;
/* The phase byte is read both as an enum and as an unsigned counter. */
typedef union PhaseByte { u8 value; s8 signedValue; } PhaseByte;

typedef struct ActorState {
    int actionTimer, cooldownPeriod, hitTimer, reservedC, moveTimer, actionPeriod, nextActionTimer, responsePeriod;
    int responseTimer, attackDelay, chaseTimer, retaliationTimer, targetTimer, pendingTarget, hitReactionTimer;
    void* effect;
    u16 flags;
    PhaseByte phase;
    s8 kind;
} ActorState;
typedef struct RuntimeState {
    u32 flags;
    u8 pad4[0x90];
    Vec3 targetPosition;
    Vec3 savedPosition;
    u8 padAC[0x14];
    int ownerId;
} RuntimeState;
typedef struct ActorData {
    u8 pad0[0x58];
    ActorState* state;
    u8 pad5C[0x30];
    RuntimeState* runtime;
    void* healthData;
} ActorData;
typedef struct HealthData { u8 pad0[0x44]; s16 health; } HealthData;
typedef struct LevelEntry { int first, second, value; } LevelEntry;
typedef struct GameState { u8 pad0[0x191C]; int flags; } GameState;
typedef struct ActorSettings {
    int chasePeriods[4];
    int primary[4];
    int secondary[3];
    int tertiary[4];
} ActorSettings;

extern void fn_80006954(u32);
extern void fn_800069DC(u32);
extern int fn_80035628(void*);
extern int fn_80035FB8();
extern int fn_80036E50(void*);
extern int fn_80038308(void*, int, s16*);
extern int fn_80038464(void*, int, s16*);
extern int fn_80038878(int, int, s16);
extern int fn_800389E0(void*, int, s16, int);
extern int fn_8003E1F0(void*, Vec3*, int, float);
extern u8 fn_80045230(void);
extern void fn_80048708();
extern void* fn_80050950(void);
extern void fn_80052580(int, int, int, int, int);
extern void fn_80064B38();
extern s32 fn_800654F8();
extern void fn_80066754();
extern int fn_8006D548();
extern void fn_800A76A0(void);
extern void fn_800A7738(int, u32, float);
extern s32 fn_800A7A68();
extern void fn_800A7D34(Vec3*, Vec3*, Vec3*);
extern void fn_800A7E88(Vec3*, int);
extern void fn_800A7F1C();
extern void fn_800A7F8C();
extern int fn_800A8034();
extern void fn_800A80CC(int, void*, void*, ActorState*);
extern void fn_800A831C();
extern s32 fn_800A83DC();
extern s32 fn_800A857C();
extern void fn_800ACD30();
extern void fn_800ACED0();
extern void fn_800AD034(int, int, int, int, int, int);
extern s32 fn_800AD1D0();
extern int fn_800AD208(void);
extern void fn_800AD210();
extern int fn_800AD3A4(void);
extern void fn_800BD194();
extern void fn_800BD2DC();
extern void fn_800BDEE4();
extern void fn_800BE010();
extern int fn_800BE2CC(void*, RuntimeState*, Vec3*);
extern void fn_800BE390(void*, RuntimeState*);
extern int fn_800BE86C(void*, Vec3*, int, int, float);
extern void fn_800BE894(void);
extern void fn_800C9A2C(void*);
extern void fn_800CA890();
extern int fn_800CAF7C(void*);
extern int fn_800CB098(s8, s8, int, int, int, int*);
extern float fn_800CB444(void*, void*);
extern s32 fn_8011EB04();
extern void fn_8011F0E8(void*, Vec3*);
extern void fn_8011F114(Vec3*, void*);
extern float fn_8011F6F8(void*);
extern u32 fn_8011FA8C(void*, u32, u32);
extern u32 fn_8011FADC(void*, u32);
extern u32 fn_8011FAEC(void*);
extern int fn_8011FF38(void);
extern void fn_80128A84(void*, u16, u32);
extern void fn_80128C28();
extern void fn_80128C44();
extern void* fn_80128E30(void*);
extern int fn_80128EAC(void*);
extern void fn_80128F74();
extern u16 fn_801290D0(void*);
extern void* fn_801294DC(void*, int, int, int);
extern void* fn_8012976C(void*, int, int, Vec3*, float);
extern int fn_80129928(void*, Vec3*);
extern void fn_80129BA4(void*, float, float);
extern int fn_8012A1BC(void*, int);
extern int fn_8012AFC4(void*);
extern void fn_8012B324(void*);
extern void fn_8012B344(void*);
extern float fn_8012B750(void*);
extern float fn_8012B7D0(const void*, const void*);
extern u8 fn_8012B8A8(void*, Vec3*);
extern void* fn_8012C62C();
extern u16 fn_8012DBE8(void*, u32, u8*);
extern void* fn_80156938(void*);
extern int fn_8015E4E8(void);
extern void fn_8016B400();
extern u32 fn_80178E94(const void*, const void*);
extern int fn_80179064(int, int, int, int);
extern void fn_8017A12C(float*, float, float);
extern u32 fn_80193860(void*);
extern void fn_801938D8(void*, u32);
extern void fn_801A7228(void*);
extern u32 fn_801A7498(void*);
extern u32 fn_801A74C0(void*);
extern void fn_801A7588(void*, u32);
extern void* fn_801A7778(void*);
extern void fn_801A7934(void*);
extern int fn_801AAE68(u16, u8, u8, float, Vec3*, s8, u8, u8, u16, u32);
extern int fn_801AC9F4(u16, u8, Vec3*, u8);
extern void fn_801D0CF0(void*);
extern void fn_801D0D30(int);
extern void fn_801D14CC(int);
extern void fn_801D19FC();
extern void* fn_801D551C(Vec3*, Vec3*, int, int, int, u8, u8, u8, int, int, u8, u8, u8);
extern int fn_801DA27C(u32);
extern s32 fn_801DAC18();
extern void fn_801DB9E0(u32, int, u32, int*);
extern int fn_801E8328();
extern int fn_802006D4();
extern int fn_80200C10(void*);
extern int fn_80200C20(void*);
extern int fn_80200C28(void*);
extern void* fn_80200C38(void*);
extern void fn_8020104C(int, int, int, int, float);
extern unsigned long long fn_8020123C(int, int, int, int);
extern void* fn_80201814(int);
extern int fn_80201ADC(void);
extern int fn_80201AE4(void);
extern void* fn_80201B3C(void);
extern int fn_80201B44(void);
extern int fn_80201B54(void*);
extern int fn_80201B5C(void*);
extern int fn_80201B64(void*);
extern void* fn_80201B94(void*);
extern void* fn_80201BC8(void*);
extern void* fn_80201C48(void*);
extern u32 fn_80201CD4(void*);
extern void fn_80201D14(void*, u8);
extern void fn_80201D1C(void*, u8);
extern void fn_80201D2C(void*, int);
extern void fn_80201D34(void*, int);
extern int fn_80201D88(void*, s16);
extern void fn_80201DD8(void*, void*);
extern int fn_802045AC(void*, Vec3*);
extern HealthData* fn_80072354(void*);
extern ActorData* fn_80201B8C(void*);
extern Vec3* fn_8011F130(void*);
extern void fn_80204810(void);
extern LevelEntry lbl_8023BA64[];
extern ActorSettings lbl_80245800;
extern GameState lbl_803003C8;
extern u8 lbl_8031D718[];
extern u8 lbl_8031D790[0xC4];
extern s32 lbl_8064B2B8;
extern u8 lbl_8064B660[8];
extern u8 lbl_8064B668[8];
extern u8 lbl_8064B670[8];
extern u32 lbl_8064C4E4;
extern s32 *lbl_8064C5A8;
extern s32 lbl_8064C960;
extern void* lbl_8064C964;
extern s32 lbl_8064C974;
extern s32 lbl_8064C978;
extern u8 lbl_8064C97C[8];
extern s32 lbl_8064C980;
extern s32 lbl_8064C984;
extern s32 lbl_8064C988;
extern s32 lbl_8064C98C;
extern s32 lbl_8064C990;
extern s32 lbl_8064CCF4;
extern s32 lbl_8064D18C;
extern s32 lbl_8064D5A8;
extern const f32 lbl_8064EF18;
extern const f32 lbl_8064EF34;
extern s32 lbl_8064EF3C;
extern s32 lbl_8064EF40;
extern s32 lbl_8064EF44;
extern s32 lbl_8064EF48;
extern s32 lbl_8064EF4C;
extern const f32 lbl_8064EF50;
extern const f32 lbl_8064EF54;
extern const f32 lbl_8064EF58;
extern const f32 lbl_8064EF5C;
extern const f32 lbl_8064EF60;
extern const f32 lbl_8064EF64;
extern const f32 lbl_8064EF68;
extern const f32 lbl_8064EF6C;
extern const f32 lbl_8064EF70;
extern const f32 lbl_8064EF74;
extern s32 lbl_80651A38;
extern const float lbl_8064EF1C;
extern void* memset(void*, int, unsigned long);

/* Dispatch shared actor events, then the active combat state. */
s32 fn_800A89D0(void* object, s32 stateId, void* event, s32 *result)
{
    s32 attackDelay;
    ActorData *actorData;
    register void* actor;
    register ActorState *state;
    register s32 objectId;
    register s32 eventId;
    register ActorData *data;
    register RuntimeState *runtime;
    register void* targeting;
    register s32 targetId;
    Vec3 position, effectPosition, effectCenter;
    Vec3 firstPosition, secondPosition, thirdPosition, eventPosition;
    Vec3 targetPosition, waypoint, turnPosition;
    Vec3 victimPosition, otherPosition, aimCopy, lookPosition, lookCopy;
    float angleDelta;
    u8 color[4];
    float lookDelta;
    s32 channelA, channelB, channelC;
    s32 otherA, otherB, otherC;
    s16 healthBefore, healthAfter, maxHealth;
    float radius;

    register ActorSettings* table = &lbl_80245800;

    eventId = fn_80200C10(event);
    actor = fn_80201BC8(object);
    actorData = fn_80201B8C(object);
    data = actorData;
    runtime = data->runtime;
    state = data->state;
    targeting = fn_80201B94(object);
    objectId = fn_80201B54(object);
    fn_8011F114(&position, actor);
    targetId = (s32)fn_80201C48(targeting);
    lbl_8064C98C = objectId;
    if (eventId == 3) {
        fn_800BE010(object, runtime);
        if (!(lbl_8064D5A8 & 0x1F) && ((int)fn_80201C48(targeting) != 0)) {
            fn_800BDEE4(object, runtime);
        }
    }

    if (stateId == 0x0) {

        if (eventId == 0x1) {
            lbl_8064C978 = 0;
            lbl_8064C974 = 1;
            lbl_8064C990 = -1;
            lbl_8064C964 = 0;
            lbl_8064C984 = 0;
            lbl_8064C960 = 0;
            state->chaseTimer = table->chasePeriods[0];
            state->retaliationTimer = 0;
            state->targetTimer = 0;
            state->pendingTarget = 0;
            state->hitReactionTimer = 0;
            fn_800AD210(0);
            if (((s32) state->phase.value == 1) && (fn_800CB098(-1, 0x1C, -1, lbl_8064D18C, 0, 0) == 0)) {
                fn_800ACD30(object);
            }
            memset(&lbl_8031D790, 0, 0xC4);
            fn_8020104C(0x91, objectId, objectId, 1, lbl_8064EF34);
            fn_8020104C(0x91, objectId, objectId, 2, lbl_8064EF50);
            fn_8020123C(0x8F, objectId, objectId, NULL);
            fn_80201D2C(object, 1);
            fn_80201D14(object, 1);
            return 1;
        } else if (eventId == 0xC9) {
            if (fn_8011FF38() != 0) {
                fn_8011FA8C(actor, 0, 0x20000000);

                fn_801AAE68(0x1F1, 0x64, 0, lbl_8064EF54, &position, 2, 2, 0, (u16) lbl_8064D18C, 0);
            }
            return 1;
        } else if (eventId == 0x3E) {
            fn_800BD194(object, runtime);
            return 1;
        } else if (eventId == 0x3D) {
            fn_800BD2DC(object, runtime);
            fn_8020123C(0x78, objectId, objectId, NULL);
            return 1;
        } else if (eventId == 0x91) {
            s32 timerKind;
            timerKind = (int)fn_80200C38(event);
            if (timerKind == (s32)1) {
                fn_800A76A0();
            } else if (timerKind == (s32)2) {
                fn_800A7738(1, 0x10000, lbl_8064EF18);
            }
            return 1;
        } else if (eventId == 0x90) {
            s32 senderId;
            senderId = fn_80200C20(event);
            if (fn_80201814(senderId) != 0) {
                state->targetTimer = 1;
                state->pendingTarget = senderId;
            }
            return 1;
        } else if (eventId == 0xFA) {
            s32 effectEvent;
            effectEvent = (int)fn_80200C38(event);

            switch (effectEvent) {
            case 3:
                if (lbl_8064C964 != 0) {
                    register u32 flags = fn_80193860(lbl_8064C964);
                    fn_801938D8(lbl_8064C964, flags | 0x40000);
                    lbl_8064C964 = 0;
                }
                break;
            case 10:
                fn_801DB9E0(fn_800A8034(object), objectId, (u32)&position, 0);
                break;
            }
            return 1;
        } else if (eventId == 0xC3) {
            s32 delay;
            s32 hitDelay;
            s32 moveDelay;
            s32 actionDelay;
            delay = (int)fn_80200C38(event);
            hitDelay = state->hitTimer;
            if (delay > hitDelay) {
                hitDelay = delay;
            }
            state->hitTimer = hitDelay;
            moveDelay = state->moveTimer;
            if (delay > moveDelay) {
                moveDelay = delay;
            }
            state->moveTimer = moveDelay;
            actionDelay = state->nextActionTimer;
            if (delay > actionDelay) {
                actionDelay = delay;
            }
            state->nextActionTimer = actionDelay;
            if ((u32) state->effect != 0) {
                fn_801D0CF0(state->effect);
                state->effect = 0;
                state->actionTimer = 0;
            }
            return 1;
        } else if (eventId == 0xFB) {
            void *newTarget;
            newTarget = fn_80200C38(event);
            fn_80201DD8(fn_80201B94(object), newTarget);
            return 1;
        } else if (eventId == 0x3B) {
            s32 queryId;
            void* queryObject;
            s32 isPlayerOwned;
            ActorData *queryData;
            isPlayerOwned = 0;
            queryId = fn_80200C20(event);
            queryObject = fn_80201814(queryId);
            queryData = fn_80201B8C(queryObject);
            if (queryData != NULL) {
                RuntimeState *queryRuntime;
                queryRuntime = queryData->runtime;
                if ((queryRuntime != NULL) && (queryRuntime->flags & 0x400000) && ((s32) queryData->runtime->ownerId == fn_80201B44())) {
                    isPlayerOwned = 1;
                }
            }
            if ((queryObject != 0) && (fn_80036E50(queryObject) != 6) && ((queryId == fn_80201B44()) || (isPlayerOwned != 0) || (fn_80201B5C(queryObject) == 0x19))) {
                if (result != NULL) {
                    *result = 1;
                }
            } else if (result != NULL) {
                *result = 0;
            }
            return 1;
        } else if (eventId == 0x27) {
            fn_80038308(object, 0, &healthBefore);
            fn_80064B38(object, event, result);
            fn_80038308(object, 0, &healthAfter);
            if ((s32) state->phase.value == 3) {
                fn_80038464(object, 0, &maxHealth);
                if (healthAfter < (s32) (maxHealth >> 1)) {
                    fn_800ACED0(actor, 2, state);
                }
            }
            return 1;
        } else if (eventId == 0x8) {
            if (fn_800AD3A4() == 0) {
                u8 deathPhase;
                deathPhase = state->phase.value;

                if (((s8) deathPhase) == 1 || ((s8) deathPhase) == 2) {
                    HealthData* health = fn_80072354(data->healthData);
                    health->health = 0x64;
                    fn_80038878(objectId, 0, 0x64);
                    fn_80201D88(object, 0x64);
                    fn_800389E0(object, 0, 0x64, 0);
                } else if (((s8) deathPhase) == 3) {
                    void* deathAction;
                    s32 playerId;
                    playerId = fn_80201AE4();
                    deathAction = fn_801294DC(actor, 0x18, 0x20, 9);
                    if (deathAction != 0) {
                        register int actionKind = fn_8012A1BC(actor, 0x18);
                        fn_80128A84(deathAction, 0, actionKind);
                    }

                    fn_801AAE68(0x213, 0x64, 0, lbl_8064EF54, &position, 2, 3, 0, (u16) lbl_8064D18C, 0);
                    fn_800A7F1C(objectId);
                    fn_801D0D30(playerId);
                    fn_8020104C(0x8D, objectId, objectId, 3, lbl_8064EF58);
                    fn_80006954(0x131);
                    fn_800069DC(0x131);
                    fn_8020123C(0xC3, objectId, objectId, (s32)0x2710);
                    fn_80201D2C(object, 8);
                    fn_80201D14(object, 1);
                }
            }
            return 1;
        } else if (eventId == 0xED) {
            fn_8020123C(0xB, fn_80200C20(event), fn_80200C28(event), (int)fn_80200C38(event));
            fn_801A7228(fn_80200C38(event));
            return 1;
        } else if (eventId == 0x3A) {
            fn_8020123C(0x27, fn_80200C20(event), fn_80200C28(event), (int)fn_80200C38(event));
            fn_801A7228(fn_80200C38(event));
            return 1;
        } else if (eventId == 0xB) {
            if (fn_800AD3A4() == 0) {
                s32 attackerId;
                s32 damageResult;
                void* attacker;
                u8 hitPhase;
                void *damage;
                damage = fn_80200C38(event);
                attackerId = fn_801A7498(damage);
                attacker = fn_80201814(attackerId);
                hitPhase = state->phase.value;
                if (((s8) hitPhase == 1) || ((s8) hitPhase == 2)) {
                    s32 isSpecialHit;
                    void* playerActor;
                    isSpecialHit = 0;
                    playerActor = fn_80050950();
                    if ((attackerId == fn_80201B44()) && (playerActor != 0) && (fn_8011EB04(playerActor) == 1) && !(fn_801A74C0(damage) & 0x10000) && (fn_801A7778(damage) != 0)) {
                        register int damageKind;
                        fn_801A7934(damage);
                        /* ASM: clrlwi captures the byte returned by the tail-called
                         * accessor; the legacy wrapper is declared void in C. */
                        asm { clrlwi damageKind, r3, 24 }

                        if ((s32) damageKind == fn_800AD1D0(1)) {
                            isSpecialHit = 1;
                        }
                    } else if (fn_800AD208() != 0U) {
                        isSpecialHit = 1;
                    }
                    if ((isSpecialHit != 0) && ((s32) lbl_8064C990 != -1)) {
                        s32 effectType;
                        u16 effectFlags;
                        void* victim;
                        victim = fn_80201814(lbl_8064C990);
                        {
                            register void* victimActor = fn_80201BC8(victim);
                            fn_8011F114(&victimPosition, victimActor);
                        }
                        effectPosition = victimPosition;
                        effectType = fn_80035628(victim);
                        fn_800A7D34(NULL, NULL, &effectCenter);
                        effectPosition.z += lbl_8064EF5C;
                        if ((u32) lbl_8064C964 != 0) {
                            fn_8020123C(0xFA, objectId, objectId, (s32)3);
                        }

                        lbl_8064C964 = fn_80156938(fn_801D551C(&effectCenter, &effectPosition, effectType, 0, 0, 3, 0xA, 4, 1, 0, 0x11, 0xA, 0xC));
                        fn_801938D8(lbl_8064C964, fn_80193860(lbl_8064C964) | 0x400);
                        fn_801AC9F4(0x4A, 0x50, &position, 2);
                        effectFlags = state->flags;
                        if (!(effectFlags & 2)) {
                            state->flags = (u16) (effectFlags | 2);
                            lbl_8064C974 = 2;
                            fn_8016B400(0x8B6, lbl_8064C980, 0);
                        } else {
                            fn_8020104C(0xFA, objectId, objectId, 3, lbl_8064EF60);
                            fn_8020123C(0x69, objectId, lbl_8064C990, (s32)8);
                        }
                    } else if ((attacker != 0) && (fn_80201B5C(attacker) == 0x19)) {
                        fn_800A80CC(objectId, object, actor, state);
                    } else if ((s32) state->hitReactionTimer != 0) {
                        fn_80201D2C(object, 1);
                        fn_80201D14(object, 1);
                    } else {
                        s32 hitCallbackTag;
                        register void* hitAction;
                        state->nextActionTimer = (s32) state->actionPeriod;
                        hitAction = fn_801294DC(actor, 0x10, 0x20, 6);
                        if (hitAction != 0) {
                            hitCallbackTag = objectId << 8;
                            fn_80128C44(hitAction, fn_80204810, hitCallbackTag | 7);
                            fn_80128C28(hitAction, &fn_80204810, hitCallbackTag | 0x36);
                            state->hitReactionTimer = 0xB4;
                            fn_80201D2C(object, 7);
                            fn_80201D14(object, 1);
                        }
                    }
                    state->responseTimer = (s32) state->responsePeriod;
                } else if ((attacker != 0) && (fn_80201B5C(attacker) == 0x19)) {
                    fn_800A80CC(objectId, object, actor, state);
                } else {
                    fn_801A7588(damage, 0x8000);
                }
                damageResult = fn_800654F8(damage);
                if (damageResult & 5) {
                    fn_800AD034(*lbl_8064C5A8, 0, 4, 0x23, 0x64, state->phase.signedValue);
                    if ((s32) state->phase.value == 3) {
                        fn_800A7D34(&firstPosition, &secondPosition, &thirdPosition);
                        fn_800A7E88(&firstPosition, 0);
                        fn_800A7E88(&secondPosition, 0);
                        fn_800A7E88(&thirdPosition, 0);
                    }
                }
                if (result != NULL) {
                    *result = damageResult;
                }
            }
            return 1;
        } else if (eventId == 0x35) {
            u8 responsePhase;
            if (fn_80201B5C(fn_80201814(fn_80200C20(event))) == 0x18) {
                state->retaliationTimer = 1;
            }
            responsePhase = state->phase.value;

            if (((s8) responsePhase) == 1 || ((s8) responsePhase) == 2) {
                register int responseOwner = (int)fn_801A7498(fn_80200C38(event));
                if (responseOwner == lbl_8064C990) {
                    fn_80066754(object, event, result);
                }
            } else if (((s8) responsePhase) == 3) {
                fn_80066754(object, event, result);
            }
            return 1;
        } else if (eventId == 0xA) {
            if ((s32) state->phase.value == 3) {
                void* other = fn_80201814(fn_80200C20(event));
                if (other != 0) {
                    Vec3 *attackerPosition;
                    attackerPosition = fn_8011F130(fn_80201BC8(other));
                    if (fn_80179064((s32) position.x, (s32) position.y, (s32) attackerPosition->x, (s32) attackerPosition->y) < 0xC8) {
                        register u8 direction = fn_8012B8A8(actor, attackerPosition);
                        fn_8020123C(0x88, objectId, objectId, direction);
                    }
                }
            }
            return 1;
        } else if (eventId == 0x39) {
            fn_8012B324(actor);
            fn_80201D34(object, 0);
            fn_80201D1C(object, 1);
            fn_801E8328(2, object);
            return 1;
        } else if (eventId == 0x69) {
            fn_8006D548(2, 0x40, 2, &eventPosition, 0, &lbl_8064C97C, 0);
            fn_800CA890(object, event, &eventPosition, 0, -1);
            fn_800BE894();
            return 1;
        } else if (eventId == 0x88) {
            enum ReactionKind { ReactionLeft = 0x9B, ReactionRight = 0x9C };
            s32 reactionCallbackTag;
            register void* reactionAction;
            enum Direction { DirectionLeft = 1 };
            register enum Direction direction = (enum Direction)(int)fn_80200C38(event);
            reactionAction = fn_801294DC(actor, direction == DirectionLeft ? ReactionLeft : ReactionRight, 0x20, 9);
            if (reactionAction != 0) {
                reactionCallbackTag = objectId << 8;
                fn_80128C44(reactionAction, fn_80204810, reactionCallbackTag | 7);
                fn_80128C28(reactionAction, &fn_80204810, reactionCallbackTag | 0x89);
                fn_80201D2C(object, 0x41);
                fn_80201D14(object, 1);
            }
            return 1;
        } else if (eventId == 0x78) {
            if (fn_8015E4E8() == 0) {
                fn_800A831C(objectId, state);
            }
            state->effect = 0;
            return 1;
        } else if (eventId == 0x8D) {
            if (fn_800AD3A4() == 0) {
                s32 transitionEvent;
                u8 transitionPhase;
                fn_80200C38(event);
                transitionPhase = state->phase.value;
                transitionEvent = -1;

                if (((s8) transitionPhase) == 1) {
                    state->cooldownPeriod = (s32)0x190;
                } else if (((s8) transitionPhase) == 2) {
                    s32 transitionId;
                    void *playerPosition;
                    void* player;
                    transitionId = fn_801DA27C(objectId);
                    playerPosition = fn_8011F130((void*)lbl_8064C4E4);
                    player = (void*)fn_80201ADC();
                    if ((player != 0) && (fn_80201B64(player) != 8) && (fn_80201B5C(player) != 0x15)) {
                        fn_8020123C(0xC4, transitionId, transitionId, (int)playerPosition);
                    }
                    state->cooldownPeriod = (s32)0x12C;
                    fn_801D19FC(lbl_8064C988, (int)lbl_8031D718);
                    transitionEvent = lbl_8023BA64[*lbl_8064C5A8].value + 0xA;
                } else if (((s8) transitionPhase) == 3) {
                    void* playerObject;
                    s32 oldFlags;
                    playerObject = fn_80201B3C();
                    if (fn_80045230() == 0) {
                        lbl_8064B2B8 = 0;
                    }
                    fn_800AD1D0(0);
                    fn_800A7F1C(objectId);
                    fn_800C9A2C(playerObject);
                    oldFlags = lbl_803003C8.flags;
                    lbl_803003C8.flags = (s32) (oldFlags | lbl_8064CCF4);
                    fn_8016B400(0x33D, 0, 0);
                }
                if ((transitionEvent >= 8) && (transitionEvent <= 0x10)) {
                    fn_80052580(2, transitionEvent, 1, 1, 0);
                }
                if ((s32) state->phase.value == 3) {
                    state->phase.value = 4U;
                } else {
                    fn_80201D2C(object, 0x26);
                    fn_80201D14(object, 1);
                    fn_8020123C(0x8E, objectId, objectId, NULL);
                }
            }
            return 1;
        } else if (eventId == 0x8E) {
            u8 oldPhase;
            oldPhase = state->phase.value;
            state->phase.value = (u8) (oldPhase + 1);
            fn_80201D2C(object, 0x26);
            fn_80201D14(object, 1);
            fn_8020104C(0x8F, objectId, objectId, 0, lbl_8064EF64);
            return 1;
        } else if (eventId == 0x8F) {
            u8 entryPhase;
            entryPhase = state->phase.value;

            if (((s8) entryPhase) == 1) {
                fn_800ACED0(actor, 1, state);
                state->attackDelay = 0;
                fn_80201D2C(object, 1);
                fn_80201D14(object, 1);
            } else if (((s8) entryPhase) == 2) {
                fn_800ACED0(actor, 1, state);
                fn_800A7738(0, 0x20000, lbl_8064EF18);
                fn_800A7738(1, 0x20000, lbl_8064EF18);
                state->attackDelay = 0;
                fn_80201D2C(object, 1);
                fn_80201D14(object, 1);
            } else if (((s8) entryPhase) == 3) {
                fn_800ACED0(actor, 1, state);
                fn_800A7738(0, 0x40000, lbl_8064EF18);
                fn_800A7738(1, 0x40000, lbl_8064EF18);
                state->hitTimer = 0;
                state->attackDelay = 0;
                fn_80038878(objectId, 0, 0xC8);
                fn_80201D88(object, 0xC8);
                fn_800389E0(object, 0, 0xC8, 0);
                fn_80201D2C(object, 1);
                fn_80201D14(object, 1);
            } else if (((s8) entryPhase) == 4) {
                fn_80201D2C(object, 0x26);
                fn_80201D14(object, 1);
            } else {
                fn_80201D2C(object, 1);
                fn_80201D14(object, 1);
            }
            return 1;
        }
    } else if (stateId == 0x1) {

        if (eventId == 1) {
            return 1;
        } else if (eventId == 2) {
            return 1;
        } else if (eventId == 3) {
            fn_800A857C(object, actor, event, objectId, state);
            return 1;
        }
    } else if (stateId == 0x15) {

        if (eventId == 0x1) {
            fn_8012B344(actor);
            return 1;
        } else if (eventId == 0x3) {
            if ((fn_800A857C(object, actor, event, objectId, state) == 0) && (fn_800BE86C(actor, &runtime->targetPosition, 2, 0, lbl_8064EF68) == 0)) {
                fn_801294DC(actor, 0xF, 0x25, 1);
                fn_80201D2C(object, 1);
                fn_80201D14(object, 1);
            }
            return 1;
        } else if (eventId == 0x5A) {
            void* otherActor;
            void* other = fn_80201814(fn_80200C20(event));
            if (other != 0) {
                otherActor = fn_80201BC8(other);
            } else {
                otherActor = 0;
            }
            if ((otherActor != 0) && (fn_800CAF7C(object) != 0)) {
                fn_8011F114(&otherPosition, otherActor);
                runtime->targetPosition = otherPosition;
            }
            return 1;
        } else if (eventId == 0x2) {
            s32 animationKind;
            s32 animationFlags;
            animationKind = fn_80128EAC(actor);
            animationFlags = fn_801290D0(actor);
            if ((animationFlags & 4) && ((animationKind == 3) || (animationKind == 2))) {
                fn_80128F74(actor, animationFlags & 0xFFFFFFFB);
            }
            return 1;
        }
    } else if (stateId == 0x3) {

        if (eventId == 0x1) {
            int phaseIndex = (s8)state->phase.value - 1;
            register int clampedPhase = (phaseIndex > 0 ? phaseIndex : 0) > 3 ? 3 : (phaseIndex > 0 ? phaseIndex : 0);
            register int* periods;
            /* ASM: slwi and addi preserve the indexed table-address sequence;
             * C folds the zero-offset array address into the indexed load. */
            asm {
                slwi clampedPhase, clampedPhase, 2
                addi periods, table, 0
            }
            state->chaseTimer = *(int*)((u8*)periods + clampedPhase);
            return 1;
        } else if (eventId == 0x3) {
            fn_80201CD4(targeting);
            if (fn_800A83DC(object, actor, event, objectId, state) != 0) {
                s32 remaining;
                remaining = state->chaseTimer;
                if (remaining == 0) {
                    fn_80201D2C(object, 1);
                    fn_80201D14(object, 1);
                } else {
                    void* target;
                    state->chaseTimer = (s32) (remaining - 1);
                    if ((remaining = (s32)fn_80201C48(targeting)) != 0 && (target = fn_80201814(remaining)) != 0) {
                        s32 distance;
                        s32 range;
                        fn_802045AC(object, &targetPosition);
                        distance = fn_80179064((s32) position.x, (s32) position.y, (s32) targetPosition.x, (s32) targetPosition.y);
                        range = (s32) fn_800CB444(object, target);
                        /* The visibility query uses half the actor radius. */
                        radius = fn_8011F6F8(actor);
                        radius *= lbl_8064EF1C;
                        if ((distance < range) || ((distance < 0x1F4) && (fn_8003E1F0(object, &targetPosition, 1, radius) != 0))) {
                            f32 desiredAngle;
                            aimCopy = targetPosition;
                            desiredAngle = fn_8012B7D0(actor, &aimCopy);
                            fn_8017A12C(&angleDelta, fn_8012B750(actor), desiredAngle);
                            if (distance < range) {
                                f32 absoluteAngle;
                                absoluteAngle = angleDelta;
                                if (absoluteAngle < lbl_8064EF18) {
                                    absoluteAngle = -absoluteAngle;
                                }

                                if (absoluteAngle <= lbl_8064EF6C) {
                                    attackDelay = state->attackDelay;
                                    if (attackDelay > 0) {
                                        state->attackDelay = (s32) (attackDelay - 1);
                                        if (fn_800A7A68(object, actor, event) == 0) {
                                            fn_80201D2C(object, 1);
                                            fn_80201D14(object, 1);
                                        }
                                    } else {
                                        state->attackDelay = 5;
                                        state->nextActionTimer = (s32) state->actionPeriod;
                                        fn_800A7F8C(objectId, fn_8011F130(actor), 0x19, 4);
                                    }
                                } else {
                                    goto moveTowardTarget;
                                }
                            } else {
                                moveTowardTarget:
                                if (fn_8012AFC4(actor) != 0) {
                                    fn_80129928(actor, &targetPosition);
                                } else {
                                    fn_8012976C(actor, 2, 0x21, &targetPosition, lbl_8064EF70);
                                }
                            }
                        } else if (fn_800BE2CC(object, runtime, &waypoint) != 0) {
                            if (fn_80178E94(&position, &waypoint) < 0x50U) {
                                fn_800BE390(object, runtime);
                            } else if (fn_8012AFC4(actor) != 0) {
                                fn_80129928(actor, &waypoint);
                            } else {
                                fn_8012976C(actor, 2, 0x21, &waypoint, lbl_8064EF70);
                            }
                        }
                    } else {
                        fn_80201D2C(object, 1);
                        fn_80201D14(object, 1);
                    }
                }
            }
            return 1;
        } else if (eventId == 0x66) {
            fn_8012B344(actor);
            fn_80201D2C(object, 1);
            fn_80201D14(object, 1);
            return 1;
        }
    } else if (stateId == 0x6) {

        if (eventId == 1) {
            return 1;
        } else if (eventId == 2) {
            return 1;
        } else if (eventId == 12) {
            fn_80201D2C(object, 1);
            fn_80201D14(object, 1);
            return 1;
        } else if (eventId == 7) {
            if (fn_80035FB8(object, table->primary, &lbl_8064B660, table->secondary, &lbl_8064B668, table->tertiary) == 0) {
                fn_80201D2C(object, 1);
                fn_80201D14(object, 1);
            }
            return 1;
        }
    } else if (stateId == 0x7) {

        if (eventId == 0x1) {
            return 1;
        } else if (eventId == 0x2) {
            return 1;
        } else if (eventId == 0x36) {
            if ((s32) state->phase.value == 3) {
                fn_8020123C(0x69, objectId, objectId, NULL);
            } else {
                fn_80201D2C(object, 1);
                fn_80201D14(object, 1);
            }
            return 1;
        } else if (eventId == 0x7) {
            if (fn_80035FB8(object, table->primary, &lbl_8064B670, table->secondary, &lbl_8064B668, table->tertiary) == 0) {
                fn_80201D2C(object, 1);
                fn_80201D14(object, 1);
            }
            return 1;
        }
    } else if (stateId == 0x30) {

        if (eventId == 0x1) {
            return 1;
        } else if (eventId == 0x2) {
            return 1;
        } else if (eventId == 0x3) {
            fn_8012DBE8(actor, 0xF, color);
            if (color[3] <= 5U) {
                fn_8011F0E8(actor, &runtime->savedPosition);
                fn_80048708(actor);
                channelC = lbl_8064EF44;
                channelB = lbl_8064EF40;
                channelA = lbl_8064EF3C;
                fn_8012C62C(actor, 0xF, &channelA, &channelB, &channelC, 4);
                if (fn_801DAC18(objectId, 1) != 0) {
                    fn_801D14CC(objectId);
                }
                if (targetId != 0) {
                    f32 lookAngle;
                    f32 absoluteLookAngle;
                    {
                        register void* lookActor = fn_80201BC8(fn_80201814(targetId));
                        fn_8011F114(&lookPosition, lookActor);
                    }
                    turnPosition = lookPosition;
                    {
                        register u32 flags;
                        fn_801290D0(actor);
                        /* ASM: mr retains the getter's already zero-extended return;
                         * C promotion of its u16 result adds a redundant clrlwi. */
                        asm { mr flags, r3 }
                        fn_80128F74(actor, flags | 0x100);
                    }
                    lookCopy = turnPosition;
                    lookAngle = fn_8012B7D0(actor, &lookCopy);
                    fn_8017A12C(&lookDelta, fn_8012B750(actor), lookAngle);
                    absoluteLookAngle = lookDelta;
                    if (absoluteLookAngle < lbl_8064EF18) {
                        absoluteLookAngle = -absoluteLookAngle;
                    }
                    if (absoluteLookAngle > lbl_8064EF74) {
                        fn_80129BA4(fn_80128E30(actor), lookAngle, lbl_8064EF34);
                    }
                }
            } else if (color[3] >= 0xFBU) {
                if ((s32) state->hitTimer < 0x78) {
                    state->hitTimer = (s32)0x78;
                }
                fn_80201D2C(object, 1);
                fn_80201D14(object, 1);
            }
            return 1;
        } else if (eventId == 0xB) {
            return 1;
        } else if (eventId == 0xA) {
            return 1;
        } else if (eventId == 0x8) {
            return 1;
        } else if (eventId == 0x28) {
            return 1;
        } else if (eventId == 0x27) {
            return 1;
        } else if (eventId == 0x69) {
            return 1;
        }
    } else if (stateId == 0x40) {

        if (eventId == 0x1) {
            return 1;
        } else if (eventId == 0x2) {
            return 1;
        } else if (eventId == 0xB0) {
            state->hitTimer = (s32) state->cooldownPeriod;
            fn_800A831C(objectId, state);
            fn_80201D2C(object, 1);
            fn_80201D14(object, 1);
            return 1;
        } else if (eventId == 0x78) {
            s32 cooldown;
            cooldown = state->cooldownPeriod;
            state->hitTimer = cooldown;
            state->effect = 0;
            fn_80201D2C(object, 1);
            fn_80201D14(object, 1);
            return 1;
        } else if (eventId == 0xC) {
            fn_80201D2C(object, 1);
            fn_80201D14(object, 1);
            return 1;
        } else if (eventId == 0x7) {
            if (fn_80035FB8(object, table->primary, &lbl_8064B670, table->secondary, &lbl_8064B668, table->tertiary) == 0) {
                fn_80201D2C(object, 1);
                fn_80201D14(object, 1);
            }
            return 1;
        }
    } else if (stateId == 0x41) {

        if (eventId == 0x1) {
            return 1;
        } else if (eventId == 0x2) {
            return 1;
        } else if (eventId == 0x89) {
            fn_8020123C(0x69, objectId, objectId, NULL);
            return 1;
        } else if (eventId == 0x7) {
            fn_80201D2C(object, 1);
            fn_80201D14(object, 1);
            return 1;
        } else if (eventId == 0xA) {
            return 1;
        }
    } else if (stateId == 0x26) {

        if (eventId == 0x1) {
            return 1;
        } else if (eventId == 0x2) {
            return 1;
        } else if (eventId == 0x7) {
            return 1;
        } else if (eventId == 0xA) {
            return 1;
        } else if (eventId == 0x35) {
            return 1;
        }
    } else if (stateId == 0x8) {

        if (eventId == 0x1) {
            if (actor != 0) {
                register u32 flags = fn_8011FAEC(actor);
                fn_8011FADC(actor, flags & 0xFFFFFF3F);
            }
            return 1;
        } else if (eventId == 0x11) {
            otherC = lbl_80651A38;
            otherB = lbl_8064EF4C;
            otherA = lbl_8064EF48;
            fn_8012C62C(actor, 0xF, &otherA, &otherB, &otherC, 4);
            fn_80201D34(object, 0x15);
            fn_80201D1C(object, 1);
            return 1;
        } else if (eventId == 0x2) {
            fn_802006D4(objectId, objectId, 8, 0x11, 0);
            return 1;
        } else if (eventId == 0x27) {
            return 1;
        } else if (eventId == 0xB) {
            return 1;
        } else if (eventId == 0x8) {
            return 1;
        } else if (eventId == 0xED) {
            return 1;
        } else if (eventId == 0x3A) {
            return 1;
        } else if (eventId == 0xFA) {
            return 1;
        } else if (eventId == 0x35) {
            return 1;
        } else if (eventId == 0x90) {
            return 1;
        } else if (eventId == 0x88) {
            return 1;
        } else if (eventId == 0x69) {
            return 1;
        } else if (eventId == 0x78) {
            return 1;
        } else if (eventId == 0xA) {
            return 1;
        } else if (eventId == 0x3B) {
            return 1;
        }
    } else {
        return 0;
    }
    return 0;
}

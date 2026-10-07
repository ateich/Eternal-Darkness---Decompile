typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef float f32;

#define NULL ((void *)0)

typedef struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

/* Per-instance AI work area (owner->0xC). */
typedef struct AiWork {
    /* 0x00 */ u8 unk0[0x3C];
    /* 0x3C */ u16 flags;
    /* 0x3E */ s16 delay;
    /* 0x40 */ u8 unk40;
    /* 0x41 */ s8 cooldown;
    /* 0x42 */ u8 unk42[3];
    /* 0x45 */ u8 unk45;
} AiWork;

typedef struct AiActor {
    /* 0x000 */ u8 unk0[0x94];
    /* 0x094 */ Vec3 targetPos;
    /* 0x0A0 */ u8 unkA0[0xC4 - 0xA0];
    /* 0x0C4 */ f32 charge;
    /* 0x0C8 */ u8 unkC8[0x14E - 0xC8];
    /* 0x14E */ s16 timer;
    /* 0x150 */ u8 unk150[0x161 - 0x150];
    /* 0x161 */ s8 mask;
} AiActor;

typedef struct AiOwner {
    /* 0x00 */ u8 unk0[0xC];
    /* 0x0C */ AiWork *work;
    /* 0x10 */ u8 unk10[0x8C - 0x10];
    /* 0x8C */ AiActor *actor;
    /* 0x90 */ u8 unk90[0x9C - 0x90];
    /* 0x9C */ s16 phase;
} AiOwner;

extern s32 fn_80035FB8(void *, char *, char *, char *, char *, char *);
extern s32 fn_80036E50(void *);
extern void fn_8003C114(void *, void *, s32);
extern void fn_8003E5DC(void *, void *, s32, AiActor *);
extern s32 fn_800460EC(void);
extern s32 fn_800654F8(s32);
extern void fn_80066888(void *, s32, f32, f32);
extern void fn_80068994(void *, void *);
extern void fn_80078CA4(void *, void *, u32 *);
extern u32 fn_80078D44(s32);
extern s32 fn_80079008(void *, void *);
extern void fn_80079054(void *, s32, void *);
extern s32 fn_800790C0(void *, void *, void *, s32, s32);
extern s32 fn_8007917C(void *, void *, void *);
extern s32 fn_8007923C(void *, void *, void *);
extern s32 fn_8007930C(void *, void *, void *);
extern void fn_80079534(void *, s32, void *, AiActor *, Vec3 *);
extern void fn_80079908(void *, void *, s32);
extern void fn_80079AA4(void *, void *, void *, u32 *);
extern void fn_80079C50(void *, void *, void *, AiWork *);
extern s32 fn_80079D24(void *, void *, s32, AiActor *, void *);
extern void fn_8007A1C0(void *, AiWork *, void *);
extern void fn_800BD194(void *, AiActor *);
extern void fn_800BD2DC(void *, AiActor *);
extern void fn_800BDEE4(void *, AiActor *);
extern void fn_800BE010(void *, AiActor *);
extern s32 fn_800BE86C(void *, Vec3 *, s32, s32, f32);
extern void fn_800BE8D4(s32);
extern u32 fn_800C9BA8(void *, AiOwner *);
extern void fn_800C9E50(void *);
extern void fn_800CA1BC(void *, void *, void *, u32 *);
extern void fn_800CA2C8(void *);
extern s32 fn_800CAF7C(void *);
extern void fn_800CC860(void *, s32, s32);
extern void fn_800CF598(void *);
extern void fn_800EA0FC(void *, AiActor *, s32, void *, u32 *);
extern void fn_800EA3A0(void *, AiActor *);
extern void fn_8011F114(Vec3 *, void *);
extern f32 fn_8011F778(void *, f32);
extern void fn_8011FA8C(void *, s32, s32);
extern void fn_8011FE5C(void *, s32);
extern s32 fn_8011FF38(void);
extern void fn_80120AD0(void *, s32, s32, s32, f32, f32);
extern s32 fn_80128EAC(void *);
extern void fn_80128F74(void *, s32);
extern s32 fn_801290D0(void *);
extern void *fn_801294DC(void *, s32, s32, s32);
extern void fn_8012B324(void *);
extern void fn_8012B344(void *);
extern void fn_801A7228(s32);
extern u32 fn_801A74C0(s32);
extern void fn_801A977C(void *, s32);
extern void fn_801AAE68(s32, s32, s32, f32, Vec3 *, s32, s32, s32, u16, s32);
extern void fn_801AC9F4(u16, s32, Vec3 *, s32);
extern void fn_801E8328(s32, void *);
extern void fn_802006D4(s32, s32, s32, s32, s32);
extern s32 fn_80200C10(void *);
extern s32 fn_80200C20(void *);
extern s32 fn_80200C28(void *);
extern s32 fn_80200C38(void *);
extern void fn_8020104C(s32, s32, s32, s32, f32);
extern void fn_80201138(s32, void *, s32, s32, s32, f32);
extern u64 fn_8020123C(s32, s32, s32, s32);
extern void *fn_80201814(s32);
extern s32 fn_80201B54(void *);
extern AiOwner *fn_80201B8C(void *);
extern s32 fn_80201B94(void *);
extern void *fn_80201BC8(void *);
extern s32 fn_80201C48(s32);
extern void fn_80201D14(void *, s32);
extern void fn_80201D1C(void *, s32);
extern void fn_80201D2C(void *, s32);
extern void fn_80201D34(void *, s32);
extern void fn_80204FDC(void *);

/* Animation, bone and effect names used by the reaction animations. */
typedef struct StringPool {
    /* 0x00 */ char anim[0x18];
    /* 0x18 */ char bone[0xC];
    /* 0x24 */ char effect[0xC];
} StringPool;

extern StringPool lbl_80244820;
extern char lbl_8064B570[8];
extern char lbl_8064B574[8];
extern char lbl_8064B57C[8];
extern s32 lbl_8064D18C;
extern s32 lbl_8064D5A8;
/* .sdata2 constants */
extern const f32 lbl_8064E920;
extern const f32 lbl_8064E950;
extern const f32 lbl_8064E954;
extern const f32 lbl_8064E958;
extern const f32 lbl_8064E95C;
extern const f32 lbl_8064E960;
extern const f32 lbl_8064E964;
extern const f32 lbl_8064E968;
extern const f32 lbl_8064E96C;
extern const f32 lbl_8064E970;
extern const f32 lbl_8064E974;

#define SET_STATE(ctx, s) \
    fn_80201D2C((ctx), (s)); \
    fn_80201D14((ctx), 1)

/* Count the work cooldown down towards zero. */
#define TICK_COOLDOWN(w) \
    do { \
        s8 c = (w)->cooldown; \
        (w)->cooldown = (c > 0) ? c - 1 : 0; \
    } while (0)

/* NonMatching: body is instruction-identical except for split-TU artifacts:
 * retail uses stmw/lmw (this unit builds without -use_lmw_stmw), pools the
 * TU-local string data in r29 (addi r29,0 instead of mr), and names the
 * signed-int conversion bias lbl_8064E930 instead of a local @ constant. */
s32 fn_8007A238(void *ctx, s32 state, void *event, u32 *out) {
    StringPool *strings = &lbl_80244820;
    s32 kind;
    AiWork *work;
    AiOwner *owner;
    AiActor *actor;
    s32 link;
    void *obj;
    s32 id;
    s32 phase;
    s32 mask;
    Vec3 pos;
    Vec3 targetPos;
    Vec3 newPos;

    kind = fn_80200C10(event);
    obj = fn_80201BC8(ctx);
    owner = fn_80201B8C(ctx);
    work = owner->work;
    actor = owner->actor;
    link = fn_80201B94(ctx);
    id = fn_80201B54(ctx);
    fn_8011F114(&pos, obj);
    phase = lbl_8064D5A8 + owner->phase;
    mask = owner->actor->mask;

    if (kind == 3) {
        fn_80079534(ctx, id, obj, actor, &pos);
    }

    if (state == 0) {
        if (kind == 1) {
            SET_STATE(ctx, 1);
            work->unk45 = 0xB4;
            fn_8011F778(obj, lbl_8064E958);
            return 1;
        } else if (kind == 8) {
            fn_80079908(ctx, event, 600);
            return 1;
        } else if (kind == 0x39) {
            fn_800EA3A0(ctx, actor);
            fn_800CA2C8(ctx);
            fn_8012B324(obj);
            fn_80201D34(ctx, 0);
            fn_80201D1C(ctx, 1);
            fn_801E8328(2, ctx);
            return 1;
        } else if (kind == 0xC9) {
            if (fn_8011FF38() != 0) {
                fn_8011FA8C(obj, 0, 0x20000000);
                fn_801AAE68(0x1F1, 0x64, 0, lbl_8064E95C, &pos, 2, 2, 0, (u16)lbl_8064D18C, 0);
            }
            return 1;
        } else if (kind == 0xED) {
            fn_8020123C(0xB, fn_80200C20(event), fn_80200C28(event), fn_80200C38(event));
            fn_801A7228(fn_80200C38(event));
            return 1;
        } else if (kind == 0x3A) {
            fn_8020123C(0x27, fn_80200C20(event), fn_80200C28(event), fn_80200C38(event));
            fn_801A7228(fn_80200C38(event));
            return 1;
        } else if (kind == 0xB) {
            u32 result = fn_80078D44(fn_80200C38(event));
            if (out != NULL) {
                *out = result;
            }
            return 1;
        } else if (kind == 0x97) {
            fn_801AC9F4(fn_80200C38(event), 0x64, &pos, 2);
            return 1;
        } else if (kind == 0x78) {
            fn_80079C50(ctx, obj, event, work);
            return 1;
        } else if (kind == 0xE) {
            fn_80068994(ctx, event);
            return 1;
        } else if (kind == 0x27) {
            fn_80079AA4(ctx, obj, event, out);
            return 1;
        } else if (kind == 0x35) {
            fn_8020123C(0xE6, fn_80200C20(event), id, fn_80200C38(event));
            return 1;
        } else if (kind == 0xE6) {
            fn_8007A1C0(obj, work, event);
            return 1;
        } else if (kind == 0x3B) {
            fn_80078CA4(ctx, event, out);
            return 1;
        } else if (kind == 0x6A) {
            fn_8007923C(ctx, obj, event);
            return 1;
        } else if (kind == 0xE1) {
            fn_8007917C(ctx, obj, event);
            return 1;
        } else if (kind == 0x3D) {
            work->unk45 = 0xB4;
            fn_800BD2DC(ctx, actor);
            return 1;
        } else if (kind == 0x3E) {
            fn_800BD194(ctx, actor);
            fn_800C9E50(ctx);
            return 1;
        } else if (kind == 0x82) {
            if (out != NULL) {
                *out = 1;
            }
            return 1;
        } else if (kind == 0xF3) {
            s32 item = fn_80200C38(event);
            fn_800EA0FC(ctx, actor, item, event, out);
            return 1;
        }
    } else if (state == 1) {
        if (kind == 3) {
            TICK_COOLDOWN(work);
            fn_80079054(ctx, phase, obj);
            fn_800790C0(ctx, obj, event, phase, mask);
            return 1;
        } else if (kind == 0x5A) {
            void *other = fn_80201814(fn_80200C20(event));
            void *target;
            if (other != NULL) {
                target = fn_80201BC8(other);
            } else {
                target = NULL;
            }
            if (target != NULL && fn_800460EC() == 0 && fn_800CAF7C(ctx) != 0 && fn_80036E50(other) != 6) {
                fn_8011F114(&targetPos, target);
                actor->targetPos = targetPos;
                SET_STATE(ctx, 0x15);
            }
            return 1;
        }
    } else if (state == 0x15) {
        if (kind == 1) {
            fn_8012B344(obj);
            actor->charge = lbl_8064E920;
            return 1;
        } else if (kind == 3) {
            if (fn_800790C0(ctx, obj, event, phase, mask) == 0) {
                s32 near = fn_80079008(ctx, obj);
                s32 type = 0x7A;
                if (near != 0) {
                    type = 2;
                }
                TICK_COOLDOWN(work);
                if (fn_800BE86C(obj, &actor->targetPos, type, 0, lbl_8064E960) == 0) {
                    fn_801294DC(obj, near != 0 ? 0xF : 0x76, 0x25, 1);
                    SET_STATE(ctx, 1);
                } else {
                    f32 charge = actor->charge;
                    if (charge < lbl_8064E964) {
                        actor->charge = charge + lbl_8064E960;
                        if (charge <= lbl_8064E968 && actor->charge > lbl_8064E968) {
                            fn_801A977C(obj, 0x3F);
                        }
                    }
                }
            }
            return 1;
        } else if (kind == 0x5A) {
            void *other = fn_80201814(fn_80200C20(event));
            void *target;
            if (other != NULL) {
                target = fn_80201BC8(other);
            } else {
                target = NULL;
            }
            if (target != NULL && fn_800460EC() == 0 && fn_800CAF7C(ctx) != 0 && fn_80036E50(other) != 6) {
                fn_8011F114(&newPos, target);
                actor->targetPos = newPos;
            }
            return 1;
        } else if (kind == 2) {
            s32 mode = fn_80128EAC(obj);
            s32 flags = fn_801290D0(obj);
            if ((flags & 4) && ((u32)(mode - 2) <= 1 || mode == 0x7A)) {
                fn_80128F74(obj, flags & ~4);
            }
            actor->charge = lbl_8064E920;
            return 1;
        }
    } else if (state == 0x31) {
        if (kind == 1) {
            return 1;
        } else if (kind == 6) {
            fn_8011FE5C(obj, 0x76);
            fn_801294DC(obj, 0x76, 0x20, 1);
            if (!(work->flags & 2) || fn_8007930C(ctx, obj, event) == 0) {
                SET_STATE(ctx, 1);
            }
            return 1;
        } else if (kind == 0xB) {
            u32 result = fn_80078D44(fn_80200C38(event));
            if (out != NULL) {
                *out = result;
            }
            return 1;
        } else if (kind == 0xE6) {
            fn_8007A1C0(obj, work, event);
            return 1;
        } else if (kind == 2) {
            work->flags &= ~2;
            return 1;
        } else if (kind == 0xE1) {
            return 1;
        }
    } else if (state == 0x32) {
        if (kind == 1) {
            return 1;
        } else if (kind == 6) {
            fn_8011FE5C(obj, 0xF);
            fn_801294DC(obj, 0xF, 0x20, 1);
            if (work->flags & 1) {
                work->flags &= ~1;
                SET_STATE(ctx, 0x26);
            } else {
                SET_STATE(ctx, 1);
            }
            return 1;
        } else if (kind == 2) {
            return 1;
        } else if (kind == 0x6A) {
            return 1;
        }
    } else if (state == 3) {
        if (kind == 3) {
            fn_800BE010(ctx, actor);
            if (fn_80201C48(link) != 0) {
                fn_800BDEE4(ctx, actor);
            }
            TICK_COOLDOWN(work);
            fn_80079D24(ctx, obj, id, actor, event);
            return 1;
        }
    } else if (state == 7) {
        if (kind == 0x36) {
            SET_STATE(ctx, 1);
            return 1;
        } else if (kind == 7) {
            if (fn_80035FB8(ctx, strings->anim, lbl_8064B570, strings->bone, lbl_8064B574, strings->effect) == 0) {
                SET_STATE(ctx, 1);
            }
            return 1;
        }
    } else if (state == 6) {
        if (kind == 0xC) {
            if (fn_80035FB8(ctx, strings->anim, lbl_8064B57C, strings->bone, lbl_8064B574, strings->effect) == 0) {
                SET_STATE(ctx, 1);
                if (work->delay != 0) {
                    fn_8020123C(0x6A, id, id, 0);
                }
            }
            return 1;
        } else if (kind == 7) {
            if (fn_80035FB8(ctx, strings->anim, lbl_8064B57C, strings->bone, lbl_8064B574, strings->effect) == 0) {
                SET_STATE(ctx, 1);
                work->flags |= 1;
                if (work->delay != 0) {
                    fn_8020123C(0x6A, id, id, 0);
                }
            }
            return 1;
        } else if (kind == 0xB) {
            u32 result = fn_80078D44(fn_80200C38(event));
            if (out != NULL) {
                *out = result;
            }
            return 1;
        } else if (kind == 0xE6) {
            fn_8007A1C0(obj, work, event);
            return 1;
        }
    } else if (state == 0x26) {
        if (kind == 1) {
            fn_80201138(5, ctx, 0x26, -1, 0, work->delay);
            return 1;
        } else if (kind == 5) {
            SET_STATE(ctx, 1);
            return 1;
        } else if (kind == 3) {
            return 1;
        } else if (kind == 0xB) {
            u32 result = fn_80078D44(fn_80200C38(event));
            if (out != NULL) {
                *out = result;
            }
            return 1;
        } else if (kind == 2) {
            fn_802006D4(id, id, 0x26, 5, 0);
            return 1;
        }
    } else if (state == 8) {
        if (kind == 1) {
            fn_8011FA8C(obj, 0xC0, 0);
            fn_800CC860(ctx, 1, 0);
            fn_800BE8D4(id);
            fn_800CA2C8(ctx);
            fn_80204FDC(ctx);
            return 1;
        } else if (kind == 3) {
            fn_8003E5DC(ctx, obj, id, actor);
            actor->timer = 0x5A;
            return 1;
        } else if (kind == 0xC2) {
            fn_800CA1BC(ctx, obj, event, out);
            return 1;
        } else if (kind == 0x3D) {
            fn_800BD2DC(ctx, actor);
            fn_800EA3A0(ctx, actor);
            fn_8020123C(0x39, id, id, 0);
            return 1;
        } else if (kind == 0xC1) {
            if (out != NULL) {
                *out = fn_800C9BA8(obj, owner);
            }
            return 1;
        } else if (kind == 0x2F) {
            SET_STATE(ctx, 0x1F);
            return 1;
        } else if (kind == 0x11) {
            fn_800EA3A0(ctx, actor);
            fn_800CF598(ctx);
            fn_80120AD0(obj, 0, 0, 0x101, lbl_8064E96C, lbl_8064E920);
            fn_801294DC(obj, 0x28, 0x21, 0xA);
            fn_80201D34(ctx, 0x15);
            fn_80201D1C(ctx, 1);
            return 1;
        } else if (kind == 0xB) {
            s32 item = fn_80200C38(event);
            if (fn_801A74C0(item) & 0x20) {
                s32 result = fn_800654F8(item);
                fn_8020123C(0x2F, id, id, 0);
                fn_8020104C(0x31, id, id, 0, lbl_8064E970);
                if (out != NULL) {
                    *out = result;
                }
            }
            return 1;
        } else if (kind == 0x35) {
            fn_80066888(obj, fn_80200C38(event), lbl_8064E950, lbl_8064E954);
            return 1;
        } else if (kind == 2) {
            fn_802006D4(id, id, 8, 0x11, 0);
            return 1;
        } else if (kind == 0x3B) {
            return 1;
        } else if (kind == 8) {
            return 1;
        } else if (kind == 0xB) {
            return 1;
        } else if (kind == 0x27) {
            return 1;
        } else if (kind == 0x6A) {
            return 1;
        }
    } else if (state == 0x1F) {
        if (kind == 1) {
            fn_800CC860(ctx, 2, 0x1E);
            fn_800BE8D4(id);
            fn_801A977C(obj, 0x33);
            fn_800CA2C8(ctx);
            fn_80204FDC(ctx);
            fn_8020104C(0x11, id, id, 0, lbl_8064E974);
            return 1;
        } else if (kind == 3) {
            actor->timer = 0x5A;
            return 1;
        } else if (kind == 0x30) {
            s32 result = fn_800654F8(fn_80200C38(event));
            if (out != NULL) {
                *out = result;
            }
            return 1;
        } else if (kind == 0x31) {
            fn_8003C114(ctx, obj, id);
            return 1;
        } else if (kind == 0x3D) {
            fn_800BD2DC(ctx, actor);
            fn_800EA3A0(ctx, actor);
            fn_8020123C(0x39, id, id, 0);
            return 1;
        } else if (kind == 0x11) {
            fn_800EA3A0(ctx, actor);
            fn_800CF598(ctx);
            fn_80120AD0(obj, 0, 0, 0x101, lbl_8064E96C, lbl_8064E920);
            fn_80201D34(ctx, 0x15);
            fn_80201D1C(ctx, 1);
            return 1;
        } else if (kind == 0x3B) {
            return 1;
        } else if (kind == 0x35) {
            return 1;
        } else if (kind == 8) {
            return 1;
        } else if (kind == 0xB) {
            return 1;
        } else if (kind == 0x27) {
            return 1;
        } else if (kind == 0x6A) {
            return 1;
        }
    } else {
        return 0;
    }
    return 0;
}

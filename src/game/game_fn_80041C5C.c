typedef signed int s32;
typedef unsigned int u32;
typedef signed short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef float f32;

#define NULL ((void *)0)

typedef struct Vec3 {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct ActorState {
    u8 pad_00[0x94];
    Vec3 target;
    u8 pad_A0[0xC1];
    s8 facing;
} ActorState;

typedef struct ContextData {
    u8 pad_00[0x8C];
    ActorState *actor;
    u8 pad_90[0xC];
    s16 phase;
} ContextData;

typedef struct NameTable {
    char sceneA[0x14];
    char tag[0xC];
    char fileA[0x18];
    char sceneB[0x10];
    char fileB[0x18];
    char sceneC[0x14];
    char fileC[0xC];
    char sceneD[0x14];
} NameTable;

s32 fn_80035FB8(s32, void *, void *, void *, void *, void *);
s32 fn_80036E14(u32);
s32 fn_8003C280(s32);
void fn_8003C86C(s32, s32);
void fn_8003CBE4(s32, s32, u32);
void fn_8003D7B4(s32);
s32 fn_8003DC04(s32, u32, s32, s32, s8, s32);
void fn_8003E214(s32, u32, s32, ActorState *, s32, s32, s8);
s32 fn_800460EC(void);
void fn_80062ED0(s32, u32, s32, s32 *);
void fn_80066754(s32, s32, s32 *);
void fn_80066AEC(s32, s32);
void fn_80067858(s32);
void fn_80067A18(s32);
void fn_800AE954(void);
void fn_800BD2DC(s32, ActorState *);
void fn_800BDEE4(s32, ActorState *);
void fn_800BE010(s32, ActorState *);
s32 fn_800BE86C(u32, Vec3 *, s32, s32, f32);
void fn_800CA2C8(s32);
s32 fn_800CAF7C(s32);
void fn_800CC4DC(s32);
void fn_800CF598(s32);
void fn_8011F114(Vec3 *, u32);
void fn_8011FA8C(u32, s32, s32);
void fn_80120AD0(u32, s32, s32, s32, f32, f32);
void *fn_801294DC(u32, s32, s32, s32);
void fn_8012B324(u32);
void fn_8012B344(u32);
void fn_801A7228(void);
void fn_801E8328(s32, s32);
void fn_802006D4(s32, s32, s32, s32, s32);
s32 fn_80200C10(s32);
s32 fn_80200C20(s32);
s32 fn_80200C28(s32);
s32 fn_80200C38(s32);
void fn_8020123C(s32, s32, s32, s32);
u32 fn_80201814(s32);
s32 fn_80201B44(void);
s32 fn_80201B54(s32);
s32 fn_80201B5C(u32);
ContextData *fn_80201B8C(s32);
s32 fn_80201B94(s32);
s32 fn_80201B9C(void);
u32 fn_80201BC8(u32);
s32 fn_80201C48(s32);
void fn_80201D14(s32, s32);
void fn_80201D1C(s32, s32);
void fn_80201D2C(s32, s32);
void fn_80201D34(s32, s32);
void fn_80204844(s32, s32);
void fn_80204FDC(s32);

extern NameTable lbl_8023E7C0;
extern char lbl_8064B488[8];
extern char lbl_8064B490[8];
extern char lbl_8064B498[4];
extern s32 lbl_8064D5A8;
extern const f32 lbl_8064E294;
extern const f32 lbl_8064E314;
extern const f32 lbl_8064E324;

s32 fn_80041C5C(s32 context, s32 state, s32 event, s32 *result) {
    NameTable *names = &lbl_8023E7C0;
    s32 eventType;
    ActorState *actor;
    s32 handle;
    ContextData *data;
    u32 runtime;
    s32 owner;
    Vec3 pos;
    Vec3 tmp;
    Vec3 tmp2;
    s32 frame;
    s32 facing;
    u32 other;

    eventType = fn_80200C10(event);
    runtime = fn_80201BC8(context);
    data = fn_80201B8C(context);
    actor = data->actor;
    handle = fn_80201B94(context);
    owner = fn_80201B54(context);
    fn_8011F114(&pos, runtime);
    frame = lbl_8064D5A8 + data->phase;
    facing = data->actor->facing;

    if (eventType == 3) {
        fn_800CC4DC(context);
    }

    if (state == 0) {
        if (eventType == 1) {
            fn_80067858(owner);
            fn_80201D2C(context, 1);
            fn_80201D14(context, 1);
            return 1;
        }
        if (eventType == 0x39) {
            fn_8012B324(runtime);
            fn_80201D34(context, 0);
            fn_80201D1C(context, 1);
            fn_801E8328(2, context);
            fn_800CA2C8(context);
            fn_80204FDC(context);
            return 1;
        }
        if (eventType == 8) {
            fn_8003C86C(context, event);
            return 1;
        }
        if (eventType == 0xED) {
            fn_8020123C(0xB, fn_80200C20(event), fn_80200C28(event), fn_80200C38(event));
            fn_80200C38(event);
            fn_801A7228();
            return 1;
        }
        if (eventType == 0x3A) {
            fn_8020123C(0x27, fn_80200C20(event), fn_80200C28(event), fn_80200C38(event));
            fn_80200C38(event);
            fn_801A7228();
            return 1;
        }
        if (eventType == 0xB) {
            other = fn_80201814(fn_80200C20(event));
            if (fn_80201B44() == fn_80200C20(event) || fn_80036E14(other) == 4) {
                fn_8020123C(8, owner, owner, 0);
                if (result != NULL) {
                    *result = 1;
                }
            } else if (result != NULL) {
                *result = 0;
            }
            return 1;
        }
        if (eventType == 0x27) {
            fn_80201814(fn_80200C20(event));
            if (fn_80200C20(event) == 0) {
                fn_8020123C(8, owner, owner, 0);
                if (result != NULL) {
                    *result = 1;
                }
            } else if (result != NULL) {
                *result = 0;
            }
            return 1;
        }
        if (eventType == 0x20) {
            fn_80062ED0(context, runtime, event, result);
            return 1;
        }
        if (eventType == 0x3B) {
            u32 target;
            s32 sender = fn_80200C20(event);
            target = fn_80201814(sender);
            if (target != 0 && (sender == fn_80201B44() || fn_80201B5C(target) == 0x19 || fn_80036E14(target) == 4)) {
                if (result != NULL) {
                    *result = 1;
                }
            } else if (result != NULL) {
                *result = 0;
            }
            return 1;
        }
        if (eventType == 0x35) {
            fn_80066754(context, event, result);
            return 1;
        }
        if (eventType == 0x37) {
            fn_80066AEC(context, event);
            return 1;
        }
        if (eventType == 0x32) {
            return 1;
        }
    } else if (state == 1) {
        if (eventType == 3) {
            fn_8003CBE4(context, frame, runtime);
            fn_8003DC04(context, runtime, event, frame, facing, 0);
            return 1;
        }
        if (eventType == 0x5A) {
            u32 target = fn_80201814(fn_80200C20(event));
            if (target != 0) {
                other = fn_80201BC8(target);
            } else {
                other = 0;
            }
            if (other != 0 && fn_800460EC() == 0 && fn_800CAF7C(context) != 0) {
                fn_8011F114(&tmp, other);
                actor->target = tmp;
                fn_80201D2C(context, 0x15);
                fn_80201D14(context, 1);
            }
            return 1;
        }
    } else if (state == 0x15) {
        if (eventType == 1) {
            fn_8012B344(runtime);
            return 1;
        }
        if (eventType == 3) {
            if (fn_8003DC04(context, runtime, event, frame, facing, 0) == 0 &&
                fn_800BE86C(runtime, &actor->target, fn_8003C280(context), 0, lbl_8064E314) == 0) {
                fn_801294DC(runtime, 0xF, 0x25, 1);
                fn_80201D2C(context, 1);
                fn_80201D14(context, 1);
            }
            return 1;
        }
        if (eventType == 0x5A) {
            u32 target = fn_80201814(fn_80200C20(event));
            if (target != 0) {
                other = fn_80201BC8(target);
            } else {
                other = 0;
            }
            if (other != 0 && fn_800460EC() == 0 && fn_800CAF7C(context) != 0) {
                fn_8011F114(&tmp2, other);
                actor->target = tmp2;
            }
            return 1;
        }
    } else if (state == 3) {
        if (eventType == 3) {
            fn_800BE010(context, actor);
            if (fn_80201C48(handle) != 0) {
                fn_800BDEE4(context, actor);
            }
            fn_8003E214(context, runtime, owner, actor, event, frame, facing);
            return 1;
        }
        if (eventType == 0x66) {
            fn_8012B344(runtime);
            fn_80201D2C(context, 1);
            fn_80201D14(context, 1);
            return 1;
        }
    } else if (state == 6) {
        if (eventType == 12) {
            fn_80201D2C(context, 1);
            fn_80201D14(context, 1);
            return 1;
        }
        if (eventType == 7) {
            if (fn_80035FB8(context, names->sceneD, lbl_8064B488, names->tag, lbl_8064B490, names->fileA) == 0) {
                fn_80201D2C(context, 1);
                fn_80201D14(context, 1);
            }
            return 1;
        }
        if (eventType == 13) {
            return 1;
        }
    } else if (state == 7) {
        if (eventType == 0x36) {
            fn_80201D2C(context, 1);
            fn_80201D14(context, 1);
            return 1;
        }
        if (eventType == 7) {
            if (fn_80035FB8(context, names->sceneD, lbl_8064B498, names->tag, lbl_8064B490, names->fileA) == 0) {
                fn_80201D2C(context, 1);
                fn_80201D14(context, 1);
            }
            return 1;
        }
    } else if (state == 0x21) {
        if (eventType == 1) {
            fn_8020123C(8, owner, owner, 0);
            return 1;
        }
        if (eventType == 0x1E) {
            return 1;
        }
        if (eventType == 0x35) {
            return 1;
        }
        if (eventType == 0x37) {
            return 1;
        }
        if (eventType == 0x32) {
            return 1;
        }
        if (eventType == 0x69) {
            return 1;
        }
        if (eventType == 0x27) {
            return 1;
        }
    } else if (state == 8) {
        if (eventType == 1) {
            if (runtime != 0) {
                fn_80204844(fn_80201B9C(), 0x20);
                fn_8011FA8C(runtime, 0xC0, 0);
                fn_800AE954();
            }
            fn_800CA2C8(context);
            fn_80204FDC(context);
            return 1;
        }
        if (eventType == 0x3D) {
            fn_800BD2DC(context, actor);
            fn_8003D7B4(owner);
            fn_80067A18(owner);
            fn_8020123C(0x39, owner, owner, 0);
            return 1;
        }
        if (eventType == 0x11) {
            fn_80204844(fn_80201B9C(), 0x20);
            fn_801294DC(runtime, 0x2C, 0x25, 0xA);
            fn_800CF598(context);
            fn_80120AD0(runtime, 0, 0, 0x101, lbl_8064E324, lbl_8064E294);
            fn_80201D34(context, 0x15);
            fn_80201D1C(context, 1);
            return 1;
        }
        if (eventType == 2) {
            fn_802006D4(owner, owner, 8, 0x11, 0);
            return 1;
        }
        if (eventType == 0x33) {
            fn_8020123C(0x39, owner, owner, 0);
            return 1;
        }
        if (eventType == 0x20) {
            return 1;
        }
        if (eventType == 0x6B) {
            return 1;
        }
        if (eventType == 0x3B) {
            return 1;
        }
        if (eventType == 0x3F) {
            return 1;
        }
        if (eventType == 0x1E) {
            return 1;
        }
        if (eventType == 0x35) {
            return 1;
        }
        if (eventType == 0x37) {
            return 1;
        }
        if (eventType == 0x32) {
            return 1;
        }
        if (eventType == 8) {
            return 1;
        }
        if (eventType == 9) {
            return 1;
        }
        if (eventType == 0xB) {
            return 1;
        }
        if (eventType == 0x27) {
            return 1;
        }
        if (eventType == 0x69) {
            return 1;
        }
        if (eventType == 0x67) {
            return 1;
        }
    } else {
        return 0;
    }
    return 0;
}

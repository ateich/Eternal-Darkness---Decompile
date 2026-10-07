/* State/event dispatch for the actor managed by the 8008xxxx handlers.
 * Each state has its own ordered event tests and returns whether it handled
 * the event. The local vector/color copies mirror the by-value temporaries
 * used when passing positions and effect parameters to those handlers.
 */
typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef float f32;
#define NULL ((void*)0)

typedef struct Vec3 { float x, y, z; } Vec3;
typedef struct Color { u8 r, g, b, a; } Color;
typedef struct Motion {
    Vec3 position;
    int value0C, value10, target_id;
    u8 pad18[8];
    s16 timer;
    s8 attempts;
} Motion;
typedef struct ActorState {
    u8 pad00[0x24];
    int first_id, second_id;
    u8 pad2C[0xC];
    int linked_id;
    u8 pad3C[0x58];
    Vec3 position;
    u8 padA0[0xC1];
    s8 variant;
} ActorState;
typedef struct Link { int unused; int target; } Link;
typedef struct Runtime {
    u8 pad00[0x30];
    Link *link;
    u8 pad34[0x1C];
    Motion *motion;
    u8 pad54[0x38];
    ActorState *actor_state;
    u8 pad90[0xC];
    s16 script_offset;
    u8 pad9E;
    u8 mode;
} Runtime;
typedef struct Stage { int unused, target; u8 pad08[0x78]; } Stage;

extern s32 fn_80035FB8();
extern void* fn_80036D5C();
extern void fn_80036DA4();
extern s32 fn_80036E50();
extern void fn_80048708();
extern void fn_80064B38();
extern s32 fn_800654F8();
extern void fn_80066754();
extern void fn_80066888(int, int, float, float);
extern void fn_80068994();
extern void fn_80072618();
extern void fn_8008CC84();
extern void fn_8008CDA0();
extern int fn_8008CEF0();
extern s32 fn_8008D6E4();
extern void fn_8008DF64();
extern int fn_8008E078();
extern int fn_8008E294();
extern void fn_8008E3D8();
extern void fn_8008E430();
extern void fn_8008E670();
extern void fn_8008E71C();
extern void fn_8008E810();
extern void fn_8008EA1C();
extern void fn_8008ED9C();
extern void fn_8008EF28();
extern void fn_8008EFA8();
extern void fn_8008F5B4();
extern s32 fn_80090204();
extern void fn_8009073C();
extern void fn_80090FF4();
extern void fn_80091124();
extern int fn_8009A2B8(void*, void*, void*, void*, void*, void*, u32, int, float);
extern void fn_800BCCC4();
extern void fn_800BCE94();
extern void fn_800BD194();
extern void fn_800BD2DC();
extern void fn_800BDEE4();
extern void fn_800BE010();
extern s32 fn_800BE70C(void*, Vec3*, int, float*, float, float, float);
extern void fn_800C9E50();
extern s32 fn_800CB254();
extern void fn_800DD314();
extern s32 fn_800DE298();
extern void fn_800DE468();
extern void fn_800DFD54();
extern void fn_8011F0E8();
extern void fn_8011F114();
extern float fn_8011F778(void*, float);
extern u32 fn_8011FA8C();
extern void fn_80120B4C();
extern int fn_801261F4();
extern s32 fn_80128EAC();
extern void fn_80128F74();
extern u16 fn_801290D0();
extern void fn_8012B344();
extern float fn_8012B750();
extern void fn_8012B7A0();
extern void* fn_8012C62C();
extern u16 fn_8012DBE8();
extern u32 fn_8015C910();
extern void fn_8016B400();
extern u32 fn_80178E94();
extern void fn_801A7228();
extern void fn_801A7588();
extern int fn_801AAE68(u16, u8, u8, float, Vec3*, s8, u8, u8, u16, u32);
extern int fn_801AC9F4();
extern void fn_801E79A0();
extern int fn_801E79FC();
extern s32 fn_80200C10();
extern s32 fn_80200C20();
extern s32 fn_80200C28();
extern void* fn_80200C38();
extern void fn_8020104C(int, int, int, int, float);
extern u64 fn_8020123C();
extern void* fn_80201814();
extern s32 fn_80201B44();
extern s32 fn_80201B54();
extern s32 fn_80201B64();
extern void* fn_80201B8C();
extern void* fn_80201B94();
extern void* fn_80201BC8();
extern void* fn_80201C48();
extern void fn_80201D14();
extern void fn_80201D1C();
extern void fn_80201D2C();
extern void fn_80201D34();
extern void fn_80201D54();
extern void fn_80201DD8();
extern s32 fn_80201EB8();
extern void fn_80201F44();
extern void** fn_800BC100();
extern u8 jumptable_802451E0[];
extern Vec3 lbl_8023966C;
extern Vec3 lbl_80239678;
extern Stage lbl_8031D3F8[];
extern Vec3 lbl_8031D578;
extern char lbl_8064B5E0[7];
extern char lbl_8064B5E8[8];
extern char lbl_8064B5F0[4];
extern void* lbl_8064C4E0;
extern void* lbl_8064C4E4;
extern s32 lbl_8064C558;
extern s32 lbl_8064C55C;
extern s32 lbl_8064C560;
extern s32 lbl_8064C564;
extern s32 lbl_8064C570;
extern s32 lbl_8064C578;
extern s32 lbl_8064C57C;
extern s32 lbl_8064C580;
extern s32 lbl_8064C584;
extern s32 lbl_8064C588;
extern f32 lbl_8064C928;
extern s32 lbl_8064D18C;
extern u8* lbl_8064D5A8;
extern f32 lbl_8064EC10;
extern f32 lbl_8064EC28;
extern f32 lbl_8064EC2C;
extern f32 lbl_8064EC30;
extern Color lbl_8064EC58;
extern Color lbl_8064EC5C;
extern f32 lbl_8064EC60;
extern f32 lbl_8064EC64;
extern f32 lbl_8064EC68;
extern f32 lbl_8064EC6C;
extern f32 lbl_8064EC70;
extern Color lbl_806519CC;
extern Color lbl_806519D0;
extern Color lbl_806519D4;
extern Color lbl_806519D8;

int fn_800912D8(void* object, int state, void* event, int* result)
{
    Vec3 position, player_position, arrival_position, exit_position;
    Vec3 chase_position, attack_position, player_transform, event_position;
    Vec3 transition_position, final_position, next_position;
    Color event_color, hold_start, hold_end, hold_rate;
    Color fade_start, fade_end, fade_rate;
    int destination_id;
    Color current_color;
    Color hold_end_copy, hold_start_copy, hold_rate_copy;
    Color fade_end_copy, fade_start_copy, fade_rate_copy;
    Color next_end_copy, next_start_copy, next_rate_copy;
    u8* messages;
    int second_id;
    int first_id;
    int linked_id;
    Motion* motion;
    Runtime* runtime;
    ActorState* details;
    ActorState* actor_state;
    u8* script;
    u32 active_scene;
    void* linked_object;
    void* linked_actor;
    void* player;
    void* sender;
    void* context;
    void* actor;
    void* effect;
    void* effect_actor;
    int event_type;
    int object_id;
    int variant;
    int destination;
    int scene_id;
    int player_type;
    int object_flags;
    int animation_flags;
    int animation;
    int value;
    int sender_id;
    int duration;
    int stage;
    s16 timer;
    float magnitude;

    messages = jumptable_802451E0;

    event_type = fn_80200C10(event);
    actor = fn_80201BC8(object);
    runtime = (Runtime*)fn_80201B8C(object);
    motion = runtime->motion;
    actor_state = runtime->actor_state;
    context = fn_80201B94(object);
    object_id = fn_80201B54(object);
    fn_8011F114(&position, actor);
    details = runtime->actor_state;
    script = lbl_8064D5A8 + runtime->script_offset;
    variant = details->variant;
    scene_id = fn_80201EB8(object);
    if (event_type == 3) {
        fn_80090FF4(object, actor, actor_state, context, motion);
    }
    /* Common events, before a state-specific behavior is selected. */
    if (state == 0x0) {
        if (event_type == 0x1) {
            fn_80091124(object, actor, context, motion);
            return 1;
        } else if (event_type == 0x1B) {
            fn_800DFD54(1, object, actor, event);
            return 1;
        } else if (event_type == 0xED) {
            fn_8020123C(0xB, fn_80200C20(event),
                         fn_80200C28(event), (int)fn_80200C38(event));
            fn_801A7228(fn_80200C38(event));
            return 1;
        } else if (event_type == 0x3A) {
            fn_8020123C(0x27, fn_80200C20(event),
                         fn_80200C28(event), (int)fn_80200C38(event));
            fn_801A7228(fn_80200C38(event));
            return 1;
        } else if (event_type == 0xB) {
            fn_80036DA4(object, (u32)fn_80036D5C(object) & 0xFFEFFFFF);
            fn_801A7588(fn_80200C38(event), 0x8000);
            value = fn_800654F8((int)fn_80200C38(event));
            if (result != NULL) {
                *result = value;
            }
            return 1;
        } else if (event_type == 0xC9) {
            fn_8011FA8C(actor, 0, 0x20000000);
            magnitude = lbl_8064EC28;
            fn_801AAE68(0x1F1, 0x64, 0, magnitude, &position,
                        2, 2, 0, (u16)lbl_8064D18C, 0);
            return 1;
        } else if (event_type == 0x3D) {
            if ((u32)fn_80036D5C(object) & 0x100000) {
                fn_8008EF28(object, actor, motion, event);
            } else {
                fn_8008DF64(object, actor, event, result);
            }
            fn_800BD2DC(object, actor_state);
            return 1;
        } else if (event_type == 0x3E) {
            fn_801261F4(actor);
            fn_800DD314(object, 0xF, 0xFF, 0);
            fn_800BD194(object, actor_state);
            fn_800C9E50(object);
            if (fn_800DE298(object) != 0) {
                fn_801261F4(actor);
                fn_8020123C(0x1B, object_id, object_id, 1);
            }
            return 1;
        } else if (event_type == 0x7B) {
            fn_8009073C(object, actor, event);
            return 1;
        } else if (event_type == 0x3B) {
            sender_id = fn_80200C20(event);
            sender = fn_80201814(sender_id);
            fn_8012DBE8(actor, 0xF, &event_color);
            if (event_color.a > 0x14U && sender_id == fn_80201B44() &&
                fn_80036E50(sender) != 6 && result != NULL) {
                *result = 1;
            }
            return 1;
        } else if (event_type == 0xE) {
            fn_80068994(object, event);
            return 1;
        } else if (event_type == 0x27) {
            fn_80036DA4(object, (u32)fn_80036D5C(object) & 0xFFEFFFFF);
            fn_80064B38(object, event, result);
            return 1;
        } else if (event_type == 0xE6) {
            effect = fn_80200C38(event);
            effect_actor = fn_80201BC8(object);
            fn_80036DA4(object, (u32)fn_80036D5C(object) & 0xFFEFFFFF);
            fn_801A7588(effect, 2);
            fn_80066888((int)effect_actor, (int)effect, lbl_8064EC60, lbl_8064EC64);
            return 1;
        } else if (event_type == 0x35) {
            fn_8008EFA8(object, event, result);
            fn_80036DA4(object, (u32)fn_80036D5C(object) & 0xFFEFFFFF);
            return 1;
        } else if (event_type == 0x8) {
            fn_80036DA4(object, (u32)fn_80036D5C(object) & 0xFFEFFFFF);
            fn_8008CDA0(object, event);
            return 1;
        }
    } else if (state == 0x1) {
        if (event_type == 3) {
            fn_8008CEF0(object, actor, event, script, variant);
            return 1;
        }
        goto unhandled;
    } else if (state == 0x3) {
        if (event_type == 1) {
            return 1;
        }
        if (event_type == 3) {
            fn_800BCE94(object, 0xA);
            chase_position = position;
            fn_8008EA1C(object, actor, object_id, &chase_position, motion, context, event, 0);
            return 1;
        }
        goto unhandled;
    } else if (state == 0x3D) {
        if (event_type == 3) {
            fn_800BCE94(object, 0xA);
            attack_position = position;
            fn_8008ED9C(object, actor, &attack_position, event);
            return 1;
        }
        goto unhandled;
    } else if (state == 0x6) {
        if (event_type == 0xC) {
            fn_80201D2C(object, 1);
            fn_80201D14(object, 1);
            return 1;
        } else if (event_type == 0x7) {
            if (fn_80035FB8(object, messages + 0x1C, lbl_8064B5E0,
                            messages + 0x30, lbl_8064B5E8, messages + 0x3C) == 0) {
                fn_80201D2C(object, 1);
                fn_80201D14(object, 1);
            }
            return 1;
        } else if (event_type == 0x1B) {
            fn_800DFD54(0, object, actor, event);
            return 1;
        } else if (event_type == 0x2) {
            fn_800DD314(object, 0xF, 0xA, 0);
            return 1;
        } else if (event_type == 0x7B) {
            return 1;
        }
    } else if (state == 0x7) {
        if (event_type == 0x1) {
            fn_800DD314(object, 0xF, 0x19, 0xFA);
            return 1;
        } else if (event_type == 0x36) {
            fn_80201D2C(object, 1);
            fn_80201D14(object, 1);
            return 1;
        } else if (event_type == 0x7) {
            if (fn_80035FB8(object, messages + 0x1C, lbl_8064B5F0,
                            messages + 0x30, lbl_8064B5E8, messages + 0x3C) == 0) {
                fn_80201D2C(object, 1);
                fn_80201D14(object, 1);
            }
            return 1;
        } else if (event_type == 0x1B) {
            fn_800DFD54(0, object, actor, event);
            return 1;
        } else if (event_type == 0x2) {
            fn_800DD314(object, 0xF, 0xA, 0);
            return 1;
        } else if (event_type == 0x7B) {
            return 1;
        }
    } else if (state == 0x39) {
        /* Delayed repositioning to the saved player position. */
        if (event_type == 0x1) {
            lbl_8064C588 = 5;
            lbl_8064C584 = 1;
            return 1;
        } else if (event_type == 0x3D) {
            fn_800BD2DC(object, actor_state);
            fn_8008DF64(object, actor, event, result);
            lbl_8064C588 = 5;
            lbl_8064C584 = 1;
            return 1;
        } else if (event_type == 0x3) {
            hold_start = lbl_806519CC;
            hold_end = lbl_806519D0;
            hold_rate = lbl_806519D4;
            lbl_8064C588 = lbl_8064C588 ? lbl_8064C588 - 1 : 0;
            hold_rate_copy = hold_rate;
            hold_start_copy = hold_start;
            hold_end_copy = hold_end;
            fn_8012C62C(actor, 0xF, &hold_end_copy, &hold_start_copy, &hold_rate_copy, 4);
            if ((s32) lbl_8064C588 == 0) {
                fn_8011F114(&player_transform, lbl_8064C4E4);
                player_position = player_transform;
                if ((s32) lbl_8064C584 != 0) {
                    lbl_8031D578 = player_position;
                    lbl_8064C928 = fn_8012B750(lbl_8064C4E4, &lbl_8031D578);
                    lbl_8064C584 = 0;
                } else if (fn_800CB254(object, 0x64, &lbl_8031D578, lbl_8064D18C, 1) == 0) {
                    fn_8012B7A0(actor, lbl_8064C928);
                    fn_8011F0E8(actor, &lbl_8031D578);
                    fn_80048708(actor);
                    fn_8011FA8C(actor, 0, 0xC0);
                    fn_80201D2C(object, 1);
                    fn_80201D14(object, 1);
                }
            }
            return 1;
        } else if (event_type == 0x2) {
            if (fn_800DE298(object) != 0) {
                fn_801261F4(actor);
                fn_8020123C(0x1B, object_id, object_id, 1);
            }
            return 1;
        } else if (event_type == 0x7B) {
            return 1;
        }
    } else if (state == 0x3B) {
        if (event_type == 0x1) {
            fn_800DD314(object, 0xF, 0xA, 0xFA);
            return 1;
        } else if (event_type == 0x6) {
            event_position = position;
            fn_8008E294(object, motion, actor, &event_position, event);
            return 1;
        } else if (event_type == 0x7E) {
            fn_8008E3D8(object, object_id, motion, actor, event);
            return 1;
        } else if (event_type == 0x3D) {
            motion->target_id = 0;
            motion->value10 = 0;
            motion->value0C = 0;
            if ((u32)fn_80036D5C(object) & 0x100000) {
                fn_8008EF28(object, actor, motion, event);
            } else {
                fn_8008DF64(object, actor, event, result);
            }
            fn_800BD2DC(object, actor_state);
            return 1;
        } else if (event_type == 0xE6) {
            fn_80036DA4(object, (u32)fn_80036D5C(object) & 0xFFEFFFFF);
            fn_80066754(object, event, result);
            return 1;
        } else if (event_type == 0x35) {
            fn_80036DA4(object, (u32)fn_80036D5C(object) & 0xFFEFFFFF);
            fn_80066754(object, event, result);
            return 1;
        } else if (event_type == 0x1B) {
            fn_800DFD54(0, object, actor, event);
            return 1;
        } else if (event_type == 0x2) {
            return 1;
        } else if (event_type == 0x7B) {
            return 1;
        }
    } else if (state == 0x38) {
        if (event_type == 0x1) {
            object_flags = (u32)fn_80036D5C(object) & 0x100000;
            motion->attempts = 0;
            duration = 0xF0;
            if (object_flags) {
                duration = 0x12C;
            }
            lbl_8064C57C = duration;
            return 1;
        } else if (event_type == 0x3) {
            fn_8008E430(object, object_id, motion, actor, event, &lbl_8064C57C, 0);
            return 1;
        } else if (event_type == 0x6) {
            fn_8008E078(object, actor, event);
            return 1;
        } else if (event_type == 0x7E) {
            fn_8008E670(object, object_id, actor, event);
            return 1;
        } else if (event_type == 0xE6) {
            fn_80036DA4(object, (u32)fn_80036D5C(object) & 0xFFEFFFFF);
            fn_80066754(object, event, result);
            return 1;
        } else if (event_type == 0x35) {
            fn_80036DA4(object, (u32)fn_80036D5C(object) & 0xFFEFFFFF);
            fn_80066754(object, event, result);
            return 1;
        } else if (event_type == 0x3D) {
            fn_8008E71C(object, object_id, motion, actor, event, result);
            fn_800BD2DC(object, actor_state);
            return 1;
        } else if (event_type == 0x1B) {
            fn_800DFD54(0, object, actor, event);
            return 1;
        } else if (event_type == 0x2) {
            fn_8008E810(object_id, motion);
            return 1;
        } else if (event_type == 0x7B) {
            return 1;
        }
    } else if (state == 0x3C) {
        if (event_type == 0x1) {
            fn_800DD314(object, 0xF, 5, 0);
            return 1;
        } else if (event_type == 0x3D) {
            if ((u32)fn_80036D5C(object) & 0x100000) {
                fn_80201D34(object, 0x49);
                fn_80201D1C(object, 1);
            } else {
                fn_8008DF64(object, actor, event, result);
                fn_800BD2DC(object, actor_state);
            }
            return 1;
        } else if (event_type == 0x6) {
            if ((u32)fn_80036D5C(object) & 0x100000) {
                fn_80201D34(object, 0x49);
                fn_80201D1C(object, 1);
            } else {
                fn_80201D2C(object, 1);
                fn_80201D14(object, 1);
            }
            return 1;
        } else if (event_type == 0x1B) {
            fn_800DFD54(0, object, actor, event);
            return 1;
        } else if (event_type == 0x2) {
            motion->value10 = 0;
            motion->value0C = 0;
            motion->target_id = 0;
            return 1;
        } else if (event_type == 0x7B) {
            return 1;
        }
    } else if (state == 0x3A) {
        if (event_type == 0x1) {
            fn_800DD314(object, 0xF, 0xA, 0xFA);
            lbl_8064C580 = 0;
            return 1;
        } else if (event_type == 0x3) {
            if ((lbl_8064C580++ > 0x82) && (fn_8008D6E4(object, actor, event) == 0)) {
                motion->value10 = 0;
                motion->value0C = 0;
                motion->target_id = 0;
                fn_80201D2C(object, 1);
                fn_80201D14(object, 1);
            }
            return 1;
        } else if (event_type == 0xE6) {
            fn_80036DA4(object, (u32)fn_80036D5C(object) & 0xFFEFFFFF);
            fn_80066754(object, event, result);
            motion->value10 = 0;
            motion->value0C = 0;
            motion->target_id = 0;
            return 1;
        } else if (event_type == 0x35) {
            fn_80036DA4(object, (u32)fn_80036D5C(object) & 0xFFEFFFFF);
            fn_80066754(object, event, result);
            motion->value10 = 0;
            motion->value0C = 0;
            motion->target_id = 0;
            return 1;
        } else if (event_type == 0x1B) {
            fn_800DFD54(0, object, actor, event);
            return 1;
        } else if (event_type == 0x7B) {
            return 1;
        }
    } else if (state == 0x15) {
        if (event_type == 1) {
            fn_8012B344(actor);
            return 1;
        } else if (event_type == 3) {
            if (fn_800BE70C(actor, &actor_state->position, 2, 0, lbl_8064EC30, lbl_8064EC30, lbl_8064EC68) == 0) {
                fn_8012B344(actor);
                fn_80201D2C(object, 1);
                fn_80201D14(object, 1);
            }
            return 1;
        } else if (event_type == 2) {
            animation = fn_80128EAC(actor);
            animation_flags = fn_801290D0(actor);
            if ((animation_flags & 4) && ((animation == 3) || (animation == 2))) {
                fn_80128F74(actor, animation_flags & 0xFFFFFFFB);
            }
            return 1;
        }
    } else if (state == 0x12) {
        if (event_type == 0x1) {
            object_flags = (u32)fn_80036D5C(object);
            runtime->mode = 0x26;
            fn_8012B344(actor);
            fn_800DD314(object, 0xF, 0xFF, 0);
            fn_80036DA4(object, object_flags & 0xFFEFFFFF);
            return 1;
        } else if (event_type == 0x81) {
            active_scene = fn_8015C910();
            fn_801E79FC(lbl_8064C4E0, 0x1F9);
            lbl_8064C560 = 0;
            lbl_8064C564 = 0;
            destination = lbl_8031D3F8[lbl_8064C578].target;
            if ((s32) lbl_8064C578 == 3) {
                if (active_scene != 0U) {
                    fn_8020104C(0x81, object_id, object_id, 0, lbl_8064EC6C);
                }
            } else if ((active_scene == 0U) && (fn_80090204(object) != 0)) {
                if ((linked_object = fn_80201814(runtime->actor_state->linked_id)) != 0) {
                    ((Runtime*)fn_80201B8C(linked_object))->link->target = destination;
                }
                stage = lbl_8064D18C;
                if ((s32) lbl_8064C578 == 2) {
                    if (stage == 0xF5) {
                        arrival_position = lbl_8023966C;
                        fn_80201D54(object, (void*)destination);
                        fn_8011F0E8(actor, &arrival_position);
                        fn_8012B7A0(actor, lbl_8064EC10);
                        fn_80048708(actor);
                        fn_8008CC84(object);
                        fn_80201D34(object, 0x41);
                        fn_80201D1C(object, 1);
                        fn_8016B400(0xAD4, scene_id, 0);
                    } else {
                        fn_80201D54(object, destination);
                        fn_8008CC84(object);
                        fn_80201D34(object, 0x49);
                        fn_80201D1C(object, 1);
                        lbl_8064C55C = 1;
                        transition_position = position;
                        fn_8008F5B4(object, actor, object_id, &transition_position,
                                    motion, context, event, runtime, actor_state,
                                    (void*)destination);
                        fn_8016B400(0x49F, destination, 0);
                    }
                } else {
                    fn_80201D54(object, destination);
                    fn_8008CC84(object);
                    fn_80201D34(object, 0x49);
                    fn_80201D1C(object, 1);
                }
            } else {
                fn_8020104C(0x81, object_id, object_id, 0, lbl_8064EC6C);
            }
            return 1;
        } else if (event_type == 0x3E) {
            return 1;
        } else if (event_type == 0x2) {
            runtime->mode = 8;
            return 1;
        } else if (event_type == 0xB) {
            return 1;
        } else if (event_type == 0x3D) {
            return 1;
        } else if (event_type == 0x7B) {
            return 1;
        } else if (event_type == 0x3B) {
            return 1;
        } else if (event_type == 0x27) {
            return 1;
        } else if (event_type == 0x35) {
            return 1;
        } else if (event_type == 0x8) {
            return 1;
        }
    } else if (state == 0x66) {
        /* Fade and relocate between the staged encounter positions. */
        if (event_type == 0x1) {
            linked_id = runtime->actor_state->linked_id;
            fade_start = lbl_8064EC58;
            fade_end = lbl_8064EC5C;
            fade_rate = lbl_806519D8;
            if (linked_id > 0) {
                fn_8020123C(0x39, linked_id, linked_id, 0);
            }
            first_id = runtime->actor_state->first_id;
            if (first_id > 0) {
                fn_8020123C(0x39, first_id, first_id, 0);
            }
            second_id = runtime->actor_state->second_id;
            if (second_id > 0) {
                fn_8020123C(0x39, second_id, second_id, 0);
            }
            stage = lbl_8064C578 + 1;
            lbl_8064C578 = stage;
            if (stage == 3) {
                destination_id = 0x2D;
                player = fn_80201814(fn_80201B44());
                player_type = fn_80201B64(player);
                linked_actor = fn_80201BC8(player);
                motion->timer = 0x258;
                if ((player_type == 6) || (player_type == 0x27)) {
                    fn_8012B344(linked_actor);
                }
                fn_800BCCC4(*fn_800BC100(0, NULL, &destination_id, 0x10, 0, 0, 0), motion);
                fn_8016B400(0x82A, 1, 0);
                fn_8011F778(actor, lbl_8064EC6C);
                fn_80201DD8(context, -1);
                final_position = motion->position;
                fn_80201F44(object, &final_position);
                fn_800BDEE4(object, runtime->actor_state);
                lbl_8064C570 = 1;
                fn_801AC9F4(0x20E, 0x7F, &position, 2);
                ((s8*)&fade_start)[3] = -1;
                if ((position.z < lbl_8064EC2C) && (fn_80178E94(motion, &position) < 0x320U)) {
                    ((s8*)&fade_start)[3] = -3;
                }
                fade_rate_copy = fade_rate;
                fade_start_copy = fade_start;
                fade_end_copy = fade_end;
                fn_8012C62C(actor, 0xF, &fade_end_copy, &fade_start_copy, &fade_rate_copy, 4);
            } else {
                fn_80072618(&position, motion, 0, 2);
                motion->timer = 0x190;
                fn_800BD194(object, actor_state);
                fn_800BCCC4(*fn_800BC100(0, motion, NULL, 2, 0, 0, 0), motion);
                fn_80201DD8(context, -1);
                next_position = motion->position;
                fn_80201F44(object, &next_position);
                fn_800BDEE4(object, runtime->actor_state);
                lbl_8064C570 = 1;
                lbl_8064C558 = 1;
                fn_801E79A0(lbl_8064C4E0, 0x1F9);
                fn_801AC9F4(0x20E, 0x7F, &position, 2);
                next_rate_copy = fade_rate;
                next_start_copy = fade_start;
                next_end_copy = fade_end;
                fn_8012C62C(actor, 0xF, &next_end_copy, &next_start_copy, &next_rate_copy, 4);
            }
            return 1;
        } else if (event_type == 0x3) {
            fn_800BE010(object, actor_state);
            if ((int)fn_80201C48(context) != 0) {
                fn_800BDEE4(object, actor_state);
            }
            fn_800BCE94(object, 0xA);
            fn_8009A2B8(object, actor, (void*)object_id, actor_state, event, (void*)3, 0x50, 0, lbl_8064EC30);
            fn_8012DBE8(actor, 0xF, &current_color);
            timer = motion->timer;
            motion->timer = timer > 0 ? timer - 1 : 0;
            if (((current_color.a == 0) || (motion->timer <= 0)) && ((s32) lbl_8064C578 == 3)) {
                exit_position = lbl_80239678;
                fn_800DE468(1);
                lbl_8064C558 = 0;
                fn_80120B4C(actor);
                fn_80201D54(object, 0xEF);
                fn_8011F0E8(actor, &exit_position);
                fn_80201D34(object, 0x30);
                fn_80201D1C(object, 1);
                fn_8016B400(0x82A, 0, 0);
            } else if (((current_color.a == 0) || (motion->timer <= 0)) && (fn_80090204(object) != 0)) {
                fn_800DE468(1);
                lbl_8064C558 = 0;
                fn_80120B4C(actor);
                fn_8020104C(0x81, object_id, object_id, 0, lbl_8064EC70);
                fn_80201D2C(object, 0x12);
                fn_80201D14(object, 1);
                fn_80201D54(object, 0xEF);
                fn_8016B400(0x82A, 0, 0);
            }
            return 1;
        } else if (event_type == 0x7) {
            return 1;
        } else if (event_type == 0x3D) {
            fn_80120B4C(actor);
            if ((s32) lbl_8064C578 != 3) {
                fn_8020104C(0x81, object_id, object_id, 0, lbl_8064EC70);
                fn_80201D2C(object, 0x12);
                fn_80201D14(object, 1);
                fn_80201D54(object, 0xEF);
            }
            return 1;
        } else if (event_type == 0x2) {
            lbl_8064C558 = 0;
            return 1;
        } else if (event_type == 0x1B) {
            return 1;
        } else if (event_type == 0xB) {
            return 1;
        } else if (event_type == 0x7B) {
            return 1;
        } else if (event_type == 0x3B) {
            return 1;
        } else if (event_type == 0x65) {
            return 1;
        } else if (event_type == 0x27) {
            return 1;
        } else if (event_type == 0x35) {
            return 1;
        } else if (event_type == 0xE6) {
            return 1;
        } else if (event_type == 0x8) {
            return 1;
        }
    } else {
        return 0;
    }
unhandled:
    return 0;
}

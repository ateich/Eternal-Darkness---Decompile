typedef int s32;
typedef unsigned char u8;
typedef short s16;
typedef struct CallbackState { char x[0x30]; void* inner; } CallbackState;
typedef struct InnerState { s32 x0, owner_kind, type, linked_id; s16 index, x12; s32 enabled; } InnerState;
typedef struct LinkedCallbackState { char x[0x8C]; void* inner; } LinkedCallbackState;
typedef struct LinkedInnerState { char x[0x38]; s32 active; } LinkedInnerState;
typedef struct ShortVector { s16 x, y, z; } ShortVector;
typedef struct FloatVector { float x, y, z; } FloatVector;
extern float lbl_8064E064, lbl_8064E06C;
extern const double lbl_8064E038;
extern s32 lbl_8064D18C;
extern s32 fn_80200C10(void*); extern void* fn_80201B8C(); extern int fn_80201B54();
extern void fn_8020104C(int, void*, void*, int, float);
#define fn_8020104C(a, b, c, d, e) fn_8020104C((a), (void*)(b), (void*)(c), (d), (e))
extern void fn_80201D2C(void*, s32); extern void fn_80201D14(void*, s32);
extern void* fn_801A717C(void); extern void fn_801A74A0(void*,s32); extern void fn_801A74A8(void*,s32); extern void fn_801A7538(void*,s32);
extern void* fn_80201814(); extern int fn_80201B44(); extern s32 fn_80071DD8(void); extern s32 fn_801CEB2C(s32);
extern s32 fn_801D38E8(s32); extern int fn_80035628(void*); extern s32 fn_801D1B10(s16,s32,s32,u8);
extern void fn_801A7518(void*,s32); extern void fn_801A7588(void*,s32); extern void fn_80149A68(void*,ShortVector*,s32,s32,s32);
extern void fn_801A764C(void*,FloatVector*); extern void fn_801A74D8(void*,s32); extern void fn_801A7668(void*,s32); extern void fn_801A7670(void*,s32);
extern unsigned long long fn_8020123C(); extern void fn_801A7228(void*); extern void fn_802006D4(s32,s32,s32,s32,s32);
extern void fn_801E8328(); extern void fn_80201D34(void*,s32); extern void fn_80201D1C(void*, s32);
extern int fn_80201B5C(void*);
#define fn_80201B5C(a) fn_80201B5C((void*)(a))
extern void* fn_80201BC8(); extern s32 fn_80126070(void*); extern void fn_802003C0(s32,s32);

s32 fn_8002E3F0(void* callback, s32 phase, void* event)
{
    s32 event_id = fn_80200C10(event);
    InnerState* state = (InnerState*)((CallbackState*)fn_80201B8C(callback))->inner;
    s32 object_id = fn_80201B54(callback);
    if (phase == 0) {
        if (event_id == 1) {
            fn_8020104C(0x4F, object_id, object_id, 0, lbl_8064E064);
            fn_80201D2C(callback, 1); fn_80201D14(callback, 1); return 1;
        }
        if (event_id == 0x4F) {
            if (state->owner_kind == lbl_8064D18C) {
                register void* linked; void* effect = fn_801A717C(); s32 selection;
                ShortVector short_pos; FloatVector pos;
                fn_801A74A0(effect, object_id); fn_801A74A8(effect, state->linked_id); fn_801A7538(effect, 1);
                linked = fn_80201814(state->linked_id);
                if (state->linked_id != fn_80201B44(linked) && fn_80071DD8() != 0) selection = 0;
                else {
                    event_id = (u8)(((s16)fn_801CEB2C(state->type) >> 1) + 1);
                    selection = fn_801D1B10(state->index, fn_80035628(linked),
                                            fn_801D38E8(state->type), event_id);
                }
                fn_801A7518(effect, selection); fn_801A7588(effect, 0x8000);
                fn_80149A68(linked, &short_pos, 0, 0, 0);
                pos.x = short_pos.x; pos.y = short_pos.y; pos.z = short_pos.z;
                fn_801A764C(effect, &pos); fn_801A74D8(effect, 0x800); fn_801A7668(effect, 4); fn_801A7670(effect, 5);
                fn_8020123C(0xB, object_id, state->linked_id, (s32)effect); fn_801A7228(effect);
                fn_8020104C(0x4F, object_id, object_id, 0, lbl_8064E06C);
            }
            return 1;
        }
        if (event_id == 0x39) {
            void* linked = fn_80201814(state->linked_id);
            if (linked != 0) {
                LinkedCallbackState* linked_callback = (LinkedCallbackState*)fn_80201B8C(linked);
                LinkedInnerState* linked_state = (LinkedInnerState*)linked_callback->inner;
                linked_state->active = 0;
            }
            fn_802006D4(object_id, object_id, -1, 0x4F, 0); fn_801E8328(2, callback);
            fn_80201D34(callback, 0); fn_80201D1C(callback, 1); return 1;
        }
    } else if (phase == 1) {
        if (event_id == 1) return 1;
        if (event_id == 3) {
            if (state->owner_kind == lbl_8064D18C) {
                void* linked;
                s32 ready = 0;
                linked = fn_80201814(state->linked_id);
                if (linked == 0) goto send_complete;
                if (fn_80201B5C(linked) == 0x15) goto send_complete;
                {
                    void* object = fn_80201BC8(linked);
                    if (object != 0) ready = fn_80126070(object);
                    if (ready != 0 && state->enabled != 0) {
                        fn_802003C0(object_id, 0x39);
                        fn_802003C0(object_id, 0x4F);
                    }
                }
                goto phase1_done;
send_complete:
                fn_8020123C(0x39, object_id, object_id, 0);
            } else fn_802003C0(object_id, 0x4F);
phase1_done:
            return 1;
        }
        if (event_id == 2) return 1;
    } else return 0;
    return 0;
}

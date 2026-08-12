typedef unsigned char u8;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct RuntimeState {
    u8 pad0[0x9F];
    u8 type;
} RuntimeState;

typedef struct HandlerState {
    u8 pad0[0x14];
    u32 object_id;
    u32 context_id;
} HandlerState;

extern f32 lbl_8064E638;

extern void* fn_80201B8C();
extern HandlerState *fn_80036D38(s32 context);
extern s32 fn_80200C20(s32 value);
extern int fn_80201B54();
extern void* fn_80201814();
extern void* fn_80201BC8();
extern f32 fn_8012B750(s32 value);
extern s32 fn_80204508(s32 context, s32 value);
extern int fn_80201B44(void);
extern void *fn_801294DC(s32 object, s32 kind, s32 value, s32 flags);
extern void fn_800359A0(s32 context, s32 value);
extern void fn_8012B7A0(s32 object, f32 value);
extern void fn_80204810(void);
extern void fn_80128C28(void *object, void (*callback)(void), s32 value);
extern s32 fn_80201B5C(s32 context);
extern void fn_80201D34(s32 context, s32 value);
extern void fn_80201D1C(s32 context, s32 value);

s32 fn_80062ED0(s32 context, s32 object, s32 event, s32 *out_result)
{
    RuntimeState *runtime;
    HandlerState *state;
    s32 event_object;
    s32 context_kind;
    s32 object_value;
    f32 amount;
    u8 adjusted;
    s32 result;

    runtime = fn_80201B8C(context);
    state = fn_80036D38(context);
    event_object = fn_80200C20(event);
    context_kind = fn_80201B54(context);
    object_value = (s32)fn_80201814(event_object);
    amount = fn_8012B750((s32)fn_80201BC8(object_value));
    adjusted = (u8)fn_80204508(context, (s32)fn_80201814(event_object));
    result = 0;

    if (runtime == 0 || runtime->type != 0x25 || event_object == fn_80201B44()) {
        void *created = fn_801294DC(object, 0x23, 0x24, 6);
        if (created != 0) {
            if ((s32)adjusted != 0) {
                amount -= lbl_8064E638;
            }

            fn_800359A0(context, object_value);
            fn_8012B7A0(object, amount);
            fn_80128C28(created, fn_80204810, (context_kind << 8) | 0x23);
            state->object_id = event_object;
            state->context_id = fn_80201B5C(context);
            fn_80201D34(context, 0x13);
            fn_80201D1C(context, 1);
            result = 1;
        }
    }

    if (out_result != 0) {
        *out_result = result;
    }
    return result;
}

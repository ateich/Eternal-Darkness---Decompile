typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct EventState {
    u8 pad[0x94];
    s32 mode;
} EventState;

extern s32 lbl_8064D18C;
extern int fn_80201B54();
extern void fn_80035628(void *context);
extern void *fn_80201B8C();
extern int fn_80200C38();
extern void *fn_80201814();
extern void *fn_801A717C(void);
extern void fn_801A74A8(void *effect, s32 value);
extern void fn_801A74A0(void *effect, s32 value);
extern void fn_801A7538(void *effect, s32 value);
extern void fn_801A7518(void *effect, s32 value);
extern void fn_801A7588(void *effect, u32 value);
extern void fn_801A764C(void *effect, void *position);
extern u8 fn_80204508(void *object, void *context);
extern unsigned long long fn_8020123C();
extern void fn_801A7470(void *effect, s32 value);
extern void fn_801A74D8(void *effect, u32 value);
extern void fn_801A7228(void *effect);

void fn_8005EA38(s32 owner, void *context, void *event, void *position)
{
    s32 context_id = fn_80201B54(context);
    fn_80035628(context);

    if (owner == lbl_8064D18C) {
        EventState *state = fn_80201B8C(context);
        s32 event_value = fn_80200C38(event);
        void *object = fn_80201814(event_value);

        if (object != 0) {
            void *effect = fn_801A717C();
            fn_801A74A8(effect, event_value);
            fn_801A74A0(effect, context_id);
            fn_801A7538(effect, 1);
            fn_801A7518(effect, 10);
            fn_801A7588(effect, 0x8000);
            fn_801A764C(effect, position);

            if (fn_80204508(object, context)) {
                fn_8020123C(0x37, context_id, event_value, 0);
                fn_801A7470(effect, 11);
            } else {
                fn_801A7470(effect, 12);
            }

            switch (state->mode) {
            case 1:
                fn_801A7538(effect, 1);
                fn_801A7518(effect, 7);
                fn_801A74D8(effect, 0x400000);
                fn_8020123C(0x27, context_id, event_value, effect);
                fn_801A7538(effect, 8);
                fn_801A7518(effect, 3000);
                fn_801A7470(effect, -1);
                fn_801A764C(effect, position);
                fn_8020123C(0x27, context_id, event_value, effect);
                break;
            case 2:
                fn_801A7538(effect, 5);
                fn_801A7518(effect, 5);
                fn_801A74D8(effect, 0x400000);
                fn_8020123C(0x27, context_id, event_value, effect);
                break;
            case 3:
                fn_801A7538(effect, 3);
                fn_801A7518(effect, 5);
                fn_801A74D8(effect, 0x400000);
                fn_8020123C(0x27, context_id, event_value, effect);
                break;
            }
            fn_801A7228(effect);
        }
    }
}

typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
typedef signed int s32;

#pragma use_lmw_stmw on

typedef struct HandlerState {
    u32 flags;
    u8 pad04[0x14C];
    s16 count;
} HandlerState;

typedef struct HandlerData {
    u8 pad00[8];
    void *target;
    u8 pad0C[0x80];
    HandlerState *state;
} HandlerData;
extern void *fn_80201B8C();
extern void *fn_80201B94(void *);
extern s32 fn_80201C48(void *);
extern int fn_80201B54();
extern void fn_80060C28(s32, void *, HandlerData *);
extern s32 fn_800359A0(void *, s32);
extern void *fn_80201814();
extern s32 fn_800601FC(void *, void *, void *);
extern void fn_800BDEE4(void *, HandlerState *);
extern void fn_80201D2C();
extern void fn_80201D14();

s32 fn_80060D4C(void *owner, void *resource, void *target, u32 first_mask,
                 u32 second_mask)
{
    HandlerData *data;
    void *value;
    s32 result;

    result = 0;
    data = fn_80201B8C(owner);
    value = fn_80201B94(owner);

    if (fn_80201C48(value) == 1 &&
        (((u8 *)data->target)[0x89] & 2) == 0) {
        fn_80060C28(fn_80201B54(owner), resource, data);
    } else {
        if (data->state->count >= 1) {
            result = 0;
        } else {
            if ((data->state->flags & 0x00800000) != 0) {
                void *resolved;

                fn_800359A0(owner, 0);
                resolved = (void *)fn_80201C48(value);
                if (fn_80201C48(value) == 1 &&
                    (((u8 *)data->target)[0x89] & 2) == 0) {
                    fn_80060C28(fn_80201B54(owner), resource, data);
                } else {
                    if (fn_800601FC(owner, fn_80201814(resolved), target) != 0) {
                        data->state->count = 600;
                    }
                }
                result = 0;
            } else if ((first_mask & second_mask) == 0 &&
                       fn_800359A0(owner, 0) != 0) {
                if (fn_80201C48(value) == 1 &&
                    (((u8 *)data->target)[0x89] & 2) == 0) {
                    fn_80060C28(fn_80201B54(owner), resource, data);
                } else {
                    if (fn_80201C48(value) != 0) {
                        fn_800BDEE4(owner, data->state);
                    }
                    fn_80201D2C(owner, 3);
                    fn_80201D14(owner, 1);
                    result = 1;
                }
            }
        }
    }
    return result;
}

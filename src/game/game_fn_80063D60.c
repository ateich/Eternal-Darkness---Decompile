typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;

typedef struct DirectionState {
    unsigned char pad00[0x8C];
    struct DirectionRuntime *runtime;
} DirectionState;

typedef struct DirectionRuntime {
    unsigned char pad00[0x64];
    s32 first_direction;
    s32 second_direction;
} DirectionRuntime;

extern s32 fn_801A6DA4(void *value);
extern s32 fn_801A6DAC(void *value);
extern s32 fn_801A6DB4(void *value);
extern s32 fn_801A6DBC(void *value);
extern s32 fn_80063C78(s32 x, s32 y);
extern void fn_801441C0(u16 count, s32 zero, u16 count_again);

s32 fn_80063D60(void *value, DirectionState *state, u16 count)
{
    s32 index;
    s32 changed;
    void *input = value;
    DirectionState *context = state;
    s32 direction;
    s32 doubled_count;

    doubled_count = count * 2;
    changed = 0;
    for (index = 0; index < 2; index++) {
        s16 x;
        s16 y;
        s32 next;

        x = index != 0 ? fn_801A6DB4(input) : fn_801A6DA4(input);
        y = index != 0 ? fn_801A6DBC(input) : fn_801A6DAC(input);
        if (index != 0) {
            direction = context->runtime->second_direction;
        } else {
            direction = context->runtime->first_direction;
        }

        next = fn_80063C78(x, y);
        if (direction != next && next != 8) {
            direction = next;
            changed++;
            fn_801441C0(doubled_count, 0, doubled_count);
        } else if (next != 8) {
            direction = next;
        }

        if (index != 0) {
            context->runtime->second_direction = direction;
        } else {
            context->runtime->first_direction = direction;
        }
    }
    return changed;
}

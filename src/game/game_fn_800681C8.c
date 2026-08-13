typedef signed int s32;

typedef struct RuntimeObject {
    unsigned char data[0xC8];
    s32 slots[12];
} RuntimeObject;

typedef struct ObjectState {
    s32 unused;
    RuntimeObject **installed;
} ObjectState;

extern void *fn_80201B8C();

s32 *fn_800681C8(void)
{
    ObjectState *state;
    RuntimeObject **installed;
    s32 valid;

    state = fn_80201B8C();
    if (state != 0) {
        installed = state->installed;
    } else {
        installed = 0;
    }

    valid = 0;
    if (installed != 0 && *installed != 0) {
        valid = 1;
    }

    if (valid != 0) {
        return (*installed)->slots;
    }
    return 0;
}

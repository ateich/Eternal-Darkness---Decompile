typedef struct EffectState {
    void *owner;
    unsigned char pad04[0xC];
    void *resource;
    unsigned char pad14[0x9A];
    unsigned char flags;
} EffectState;

extern void fn_801850CC(void *);
extern void fn_801A7478(void *, int);

void fn_800E9DE0(EffectState *state)
{
    if ((state->flags & 8) == 0 && (state->flags & 4) != 0) {
        fn_801850CC(state->resource);
        state->flags |= 8;
        state->resource = 0;
        fn_801A7478(state->owner, 0);
    }
}

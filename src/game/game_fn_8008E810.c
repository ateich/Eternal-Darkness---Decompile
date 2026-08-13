typedef struct EffectState {
    unsigned char pad[0xC];
    int value;
    int primary;
    int secondary;
} EffectState;

extern unsigned long long fn_8020123C();

/* NonMatching: behavior-complete frontier reconstruction; MWCC removes the
 * retail redundant branch around the primary/fallback selection. */
void fn_8008E810(int object_id, EffectState* state)
{
    int target = state->primary;
    if (target == 0) {
        target = state->secondary;
    }
    fn_8020123C(126, object_id, target, 0);
    fn_8020123C(122, object_id, state->value, 0);
    state->primary = 0;
    state->value = 0;
    state->secondary = 0;
}

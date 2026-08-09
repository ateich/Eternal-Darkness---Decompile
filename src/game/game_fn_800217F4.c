typedef float f32;
typedef int s32;

void fn_800217F4(f32* value, f32* velocity, f32 lower, f32 upper,
                 s32 reset, s32* counter)
{
    s32 was_at_limit = 0;
    if (*value == upper || *value == lower) {
        was_at_limit = 1;
    }

    *value += *velocity;
    if (*value <= lower) {
        *value = lower;
        *velocity = -*velocity;
    }

    if (*value >= upper) {
        *value = upper;
        if (!was_at_limit) {
            *counter = reset;
        } else {
            (*counter)--;
        }
        if (*counter <= 0) {
            *velocity = -*velocity;
        }
    }
}

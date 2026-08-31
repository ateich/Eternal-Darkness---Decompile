typedef signed short s16;
typedef signed long s32;
typedef unsigned char u8;

void fn_801A8C60(s32 upper, s32 lower, u8* value, s16* delta)
{
    s32 step = *delta;
    u8 current = *value;

    if (step > 0) {
        if (current + step < upper) {
            *value = current + step;
        } else {
            *value = upper;
            *delta = -*delta;
        }
    } else if (step < 0) {
        if (current + step > lower) {
            *value = current + step;
        } else {
            *value = lower;
            *delta = -*delta;
        }
    }
}

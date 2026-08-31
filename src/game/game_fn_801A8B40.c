typedef signed short s16;
typedef signed long s32;
typedef unsigned char u8;

s32 fn_801A8B40(const u8* upper, const u8* lower, u8* value, s16* delta)
{
    u8* end = value + 3;
    s32 lower_count = 0;
    s32 upper_count = 0;
    s16* cursor = delta;

    while (value <= end) {
        if (*cursor > 0) {
            if (*value < *upper) {
                s32 next = *value + *cursor;
                if (next >= *upper) {
                    next = *upper;
                }
                *value = next;
            }
        } else if (*cursor < 0) {
            if (*value > *lower) {
                s32 next = *value + *cursor;
                if (next <= *lower) {
                    next = *lower;
                }
                *value = next;
            }
        }

        if (*value >= *upper) {
            upper_count++;
        }
        if (*value <= *lower) {
            lower_count++;
        }
        upper++;
        lower++;
        value++;
        cursor++;
    }

    if (upper_count == 4 || lower_count == 4) {
        delta[0] = -delta[0];
        delta[1] = -delta[1];
        delta[2] = -delta[2];
        delta[3] = -delta[3];
    }

    if (upper_count == 4) {
        return 4;
    }
    if (lower_count == 4) {
        return -4;
    }
    return upper_count - lower_count;
}

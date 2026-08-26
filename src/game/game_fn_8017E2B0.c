typedef signed short s16;
typedef unsigned short u16;

#pragma opt_propagation off
#pragma opt_common_subs off

typedef struct Vec3s {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

int fn_8017E2B0(Vec3s* lhs, Vec3s* rhs, s16 threshold)
{
    int result = 0;
    int delta;

    delta = rhs->x - lhs->x;
    if (delta >= 0) goto x_nonnegative;
    delta = -delta;
x_nonnegative:
    if ((u16)delta < (u16)threshold) {
        delta = rhs->y - lhs->y;
        if (delta >= 0) goto y_nonnegative;
        delta = -delta;
y_nonnegative:
        if ((u16)delta < (u16)threshold) {
            delta = rhs->z - lhs->z;
            if (delta >= 0) goto z_nonnegative;
            delta = -delta;
z_nonnegative:
            if ((u16)delta < (u16)threshold) {
                result = 1;
            }
        }
    }

    return result;
}

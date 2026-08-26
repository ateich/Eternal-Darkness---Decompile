typedef signed short s16;

typedef struct Vec3s {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

void fn_8017E1B0(Vec3s* lhs, Vec3s* rhs)
{
    lhs->x += rhs->x;
    lhs->y += rhs->y;
    lhs->z += rhs->z;
}

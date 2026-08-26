typedef struct Vec3f {
    float x;
    float y;
    float z;
} Vec3f;

void fn_8017E17C(Vec3f* lhs, Vec3f* rhs)
{
    lhs->x += rhs->x;
    lhs->y += rhs->y;
    lhs->z += rhs->z;
}

typedef unsigned char u8;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

u8 fn_8017ABE0(const Vec3* left, const Vec3* right)
{
    return left->x == right->x && left->y == right->y && left->z == right->z;
}

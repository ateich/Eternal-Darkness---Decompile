typedef struct Vec4 {
    float x;
    float y;
    float z;
    float w;
} Vec4;

float fn_8017A574(const Vec4* left, const Vec4* right)
{
    return left->x * right->x + left->y * right->y +
           left->z * right->z + left->w * right->w;
}

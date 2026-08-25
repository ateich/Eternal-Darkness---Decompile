typedef struct Vec4 {
    float x;
    float y;
    float z;
    float w;
} Vec4;

void fn_8017A34C(const Vec4* left, const Vec4* right, Vec4* output)
{
    Vec4 temporary;
    Vec4* result;

    if (output == left || output == right) {
        result = &temporary;
    } else {
        result = output;
    }

    result->x = left->y * right->z - left->z * right->y
              + left->x * right->w + left->w * right->x;
    result->y = left->z * right->x - left->x * right->z
              + left->y * right->w + left->w * right->y;
    result->z = left->x * right->y - left->y * right->x
              + left->z * right->w + left->w * right->z;
    result->w = left->w * right->w - left->x * right->x
              - left->y * right->y - left->z * right->z;

    if (result == &temporary) {
        *output = *result;
    }
}

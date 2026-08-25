typedef struct Vec4 {
    float x;
    float y;
    float z;
    float w;
} Vec4;

void fn_8017A694(const Vec4* left, const Vec4* right, Vec4* output)
{
    output->x = left->x - right->x;
    output->y = left->y - right->y;
    output->z = left->z - right->z;
    output->w = left->w - right->w;
}

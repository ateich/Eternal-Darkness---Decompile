typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct Vec4 {
    float x;
    float y;
    float z;
    float w;
} Vec4;

extern void fn_80179F48(const Vec4* input, Vec4* output);

void fn_8017A244(const Vec3* input, Vec4* output, float angle)
{
    Vec4 temporary;

    temporary.w = angle;
    temporary.x = input->x;
    temporary.y = input->y;
    temporary.z = input->z;
    fn_80179F48(&temporary, output);
}

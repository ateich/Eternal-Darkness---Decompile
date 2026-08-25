typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct Matrix34 {
    float m[3][4];
} Matrix34;

void fn_8017AD00(const Matrix34* matrix, const Vec3* input, Vec3* output)
{
    output->x = input->x * matrix->m[0][0] + input->y * matrix->m[0][1] +
                input->z * matrix->m[0][2];
    output->y = input->x * matrix->m[1][0] + input->y * matrix->m[1][1] +
                input->z * matrix->m[1][2];
    output->z = input->x * matrix->m[2][0] + input->y * matrix->m[2][1] +
                input->z * matrix->m[2][2];
}

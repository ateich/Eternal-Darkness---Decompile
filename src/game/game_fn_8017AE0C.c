typedef struct Matrix44 {
    float m[4][4];
} Matrix44;

float fn_8017AE0C(const Matrix44* matrix, float value)
{
    return matrix->m[3][2] / (value + matrix->m[2][2]);
}

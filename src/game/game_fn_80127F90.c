typedef float Matrix34[3][4];
typedef float Vec3[3];

extern void fn_80127FD8(void*, int, Matrix34);

void fn_80127F90(void* owner, int index, Vec3 output)
{
    Matrix34 matrix;

    fn_80127FD8(owner, index, matrix);
    output[0] = matrix[0][3];
    output[1] = matrix[1][3];
    output[2] = matrix[2][3];
}

extern void* memset(void*, int, unsigned long);
extern const double lbl_806508F0;
extern const float lbl_806508F8;

typedef struct Matrix44 {
    float m[4][4];
} Matrix44;

void fn_8017AD7C(const Matrix44* input, Matrix44* output)
{
    memset(output, 0, sizeof(*output));
    output->m[0][0] = lbl_806508F0 / input->m[0][0];
    output->m[1][1] = lbl_806508F0 / input->m[1][1];
    output->m[2][3] = lbl_806508F0 / input->m[3][2];
    output->m[3][2] = lbl_806508F8;
    output->m[3][3] = input->m[2][2] / input->m[3][2];
}

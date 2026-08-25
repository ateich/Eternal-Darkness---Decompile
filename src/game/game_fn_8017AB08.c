typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern float fn_80048C2C(float);
extern float fn_80048C50(float);

void fn_8017AB08(const Vec3* input, Vec3* output, float angle)
{
    float sine = fn_80048C2C(angle);
    float cosine = fn_80048C50(angle);

    output->x = input->x * cosine - input->y * sine;
    output->y = input->x * sine + input->y * cosine;
    output->z = input->z;
}

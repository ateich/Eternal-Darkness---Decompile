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

extern float fn_8003315C(float value);
extern float fn_800ED720(float value);
extern const float lbl_80650894;
extern const float lbl_80650878;
extern const float lbl_80650860;
extern const float lbl_806508D0;

/* Constants are retail-owned: 2.0f, 1.0f, 0.0f, and epsilon 0.0005f, respectively. */
void fn_8017A284(const Vec4* input, float* angle, Vec3* axis)
{
    float w = input->w;
    float length;
    float inverse;

    *angle = lbl_80650894 * fn_8003315C(w);
    length = fn_800ED720(lbl_80650878 - w * w);
    if ((length < lbl_80650860 ? -length : length) < lbl_806508D0) {
        length = lbl_80650878;
    }
    inverse = lbl_80650878 / length;
    axis->x = input->x * inverse;
    axis->y = input->y * inverse;
    axis->z = input->z * inverse;
}

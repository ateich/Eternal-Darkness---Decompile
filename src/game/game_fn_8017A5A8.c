typedef struct Vec4 {
    float x;
    float y;
    float z;
    float w;
} Vec4;

extern float fn_8017A574(const Vec4*, const Vec4*);
extern float fn_8003315C(float);
extern const float lbl_80650860;
extern const float lbl_80650878;
extern const float lbl_806508CC;

float fn_8017A5A8(const Vec4* left, const Vec4* right, float limit)
{
    float result = lbl_80650878;
    float dot = fn_8017A574(left, right);

    if (lbl_80650878 - (dot < lbl_80650860 ? -dot : dot) > lbl_806508CC) {
        float angle = fn_8003315C(dot);
        if (angle > limit) {
            result = limit / angle;
        }
    }

    return result;
}

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern const float lbl_8064E2D8;
extern int fn_8003E0E4(void *object, Vec3 *position, float first,
                      float second, int enabled);

int fn_8003E1F0(void *object, Vec3 *position, int enabled, float value)
{
    return fn_8003E0E4(object, position, value, lbl_8064E2D8, enabled);
}

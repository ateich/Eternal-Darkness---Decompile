typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern const float lbl_8064F114;
extern const float lbl_8064F118;
extern int fn_800BE70C(void *, Vec3 *, int, int, float, float, float);

int fn_800BE86C(void *object, Vec3 *position, int type, int enabled,
                float value)
{
    return fn_800BE70C(object, position, type, enabled, value,
                       lbl_8064F114, lbl_8064F118);
}

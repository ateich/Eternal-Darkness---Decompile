typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern float fn_800ED720(float);

void fn_800EC3C4(Vec3 *v)
{
    float length = fn_800ED720(v->x * v->x + v->y * v->y + v->z * v->z);

    v->x /= length;
    v->y /= length;
    v->z /= length;
}

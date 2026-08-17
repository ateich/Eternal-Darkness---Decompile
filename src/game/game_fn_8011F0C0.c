typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

void fn_8011F0C0(Vec3* value, float x, float y, float z)
{
    value->x += x;
    value->y += y;
    value->z += z;
}

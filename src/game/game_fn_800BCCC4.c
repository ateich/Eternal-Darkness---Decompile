typedef struct Vec3f {
    float x, y, z;
} Vec3f;

void fn_800BCCC4(const short *source, Vec3f *result)
{
    result->x = source[0];
    result->y = source[1];
    result->z = source[2];
}

typedef float f32;

typedef struct Float3 {
    f32 x;
    f32 y;
    f32 z;
} Float3;

f32 fn_8003CC1C(Float3 *value)
{
    f32 x = value->x;
    f32 maximum = value->y > x ? value->y : x;

    if (value->z > maximum) {
        return value->z;
    }
    return maximum;
}

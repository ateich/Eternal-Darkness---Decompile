typedef struct Vec4 {
    float x;
    float y;
    float z;
    float w;
} Vec4;

void fn_8017A71C(Vec4* value)
{
    value->x = -value->x;
    value->y = -value->y;
    value->z = -value->z;
    value->w = -value->w;
}

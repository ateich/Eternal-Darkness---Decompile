typedef signed short s16;

typedef struct Vec3s {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

void fn_8017D2B4(Vec3s* first, Vec3s* second, Vec3s* offset)
{
    offset->x += second->x;
    offset->y += second->y;
    offset->z += second->z;
    first->x += offset->x;
    first->y += offset->y;
    first->z += offset->z;
}

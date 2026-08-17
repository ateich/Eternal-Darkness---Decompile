typedef struct Vec3s { short x, y, z; } Vec3s;

void fn_8013C964(const Vec3s* value, int* first, int* second, int axis)
{
    switch (axis) {
    case 0:
        *first = value->z;
        *second = value->y;
        break;
    case 1:
        *first = value->x;
        *second = value->z;
        break;
    case 2:
        *first = value->x;
        *second = value->y;
        break;
    }
}

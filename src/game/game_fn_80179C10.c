typedef signed char s8;

typedef struct Coord3 {
    float x;
    float y;
    float z;
} Coord3;

void fn_80179C10(Coord3* point, const Coord3* plane, float first, float second,
                 float constant, s8 axis)
{
    switch (axis) {
    case 0:
        point->y = first;
        point->z = second;
        point->x = (plane->y * point->y + constant + plane->z * point->z) / -plane->x;
        break;
    case 1:
        point->x = first;
        point->z = second;
        point->y = (plane->x * point->x + constant + plane->z * point->z) / -plane->y;
        break;
    case 2:
        point->x = first;
        point->y = second;
        point->z = (plane->x * point->x + constant + plane->y * point->y) / -plane->z;
        break;
    }
}

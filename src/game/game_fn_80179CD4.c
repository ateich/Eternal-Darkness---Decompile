typedef signed char s8;

typedef struct Coord2 {
    float x;
    float y;
} Coord2;

typedef struct Coord3 {
    float x;
    float y;
    float z;
} Coord3;

void fn_80179CD4(Coord2* destination, const Coord3* source, float unused_first,
                 float unused_second, float unused_third, s8 axis)
{
    switch (axis) {
    case 0:
        destination->x = source->y;
        destination->y = source->z;
        break;
    case 1:
        destination->x = source->x;
        destination->y = source->z;
        break;
    case 2:
        destination->x = source->x;
        destination->y = source->y;
        break;
    }
}

typedef struct ShortCoord3 {
    short x;
    short y;
    short z;
} ShortCoord3;

typedef struct Coord3 {
    float x;
    float y;
    float z;
} Coord3;

void fn_8017960C(ShortCoord3* first, ShortCoord3* second, Coord3* output)
{
    output->x = first->x - second->x;
    output->y = first->y - second->y;
    output->z = first->z - second->z;
}

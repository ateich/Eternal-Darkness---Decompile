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

void fn_8017974C(ShortCoord3* first, ShortCoord3* second, Coord3* output,
                 float amount)
{
    output->x = first->x + amount * (second->x - first->x);
    output->y = first->y + amount * (second->y - first->y);
    output->z = first->z + amount * (second->z - first->z);
}

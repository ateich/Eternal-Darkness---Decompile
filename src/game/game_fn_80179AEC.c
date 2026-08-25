typedef struct Coord3 {
    float x;
    float y;
    float z;
} Coord3;

void fn_80179AEC(Coord3* source, Coord3* destination)
{
    destination->x = source->x;
    destination->y = source->y;
    destination->z = source->z;
}

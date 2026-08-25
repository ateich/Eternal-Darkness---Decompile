typedef struct Coord3 {
    float x;
    float y;
    float z;
} Coord3;

void fn_80179570(Coord3* first, Coord3* second, Coord3* output)
{
    output->x = first->x + second->x;
    output->y = first->y + second->y;
    output->z = first->z + second->z;
}

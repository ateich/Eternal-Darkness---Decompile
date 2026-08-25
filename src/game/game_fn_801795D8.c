typedef struct ShortCoord3 {
    short x;
    short y;
    short z;
} ShortCoord3;

void fn_801795D8(ShortCoord3* first, ShortCoord3* second, ShortCoord3* output)
{
    output->x = first->x - second->x;
    output->y = first->y - second->y;
    output->z = first->z - second->z;
}

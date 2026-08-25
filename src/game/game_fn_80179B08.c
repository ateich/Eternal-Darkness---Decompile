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

extern void fn_80179B58(short*, float*);

void fn_80179B08(ShortCoord3* source, Coord3* destination)
{
    fn_80179B58(&source->x, &destination->x);
    fn_80179B58(&source->y, &destination->y);
    fn_80179B58(&source->z, &destination->z);
}

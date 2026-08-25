typedef struct Coord3 {
    float x;
    float y;
    float z;
} Coord3;

typedef struct ShortCoord3 {
    short x;
    short y;
    short z;
} ShortCoord3;

extern void fn_80179BB4(float*, short*);

void fn_80179BC0(Coord3* source, ShortCoord3* destination)
{
    fn_80179BB4(&source->x, &destination->x);
    fn_80179BB4(&source->y, &destination->y);
    fn_80179BB4(&source->z, &destination->z);
}

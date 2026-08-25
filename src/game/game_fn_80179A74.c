typedef struct Coord3 {
    float x;
    float y;
    float z;
} Coord3;

extern unsigned int fn_80178F14(int, int, int, int, int, int);

float fn_80179A74(Coord3* value)
{
    return (float)fn_80178F14(0, 0, 0, (int)value->x, (int)value->y,
                              (int)value->z);
}

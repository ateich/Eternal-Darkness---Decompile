typedef struct Coord3 {
    float x;
    float y;
    float z;
} Coord3;

void fn_801798DC(Coord3* value, float scale)
{
    value->x *= scale;
    value->y *= scale;
    value->z *= scale;
}

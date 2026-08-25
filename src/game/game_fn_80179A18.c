typedef struct Coord3 {
    float x;
    float y;
    float z;
} Coord3;

extern float fn_80179A74(Coord3*);

void fn_80179A18(Coord3* value)
{
    float length = fn_80179A74(value);

    if (length != 0.0) {
        value->x /= length;
        value->y /= length;
        value->z /= length;
    }
}

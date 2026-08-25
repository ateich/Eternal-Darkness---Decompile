typedef struct ShortCoord3 {
    short x;
    short y;
    short z;
} ShortCoord3;

extern int fn_80178F14(int, int, int, int, int, int);

void fn_80179904(ShortCoord3* value, short length)
{
    int current = fn_80178F14(0, 0, 0, value->x, value->y, value->z);

    if (current != 0) {
        float scale = (float)length / (float)current;

        value->x = (short)(scale * (float)value->x);
        value->y = (short)(scale * (float)value->y);
        value->z = (short)(scale * (float)value->z);
    }
}

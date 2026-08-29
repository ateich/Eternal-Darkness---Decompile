typedef signed short s16;

typedef struct ShortCoord3 {
    s16 x;
    s16 y;
    s16 z;
} ShortCoord3;

extern double lbl_80650B98;

void fn_80198BF4(ShortCoord3* point, float scale)
{
    point->x = (s16)(scale * point->x);
    point->y = (s16)(scale * point->y);
    point->z = (s16)(scale * point->z);
}

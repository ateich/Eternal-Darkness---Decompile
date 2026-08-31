typedef signed short s16;

int fn_801A9384(s16 x0, s16 x1, s16 y0, s16 y1, s16 x2, s16 x3, s16 y2, s16 y3)
{
    if (y3 < x1) {
        return 0;
    }
    if (x3 > y1) {
        return 0;
    }
    if (y2 < x0) {
        return 0;
    }
    return x2 <= y0;
}

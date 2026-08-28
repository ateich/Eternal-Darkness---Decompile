typedef signed short s16;

void fn_8018D020(s16* out, float x, float y, float z, float w, float t)
{
    out[0] = x;
    out[1] = y;
    out[2] = t;
    out[3] = z;
    out[4] = y;
    out[5] = t;
    out[6] = w;
    out[7] = t;
    out[8] = x;
    out[9] = w;
    out[10] = w;
    out[11] = t;
}

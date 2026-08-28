typedef signed short s16;

void fn_8018D724(s16* out, float x, float y, float z, float unused,
                 float depth)
{
    out[0] = x;
    out[1] = y;
    out[2] = depth;
    out[3] = z;
    out[4] = y;
    out[5] = depth;
}

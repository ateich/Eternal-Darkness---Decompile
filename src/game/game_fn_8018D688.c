typedef signed short s16;

void fn_8018D688(s16* out, float left, float top, float right, float bottom,
                 float depth)
{
    out[0] = left + (s16)((int)(right - left) >> 1);
    out[1] = top;
    out[2] = depth;
    out[3] = left + (s16)((int)(right - left) >> 1);
    out[4] = bottom;
    out[5] = depth;
}

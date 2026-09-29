typedef float f32;
typedef signed short s16;

extern void fn_801252D8(int);

/*
 * NonMatching: assumes GQR2 retains the signed-16, scale-4 setup installed
 * by fn_801EF788. fn_801252D8(4) configures GQR6, not GQR2.
 * Retail loads all three packed components before storing the float vector.
 */
void fn_801270DC(f32* output, const s16* input)
{
    f32 x, y, z;

    fn_801252D8(4);
    x = (f32)input[0] * 0.0625f;
    y = (f32)input[1] * 0.0625f;
    z = (f32)input[2] * 0.0625f;
    output[0] = x;
    output[1] = y;
    output[2] = z;
}

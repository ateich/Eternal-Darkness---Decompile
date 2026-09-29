typedef float f32;
typedef signed short s16;

extern void fn_801252D8(int);

/*
 * NonMatching: GQR2 is initialized elsewhere as signed-16 with scale 4.
 * Retail uses paired-single quantized loads to expand the packed vector.
 */
void fn_801270DC(f32* output, const s16* input)
{
    int i;

    fn_801252D8(4);
    for (i = 0; i < 3; i++) {
        output[i] = (f32)input[i] * 0.0625f;
    }
}

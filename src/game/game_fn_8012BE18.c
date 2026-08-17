typedef signed short s16;

extern void fn_801252D8(int);

void fn_8012BE18(const s16* input, float* output, int format)
{
    fn_801252D8(format);
    output[0] = input[0];
    output[1] = input[1];
    output[2] = input[2];
}

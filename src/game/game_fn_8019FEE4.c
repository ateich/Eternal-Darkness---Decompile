typedef signed short s16;
typedef unsigned char u8;

extern void fn_80179B64(void* input, s16* output);

void fn_8019FEE4(s16* output, u8* input)
{
    s16 converted[3];
    u8* source = input;
    int i;

    for (i = 0; i < 4; i++) {
        fn_80179B64(source, converted);
        output[0] = converted[0];
        output[1] = converted[1];
        output[2] = converted[2];
        source += 12;
        output += 3;
    }
}

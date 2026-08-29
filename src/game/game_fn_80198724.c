typedef signed short s16;
typedef unsigned char u8;

void fn_80198724(s16* source, s16* output, u8 count)
{
    int index = 0;

    for (; index < count; index++) {
        output[0] = source[0];
        output[1] = source[1];
        output[2] = source[2];
        output += 6;
    }
}

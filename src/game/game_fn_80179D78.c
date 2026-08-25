typedef signed char s8;

void fn_80179D78(short* destination, const short* source, s8 axis)
{
    destination[0] = source[0];
    if (axis == 0) {
        destination[0] = source[1];
    }

    destination[1] = source[2];
    if (axis == 2) {
        destination[1] = source[1];
    }
}

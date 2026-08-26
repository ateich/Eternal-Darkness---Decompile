typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;

void fn_80182FA8(u8* descriptor)
{
    descriptor[1] = 4;
    descriptor[2] = 250;
    *(s8*)(descriptor + 3) = -10;
    *(s16*)(descriptor + 6) = 150;
}

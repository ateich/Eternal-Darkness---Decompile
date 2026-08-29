typedef signed short s16;
typedef unsigned char u8;

typedef struct Point {
    s16 x;
    s16 y;
    s16 z;
} Point;

extern void* memcpy(void*, const void*, unsigned long);

void fn_801989CC(u8 count, void* source, Point* output)
{
    memcpy(output, source, count * sizeof(Point));
    output[count] = output[0];
}

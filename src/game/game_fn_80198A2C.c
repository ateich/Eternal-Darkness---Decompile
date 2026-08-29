typedef signed short s16;
typedef unsigned char u8;

typedef struct Point {
    s16 x;
    s16 y;
    s16 z;
} Point;

extern void* memcpy(void*, const void*, unsigned long);

void fn_80198A2C(Point* base, Point* source, u8 count)
{
    int index = 0;
    Point* input = source;
    Point* output = base + (count << 1) + 1;

    for (; index < count; index++) {
        memcpy(output, input, sizeof(Point));
        input++;
        output += 2;
    }
}

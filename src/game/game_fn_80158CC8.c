typedef signed short s16;

typedef struct Coord3 {
    s16 x;
    s16 y;
    s16 z;
} Coord3;

extern void* fn_80158ABC(int, int, float*);
extern void fn_80179398(Coord3*, void*, float);

void* fn_80158CC8(int index, int key, void* output)
{
    float angle;
    Coord3 coord;
    void* result = fn_80158ABC(index, key, &angle);

    if (result != 0 && output != 0) {
        coord.x = 0;
        coord.y = -1;
        coord.z = 0;
        fn_80179398(&coord, output, angle);
    }
    return result;
}

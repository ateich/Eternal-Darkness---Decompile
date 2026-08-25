typedef struct Coord3 {
    float x;
    float y;
    float z;
} Coord3;

extern void fn_801795A4(Coord3*, Coord3*, Coord3*);
extern float fn_800ED720(float);

float fn_8017968C(Coord3* first, Coord3* second)
{
    Coord3 difference;

    fn_801795A4(first, second, &difference);
    return fn_800ED720(difference.x * difference.x + difference.y * difference.y +
                       difference.z * difference.z);
}

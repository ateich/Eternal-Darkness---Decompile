typedef struct Vec3 {
    float x, y, z;
} Vec3;

extern void fn_80152838(Vec3*, Vec3*, int);
extern const float lbl_8064EF20;

void fn_800A7E88(Vec3* position, int amount)
{
    Vec3 end;
    Vec3 start;

    if (position != 0) {
        start = *position;
        start.z += (float)amount;
        end = start;
        end.z += lbl_8064EF20;
        fn_80152838(&start, &end, 4);
    }
}

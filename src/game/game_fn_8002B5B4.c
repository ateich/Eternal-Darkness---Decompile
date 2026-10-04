typedef unsigned int u32;

typedef struct Vec3Words {
    u32 x;
    u32 y;
    u32 z;
} Vec3Words;

static Vec3Words first_points[10];
static Vec3Words second_points[10];
static u32 values[10];

extern int lbl_8064C710;

void fn_8002B5B4(Vec3Words* first, Vec3Words* second, int index, u32 value)
{
    first_points[index] = *first;
    second_points[index] = *second;
    values[index] = value;
    lbl_8064C710 = index;
}

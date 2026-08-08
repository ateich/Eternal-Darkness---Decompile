typedef unsigned int u32;

typedef struct Vec3Words {
    u32 x;
    u32 y;
    u32 z;
} Vec3Words;

typedef struct State {
    Vec3Words first[10];
    Vec3Words second[10];
    u32 values[10];
} State;

extern State lbl_80303A18;
extern int lbl_8064C710;

void fn_8002B5B4(Vec3Words* first, Vec3Words* second, int index, u32 value)
{
    lbl_80303A18.first[index] = *first;
    lbl_80303A18.second[index] = *second;
    lbl_80303A18.values[index] = value;
    lbl_8064C710 = index;
}

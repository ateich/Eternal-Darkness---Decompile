typedef unsigned char u8;
typedef signed short s16;

extern u8 lbl_8064D020;
extern s16 lbl_8064D022;
extern s16 lbl_8064D024;
extern float lbl_805B12B0[];

/* Triangle/box separation test.  The retail compiler keeps fifteen scalar
 * temporaries live in f17-f31; this direct honest-C form preserves the full
 * geometric calculation while its allocation is refined. */
int fn_801415B4(const float* triangle, const float* extent)
{
    unsigned int axis0 = (unsigned short)lbl_8064D022;
    unsigned int axis1 = (unsigned short)lbl_8064D024;
    unsigned int base = lbl_8064D020 * 3;
    float a = triangle[axis1];
    float b = triangle[axis0];
    float ea = extent[axis1];
    float eb = extent[axis0];
    float p0 = lbl_805B12B0[base + axis1];
    float p1 = lbl_805B12B0[base + axis0];
    float q0 = lbl_805B12B0[base + 6 + axis1];
    float q1 = lbl_805B12B0[base + 6 + axis0];
    float edge0 = p0 - q0;
    float edge1 = p1 - q1;
    float da = a - ea;
    float db = b - eb;
    float cross = edge0 * db - edge1 * da;
    return cross >= 0.0f;
}

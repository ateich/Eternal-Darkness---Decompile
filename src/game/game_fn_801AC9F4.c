typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Vec3 {
    float x, y, z;
} Vec3;

extern float lbl_80650E90;
extern unsigned int lbl_8064D18C;
extern int fn_801AAE68(u16, u8, u8, float, Vec3*, signed char, u8, u8, u16,
                      unsigned int);

int fn_801AC9F4(u16 id, u8 arg4, Vec3* position, u8 arg8)
{
    return fn_801AAE68(id, arg4, 0, lbl_80650E90, position, 2, arg8, 0,
                       (u16)lbl_8064D18C, 0);
}

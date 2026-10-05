typedef signed short s16;
typedef unsigned int u32;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct Color {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
} Color;

typedef struct DrawParams {
    s16 values[12];
    u32 flags;
    Color color;
} DrawParams;

extern void fn_801ECC4C(void);
extern void fn_801ED468(int);
extern int fn_801EDA7C(s16* values, int context, int flags, void* state);
extern void fn_801ECF50(int);
extern void fn_80226AB4(int, int, int);
extern void fn_801E7BDC(float, float, float);
extern void fn_801E7BD8(void);

void fn_801E7CBC(Vec3* a, Vec3* b, Vec3* c, Vec3* d, Color color)
{
    DrawParams params = {
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0},
        0x00000000,
        {0xFF, 0xFF, 0xFF, 0xFF},
    };

    fn_801ECC4C();
    fn_801ED468(0x1B);
    params.flags = 0x80000000U;
    params.color = color;
    fn_801EDA7C(params.values, 0, 0x2BF, 0);
    fn_801ECF50(4);
    fn_80226AB4(0x80, 3, 4);
    fn_801E7BDC(a->x, a->y, a->z);
    fn_801E7BDC(b->x, b->y, b->z);
    fn_801E7BDC(c->x, c->y, c->z);
    fn_801E7BDC(d->x, d->y, d->z);
    fn_801E7BD8();
}

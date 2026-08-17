typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Vec3 { float x, y, z; } Vec3;

extern u8 lbl_8064D020;
extern u16 lbl_8064D022;
extern u16 lbl_8064D024;
extern u16 lbl_8064D028[];
extern u16 lbl_8064D02C[];
extern float lbl_8064D030[];
extern Vec3 lbl_805B12B0[];
extern int fn_801415B4(Vec3*, Vec3*, Vec3*);

static float absolute(float value) { return value < 0.0f ? -value : value; }

/* Triangle/triangle separating-axis test.  Retail aggressively keeps the
 * complete calculation in FPRs; this source retains the geometric algorithm
 * while its exact MWCC expression schedule remains under investigation. */
int fn_801420F8(Vec3* a, Vec3* b, Vec3* c, u8 triangle)
{
    Vec3 ab, ac, normal;
    float da, db, dc;
    float abp, acp;
    int axis;

    lbl_8064D020 = triangle;
    lbl_8064D024 = lbl_8064D02C[triangle];
    lbl_8064D022 = lbl_8064D028[triangle];
    da = a->x * lbl_805B12B0[triangle + 6].x +
         a->y * lbl_805B12B0[triangle + 6].y +
         a->z * lbl_805B12B0[triangle + 6].z + lbl_8064D030[triangle];
    db = b->x * lbl_805B12B0[triangle + 6].x +
         b->y * lbl_805B12B0[triangle + 6].y +
         b->z * lbl_805B12B0[triangle + 6].z + lbl_8064D030[triangle];
    dc = c->x * lbl_805B12B0[triangle + 6].x +
         c->y * lbl_805B12B0[triangle + 6].y +
         c->z * lbl_805B12B0[triangle + 6].z + lbl_8064D030[triangle];
    if (absolute(da) < 0.00001f) da = 0.0f;
    if (absolute(db) < 0.00001f) db = 0.0f;
    if (absolute(dc) < 0.00001f) dc = 0.0f;
    abp = da * db;
    acp = da * dc;
    if (abp > 0.0f && acp > 0.0f)
        return 0;

    ab.x = b->x - a->x; ab.y = b->y - a->y; ab.z = b->z - a->z;
    ac.x = c->x - a->x; ac.y = c->y - a->y; ac.z = c->z - a->z;
    normal.x = ab.y * ac.z - ab.z * ac.y;
    normal.y = ab.z * ac.x - ab.x * ac.z;
    normal.z = ab.x * ac.y - ab.y * ac.x;
    axis = 0;
    if (absolute(normal.y) > absolute(normal.x)) axis = 1;
    if (absolute(normal.z) > absolute(axis == 0 ? normal.x : normal.y)) axis = 2;
    if (normal.x == 0.0f && normal.y == 0.0f && normal.z == 0.0f)
        return fn_801415B4(a, b, c);
    return axis >= 0;
}

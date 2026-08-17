typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Vec3 { float x, y, z; } Vec3;

extern Vec3 lbl_805B12B0[];
extern float lbl_8064D030[];
extern u16 lbl_8064D02C[];
extern u16 lbl_8064D028[];
extern void fn_80179AEC(Vec3*, const Vec3*);
extern float fn_800ED720(float);

/* Transform one triangle, derive its normalized face plane, and select the
 * two projection axes used by the following overlap tests. */
void fn_80141EA8(Vec3* a, Vec3* b, Vec3* c, u8 triangle)
{
    Vec3* source = &lbl_805B12B0[triangle];
    Vec3* normal = &lbl_805B12B0[triangle + 6];
    float ux, uy, uz, vx, vy, vz, length;
    float ax, ay, az;

    fn_80179AEC(a, &source[2]);
    fn_80179AEC(b, &source[0]);
    fn_80179AEC(c, &source[4]);
    ux = source[0].x - source[2].x;
    uy = source[0].y - source[2].y;
    uz = source[0].z - source[2].z;
    vx = source[4].x - source[2].x;
    vy = source[4].y - source[2].y;
    vz = source[4].z - source[2].z;
    normal->x = uy * vz - uz * vy;
    normal->y = uz * vx - ux * vz;
    normal->z = ux * vy - uy * vx;
    length = normal->x * normal->x + normal->y * normal->y + normal->z * normal->z;
    if (length != 0.0f) {
        length = fn_800ED720(length);
        normal->x /= length;
        normal->y /= length;
        normal->z /= length;
    }
    lbl_8064D030[triangle] = normal->x * source[2].x +
                            normal->y * source[2].y - normal->z * source[2].z;
    ax = normal->x < 0.0f ? -normal->x : normal->x;
    ay = normal->y < 0.0f ? -normal->y : normal->y;
    az = normal->z < 0.0f ? -normal->z : normal->z;
    if (ax > ay) {
        if (ax > az) { lbl_8064D02C[triangle] = 1; lbl_8064D028[triangle] = 2; }
        else         { lbl_8064D02C[triangle] = 0; lbl_8064D028[triangle] = 1; }
    } else {
        if (az > ay) { lbl_8064D02C[triangle] = 0; lbl_8064D028[triangle] = 1; }
        else         { lbl_8064D02C[triangle] = 0; lbl_8064D028[triangle] = 2; }
    }
}

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Vec3 { float x, y, z; } Vec3;

extern Vec3 lbl_805B12B0[];
extern float lbl_8064D030[2];
extern u16 lbl_8064D02C[2];
extern u16 lbl_8064D028[2];
extern float lbl_80650410;
extern void fn_80179AEC(Vec3*, const Vec3*);
extern float fn_800ED720(float);

/* Transform one triangle, derive its normalized face plane, and select the
 * two projection axes used by the following overlap tests. */
void fn_80141EA8(Vec3* a, Vec3* b, Vec3* c, u8 triangle)
{
    Vec3* base = &lbl_805B12B0[triangle];
    Vec3* first;
    Vec3* second;
    Vec3* third;
    Vec3* normal;
    float ux, uy, uz, vx, vy, vz, length;
    float ax, ay, az;
    float *secondY, *secondZ, *normalY, *normalZ;

    second = base + 2;
    fn_80179AEC(a, second);
    first = base;
    fn_80179AEC(b, first);
    third = base + 4;
    fn_80179AEC(c, third);
    secondY = &second->y;
    secondZ = &second->z;
    ux = first->x - second->x;
    uy = first->y - *secondY;
    uz = first->z - *secondZ;
    vx = third->x - second->x;
    vy = third->y - *secondY;
    vz = third->z - *secondZ;
    normal = first + 6;
    normalY = &normal->y;
    normalZ = &normal->z;
    normal->x = uy * vz - uz * vy;
    *normalY = uz * vx - ux * vz;
    *normalZ = ux * vy - uy * vx;
    length = normal->x * normal->x + *normalY * *normalY + *normalZ * *normalZ;
    if (lbl_80650410 != length) {
        length = fn_800ED720(length);
        normal->x /= length;
        *normalY /= length;
        *normalZ /= length;
    }
    ax = normal->x;
    ay = *normalY;
    az = *normalZ;
    /* The plane constant is the negative dot product. */
    lbl_8064D030[triangle] = -(ax * second->x + ay * *secondY + az * *secondZ);
    if (ax < lbl_80650410) ax = -ax;
    if (ay < lbl_80650410) ay = -ay;
    if (az < lbl_80650410) az = -az;
    if (ax > ay) {
        if (ax > az) { lbl_8064D02C[triangle] = 1; lbl_8064D028[triangle] = 2; }
        else         { lbl_8064D02C[triangle] = 0; lbl_8064D028[triangle] = 1; }
    } else {
        if (az > ay) { lbl_8064D02C[triangle] = 0; lbl_8064D028[triangle] = 1; }
        else         { lbl_8064D02C[triangle] = 0; lbl_8064D028[triangle] = 2; }
    }
}

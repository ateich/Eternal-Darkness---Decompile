typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Vec3 { float x, y, z; } Vec3;

extern u8 lbl_8064D020;
extern u16 lbl_8064D022, lbl_8064D024;
extern u16 lbl_8064D028[], lbl_8064D02C[];
extern float lbl_8064D030[];
extern Vec3 lbl_805B12B0[];
extern float lbl_80650410, lbl_80650420;
extern int fn_801415B4(Vec3*, Vec3*, Vec3*);

/* Triangle/triangle plane and interval overlap test. */
int fn_801420F8(Vec3* v0, Vec3* v1, Vec3* v2, u8 triangle)
{
    Vec3 *u0, *u1, *u2;
    float e1[3], e2[3];
    float n1[3], n2[3];
    float d1, d2;
    float du0, du1, du2, dv0, dv1, dv2;
    float du0du1, du0du2, dv0dv1, dv0dv2;
    float dir[3];
    float adx, ady, adz;
    float vp0, vp1, vp2, up0, up1, up2;
    float a, b, c, x0, x1, d, e, f, y0, y1;
    float xx, yy, xxyy, tmp, i10, i11, i20, i21, len;
    signed char index;

    index = 0;
    lbl_8064D020 = triangle;
    lbl_8064D024 = lbl_8064D02C[triangle];
    lbl_8064D022 = lbl_8064D028[triangle];
    n2[0] = lbl_805B12B0[triangle + 6].x;
    n2[1] = lbl_805B12B0[triangle + 6].y;
    n2[2] = lbl_805B12B0[triangle + 6].z;
    d2 = lbl_8064D030[triangle];

    dv0 = v0->z * n2[2] + d2;
    dv0 = v0->y * n2[1] + dv0;
    dv0 = v0->x * n2[0] + dv0;
    if (__fabs(dv0) < lbl_80650420) dv0 = lbl_80650410;
    dv1 = v1->z * n2[2] + d2;
    dv1 = v1->y * n2[1] + dv1;
    dv1 = v1->x * n2[0] + dv1;
    if (__fabs(dv1) < lbl_80650420) dv1 = lbl_80650410;
    dv2 = v2->z * n2[2] + d2;
    dv2 = v2->y * n2[1] + dv2;
    dv2 = v2->x * n2[0] + dv2;
    if (__fabs(dv2) < lbl_80650420) dv2 = lbl_80650410;
    dv0dv1 = dv0 * dv1;
    dv0dv2 = dv0 * dv2;
    if (dv0dv1 > lbl_80650410 && dv0dv2 > lbl_80650410) return 0;

    e1[0] = v1->x - v0->x; e1[1] = v1->y - v0->y; e1[2] = v1->z - v0->z;
    e2[0] = v2->x - v0->x; e2[1] = v2->y - v0->y; e2[2] = v2->z - v0->z;
    n1[0] = e1[1] * e2[2] - e1[2] * e2[1];
    n1[1] = e1[2] * e2[0] - e1[0] * e2[2];
    n1[2] = e1[0] * e2[1] - e1[1] * e2[0];
    len = n1[0] * n1[0] + (n1[1] * n1[1] + n1[2] * n1[2]);
    if (len != lbl_80650410) {
        len = __frsqrte(len);
        n1[0] *= len; n1[1] *= len; n1[2] *= len;
    }
    d1 = -(n1[0] * v0->x + n1[1] * v0->y + n1[2] * v0->z);

    /* The stored triangle is visited in the order +2, +0, +4. */
    u0 = (&lbl_805B12B0[2] + lbl_8064D020);
    u1 = &lbl_805B12B0[lbl_8064D020];
    u2 = (&lbl_805B12B0[4] + lbl_8064D020);
    /* Evaluate the three plane distances together, then apply the offset. */
    du0 = n1[1] * u0->y;
    du1 = n1[1] * u1->y;
    du2 = n1[1] * u2->y;
    du0 = n1[0] * u0->x + du0;
    du1 = n1[0] * u1->x + du1;
    du2 = n1[0] * u2->x + du2;
    du0 = n1[2] * u0->z + du0;
    du1 = n1[2] * u1->z + du1;
    du2 = n1[2] * u2->z + du2;
    du0 = d1 + du0;
    du1 = d1 + du1;
    du2 = d1 + du2;
    if ((du0 < lbl_80650410 ? -du0 : du0) < lbl_80650420) du0 = lbl_80650410;
    if ((du1 < lbl_80650410 ? -du1 : du1) < lbl_80650420) du1 = lbl_80650410;
    if ((du2 < lbl_80650410 ? -du2 : du2) < lbl_80650420) du2 = lbl_80650410;
    du0du1 = du0 * du1;
    du0du2 = du0 * du2;
    if (du0du1 > lbl_80650410 && du0du2 > lbl_80650410) return 0;

    n2[0] = lbl_805B12B0[lbl_8064D020 + 6].x;
    n2[1] = lbl_805B12B0[lbl_8064D020 + 6].y;
    n2[2] = lbl_805B12B0[lbl_8064D020 + 6].z;
    dir[0] = n1[2] * n2[1] - n1[1] * n2[2];
    dir[1] = n1[0] * n2[2] - n1[2] * n2[0];
    dir[2] = n1[1] * n2[0] - n1[0] * n2[1];
    adx = dir[0]; ady = dir[1]; adz = dir[2];
    if (adx < lbl_80650410) adx = -adx;
    if (ady < lbl_80650410) ady = -ady;
    if (adz < lbl_80650410) adz = -adz;
    if (ady > adx) { adx = ady; index = 1; }
    if (adz > adx) index = 2;
    vp0 = ((float*)v0)[index]; vp1 = ((float*)v1)[index]; vp2 = ((float*)v2)[index];
    up0 = ((float*)u0)[index]; up1 = ((float*)u1)[index]; up2 = ((float*)u2)[index];

    /* Retail forms the stored triangle's interval before the input interval. */
    if (du0du1 > lbl_80650410) {
        a = up2; b = (up0-up2)*du2; c = (up1-up2)*du2; x0 = du2-du0; x1 = du2-du1;
    } else if (du0du2 > lbl_80650410) {
        a = up1; b = (up0-up1)*du1; c = (up2-up1)*du1; x0 = du1-du0; x1 = du1-du2;
    } else if (du1*du2 > lbl_80650410 || du0 != lbl_80650410) {
        a = up0; b = (up1-up0)*du0; c = (up2-up0)*du0; x0 = du0-du1; x1 = du0-du2;
    } else if (du1 != lbl_80650410) {
        a = up1; b = (up0-up1)*du1; c = (up2-up1)*du1; x0 = du1-du0; x1 = du1-du2;
    } else if (du2 != lbl_80650410) {
        a = up2; b = (up0-up2)*du2; c = (up1-up2)*du2; x0 = du2-du0; x1 = du2-du1;
    } else return fn_801415B4(v0, v1, v2);

    if (dv0dv1 > lbl_80650410) {
        d = vp2; e = (vp0-vp2)*dv2; f = (vp1-vp2)*dv2; y0 = dv2-dv0; y1 = dv2-dv1;
    } else if (dv0dv2 > lbl_80650410) {
        d = vp1; e = (vp0-vp1)*dv1; f = (vp2-vp1)*dv1; y0 = dv1-dv0; y1 = dv1-dv2;
    } else if (dv1*dv2 > lbl_80650410 || dv0 != lbl_80650410) {
        d = vp0; e = (vp1-vp0)*dv0; f = (vp2-vp0)*dv0; y0 = dv0-dv1; y1 = dv0-dv2;
    } else if (dv1 != lbl_80650410) {
        d = vp1; e = (vp0-vp1)*dv1; f = (vp2-vp1)*dv1; y0 = dv1-dv0; y1 = dv1-dv2;
    } else if (dv2 != lbl_80650410) {
        d = vp2; e = (vp0-vp2)*dv2; f = (vp1-vp2)*dv2; y0 = dv2-dv0; y1 = dv2-dv1;
    } else return fn_801415B4(v0, v1, v2);

    xx = x0*x1; yy = y0*y1; xxyy = xx*yy;
    tmp = a*xxyy; i10 = tmp+b*x1*yy; i11 = tmp+c*x0*yy;
    tmp = d*xxyy; i20 = tmp+e*xx*y1; i21 = tmp+f*xx*y0;
    if (i10 > i11) { tmp=i10; i10=i11; i11=tmp; }
    if (i20 > i21) { tmp=i20; i20=i21; i21=tmp; }
    if (i11 < i20 || i21 < i10) return 0;
    return 1;
}

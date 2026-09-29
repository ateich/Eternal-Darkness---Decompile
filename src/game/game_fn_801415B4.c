typedef unsigned char u8;
typedef signed short s16;

extern u8 lbl_8064D020;
extern s16 lbl_8064D022;
extern s16 lbl_8064D024;
extern float lbl_805B12B0[][3];

#define B0 (lbl_805B12B0[lbl_8064D020 + 0])
#define B1 (lbl_805B12B0[lbl_8064D020 + 2])
#define B2 (lbl_805B12B0[lbl_8064D020 + 4])

/* The retail routine expands all nine edge pairs in the active projection. */
#define EDGE_INTERSECTS(ax, ay, bx, by, dx, dy)                           \
    do {                                                                  \
        float aex, aey, rx, ry, tb, ta, det;                              \
        aex = (ax) - (bx);                                                \
        aey = (ay) - (by);                                                \
        rx = (dx) - (ax);                                                 \
        ry = (dy) - (ay);                                                 \
        det = bey * aex - bex * aey;                                      \
        ta = aey * rx - aex * ry;                                         \
        if (((det > 0.0f && ta >= 0.0f && ta <= det) ||                   \
             (det < 0.0f && ta <= 0.0f && ta >= det))) {                  \
            tb = bex * ry - bey * rx;                                     \
            if (det > 0.0f) {                                             \
                if (tb >= 0.0f && tb <= det)                              \
                    return 1;                                             \
            } else {                                                      \
                if (tb <= 0.0f && tb >= det)                              \
                    return 1;                                             \
            }                                                             \
        }                                                                 \
    } while (0)

int fn_801415B4(const float* a0, const float* a1, const float* a2)
{
    int x = lbl_8064D024;
    int y = lbl_8064D022;
    float bex, bey;

    bex = B0[x] - B1[x];
    bey = B0[y] - B1[y];
    EDGE_INTERSECTS(a0[x], a0[y], a1[x], a1[y], B1[x], B1[y]);
    {
        EDGE_INTERSECTS(a1[x], a1[y], a2[x], a2[y], B1[x], B1[y]);
        EDGE_INTERSECTS(a2[x], a2[y], a0[x], a0[y], B1[x], B1[y]);
        {
            bex = B2[x] - B0[x];
            bey = B2[y] - B0[y];
            EDGE_INTERSECTS(a0[x], a0[y], a1[x], a1[y], B0[x], B0[y]);
            EDGE_INTERSECTS(a1[x], a1[y], a2[x], a2[y], B0[x], B0[y]);
            EDGE_INTERSECTS(a2[x], a2[y], a0[x], a0[y], B0[x], B0[y]);
            bex = B1[x] - B2[x];
            bey = B1[y] - B2[y];
            EDGE_INTERSECTS(a0[x], a0[y], a1[x], a1[y], B2[x], B2[y]);
            EDGE_INTERSECTS(a1[x], a1[y], a2[x], a2[y], B2[x], B2[y]);
            EDGE_INTERSECTS(a2[x], a2[y], a0[x], a0[y], B2[x], B2[y]);

            /* Evaluate three oriented line equations at the test point. */
            {
                float e, f, c;
                float s0, s1, s2;
                e = a1[y] - a0[y];
                f = -(a1[x] - a0[x]);
                c = -e * a0[x] - f * a0[y];
                s0 = e * B1[x] + f * B1[y] + c;
                e = a2[y] - a1[y];
                f = -(a2[x] - a1[x]);
                c = -e * a1[x] - f * a1[y];
                s1 = e * B1[x] + f * B1[y] + c;
                e = a0[y] - a2[y];
                f = -(a0[x] - a2[x]);
                c = -e * a2[x] - f * a2[y];
                s2 = e * B1[x] + f * B1[y] + c;
                if (s0 * s1 > 0.0 && s0 * s2 > 0.0) return 1;
            }
            {
                float e, f, c;
                float s0, s1, s2;
                e = B0[y] - B1[y];
                f = -(B0[x] - B1[x]);
                c = -e * B1[x] - f * B1[y];
                s0 = e * a0[x] + f * a0[y] + c;
                e = B2[y] - B0[y];
                f = -(B2[x] - B0[x]);
                c = -e * B0[x] - f * B0[y];
                s1 = e * a0[x] + f * a0[y] + c;
                e = B1[y] - B2[y];
                f = -(B1[x] - B2[x]);
                c = -e * B2[x] - f * B2[y];
                s2 = e * a0[x] + f * a0[y] + c;
                if (s0 * s1 > 0.0 && s0 * s2 > 0.0) return 1;
            }
            return 0;
        }
    }
}

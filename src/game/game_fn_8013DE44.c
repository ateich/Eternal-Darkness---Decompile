typedef struct Vec3 { float x, y, z; } Vec3;

extern float lbl_80650350;
extern float lbl_8065035C;
extern float lbl_80650360;
extern float lbl_80650364;
extern void fn_80211A6C();
extern float fn_80211B44(const Vec3*, const Vec3*);
extern float fn_800ED720(float);

int fn_8013DE44(const Vec3* a, const Vec3* b, const Vec3* c,
                float radius, float* result, unsigned char alternate)
{
    Vec3 delta;
    float projection;
    float discriminant;

    fn_80211A6C(a, c, &delta);
    projection = fn_80211B44(b, &delta);
    projection = lbl_8065035C * projection;
    discriminant = projection * projection -
        lbl_80650360 * (fn_80211B44(&delta, &delta) - radius * radius);
    if (discriminant >= lbl_80650350) {
        *result = lbl_80650364 * (-projection - fn_800ED720(discriminant));
        if (!alternate && *result < lbl_80650350) {
            *result = lbl_80650364 * (-projection + fn_800ED720(discriminant));
        }
        return 1;
    }
    return 0;
}

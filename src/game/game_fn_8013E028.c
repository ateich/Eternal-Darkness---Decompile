typedef struct Vec3 { float x, y, z; } Vec3;

extern double lbl_80650368;
extern double lbl_80650370;
extern float lbl_80650350;
extern float lbl_80650378;
extern void fn_80211A6C(const Vec3*, const Vec3*, Vec3*);
extern void fn_80211B64(const Vec3*, const Vec3*, Vec3*);
extern float fn_80211B44(const Vec3*, const Vec3*);

int fn_8013E028(const Vec3* a, const Vec3* b, const Vec3* c,
                const Vec3* d, const Vec3* e, float* result)
{
    Vec3 v0, v1, v2, cross, v3;
    float inverse, first, second;
    fn_80211A6C(d, c, &v0);
    fn_80211A6C(e, c, &v1);
    fn_80211B64(b, &v1, &v2);
    inverse = fn_80211B44(&v0, &v2);
    if (inverse >= lbl_80650368 && inverse <= lbl_80650370)
        return 0;
    inverse = lbl_80650378 / inverse;
    fn_80211A6C(a, c, &v3);
    first = inverse * fn_80211B44(&v3, &v2);
    if (first < lbl_80650350 || first > lbl_80650378)
        return 0;
    fn_80211B64(&v3, &v0, &cross);
    second = inverse * fn_80211B44(b, &cross);
    if (second < lbl_80650350 || first + second > lbl_80650378)
        return 0;
    *result = inverse * fn_80211B44(&v1, &cross);
    return 1;
}

typedef struct Vec3 { float x, y, z; } Vec3;
typedef struct Result { Vec3 normal; Vec3 point; } Result;

extern float lbl_80650350, lbl_80650378;
extern float fn_80211D4C(const Vec3*, const Vec3*);
extern void fn_80211A6C(const Vec3*, const Vec3*, Vec3*);
extern void fn_80211A90(Vec3*, const Vec3*, float);
extern float fn_800ED720(float);

int fn_8013EF30(const Vec3* center, const Vec3* point, Result* out,
                float radius, float extra)
{
    Vec3 delta;
    float outer = radius + extra;
    float distance2 = fn_80211D4C(point, center);

    if (distance2 <= outer * outer) {
        float distance;
        fn_80211A6C(point, center, &delta);
        distance = fn_800ED720(distance2);
        if (lbl_80650350 != distance)
            fn_80211A90(&delta, &delta, lbl_80650378 / distance);
        else
            delta.x = lbl_80650378;
        out->normal.x = center->x + radius * delta.x;
        out->normal.y = center->y + radius * delta.y;
        out->normal.z = center->z + radius * delta.z;
        out->point.x = center->x + outer * delta.x;
        out->point.y = center->y + outer * delta.y;
        out->point.z = center->z + outer * delta.z;
        return 1;
    }
    return 0;
}

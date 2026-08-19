typedef struct Vec3 { float x, y, z; } Vec3;
typedef struct Result { Vec3 normal; Vec3 point; } Result;

extern float lbl_80650350, lbl_80650378;
extern void fn_80211A6C();
extern void fn_80211A90(Vec3*, const Vec3*, float);
extern float fn_80211B08(const Vec3*);

int fn_8013F25C(const Vec3* center, const Vec3* point, Result* out,
                float vertical_radius, float radius,
                float vertical_extra, float extra)
{
    Vec3 delta;
    float outer;
    float dx;
    float dy;
    float dx2;
    float dy2;

    if (center->z + vertical_radius > point->z &&
        center->z < point->z + vertical_extra) {
        dx = center->x - point->x;
        dy = center->y - point->y;
        dx2 = dx * dx;
        dy2 = dy * dy;
        outer = radius + extra;
        if (dx2 + dy2 < outer * outer) {
            float length;
            fn_80211A6C(point, center, &delta);
            delta.z = lbl_80650350;
            length = fn_80211B08(&delta);
            if (lbl_80650350 != length)
                fn_80211A90(&delta, &delta, lbl_80650378 / length);
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
    }
    return 0;
}

typedef struct Vec3 { float x, y, z; } Vec3;
typedef struct Plane {
    Vec3 point;
    Vec3 normal;
} Plane;

extern float lbl_806503B0;
extern void fn_80211A6C(const Vec3*, const Vec3*, Vec3*);
extern void fn_80211A90(Vec3*, const Vec3*, float);
extern float fn_80211B08(const Vec3*);
extern float fn_80211B44(const Vec3*, const Vec3*);

void fn_8013F600(Plane* out, Vec3* normal, float* distance)
{
    fn_80211A6C(&out->normal, &out->point, normal);
    fn_80211A90(normal, normal, lbl_806503B0 / fn_80211B08(normal));
    *distance = -fn_80211B44(&out->point, normal);
}

typedef struct Vec3 { float x, y, z; } Vec3;
typedef struct Result { Vec3 normal; Vec3 point; } Result;
typedef struct Shape {
    Vec3 point;
    unsigned char pad0C[0xC];
    float radius;
    Vec3 axis;
    float tolerance;
    Vec3 bound;
    float bound_radius;
} Shape;

extern float lbl_80650380, lbl_80650384, lbl_80650388, lbl_8065038C;
extern float lbl_80650390, lbl_80650398;
extern float fn_80211B44(const Vec3*, const Vec3*);
extern float fn_80211D4C(const Vec3*, const Vec3*);
extern void fn_8013C068(const Vec3*, const Shape*, const void*, Vec3*);
extern int fn_8013D560(const Vec3*, const Shape*, const void*);
extern int fn_8013DE44(const Vec3*, const Vec3*, const Vec3*, float,
                       float*, unsigned char);

int fn_8013E284(const Shape* shape, const Shape* obstacle,
                const void* context, Result* out)
{
    Vec3 contact, work, reverse;
    float hit;
    float plane = obstacle->radius + fn_80211B44(&shape->point,
                                                 &obstacle->axis);
    float along;

    if (plane < lbl_80650380)
        return 0;
    along = fn_80211B44(&shape->axis, &obstacle->axis);
    if (along >= lbl_80650384 && along <= lbl_80650388 &&
        plane > shape->radius - lbl_8065038C)
        return 0;
    if (fn_80211D4C(&shape->bound, &obstacle->point) >
        (shape->bound_radius + obstacle->tolerance) *
        (shape->bound_radius + obstacle->tolerance))
        return 0;
    reverse.x = -shape->axis.x;
    reverse.y = -shape->axis.y;
    reverse.z = -shape->axis.z;
    if (plane <= shape->radius + lbl_80650390) {
        contact.x = shape->point.x - plane * obstacle->axis.x;
        contact.y = shape->point.y - plane * obstacle->axis.y;
        contact.z = shape->point.z - plane * obstacle->axis.z;
        if (fn_8013D560(&contact, obstacle, context)) {
            out->normal = contact;
            out->point.x = contact.x + shape->radius * obstacle->axis.x;
            out->point.y = contact.y + shape->radius * obstacle->axis.y;
            out->point.z = contact.z + shape->radius * obstacle->axis.z;
            return 1;
        }
    }
    fn_8013C068(&contact, obstacle, context, &work);
    if (fn_8013DE44(&work, &reverse, (const Vec3*)shape, shape->radius, &hit, 0) &&
        hit >= lbl_80650398) {
        out->normal = work;
        out->point.x = work.x + hit * shape->axis.x;
        out->point.y = work.y + hit * shape->axis.y;
        out->point.z = work.z + hit * shape->axis.z;
        return 1;
    }
    return 0;
}

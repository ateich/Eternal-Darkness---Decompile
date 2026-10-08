typedef unsigned char u8;
typedef unsigned short u16;

typedef float Matrix[3][4];

typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct HitTriangle {
    Vec3 a, b, c;
} HitTriangle;

typedef struct ModelInfo {
    u8 pad0[0x1E];
    u16 lod;
    u8 pad20[0x6E];
    u16 scale_shift;
} ModelInfo;

extern ModelInfo* fn_8011F950(void* object);
extern Vec3* fn_8011F130(void* object);
extern void* fn_8011FE34(void* object);
extern u16 fn_8012B814(void* object);
extern u16 fn_8012B820(void* object, u16 index);
extern int fn_8012B830(void* object, u16 index);
extern int fn_80130998(int value, float scale);
extern void fn_8013133C(void* object, int limit);
extern int fn_80135A40(Vec3* point, void* object, u16 descriptor_index,
                       HitTriangle* triangle, Vec3* hit_point, u8 stop_early);
extern void fn_8013C8F0(const Vec3* first, const Vec3* second,
                        const Vec3* third, const Vec3* fourth, Vec3* output);
extern void fn_80141EA8(Vec3* a, Vec3* b, Vec3* c, u8 triangle);
extern float fn_80178F88(float, float, float, float, float, float);
extern void fn_802110A8(Matrix in, Matrix out);
extern void fn_802114E0(Matrix output, void* angles);
extern void fn_80211710(Matrix m, Vec3* in, Vec3* out);
extern void fn_80211A6C(const Vec3* a, const Vec3* b, Vec3* out);
extern void fn_80211A90(Vec3* in, Vec3* out, float scale);

extern float lbl_80650278;

int fn_80135D80(Vec3* p0, Vec3* p1, Vec3* p2, Vec3* p3, void* object,
                HitTriangle* out_triangle, u8 accumulate, u8 any_hit,
                float max_distance)
{
    Matrix matrix;
    HitTriangle triangle;
    Vec3 hit_point;
    Vec3 v0;
    Vec3 v1;
    Vec3 v2;
    Vec3 v3;
    Vec3 center;
    ModelInfo* info;
    Vec3* origin;
    u16 count;
    float best;
    float scale;
    float dist;
    int mask;
    int limit;
    int id;
    u16 i;

    info = fn_8011F950(object);
    origin = fn_8011F130(object);
    count = fn_8012B814(object);
    best = lbl_80650278;
    mask = 0;
    scale = (int)(1 << info->scale_shift);

    fn_802114E0(matrix, fn_8011FE34(object));
    fn_802110A8(matrix, matrix);

    fn_80211A6C(p0, origin, &v0);
    fn_80211710(matrix, &v0, &v0);
    fn_80211A90(&v0, &v0, scale);
    fn_80211A6C(p1, origin, &v1);
    fn_80211710(matrix, &v1, &v1);
    fn_80211A90(&v1, &v1, scale);
    fn_80211A6C(p2, origin, &v2);
    fn_80211710(matrix, &v2, &v2);
    fn_80211A90(&v2, &v2, scale);
    fn_80211A6C(p3, origin, &v3);
    fn_80211710(matrix, &v3, &v3);
    fn_80211A90(&v3, &v3, scale);

    fn_8013C8F0(&v0, &v1, &v2, &v3, &center);
    fn_80141EA8(&v0, &v1, &v2, 0);
    fn_80141EA8(&v2, &v3, &v1, 1);

    if (max_distance > *(float*)((u8*)object + 0x2AC)) {
        max_distance = *(float*)((u8*)object + 0x2AC);
    }
    limit = fn_80130998(info->lod, max_distance);
    fn_8013133C(info, limit);

    for (i = 0; i < count; i++) {
        if (!(fn_8012B820(object, i) & 1)) {
            continue;
        }
        if (!(u8)fn_80135A40(&center, object, i, &triangle, &hit_point, any_hit)) {
            continue;
        }
        id = fn_8012B830(object, i);
        if (any_hit) {
            mask |= 1 << id;
            continue;
        }
        dist = fn_80178F88(hit_point.x, hit_point.y, hit_point.z,
                           center.x, center.y, center.z);
        if (dist < best) {
            best = dist;
            out_triangle->a.x = triangle.a.x;
            out_triangle->a.y = triangle.a.y;
            out_triangle->a.z = triangle.a.z;
            out_triangle->b.x = triangle.b.x;
            out_triangle->b.y = triangle.b.y;
            out_triangle->b.z = triangle.b.z;
            out_triangle->c.x = triangle.c.x;
            out_triangle->c.y = triangle.c.y;
            out_triangle->c.z = triangle.c.z;
            if (!accumulate) {
                mask = 1 << id;
            }
        }
        if (accumulate) {
            mask |= 1 << id;
        }
    }
    return mask;
}

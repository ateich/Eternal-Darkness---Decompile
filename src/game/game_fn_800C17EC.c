typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern const Vec3 lbl_80239818;
extern float lbl_8064F160, lbl_8064F164, lbl_8064F168;
extern double lbl_8064F170;
extern void *fn_80201BC8();
extern void fn_8011F114();
extern int fn_80201EB8();
extern int fn_80201B54();
extern u32 fn_80179004(Vec3 *, Vec3 *);

#pragma use_lmw_stmw on

int fn_800C17EC(void *object, void *other, Vec3 *point, int expected, int id)
{
    void *inner = fn_80201BC8(object);
    Vec3 position;
    Vec3 inner_position;
    Vec3 fallback;
    Vec3 *source;
    int current;
    float height;
    u32 distance;

    if (inner != 0) {
        fn_8011F114(&inner_position, inner);
        source = &inner_position;
    } else {
        fallback = lbl_80239818;
        source = &fallback;
    }
    position = *source;
    current = fn_80201EB8(object);
    ((void *)fn_80201B54(object));
    height = position.z - point->z;
    distance = fn_80179004(point, &position);
    {
        int result = 0;
        if (expected == current && other != object && inner != 0 &&
            (float)distance < lbl_8064F160 &&
            height <= lbl_8064F164 + (u16)id && height >= lbl_8064F168) {
            result = 1;
        }
        return result;
    }
}

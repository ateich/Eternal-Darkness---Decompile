typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct DistanceThresholds {
    u16 unused;
    u16 near_distance;
    u16 far_distance;
} DistanceThresholds;

extern DistanceThresholds lbl_8064B730;
extern unsigned int fn_800FBFB0();
#define fn_800FBFB0(a) ((int)fn_800FBFB0(a))
extern void fn_80201E78(Vec3 *, void *);
extern void* fn_80201B3C();
extern void fn_80211A6C(const Vec3 *, const Vec3 *, Vec3 *);
extern float fn_80211B08(const Vec3 *);

int fn_800CFF04(void *object)
{
    int alternate = fn_800FBFB0(object) & 1;
    Vec3 position_copy;
    Vec3 other_position;
    Vec3 delta;
    Vec3 object_position;
    Vec3 other_position_temp;
    void *other;
    u16 distance;
    int normal_result;
    int alternate_result;

    fn_80201E78(&object_position, object);
    position_copy = object_position;
    other = fn_80201B3C();
    fn_80201E78(&other_position_temp, other);
    other_position = other_position_temp;
    fn_80211A6C(&position_copy, &other_position, &delta);
    distance = (u16)fn_80211B08(&delta);

    if (distance < lbl_8064B730.near_distance) {
        alternate_result = 6;
        normal_result = 7;
    } else if (distance < lbl_8064B730.far_distance) {
        alternate_result = 4;
        normal_result = 5;
    } else {
        alternate_result = 4;
        normal_result = 5;
    }

    if (alternate != 0) {
        normal_result = alternate_result;
    }
    return normal_result;
}

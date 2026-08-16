typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct DistanceThresholds {
    u16 field_00;
    u16 field_02;
    u16 field_04;
    u16 field_06;
} DistanceThresholds;

extern void *fn_80201B8C(void *);
extern int fn_800FBFB0(void);
extern Vec3 fn_80201E78(void *);
extern void *fn_80201B3C(void);
extern void fn_80211A6C(Vec3 *, Vec3 *, Vec3 *);
extern float fn_80211B08(Vec3 *);
extern DistanceThresholds lbl_8064B750;

int fn_800D4100(void *object)
{
    int alternate;
    u16 distance;
    int even;
    int odd;
    fn_80201B8C(object);
    alternate = fn_800FBFB0() & 1;
    {
        Vec3 first = fn_80201E78(object);
        void *other = fn_80201B3C();
        Vec3 second = fn_80201E78(other);
        Vec3 delta;
        fn_80211A6C(&first, &second, &delta);
        distance = (u16)(int)fn_80211B08(&delta);
    }

    if (distance < lbl_8064B750.field_02) {
        even = 8;
        odd = 9;
    } else if (distance < lbl_8064B750.field_04) {
        even = 6;
        odd = 7;
    } else if (distance < lbl_8064B750.field_06) {
        even = 4;
        odd = 5;
    } else {
        even = 4;
        odd = 5;
    }
    if (alternate != 0) {
        odd = even;
    }
    return odd;
}

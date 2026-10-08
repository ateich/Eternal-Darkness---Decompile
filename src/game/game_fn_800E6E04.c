typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern Vec3 fn_80201E78(void *);
extern void fn_80211A6C(Vec3 *, Vec3 *, Vec3 *);
extern float fn_80211B08(Vec3 *);
extern const float lbl_8064F7C0;

int fn_800E6E04(void *first, void *second)
{
    Vec3 secondPosition = fn_80201E78(second);
    int result = 0;
    Vec3 firstPosition = fn_80201E78(first);
    Vec3 difference;

    fn_80211A6C(&firstPosition, &secondPosition, &difference);
    if (firstPosition.z < secondPosition.z ||
        fn_80211B08(&difference) < lbl_8064F7C0) {
        result = 1;
    }
    return result;
}

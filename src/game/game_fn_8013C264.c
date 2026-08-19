typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern void fn_80211A6C();
extern float fn_80211B08(const Vec3*);
extern void fn_80211A90(Vec3*, const Vec3*, float);
extern float fn_8013C418(const Vec3*, const Vec3*, const Vec3*, Vec3*);
extern float lbl_8065031C;
extern float lbl_80650320;

void fn_8013C264(const Vec3* first, const Vec3* second, Vec3* direction,
                 const Vec3* origin, Vec3* output)
{
    const Vec3* second_ptr;
    Vec3* direction_ptr;
    float distance;
    float amount;

    second_ptr = second;
    direction_ptr = direction;
    fn_80211A6C((Vec3*)second_ptr, first);
    distance = fn_80211B08(direction_ptr);
    if (lbl_8065031C != distance) {
        fn_80211A90(direction_ptr, direction_ptr, lbl_80650320 / distance);
        amount = fn_8013C418(origin, first, direction_ptr, output);
        if (amount < lbl_8065031C) {
            *output = *first;
        } else if (amount > distance) {
            *output = *second_ptr;
        }
    } else {
        *output = *first;
    }
}

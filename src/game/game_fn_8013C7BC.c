typedef struct Vec3 { float x, y, z; } Vec3;

extern float fn_80211B44(const Vec3*, const Vec3*);
extern float lbl_80650324;

int fn_8013C7BC(const Vec3* first, const Vec3* second,
                const Vec3* direction, float offset, float limit)
{
    float first_value;
    float second_value;
    int first_side;
    int second_side;

    first_value = -fn_80211B44(first, direction);
    second_value = -fn_80211B44(second, direction);
    first_side = first_value - offset - lbl_80650324 < limit;
    second_side = second_value + offset + lbl_80650324 < limit;
    if (first_side != second_side) {
        if (first_side == 0) {
            return 2;
        }
        return 3;
    }
    return first_side == 0;
}

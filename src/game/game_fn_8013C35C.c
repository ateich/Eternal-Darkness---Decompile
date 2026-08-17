typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern float fn_8013C418(const Vec3*, const Vec3*, const Vec3*, Vec3*);
extern float lbl_8065031C;

int fn_8013C35C(const Vec3* first, const Vec3* second,
                const Vec3* direction, const Vec3* origin, Vec3* output,
                float limit)
{
    float amount;

    amount = fn_8013C418(origin, first, direction, output);
    if (amount < lbl_8065031C) {
        *output = *first;
        return 1;
    }
    if (amount > limit) {
        *output = *second;
        return 2;
    }
    return 0;
}

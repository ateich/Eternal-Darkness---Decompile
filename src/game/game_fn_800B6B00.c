extern float lbl_80320B30[6];
extern const float lbl_8064F01C;
extern const float lbl_8064F02C;
extern const float lbl_8064F030;
extern const float lbl_8064F034;

void fn_800B6B00(int value)
{
    float* entry = lbl_80320B30;
    int i;

    for (i = 0; i < 6; i++) {
        float target = i == value ? lbl_8064F01C : lbl_8064F02C;

        if (*entry >= target - lbl_8064F030 &&
            *entry <= lbl_8064F030 + target) {
        } else {
            if (*entry < target) {
                *entry += lbl_8064F034;
            } else if (*entry > target) {
                *entry -= lbl_8064F034;
            }
        }
        entry++;
    }
}

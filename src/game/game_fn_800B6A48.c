extern float lbl_80320B30[6];
extern const float lbl_8064F01C;
extern const float lbl_8064F02C;

void fn_800B6A48(int value)
{
    float* entry = lbl_80320B30;
    int i;

    for (i = 0; i < 6; i++, entry++) {
        if (i == value) {
            *entry = lbl_8064F01C;
        } else {
            *entry = lbl_8064F02C;
        }
    }
}

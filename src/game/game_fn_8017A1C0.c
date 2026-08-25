void fn_8017A1C0(float* out, int direction, float current, float target)
{
    float difference = target - current;
    int wrap;

    if ((difference < 0.0f ? -difference : difference) <= 1.17549435e-38f) {
        wrap = direction == 1;
    } else {
        wrap = difference > 0.0f;
    }

    if ((direction == 1) != wrap) {
        if (wrap != 0) {
            difference -= 6.2831855f;
        } else {
            difference = 6.2831855f + difference;
        }
    }

    *out = difference;
}

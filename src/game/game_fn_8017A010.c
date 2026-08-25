extern void fn_8017A12C(float* out, float current, float target);
extern void fn_8017A1C0(float* out, float current, float target);

int fn_8017A010(float* current, int raw, float target, float step,
                float tolerance)
{
    float difference;
    int result;

    if (raw == 0) {
        fn_8017A12C(&difference, *current, target);
    } else {
        fn_8017A1C0(&difference, *current, target);
    }

    if ((difference < 0.0f ? -difference : difference) <= tolerance) {
        result = 0;
    } else {
        if ((difference < 0.0f ? -difference : difference) <= step) {
            *current = target;
            result = 1;
        } else {
            result = 1;
            if (difference < 0.0) {
                *current -= step;
            } else {
                *current += step;
            }
        }
    }

    return result;
}

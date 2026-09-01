extern int fn_801ABCA8(int, int, int, int, int, int);

int fn_801AF9B0(int target, int current, int desired)
{
    int value;

    if (desired == current) {
        value = desired;
    } else {
        value = fn_801ABCA8(current, target, 250, 600, 80, 10);
        if (desired < current) {
            if (desired > value) {
                value = desired;
            }
        } else {
            value = current + current - value;
            if (desired < value) {
                value = desired;
            }
        }
    }

    return (value > 0 ? value : 0) > 127 ? 127 : (value > 0 ? value : 0);
}

extern const volatile double lbl_80239CD0[3];

unsigned int fn_800F5C54(double value)
{
    double zero = lbl_80239CD0[0];
    double limit = lbl_80239CD0[1];
    double bias = lbl_80239CD0[2];
    double converted;
    unsigned int result = 0;

    /* Unordered input must fall through to the all-ones saturation result. */
    if (!(value < zero)) {
        result--;
        if (value < limit) {
            if (value < bias) {
                converted = value;
            } else {
                converted = value - bias;
            }
            result = (int)converted;
            if (!(value < bias)) {
                result += 0x80000000;
            }
        }
    }
    return result;
}

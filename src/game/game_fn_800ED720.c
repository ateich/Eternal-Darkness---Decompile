extern float lbl_8064F898;
extern double lbl_8064F8A0;
extern double lbl_8064F8A8;
extern double __frsqrte(double);

float fn_800ED720(float value)
{
    double estimate;
    volatile float result;

    if (value > lbl_8064F898) {
        estimate = __frsqrte(value);
        estimate = lbl_8064F8A0 * estimate *
                   (lbl_8064F8A8 - estimate * estimate * value);
        estimate = lbl_8064F8A0 * estimate *
                   (lbl_8064F8A8 - estimate * estimate * value);
        estimate = lbl_8064F8A0 * estimate *
                   (lbl_8064F8A8 - estimate * estimate * value);
        result = value * estimate;
        return result;
    }
    return value;
}

extern float lbl_80651000;
extern double lbl_80651008;
extern double lbl_80651010;
extern double __frsqrte(double);

void fn_801CA484(float* vector)
{
    float value = vector[0] * vector[0] + vector[1] * vector[1] +
                  vector[2] * vector[2];
    double estimate;
    volatile float result;

    if (value > lbl_80651000) {
        estimate = __frsqrte(value);
        estimate = lbl_80651008 * estimate *
                   (lbl_80651010 - estimate * estimate * value);
        estimate = lbl_80651008 * estimate *
                   (lbl_80651010 - estimate * estimate * value);
        estimate = lbl_80651008 * estimate *
                   (lbl_80651010 - estimate * estimate * value);
        result = value * estimate;
        value = result;
    }

    vector[0] /= value;
    vector[1] /= value;
    vector[2] /= value;
}

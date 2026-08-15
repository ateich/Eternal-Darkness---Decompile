extern double lbl_8064F080;
extern double lbl_8064F088;
extern double lbl_8064F090;
typedef struct FloatObject {
    float value;
    char pad[12];
} FloatObject;
extern FloatObject lbl_8064B850;
extern FloatObject lbl_8064B854;
extern double __frsqrte(double);

double fn_800B811C(double value)
{
    double estimate;
    if (value > lbl_8064F080) {
        estimate = __frsqrte(value);
        estimate = lbl_8064F088 * estimate *
                   (lbl_8064F090 - estimate * estimate * value);
        estimate = lbl_8064F088 * estimate *
                   (lbl_8064F090 - estimate * estimate * value);
        estimate = lbl_8064F088 * estimate *
                   (lbl_8064F090 - estimate * estimate * value);
        estimate = lbl_8064F088 * estimate *
                   (lbl_8064F090 - estimate * estimate * value);
        return value * estimate;
    }
    if (lbl_8064F080 == value) {
        return lbl_8064F080;
    }
    if (value != lbl_8064F080) {
        return lbl_8064B850.value;
    }
    return lbl_8064B854.value;
}

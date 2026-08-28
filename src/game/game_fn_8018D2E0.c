typedef float Matrix34[3][4];

extern void fn_80211484(Matrix34, float, float, float);
extern void fn_80211268(Matrix34, int, float);
extern void fn_80210FDC(Matrix34, Matrix34, Matrix34);
extern void fn_8022B748(Matrix34, int, int);
extern int* fn_801EF2B0(void);
extern void fn_801EDEC4(int, int, int, int);

void fn_8018D2E0(float value)
{
    Matrix34 second;
    Matrix34 first;
    Matrix34 result;
    int* states;
    int index;
    float angle;
    float scale;

    angle = value;
    value = -0.5f;
    scale = value;
    fn_80211484(first, scale, scale, 0.0f);
    fn_80211268(second, 0x5A, angle);
    fn_80210FDC(second, first, result);
    scale = 0.5f;
    fn_80211484(first, scale, scale, 0.0f);
    fn_80210FDC(first, result, second);
    fn_8022B748(second, 0x1E, 1);

    states = fn_801EF2B0();
    for (index = 0; index < 8; index++) {
        if (states[index] == 0) {
            fn_801EDEC4(index, 1, 4, 0x1E);
            break;
        }
    }
    for (index = 0; index < 8; index++) {
        if (states[index] == 5) {
            fn_801EDEC4(index, 1, 4, 0x1E);
            break;
        }
    }
}

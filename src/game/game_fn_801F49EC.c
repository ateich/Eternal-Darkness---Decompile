typedef struct Vec3 {
    float x, y, z;
} Vec3;

extern Vec3 lbl_802FC678;
extern float lbl_8064C394;
extern float lbl_8064C398;

void fn_801F49EC(Vec3 value, float first, float second)
{
    lbl_802FC678 = value;
    lbl_8064C394 = first;
    lbl_8064C398 = second;
}

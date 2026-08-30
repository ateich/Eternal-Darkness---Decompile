typedef unsigned short u16;

extern float lbl_80650DA0;
extern float lbl_80650DC8;

extern float fn_801A657C(int);
extern u16 fn_801A6E5C(int);

float fn_801A65E0(int value)
{
    float result = lbl_80650DA0;
    u16 state = fn_801A6E5C(value);

    if (state == 2) {
        result = lbl_80650DC8;
    } else if (state == 0) {
        result = fn_801A657C(value);
    }
    return result;
}

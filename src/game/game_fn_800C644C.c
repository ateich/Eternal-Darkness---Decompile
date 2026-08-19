typedef signed short s16;
typedef unsigned int u32;

extern u32 lbl_8064D5A8;
extern double lbl_8064F158;
extern float lbl_8064F1A8;

extern int fn_80038308(void *, int, s16 *);
extern int fn_80038464(void *, int, s16 *);
extern void fn_80036C40(void *, int, s16);

void fn_800C644C(void *object)
{
    s16 x0;
    s16 x1;
    s16 x2;
    s16 y0;
    s16 y1;
    s16 y2;
    float ratio0;
    float ratio1;
    float ratio2;

    if ((lbl_8064D5A8 & 0xF) == 0) {
        fn_80038308(object, 0, &x0);
        fn_80038308(object, 2, &x1);
        fn_80038308(object, 1, &x2);
        fn_80038464(object, 0, &y0);
        fn_80038464(object, 2, &y1);
        fn_80038464(object, 1, &y2);

        ratio0 = (float)x0 / (float)y0;
        ratio1 = (float)x1 / (float)y1;
        ratio2 = (float)x2 / (float)y2;
        if (ratio0 <= lbl_8064F1A8) {
            fn_80036C40(object, 0, x0);
        }
        if (ratio1 <= lbl_8064F1A8) {
            fn_80036C40(object, 2, x1);
        }
        if (ratio2 <= lbl_8064F1A8) {
            fn_80036C40(object, 1, x2);
        }
    }
}

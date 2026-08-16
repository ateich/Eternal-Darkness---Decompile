extern float lbl_8064F1B4;

extern void *fn_800BF0C0(void *);
extern void *fn_8004914C(void *);
extern int fn_8011EB04(void *);
extern void fn_800E87E0(void *, int, int, int, int, int, float);

#pragma use_lmw_stmw on

void *fn_800C3418(void *context, void *object)
{
    void *result = fn_800BF0C0(context);

    if (result != 0) {
        int red;
        int green;
        int blue;
        int type = fn_8011EB04(fn_8004914C(object));

        if (type == 112) {
            red = 233;
            green = 139;
            blue = 233;
        } else if (type == 113) {
            red = 256;
            green = 157;
            blue = 243;
        }
        fn_800E87E0(object, 0, 0, red, green, blue, lbl_8064F1B4);
    }
    return result;
}

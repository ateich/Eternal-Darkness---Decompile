#pragma use_lmw_stmw on

extern int lbl_8064D18C;

extern int fn_8011FB4C(void *);
extern int fn_80128EAC(void *);
extern int fn_80128F40(void *);

int fn_800C99B4(void *object, int expected_type, int threshold)
{
    int result = 0;

    if (object != 0 && lbl_8064D18C == fn_8011FB4C(object)) {
        int type = fn_80128EAC(object);
        int value = fn_80128F40(object) >> 17;

        if (expected_type == type && value > threshold) {
            result = 1;
        }
    }
    return result;
}

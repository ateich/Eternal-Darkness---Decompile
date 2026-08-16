typedef unsigned char u8;

extern int lbl_8064D18C;

extern int fn_8011FB4C(void *);
extern int fn_801261F4(void *);
extern int fn_8011FCEC(void *);
extern void fn_8011EBFC(void *);
extern int fn_80128F40(void *);
extern int fn_800CA13C(u8);
extern int fn_80128EAC(void *);

int fn_800C9BA8(void *object, void *info)
{
    int value;
    int threshold;
    int result;

    if (lbl_8064D18C == fn_8011FB4C(object)) {
        if (fn_801261F4(object) != 0 && fn_8011FCEC(object) != -1) {
            fn_8011EBFC(object);
        }

        value = fn_80128F40(object) >> 17;
        threshold = fn_800CA13C(((u8 *)info)[0x9F]);
        if (fn_80128EAC(object) == 0x18 && value < threshold) {
            result = 0;
        } else {
            result = 1;
        }
    } else {
        result = 0;
    }
    return result;
}

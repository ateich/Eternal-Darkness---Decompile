extern void *fn_80201BC8(void *);
extern int fn_80047CB4(void);
extern int fn_8011EB04(void *);
extern int fn_8011FB4C(void *);
extern int fn_80201B54(void *);
extern void fn_8020104C(int, float, int, int, int);
extern int lbl_8064D18C;
extern float lbl_8064F4C8;

void fn_800DBE34(void *context)
{
    void *object = fn_80201BC8(context);
    if (object != 0 && fn_8011EB04(object) == fn_80047CB4()
        && fn_8011FB4C(object) == lbl_8064D18C) {
        int owner = fn_80201B54(context);
        fn_8020104C(223, lbl_8064F4C8, owner, owner, 1);
    }
}

extern void* lbl_8064CE98;
extern int lbl_8064B9C0;

extern void fn_801E5FB0(void*);

void fn_8011DF6C(void)
{
    if (lbl_8064CE98 != 0) {
        fn_801E5FB0(lbl_8064CE98);
        lbl_8064CE98 = 0;
        lbl_8064B9C0 = -1;
    }
}

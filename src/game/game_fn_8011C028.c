extern int lbl_8064C2BC;

extern void fn_801A872C(int, int, int, int, int, int, int *);
extern void fn_801A8974(int, int, int, int, int, int);

void fn_8011C028(int mode, unsigned char enabled)
{
    if (enabled != 0) {
        if (mode == 1) {
            int color = lbl_8064C2BC;
            fn_801A872C(180, 209, 72, 32, -1, 3, &color);
        } else {
            int color = lbl_8064C2BC;
            fn_801A872C(180, 137, 72, 33, -1, 3, &color);
        }
    } else if (mode == 1) {
        fn_801A8974(180, 209, 72, 32, -1, 3);
    } else {
        fn_801A8974(180, 137, 72, 33, -1, 3);
    }
}

extern void fn_8021345C(void *);
extern void *lbl_8064CD84;
extern int lbl_8064CDA4;
extern void fn_8015DAB0(void *);

void fn_8011824C(void *unused, void *value)
{
    if (value != 0) {
        fn_8021345C(value);
        fn_8015DAB0(lbl_8064CD84);
        lbl_8064CDA4 = 1;
    }
}

extern void *fn_80156938();
extern unsigned int fn_8011FA8C(void *, int, int);
extern int fn_8011FCB0(void *);
extern void fn_8012D0D0(void *);
extern void fn_80124DBC(void *);

int fn_80117FDC(void)
{
    void *object = fn_80156938();

    fn_8011FA8C(object, 0, 0x80000);
    if (fn_8011FCB0(object)) {
        fn_8012D0D0(object);
        fn_80124DBC(object);
    } else {
        fn_8012D0D0(object);
        fn_80124DBC(object);
    }
    return 2;
}

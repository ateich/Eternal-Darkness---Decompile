extern void *fn_80201BC8();
extern void *fn_80201C24(void *);
extern int fn_801579F4(void *);
extern void *fn_80201814();
extern void fn_8011FA8C(void *, int, int);

void fn_800DBEC4(void *context)
{
    void *object = fn_80201BC8(context);
    int count = fn_801579F4(fn_80201C24(context));

    fn_8011FA8C(object, 0x100, 0);
    if (count > 0) {
        fn_8011FA8C(fn_80201BC8(fn_80201814(count)), 0x100, 0);
    }
}

extern void *fn_80201BC8();
extern int fn_80201B54();
extern void fn_8011FE5C(void *, int);
extern void *fn_8011F950(void *);
extern void *fn_801294DC(void *, int, int, int);
extern unsigned long long fn_8020123C();
extern int fn_800E4520(int, int);

void fn_800E41FC(int id)
{
    void *resource;
    int object;

    resource = fn_80201BC8(id);
    fn_8011FE5C(resource, 26);
    if (fn_8011F950(resource) != 0)
        fn_801294DC(resource, 26, 0x10000, 9);

    object = fn_80201B54(id);
    fn_8020123C(20, object, object, 0);
    fn_800E4520(0, 0);
}

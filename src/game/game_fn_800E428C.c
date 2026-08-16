extern void fn_8011FE5C(void *, int);
extern void *fn_8011F950(void *);
extern void *fn_801294DC(void *, int, int, int);

void fn_800E428C(void *resource, int type)
{
    fn_8011FE5C(resource, type);
    if (fn_8011F950(resource) != 0)
        fn_801294DC(resource, type, 33, 1);
}

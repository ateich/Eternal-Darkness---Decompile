extern void *fn_80201BC8();
extern int fn_8011EB04(void *);
extern void *fn_801294DC(void *, int, int, int);
extern void fn_80128C28(void *, int (*)(int, void *), void *);
extern int fn_800C7918(int, void *);
extern int fn_800C77B4(int, void *);

void fn_800C7AEC(void *object)
{
    void *runtime = fn_80201BC8(object);
    int kind = fn_8011EB04(runtime);
    void *result = fn_801294DC(runtime, 6, 36, 6);

    if (kind != 0xFB) {
        fn_80128C28(result, fn_800C7918, object);
    } else {
        fn_80128C28(result, fn_800C77B4, object);
    }
}

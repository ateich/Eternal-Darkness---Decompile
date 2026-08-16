extern void *fn_80201B94(void *);
extern void *fn_80201C48(void *);
extern void *fn_80201814();
extern void *fn_80201BC8();
extern void fn_8011FA8C(void *, int, int);
extern void *fn_801294DC(void *, int, int, int);
extern void fn_80128C28(void *, int (*)(int, void *), void *);
extern int fn_800C77B4(int, void *);
extern int fn_800C7878(int, void *);

void fn_800C7B74(void *object)
{
    void *other = fn_80201814(fn_80201C48(fn_80201B94(object)));
    void *runtime = fn_80201BC8(object);

    fn_8011FA8C(fn_80201BC8(other), 0x800, 0xC0);
    fn_80128C28(fn_801294DC(runtime, 7, 4, 9), fn_800C77B4, object);
    fn_800C7878(0, object);
}

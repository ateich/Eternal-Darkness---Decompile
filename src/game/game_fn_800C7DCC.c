extern void *fn_80201B94(void *);
extern void *fn_80201C48(void *);
extern void *fn_80201814();
extern void *fn_80201BC8();
extern void fn_8011FA8C(void *, int, int);
extern void *fn_801294DC(void *, int, int, int);

void fn_800C7DCC(void *object)
{
    void *other = fn_80201814(fn_80201C48(fn_80201B94(object)));
    void *runtime = fn_80201BC8(object);

    fn_8011FA8C(fn_80201BC8(other), 0xC0, 0x800);
    fn_801294DC(runtime, 5, 0x25, 6);
}

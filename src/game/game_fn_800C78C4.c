extern void *fn_80201BC8(void *);
extern void *fn_801294DC(void *, int, int, int);
extern int fn_800C77B4(int, void *);
extern void fn_80128C28(void *, int (*)(int, void *), void *);

int fn_800C78C4(int unused, void *object)
{
    void *result = fn_801294DC(fn_80201BC8(object), 6, 36, 1);
    fn_80128C28(result, fn_800C77B4, object);
    return 1;
}

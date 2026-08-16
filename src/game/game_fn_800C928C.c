extern void fn_80152404(void *, void *, void *, int, void *);
extern void fn_801AC9F4(void *, int, void *, int);

void fn_800C928C(void *object, void *arg1, void *arg2, void *owner,
                 void **extra)
{
    void *extra_copy = *extra;

    fn_80152404(object, arg1, arg2, 0xC, &extra_copy);
    fn_801AC9F4(owner, 0x64, object, 2);
}

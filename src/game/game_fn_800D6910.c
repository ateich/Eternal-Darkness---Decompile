extern void *fn_80201BC8();
extern void fn_800A30B8(void *, int);
extern void fn_8012C478(void *, int, int);

void fn_800D6910(void *object, void *handle)
{
    void *runtime = fn_80201BC8(handle);

    fn_800A30B8(object, 1);
    fn_8012C478(runtime, 0, 0);
    fn_8012C478(runtime, 14, 0);
}

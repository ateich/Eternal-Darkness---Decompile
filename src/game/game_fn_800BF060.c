extern void *fn_800BF0C0(void *, void *);
extern void fn_8003BD48(void *, void *);
extern void fn_800890F4(int);

void *fn_800BF060(void *object, void *value)
{
    void *result = fn_800BF0C0(object, value);

    if (result != 0) {
        fn_8003BD48(object, value);
        fn_800890F4(0);
    }
    return result;
}

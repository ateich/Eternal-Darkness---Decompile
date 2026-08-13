extern int fn_80128F40(void *object);
extern void fn_80129FD0(void *object, int value, int flags);

int fn_800798C4(void *object)
{
    int value = fn_80128F40(object);
    fn_80129FD0(object, value, 0);
    return 1;
}

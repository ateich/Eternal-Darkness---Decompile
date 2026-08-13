extern int fn_80128EAC(void *);
extern void fn_8007412C(void *, int);

int fn_800740E8(void *object, void *argument)
{
    if (fn_80128EAC(object) == 7) {
        fn_8007412C(argument, 0);
    }
    return 1;
}

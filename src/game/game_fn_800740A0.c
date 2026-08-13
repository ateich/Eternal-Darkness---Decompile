extern int fn_80201B64(void *);
extern void fn_8007412C(void *, int);

int fn_800740A0(void *unused, void *argument)
{
    if (fn_80201B64(argument) == 0x33) {
        fn_8007412C(argument, 1);
    }
    return 1;
}

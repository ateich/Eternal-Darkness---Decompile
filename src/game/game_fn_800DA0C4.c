extern int fn_800A30AC(void *);
extern void fn_801296F8(void *, int);

int fn_800DA0C4(void *context, void *object)
{
    if (fn_800A30AC(object) != 0) {
        fn_801296F8(context, 0x9911);
    }
    return 1;
}

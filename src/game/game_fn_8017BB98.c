extern int fn_8017BB24(void);
extern unsigned int* fn_8017BB44(void);

unsigned int fn_8017BB98(void)
{
    if (fn_8017BB24() == 0) {
        return fn_8017BB44()[1];
    }
    return 0;
}

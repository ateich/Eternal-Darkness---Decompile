extern int fn_8017BB24(void);
extern unsigned int* fn_8017BB44(void);

unsigned int fn_8017BB60(void)
{
    if (fn_8017BB24() == 0) {
        return fn_8017BB44()[0];
    }
    return 0;
}

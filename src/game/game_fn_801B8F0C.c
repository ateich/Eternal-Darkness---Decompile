extern unsigned int fn_801C14D0(void);

int fn_801B8F0C(int arg0)
{
    if (fn_801C14D0() != (unsigned int)-1) {
        return arg0;
    }
    return -1;
}

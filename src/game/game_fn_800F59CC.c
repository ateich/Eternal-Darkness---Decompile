extern unsigned char fn_800F592C(void);
extern int fn_800F2BEC(void);
extern unsigned char fn_800F4F30(int, int, unsigned int *, void *);

int fn_800F59CC(int unused, void *arg, unsigned int *value)
{
    unsigned int local;
    unsigned char result;
    if (fn_800F592C() == 0) {
        return 1;
    }
    if (fn_800F2BEC() == 0) {
        return 1;
    }
    local = *value;
    result = fn_800F4F30(0xD0, 1, &local, arg);
    *value = local;
    switch (result) {
    case 0:
        return 0;
    case 2:
        return 2;
    default:
        return 1;
    }
}

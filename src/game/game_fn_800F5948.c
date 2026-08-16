extern int fn_800F2BEC(void);
extern unsigned char fn_800F4F40(int, void *);

int fn_800F5948(void *arg)
{
    unsigned char result;
    if (fn_800F2BEC() == 0) {
        return 1;
    }
    result = fn_800F4F40(0xD3, arg);
    switch (result) {
    case 0:
        return 0;
    case 2:
        return 2;
    default:
        return 1;
    }
}

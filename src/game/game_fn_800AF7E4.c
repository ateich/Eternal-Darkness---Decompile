extern int fn_80220234(int, int*, int*);

int fn_800AF7E4(int index, int* status)
{
    int value;
    int flags;

    *status = fn_80220234(index, &value, &flags);
    if (*status == 0) {
        if (flags == 0x2000) {
            return 1;
        }
        return -2;
    }
    return -1;
}

extern unsigned short fn_800BAE80(void *, void *, void *, int *, int *);

#pragma use_lmw_stmw on

unsigned short fn_800BB1EC(void *output, int count, void *arg1, void *arg2)
{
    unsigned short size = 0;
    int index;
    int zero;
    int consumed;
    int unused;

    if (count != 0) {
        index = 0;
        zero = 0;
        while (index < count) {
            consumed = zero;
            size += fn_800BAE80((char *)output + size, arg1, arg2,
                                &consumed, &unused);
            index += consumed;
            index++;
        }
    }
    return size;
}

extern void *lbl_8064CB10;
extern void *fn_8017CDB4(void *);
extern void *memset(void *, int, unsigned long);

void *fn_800EA08C(void)
{
    void *entry = fn_8017CDB4(lbl_8064CB10);

    if (entry != 0) {
        memset(entry, 0, 40);
    }
    return entry;
}

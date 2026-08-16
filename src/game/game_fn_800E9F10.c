extern void *memset(void *, int, unsigned long);
extern void *lbl_80325F1C[6];

void fn_800E9F10(void)
{
    memset(lbl_80325F1C, 0, sizeof(lbl_80325F1C));
}

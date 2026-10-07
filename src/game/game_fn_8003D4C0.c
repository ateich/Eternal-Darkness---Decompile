extern void *memset(void *, int, unsigned long);

extern unsigned char lbl_80303D90[0x2D0];

void fn_8003D4C0(void)
{
    memset(lbl_80303D90, 0, sizeof(lbl_80303D90));
}

extern void *memset(void *, int, unsigned int);
extern unsigned char lbl_80320FD0[];
extern unsigned char lbl_80320DF0[];

void fn_800BD384(void)
{
    memset(lbl_80320FD0, 0, 0x4060);
    memset(lbl_80320DF0, 0, 0x1E0);
}

typedef unsigned int u32;
extern unsigned char lbl_8064C8DC[8];
extern void *memset(void *, int, u32);

void fn_8007BD14(void)
{
    memset(lbl_8064C8DC, 0, sizeof(lbl_8064C8DC));
}

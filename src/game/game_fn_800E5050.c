extern unsigned int lbl_8064CAFC;
extern void *memcpy(void *, const void *, unsigned int);

int fn_800E5050(void *dst)
{
    memcpy(dst, &lbl_8064CAFC, 4);
    return 0x20;
}

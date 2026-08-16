extern unsigned char lbl_80331748[];
extern void *memcpy(void *, const void *, unsigned int);

int fn_80117AAC(const void *source)
{
    memcpy(lbl_80331748, source, 0xB0);
    return 0xC0;
}

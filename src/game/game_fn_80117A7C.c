extern unsigned char lbl_80331748[];
extern void *memcpy(void *, const void *, unsigned int);

int fn_80117A7C(void *destination)
{
    memcpy(destination, lbl_80331748, 0xB0);
    return 0xC0;
}

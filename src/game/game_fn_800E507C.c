extern unsigned int lbl_8064CAFC;
extern void *memcpy(void *, const void *, unsigned int);

int fn_800E507C(const void *src)
{
    memcpy(&lbl_8064CAFC, src, 4);
    return 0x20;
}

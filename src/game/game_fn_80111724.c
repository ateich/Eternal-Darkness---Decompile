extern unsigned int lbl_8064CCF4;
extern void* memcpy(void*, const void*, unsigned int);

int fn_80111724(void* dst)
{
    memcpy(dst, &lbl_8064CCF4, 4);
    return 32;
}

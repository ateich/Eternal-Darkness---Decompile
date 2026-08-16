extern unsigned int lbl_8064CCF4;
extern void* memcpy(void*, const void*, unsigned int);

int fn_80111750(const void* src)
{
    memcpy(&lbl_8064CCF4, src, 4);
    return 32;
}

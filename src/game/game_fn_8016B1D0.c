extern unsigned char lbl_805FAA60[80];
extern void* lbl_8064D1C0;
extern void* memcpy(void*, const void*, unsigned long);
extern int fn_800480D4(void*, void*);

int fn_8016B1D0(void* output)
{
    int result;

    memcpy(output, lbl_805FAA60, 80);
    result = fn_800480D4(lbl_8064D1C0, (unsigned char*)output + 80);
    return (result + 111) & 0xFFE0;
}

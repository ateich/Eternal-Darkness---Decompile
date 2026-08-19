extern unsigned char lbl_805FAA60[80];
extern void* lbl_8064D1C0;
extern void* memcpy(void*, const void*, unsigned long);
extern int fn_800483A0(void*, void*);

int fn_8016B21C(void* input)
{
    int result;

    memcpy(lbl_805FAA60, input, 80);
    result = fn_800483A0(lbl_8064D1C0, (unsigned char*)input + 80);
    return (result + 111) & 0xFFE0;
}

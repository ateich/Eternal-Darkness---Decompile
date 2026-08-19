extern int lbl_8064D124;
extern void* lbl_8064D128;
extern unsigned char lbl_805EDEA0[];

void* fn_8015D424(int* size, void* callback)
{
    void* result = lbl_805EDEA0;

    lbl_8064D124 = 1;
    lbl_8064D128 = callback;
    *size = 50000;
    return result;
}

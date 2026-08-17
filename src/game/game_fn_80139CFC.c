extern unsigned char* lbl_8064CFEC;

void* fn_80139CFC(int size)
{
    unsigned char* result = lbl_8064CFEC;
    lbl_8064CFEC += size;
    return result;
}

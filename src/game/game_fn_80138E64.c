extern unsigned char* lbl_8064CFD8;
extern unsigned int fn_80138E58(void);

void* fn_80138E64(unsigned char* address)
{
    unsigned int size = fn_80138E58();

    lbl_8064CFD8 = address;
    address += size;
    return address;
}

extern unsigned char* lbl_8064CFC0;
extern unsigned int lbl_8064D00C;

extern void fn_8015E9EC(void*, void*, unsigned int);
extern void fn_8013824C(void);

void* fn_80138CD4(void* object, unsigned int size)
{
    void* address = lbl_8064CFC0 + 0x3D3100 - size;

    fn_8015E9EC(object, address, size);
    lbl_8064D00C = size;
    fn_8013824C();
    return address;
}

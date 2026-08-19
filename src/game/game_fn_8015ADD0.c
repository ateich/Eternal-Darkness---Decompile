typedef unsigned char u8;

extern int fn_800460FC(void);
extern int fn_8015AA14(void);
extern u8* lbl_8064D170;

u8* fn_8015ADD0(u8* address)
{
    int count = fn_800460FC();
    int stride = fn_8015AA14();
    int i;

    for (i = 0; i < count; i++) {
        (&lbl_8064D170)[i] = address;
        address += stride;
    }

    return address;
}

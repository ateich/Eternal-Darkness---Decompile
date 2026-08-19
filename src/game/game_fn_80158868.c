typedef unsigned char u8;

extern int fn_800460FC(void);
extern int fn_8015885C(void);
extern u8* lbl_8064D168;

u8* fn_80158868(u8* address)
{
    int count = fn_800460FC();
    int size = fn_8015885C();
    int i;

    for (i = 0; i < count; i++) {
        (&lbl_8064D168)[i] = address;
        address += size;
    }
    return address;
}

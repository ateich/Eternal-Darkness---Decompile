typedef unsigned char u8;
extern u8 lbl_805B40A0[];
extern void fn_8021959C(int, int);
extern void* memset(void*, int, unsigned int);

void fn_801443F4(void)
{
    fn_8021959C(0, 2);
    memset(lbl_805B40A0, 0, 0x1E);
}

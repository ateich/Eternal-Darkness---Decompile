typedef unsigned char u8;

extern void* memset(void*, int, unsigned long);
extern u8 lbl_8060B22C[0x200];
extern void* lbl_8064D304;

void fn_801ACD8C(void)
{
    memset(lbl_8060B22C, 0, 0x200);
    lbl_8064D304 = 0;
}

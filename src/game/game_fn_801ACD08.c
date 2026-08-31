typedef unsigned char u8;

extern void fn_801ACD8C(void);
extern void* memset(void*, int, unsigned long);
extern void fn_801ACCA0(int, int);
extern void fn_801B1740(int);
extern void fn_801B17A8(int);
extern void fn_801B17A4(int);
extern u8 lbl_8060B060[0x1A4];
extern u8 lbl_8060B204[0x28];
extern int lbl_8064D300;
extern int lbl_8064C2D0;
extern int lbl_8064D2FC;

void fn_801ACD08(void)
{
    fn_801ACD8C();
    memset(lbl_8060B060, 0, 0x1A4);
    memset(lbl_8060B204, 0, 0x28);
    lbl_8064D300 = 1;
    lbl_8064C2D0 = -1;
    lbl_8064D2FC = 0;
    fn_801ACCA0(100, 100);
    fn_801B1740(0);
    fn_801B17A8(lbl_8064D2FC);
    fn_801B17A4(1);
}
